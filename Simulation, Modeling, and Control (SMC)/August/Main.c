#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Comms.h"

#define BUFFSIZE 512

int wait_loop0 = 10000 / 10;
int wait_loop1 = 6000;
int controlIndex = 0;

// hey put in reverse later please
double driveTable[7][2] = {
    {77, .724},
    {79, 1.32},
    {81, 1.95},
    {83, 2.37},
    {85, 2.82},
    {87, 2.74},
    {89, 2.8}};

double steerTable[24][2] = {
    {87, 61}, {86, 64}, {85, 66}, {84, 69}, {83, 71}, {82, 73}, {81, 75}, {80, 77}, {79, 81}, {78, 84}, {77, 86}, {76, 90}, {75, 94}, {74, 96}, {73, 100}, {72, 104}, {71, 106}, {70, 108}, {69, 111}, {68, 116}, {67, 120}, {66, 124}, {65, 130}, {64, 135}};

// line
// double controlArray[1][9] = {
//   {1, 10.927, 9.55, 5.366, 9.464, -1, 0, -100, 0}};
// circle
//  double controlArray[1][9] = {
//   {0, 9.415, 9.592, 1, 1, 0, 1, 0, 100}};
// minitrack
double controlArray[4][9] = {
    {1, 9, 11, 8, 11.054, -1, 0, 7.8, 11.054},
    {0, 8, 10, 1, 1, 1, 0, 8, 9},
    {1, 8, 9, 9, 9, 1, 0, 9, 9},
    {0, 9, 10, 1, 1, -1, 0, 9, 11.069}};

// double controlArray[17][9] = {
//     {1, 1, 9, 1, 2, 0, -1, 1, 2},
//     {0, 2, 2, 1, 1, 1, 0, 2, 1},
//     {1, 2, 1, 6, 2, 1, 0, 6, 2},
//     {1, 6, 2, 10, 1.5, 1, 0, 9.8, 1.5},
//     {0, 10, 2.5, 1, 1, 0, 1, 10.8, 2.5},
//     {1, 11, 2.5, 11, 5, 0, 1, 11, 5},
//     {0, 10, 4.9, 1, 1, 0, -1, 9, 5},
//     {0, 8, 5, 1, 0, -1, 0, 8, 4},
//     {1, 8, 4, 4, 4.5, -1, 0, 4.2, 4.5},
//     {0, 4, 5.5, 1, 0, 0, 1, 3, 5.3},
//     {1, 3, 5.5, 3, 8, 0, 1, 3, 7.6},
//     {0, 4, 8, 1, 0, 1, 0, 3.8, 9},
//     {1, 4, 9, 10, 9, 1, 0, 10.1, 9},
//     {0, 10, 10.5, 1.5, 1, -1, 0, 10, 12},
//     {1, 10, 12, 6, 10, -1, 0, 6, 10},
//     {1, 6, 10, 2, 10, -1, 0, 2, 1},
//     {0, 2, 9, 1, 1, 0, -1, 1, 9}};

double dt = .01;
double v = 1;
double pozyxInput[2];

struct node
{
    double index;
    double data1;
    double data2;
    struct node *link;
} * front, *rear;

double X_old_predicted[2];
double x[2];
double out[2] = {0, 0};
int sizeOf;

double sigmaSteering;
double degs = 5;
double sigmaDrive = .7;
double sigmaPos = .1;
double sigmaPosTime = .1;
// check the xbar number
double xbar[3];

/* function defs*/
void topLevel(void);
void Initialize(double X[3], double U[2]);
double deg2rad(double degs);
void Dynamics(double U[2], double X[3]);
void Control(double X[3], double U[2]);
void controlLine(double X[3], double U[2]);
void controlCircle(double X[3], double U[2], int reset);
void delet();
void setMotorPWM(double U[2], int PWM[2]);
double checkHalfPlane(double X[3]);
void Uncertainty(int xbar[], int pozyxInput[], int counter);
void search(int index, double X_old_predicted[2]);
int size();
void insert(double pozInput[3]);
void Encoder(double U[2], float encoderData);
void estimatePos(double X[3], double U[2]);
void updatePosPozyx(double X[3], double pozyxInput[2], int counter);
void wait(int seconds);

// X, U = Initialize
void main()
{
    topLevel();
}

void topLevel(void)
{
    double X[3];
    double X_dot[3];
    double U[2];
    int counter = 0;
    int PWM[2];
    float encoderData;
    double Rcar;

    struct Pipes pip;
    pip = openPipes();
    double heading;
    double posx;
    double posy;
    char buff[BUFFSIZE] = {0};
    char outbuff[BUFFSIZE] = {0};

    Initialize(X, U);

    // sigmaSteering = deg2rad(degs);
    // double carLocation[] = {1, 9};
    // double thetaC = 3 * M_PI / 2;
    // double X[] = {carLocation[1], carLocation[2], thetaC}; // x, y, thetaC
    // double U[] = {v, 0};
    // int xbar = 0;
    // // fix priority queue
    // int oldPos = priorityQueue[0];

    while (1)
    {
        readInPipe(pip, buff, BUFFSIZE);
        if (buff[0] != 0x0)
        {
            sscanf(strtok(buff, ","), "%lf", &posx);
            printf("%.4lf\n", posx);
            sscanf(strtok(NULL, ","), "%lf", &posy);
            printf("%.4lf\n", posy);
            sscanf(strtok(NULL, ","), "%lf", &heading);
            printf("%.4lf\n", heading);
        }
        double pozyxInfo[2] = {posx, posy};

        // fix these
        Encoder(U, encoderData);
        // printf("1: %lf", U[1]);
        estimatePos(X, U);
        // printf("2: %lf", U[1]);
        // updatePosPozyx(X, pozyxInfo, counter);
        Control(X, U);
        // printf("3: %lf", U[1]);
        setMotorPWM(U, PWM);
        sprintf(outbuff, "%d,%d", PWM[0], PWM[1]);
        writeOutPipe(pip, outbuff, BUFFSIZE);

        if (counter > 2 / dt)
        {
            delet();
        }
        double queueInsert[3] = {counter, X[0], X[1]};
        insert(queueInsert);
        printf("X: %.2f, Y: %.2f, Heading: %.2f, Velocity: %.2f, Steering Angle: %.2f\n", X[0], X[1], X[2], U[0], U[1]);
        double testAngle = U[1] * 180 / M_PI;
        counter += 1; //(counter %10) == 0
        // wait(1);      // wait 0.1 seconds

        // xbar = Uncertainty(xbar, oldPos, counter);
        // ubar = Control(xbar);
        // [ U, PWMToSend ] = MotorModels(ubar);
        // X = Dynamics(U, X);
        // if (counter > 2 / dt)
        //     oldPos.remove(oldPos.peek());
        // end
        //     oldPos.insert([ counter, xbar(1), xbar(2) ]);
        // counter = counter + 1;
        // pause(dt / 100);
        // t = t + dt;
    }
}

void Initialize(double X[3], double U[2])
{
    X[0] = 9;  // 9.3
    X[1] = 11; // 11
    X[2] = deg2rad(-180);
    U[0] = 1.0;
    U[1] = 0.0;
}

void Encoder(double U[2], float encoderData)
{
    static int count1;
    static int count2;
    static float buffer;
    encoderData = -1; // for test
    while (count1 < 3 && count2 < 5)
    {
        if (0 < encoderData && encoderData < 500)
        {
            buffer += 46 / encoderData;
            count1 += 1;
        }
        count2 += 1;
    }
    if (count1 == 3)
    {
        if (0 < buffer && buffer < 10)
        {
            U[0] = buffer / 3;
        }
        count1 = 0;
        count2 = 0;
    }
    else
    {
        U[0] = U[0];
        count1 = 0;
        count2 = 0;
    }
}

void estimatePos(double X[3], double U[2])
{
    /* X = X_dot * dt + X */
    X[0] += U[0] * cos(X[2]) * dt;
    /* x velocity * dt + current x_location */
    X[1] += U[0] * sin(X[2]) * dt;
    /* y velocity * dt + current y_location */
    X[2] += U[0] * tan(U[1]) / 0.27 * dt;
    while (X[2] > 2 * M_PI)
    {
        X[2] -= 2 * M_PI;
    }

    while (X[2] < 0.0)
    {
        X[2] += 2 * M_PI;
    }
}

double deg2rad(double degs)
{
    double radian = degs * (M_PI / 180.0);
    return radian;
}

double checkHalfPlane(double X[3])
{
    double result = 0;
    // double x[2] = {xbar[1], xbar[2]};
    double P[] = {controlArray[controlIndex][7], controlArray[controlIndex][8]};
    double N[] = {controlArray[controlIndex][5], controlArray[controlIndex][6]};

    double vec1[2] = {X[0] - P[0], X[1] - P[1]};

    for (int i = 0; i < 2; i++)
        result += vec1[i] * N[i];
    return result;
    // H=sign(dot((x-P)', N));
}

// dynamics
void Dynamics(double U[2], double X[3])
{ // this function assigns values to velocity and draws the car according to // these values // math done in control and other functions global dt;
    double v = U[1];
    double thetaS = U[2];
    // x = X(1);
    // y = X(2);
    double theta = X[3];
    double xdot[3] = {v * cos(theta),
                      v * sin(theta),
                      v * tan(thetaS) / .27};

    X[1] = xdot[1] * dt + X[1];
    // velocity *dt + current x_location
    X[2] = xdot[2] * dt + X[2];
    // velocity *dt + current y_location
    X[3] = xdot[3] * dt + X[3];
}

void Control(double X[3], double U[2])
{

    double sign;
    int reset = 0;
    sign = checkHalfPlane(X);
    // controlIndex;
    // controlArray;

    if (sign > 0)
    {
        if (controlIndex == (sizeof(controlArray) / (sizeof(controlArray[0])) - 1))
        {
            controlIndex = 0;
        }
        else
        {
            controlIndex = controlIndex + 1;
        }
        reset = 1;
    }
    else
    {
        reset = 0;
    }

    if (controlArray[controlIndex][0] == 0)
    {
        controlCircle(X, U, reset);
    }
    else
    {
        controlLine(X, U);
    }
}

void controlLine(double X[3], double U[2])
{ // this function automates the motion of the car and corrects the movement // so that the course is adjusted to match expectations // U represents the changed state of the car as apposed to xbar which is the // sensed state

    static double oldDline;
    static double deriv;
    double alpha = 0;
    double determinant = 0;
    double inverse[3][3];
    double D = 0;

    // persistent lineToFollow;

    double W1[] = {controlArray[controlIndex][1], controlArray[controlIndex][2]};
    double W2[] = {controlArray[controlIndex][3], controlArray[controlIndex][4]};
    double xdiff = W2[0] - W1[0];
    double ydiff = W2[1] - W1[1];
    double alpha1 = atan2(ydiff, xdiff);

    // fix stuff after this
    //  rotation matrix
    double R[3][3] = {
        {cos(alpha1), -sin(alpha1), W1[0]},
        {sin(alpha1), cos(alpha1), W1[1]},
        {0, 0, 1}};

    for (int i = 0; i < 3; i++)
    {
        determinant = determinant + (R[0][i] * (R[1][(i + 1) % 3] * R[2][(i + 2) % 3] - R[1][(i + 2) % 3] * R[2][(i + 1) % 3]));
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            inverse[i][j] = ((R[(j + 1) % 3][(i + 1) % 3] * R[(j + 2) % 3][(i + 2) % 3]) - (R[(j + 1) % 3][(i + 2) % 3] * R[(j + 2) % 3][(i + 1) % 3])) / determinant;
        }
    }

    double xbar[3] = {X[0], X[1], 1};

    D = inverse[1][0] * xbar[0] + inverse[1][1] * xbar[1] + inverse[1][2] * xbar[2];

    double kp = -0.4;
    double kd = -0.5;
    deriv = (D - oldDline) / dt;

    U[1] = D * kp + kd * deriv;
    U[0] = v;
    oldDline = D;
}

void controlCircle(double X[3], double U[2], int reset)
{

    static double oldDcirc;
    static double integral;
    // static double integralPlot;
    static double error;
    static double deriv;
    static double thetaS;

    double C[2] = {controlArray[controlIndex][1], controlArray[controlIndex][2]};
    double Rcar1 = C[0] - X[0];
    double Rcar2 = C[1] - X[1];
    double Rcar = sqrt((Rcar1 * Rcar1 + Rcar2 * Rcar2));

    error = Rcar - controlArray[controlIndex][3];

    double kp = -0.4;
    double kd = -0.5;
    double ki = -0.01;

    if (controlArray[controlIndex][4] != 1)
    {
        kp = -kp;
        kd = -kd;
        ki = -ki;
    }

    if (reset == 1)
    {
        integral = 0;
        deriv = 0;
    }
    else
    {
        deriv = (error - oldDcirc) / dt;
    }

    U[1] = error * kp + integral * ki + kd * deriv;
    U[0] = v;
    oldDcirc = error;
    integral += error * dt;
}

void insert(double pozInput[3])
{

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->index = pozInput[0];
    temp->data1 = pozInput[1];
    temp->data2 = pozInput[2];
    temp->link = NULL;
    if (rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void delet()
{
    struct node *temp;
    temp = front;
    if (front == NULL)
    {
        // printf("Queue underflow\n");
        front = rear = NULL;
    }
    else
    {
        // printf("The deleted element from the queue is: %f\n", front->data1);
        front = front->link;
        free(temp);
    }
}

void setMotorPWM(double U[2], int PWM[2])
{ // MotorModels This function takes in duty cycle and outputs v, thetaS

    double steerCurve;
    // static double ubar_hold;
    // static double uncert[2] = {0, 0};

    int driveSpeedPWM = 0;
    int steerCurvePWM = 0;

    // double driveCurve = ubar[1];
    // double steerCurve = rad2deg(ubar[2]);
    steerCurve = 57.3 * U[1];

    while (steerCurve < -180 || steerCurve > 180)
    {
        wait(1);
        if (steerCurve < -180)
        {
            steerCurve = steerCurve + 360;
        }
        else if (steerCurve > 180)
        {
            steerCurve = steerCurve - 360;
        }
    }

    steerCurve = steerCurve + 90;

    for (int i = 1; i < sizeof(driveTable) / sizeof(driveTable[0]); i++)
    {
        if (abs(U[0] - driveTable[i][1]) < 0.3)
        {
            // set it to be less remember that
            driveSpeedPWM = driveTable[i - 1][0];
            U[0] = driveTable[i - 1][1];
            break;
        }
    }

    for (int i = 0; i < sizeof(steerTable) / sizeof(steerTable[0]); i++)
    {
        if (abs(steerCurve - steerTable[i][1]) < 7)
        {
            steerCurvePWM = steerTable[i][0];
            U[1] = (steerTable[i][1] - 90) / 57.3;
            break;
        }
    }

    if (steerCurve > 130.0)
    {
        steerCurvePWM = 88;
        U[1] = (steerTable[14][1] - 90) / 57.3;
    }
    else if (steerCurve < 45.0)
    {
        steerCurvePWM = 60;
        U[1] = (steerTable[0][1] - 90) / 57.3;
    }

    if (driveSpeedPWM == 0)
    {
        driveSpeedPWM = 78;
        U[0] = driveTable[0][1];
    }

    if (steerCurvePWM == 0)
    {
        steerCurvePWM = 74;
        U[1] = (steerTable[7][1] - 90) / 57.3;
    }
    // shift min angle to center around 0 end

    PWM[0] = driveSpeedPWM;
    PWM[1] = steerCurvePWM;
}

void updatePosPozyx(double X[3], double pozyxInput[2], int counter)
{
    double muPosTime = .7;
    double updatePos[2];
    if (size() > 1.9 / dt)
    {
        int index = muPosTime / dt;
        search(counter - index, X_old_predicted);
        updatePos[0] = pozyxInput[0] - X_old_predicted[0];
        updatePos[1] = pozyxInput[1] - X_old_predicted[1];
        X[0] += updatePos[0] / 100;
        X[1] += updatePos[1] / 100;
    }
}

void Uncertainty(int xbar[], int pozyxInput[], int counter)
{
    int updatePos[2] = {0, 0};
    double muPosTime = .7;
    if (size() > 1.9 / dt)
    {
        double index = muPosTime / dt;
        search(counter + index, X_old_predicted);

        updatePos[0] = pozyxInput[0] - X_old_predicted[0];
        updatePos[1] = pozyxInput[1] - X_old_predicted[1];

        xbar[0] = xbar[0] + updatePos[0] / 100;
        xbar[1] = xbar[1] + updatePos[1] / 100;
    }
}

void search(int index, double X_old_predicted[2])
{
    struct node *temp;
    temp = front;
    int cnt = 0;

    while (temp)
    {
        if (temp->index == index)
        {
            X_old_predicted[0] = temp->data1;
            X_old_predicted[1] = temp->data2;
        }
        temp = temp->link;
    }
}

int size()
{
    struct node *temp;
    temp = front;
    int cnt = 0;

    while (temp)
    {
        // printf("%d\n", temp->data);
        temp = temp->link;
        cnt++;
    }
    return cnt;
}
// printf("%d\n", cnt)

/* Time Delay method*/
void wait(int seconds)
{ // this function needs to be finetuned for the specific microprocessor
    int i, j, k;
    for (i = 0; i < seconds; i++)
    {
        for (j = 0; j < wait_loop0; j++)
        {
            for (k = 0; k < wait_loop1; k++)
            { // waste function, volatile makes sure it is not being optimized out by compiler
                int volatile t = 120 * j * i + k;
                t = t + 5;
            }
        }
    }
}
