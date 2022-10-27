//usr/bin/cc "$0" "comms.c" -lm && exec ./a.out "$@"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "comms.h"

#define BUFFSIZE 512

int wait_loop0 = 10000/10;
int wait_loop1 = 6000;

double driveTable[4][2] = {
    {78, 0.92}, {80, 1.56}, {82, 2.19}, {84, 2.61}
};
double steerTable[15][2] = {
  {54, 45}, {56, 45}, {58, 55}, {60, 60}, {62, 70},
  {64, 75}, {66, 80}, {68, 85}, {70, 90}, {72, 95},
  {74, 105}, {76, 110}, {80, 115}, {82, 120}, {84, 125}, 
  {86, 130}
/*    {75.0,135.46}, {75.2,135.80}, {75.4,138.26}, {75.6,136.94},
    {75.8,132.40}, {76.0,123.60}, {76.2,109.53}, {76.4,105.06},
    {76.6,95.60}, {76.8,92.33}, {77.0,87.06}, {77.2,79.53},
    {77.4,76.53}, {77.6,71.73}, {77.8,67.86}, {78.0,66.20},
    {78.2,63.74}, {78.4,63.40}, {78.6,64.73}, {78.8,61.07},
    {79.0,59.20}, {79.2,56.60}, {79.4,55.60}, {79.6,52.73},
    {79.8,51.07}, {80.0,49.87}, {80.2,48.20}, {80.4,46.40},
    {80.6,45.07}, {80.8,43.93}, {81.0,42.13}, {81.2,41.47},
    {81.4,40.47}, {81.6,38.93}, {81.8,39.07}*/
};
double controlArray[14][9] = {
    {1,    1,    8.5,  1,    3,    0,    -1,   1,    3   }/*, 
    {0,    3,    3,    2,    1,    1,    0,    3,    1   },
    {1,    3,    1,    9.5,  1.5,  1,    0,    9.5,  1.5 },
    {0,    9.5,  3,    1.5,  1,    0,    1,    11,   3   },
    {1,    11,   3,    11,   4.5,  0,    1,    11,   4.5 },
    {0,    9.5,  4.5,  1.5,  1,    0,    -1,   8,    4.5 },
    {0,    7,    4.5,  1,    -1,   -1,   0,    7,    3.5 },
    {1,    7,    3.5,  5.5,  3.5,  -1,   0,    5.5,  3.5 },
    {0,    5.5,  6.0,  2.5,  -1,   1,    0,    5.5,  8.5 },
    {1,    5.5,  8.5,  9,    8.5,  1,    0,    9,    8.5 },
    {0,    9,    10,   1.5,  1,    -1,   0,    9,    11.5},
    {1,    9,    11.5, 6,    10.5, -1,   0,    6,    10.5},
    {1,    6,    10.5, 3,    10.5, -1,   0,    3,    10.5},
    {0,    3,    8.5,  2,    1,    0,    -1,   1,    8.5 }*/
/*  {1, 1, 9, 1, 2, 0, -1, 1, 2},
    {0, 2.1, 2.1, 1, 1, 1, 0, 2, 1},
    {1, 2, 1, 6, 2, 1, 0, 6, 2},
    {1, 6, 2, 10, 1.5, 1, 0, 9.8, 1.5},
    {0, 9.9, 2.6, 1, 1, 0, 1, 10.8, 2.5},
    {1, 11, 2.5, 11, 5, 0, 1, 11, 5},
    {0, 10, 4.9, 1, 1, 0, -1, 9, 5},
    {0, 7.9, 5.1, 1, 0, -1, 0, 8, 4},
    {1, 8, 4, 4, 4.5, -1, 0, 4.2, 4.5},
    {0, 4.1, 5.6, 1, 0, 0, 1, 3, 5.3},
    {1, 3, 5.5, 3, 8, 0, 1, 3, 7.6},
    {0, 4.1, 7.9, 1, 0, 1, 0, 3.8, 9},
    {1, 4, 9, 10, 9, 1, 0, 10.1, 9},
    {0, 10, 10.5, 1.5, 1, -1, 0, 10, 12},
    {1, 10, 12, 6, 10, -1, 0, 6, 10},
    {1, 6, 10, 2, 10, -1, 0, 2, 10},
    {0, 2, 9, 1, 1, 0, -1, 1, 9}*/
};
int controlIndex = 0;
double kp = 0;
double kd = 0;
double ki = 0;
int lap = 0;
double dt = 0.05;
double v = 1.0;
double carLocation[2] = {1, 6};
double thetaC = 3 * M_PI/2;
double thetaS = 0;
double theta = 0;
double derivLine = 0;
double derivCirc = 0;
double X[3] = {0, 0, 0};
double U[2] = {0, 0};
double pozyxInput[3] = {0, 0, 0};
double resetIntegral = 0;
double PWM[2] = {0, 0};
double X_old_predicted[2] = {0, 0};
int counter = 0;
float encoderData;

void initialize();
void AutoCodeEncoder(double U[], float encoderData);
void estimatedPos(double U[], double X[]);
void updatePosPozyx(double X[], double pozyxInput[]);
void control(double X[]);
void sendMotorPWM(double U[]);

/* Queue */
struct node {
    double index;
    double data1;
    double data2;
    struct node *link;
}*front, *rear;


void insert(); // Function used to insert the element into the queue
void delet(); // Function used to delete the elememt from the queue
void serch(int index, double out[2]); // Function used to display all the elements in the queue according to FIFO rule
int size();
void wait(int seconds);

double out[2] = {0, 0};

void insert(double pozInput[3]) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    /*
    printf("Enter the element to be inserted in the queue: ");
    scanf("%f", &temp->data);
    */
    temp->index = pozInput[0];
    temp->data1 = pozInput[1];
    temp->data2 = pozInput[2];
    temp->link = NULL;
    if (rear == NULL) {
        front = rear = temp;
    }
    else {
        rear->link = temp;
        rear = temp;
    }
}

void delet() {
    struct node *temp;
    temp = front;
    if (front == NULL) {
        front = rear = NULL;
    } 
    else {
        front = front->link;
        free(temp);
    }
}
        
void serch(int index, double X_old_predicted[2]) {
    struct node *temp;
    temp = front;
    while (temp) {
        if (temp->index == index) {
            X_old_predicted[0] = temp->data1;
            X_old_predicted[1] = temp->data2;
        }
        temp = temp->link;
    }
}

int size() {
    struct node *temp;
    temp = front;
    int cnt = 0;
    while (temp)
    {
        temp = temp->link;
        cnt++;
    }
    return cnt;
}
/* End Queue */

void main() {
    /*Stuff to send/receive data for HW interfacing*/
    struct Pipes pip;
	pip = openPipes();
    double heading;
	double posx;
	double posy;

	char buf[BUFFSIZE] = {0};
	char outbuf[BUFFSIZE] = {0};
    /* END of HW interfacing*/

    initialize();
    while(lap < 4 ) {
        readInPipe(pip, buf, BUFFSIZE);
        if(buf[0] != 0x0)
        {
            sscanf(strtok(buf, ","), "%lf", &posx);
            printf("%.4lf\n", posx);
            sscanf(strtok(NULL, ","), "%lf", &posy);
            printf("%.4lf\n", posy);
            sscanf(strtok(NULL, ","), "%lf", &heading);
            printf("%.4lf\n", heading);
        }
        double pozyxInfo[2] = {posx, posy}; 

        AutoCodeEncoder(U, encoderData);
        estimatedPos(X, U);
        //updatePosPozyx(X, pozyxInput);
        control(X);
        sendMotorPWM(U);
        sprintf(outbuf, "%lf,%lf",PWM[0],PWM[1]);
        writeOutPipe(pip, outbuf, BUFFSIZE);
        if(counter > 2/dt) {
            delet();
        }
        double queueInsert[3] = {counter, X[0],X[1]};
        insert(queueInsert);
        counter +=1; 
        printf("Coordinates: [%lf, %lf] Drive PWM: %lf Steer PWM: %lf \n", X[0], X[1], PWM[0], PWM[1]);
        wait(1);
    }
}

void initialize() {
    X[0] = carLocation[0];
    X[1] = carLocation[1];
    X[2] = thetaC;
    U[0] = v;
    U[1] = 0;
    pozyxInput[0] = 0;
    pozyxInput[1] = 0;
    pozyxInput[2] = 0;
}

void AutoCodeEncoder(double U[2], float encoderData)
{
    static int counter1;
    static int counter2;
    static float buffer;
    encoderData = -1; // for testing
    while(counter1 < 3 && counter2 < 5)
    {
        if (0 < encoderData && encoderData < 500)
        {
            buffer += 46.019423 / encoderData;
            counter1 += 1;
        }
        counter2 += 1;
    }

    if (counter1 == 3)
    {
        if (0 < buffer && buffer < 10)
        {
            U[0] = buffer/3;
        }
        counter1 = 0;
        counter2 = 0;
    }
    else {
        U[0] = U[0];
        counter1 = 0;
        counter2 = 0;  
    }
  
}

void estimatedPos(double X[], double U[]) {
    v = U[0];
    thetaS = U[1];
    theta = X[2];
    double X_dot[3] = {v*cos(theta), v*sin(theta), v*tan(thetaS)/0.27};
    X[0] = X_dot[0] * dt + X[0];
    X[1] = X_dot[1] * dt + X[1];
    X[2] = X_dot[2] * dt + X[2];
    while(X[2] > 2*M_PI) {
        X[2] -= 2*M_PI;
    }
    while(X[2] < 0.0) {
        X[2] += 2*M_PI;
    }
}

void updatePosPozyx(double X[], double pozyxInput[]) {
    double muPosTime = .01;
    double updatePos[2];
    if (size() > 1.9 / dt){
        int index = muPosTime/dt;
        serch(counter-index, X_old_predicted);
        updatePos[0] = pozyxInput[0] - X_old_predicted[0];
        updatePos[1] = pozyxInput[1] - X_old_predicted[1];
        X[0] += updatePos[0]/100;
        X[1] += updatePos[1]/100;
    }
}

void control(double X[]) {
    static double oldDLine;
    static double oldDCirc;
    static double integral;
    double H = 0;
    double P[2] = {controlArray[controlIndex][7], controlArray[controlIndex][8]};
    double N[2] = {controlArray[controlIndex][5], controlArray[controlIndex][6]};
    double vec1[2] = {X[0] - P[0], X[1] - P[1]};
    for (int i = 0; i < 2; i++) {
        H += vec1[i] * N[i];
    }
    if(H > 0) {
        if(controlIndex == (sizeof(controlArray) / sizeof(controlArray[0])) - 1) {
            controlIndex = 0;
            lap++;
        }
        else {
            controlIndex++;
        }
        resetIntegral = 1;
    }
    else {
        resetIntegral = 0;
    }
    if(controlArray[controlIndex][0] == 0) {
        //Control Circle
        if(resetIntegral == 1) {
            integral = 0;
        }
        double lambda = controlArray[controlIndex][4];
        double Rcirc = controlArray[controlIndex][3];
        double C[2] = {controlArray[controlIndex][1], controlArray[controlIndex][2]};
        double xy[2] = {X[0], X[1]};
        double Rcar = sqrt(((C[0]-xy[0])*(C[0]-xy[0]))+((C[1]-xy[1])*(C[1]-xy[1])));
        double error = Rcar - Rcirc;
        kp = lambda * 0.4;
        kd = lambda * 0.5;
        ki = lambda * 0.01;
        if(resetIntegral == 1) {
            integral = 0;
            derivCirc = 0;
        }
        else {
            derivCirc = (error-oldDCirc)/dt;
        }
        thetaS = error*kp + integral*ki + kd*derivCirc;
        U[0] = v;
        U[1] = thetaS;
        oldDCirc = error;
        integral = integral + error*dt;
    }
    else {
        // Control Line
        double determinant = 0;
        double inverse[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
        double D = 0;
        double Xmatrix[3] = {X[0], X[1], 1};
        double W1[2] = {controlArray[controlIndex][1], controlArray[controlIndex][2]};
        double W2[2] = {controlArray[controlIndex][3], controlArray[controlIndex][4]};
        double xdiff = W2[0] - W1[0];
        double ydiff = W2[1] - W1[1];
        double angle = atan2(ydiff,xdiff);
        double R[3][3] = {
            {cos(angle), -sin(angle), W1[0]},
            {sin(angle), cos(angle), W1[1]},
            {0, 0, 1}
        };
        for(int i=0;i<3;i++) {
            determinant = determinant + (R[0][i]*(R[1][(i+1)%3]*R[2][(i+2)%3] - R[1][(i+2)%3]*R[2][(i+1)%3]));
        }
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                inverse[i][j] = ((R[(j+1)%3][(i+1)%3] * R[(j+2)%3][(i+2)%3]) - (R[(j+1)%3][(i+2)%3]*R[(j+2)%3][(i+1)%3])) / determinant;
            }
        }
        D = inverse[1][0] * Xmatrix[0] + inverse[1][1] * Xmatrix[1] + inverse[1][2] * Xmatrix[2];
        kp = -0.4;
        kd = -0.5;
        derivLine = (D-oldDLine)/dt;
        thetaS = D * kp + kd * derivLine;
        U[0] = v;
        U[1] = thetaS;
        oldDLine = D;
    }

}

void sendMotorPWM(double U[]) {
    double steerAnglePWM = 0;
    double driveSpeedPWM = 0;
    double steerAngle = 57.295579513082323 * U[1];
    double driveSpeed;
    while ((steerAngle < -180.0) || (steerAngle > 180.0)) {
        if (steerAngle < -180.0) {
            steerAngle += 360.0;
        } else if (steerAngle > 180.0) {
            steerAngle -= 360.0;
        }
    }
    steerAngle += 90.0;
    for(int i = 0; i < sizeof(driveTable) / sizeof(driveTable[0]); i++) {
        if(driveSpeedPWM == 0 && U[0] - 0.3 < driveTable[i][1] && U[0] + 0.3 > driveTable[i][1]) {
            driveSpeedPWM = driveTable[i][0];
            //U[0] = driveTable[i][1];
        }
    }
    for(int i = 0; i < sizeof(steerTable) / sizeof(steerTable[0]); i++) {
        if(steerAnglePWM == 0 && steerAngle - 7 < steerTable[i][1] && steerAngle + 7 > steerTable[i][1]) {
            steerAnglePWM = steerTable[i][0];
            //U[1] = driveTable[i][1];
        }
    }
    if (steerAngle > 130.0) {
        steerAnglePWM = 88;
        //U[1] = steerTable[14][1];
    } else if (steerAngle < 45.0) {
        steerAnglePWM = 60;
        //U[1] = steerTable[0][1];
    }

    if(driveSpeedPWM == 0) {
        driveSpeedPWM == 78;
        //U[0] = driveTable[0][1];
    }

    if(steerAnglePWM == 0) {
        steerAnglePWM = 74;
        //U[1] = steerTable[7][1];
    }
    PWM[0] = driveSpeedPWM;
    PWM[1] = steerAnglePWM;
}

/* Time Delay method*/
void wait( int seconds )
{   // this function needs to be finetuned for the specific microprocessor
    int i, j, k;
    for(i = 0; i < seconds; i++)
    {
        for(j = 0; j < wait_loop0; j++)
        {
            for(k = 0; k < wait_loop1; k++)
            {   // waste function, volatile makes sure it is not being optimized out by compiler
                int volatile t = 120 * j * i + k;
                t = t + 5;
            }
        }
    }
}
