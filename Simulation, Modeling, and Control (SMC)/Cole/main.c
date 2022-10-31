//Cole Williams
//C code for SMC Team
//Results: Car can do the first linear movement. Once moving to the first circle, it errors out, as the checkHalfPlane
//      result diverges. The heading value also approaches 6 then resets back to 0 after an unknown amount of iterations.

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFFSIZE 512

double pi = 3.141;
double checkHalfPlaneResult;
//int resetIntegral;
int Index = 0;
int cool = 1;
int counter =0;
//double carLocation[] = {1.5, 9};
double thetaC = (270 * 3.1415 / 180);
double initializeX[] = {1.5, 9, (270 * 3.141 / 180)};
double dt = 0.01;
double velocity = 2;
double thetaDot;
double muPosTime = 0.7;
double sigmaDrive = 0.2;
double sigmaPosition = 0.2;
double sigmaPosTime = 0.1;
double sigmaSteering = 0.0873;
double theta;
double deltaX;
double deltaY;
double angle;
double xCircle;
double yCircle;
double thetaC;
double lambda;
double Rcirc;
double Rcar;
double error;
double driveCurve =  0;
double steerCurve = 0;
double X[3] = {1.5, 9, 4.7124};
double U[2] ={2, 0};
double X_dot[3] = {0, 0, 0};
double determinant = 0;
double LineKP = -0.4;
double LineKD = -0.5;
double CircleKP;
double CircleKD;
double CircleKI;
double PWM[2];
double XBar[3] = {1.5, 9, 4.7124};
double U_bar[2];
double x[2];
double P[2];
double N[2];
double A[2];
double B[2];
double D[3];
double c[2];
double inverse[3][3];
double pozyxInput[];
double X_old_predicted[2];
int wait_loop0 = 1000;
int wait_loop1 = 6000;

double Array[13][9] = {
        {1, 1, 9, 1, 3, 0, -1, 1, 3},
        {0, 3, 3, 2, 1, 1, 0, 3, 1},
        {1, 3, 1, 6, 1, 1, 0, 6, 1},
        {1, 6, 1, 9, 1, 1, 0, 9, 1},
        {0, 9, 3, 2, 1, 0, 1, 11, 3},
        {1, 11, 3, 11, 5, 0, 1, 11, 5},
        {0, 9.5, 5, 1.5, 1, 0, -1, 8, 5},
        {1, 8, 4, 5, 4, -1, 0, 5, 4},
        {0, 5, 6, 2, 0, 0, 1, 5, 7.9},
        {1, 5, 8, 9, 8, 1, 0, 9, 8},
        {0, 9, 9.5, 1.5, 1, -1, 0, 9, 11},
        {1, 9, 11, 2, 11, -1, 0, 2, 11},
        {0, 2, 10, 1, 1, 0, -1, 1, 10}
};

double driveTable[4][2] = {{77, 0.9}, {78, 1.1}, {79, 1.5}, {80, 1.9}};
double steerTable[15][2] = {{60, 45}, {62, 45}, {64, 55}, {66, 60}, {68, 70}, {70, 75}, {72, 80}, {74, 90}, {76, 95},
                            {78, 105}, {80, 110}, {82, 115},{84, 120}, {86, 125}, {88, 130}};

void Initialize(double X[3], double U[2]);
void Dynamics(double X[3], double U[2]);
double checkHalfPlane(double X[3]);
void Control(double X[3], double U[2]);
void controlCircle(double X[3], double U[2], int resetIntegral);
void controlLine(double X[3], double U[2]);
void setMotorPWM(double U[2], double PWM[2]);
void updatePosPozyx(double X[3], double pozyxInput[2], int counter);
void Encoder(double U[2], float encoderData);
void TopLevel(void);
void insert();
void search(int index, double out[2]);
void delete();
int size();
void wait(int seconds);

struct node
{
    double index;
    double data1;
    double data2;
    struct node *link;
} *front, *rear;

void main() {
    TopLevel();
}

void TopLevel(void){
    float encoderData;
    //struct Pipes pip;
    //pip = openPipes();
    double heading;
    double posx;
    double posy;
    char buf[BUFFSIZE] = {0};
    char outbuf[BUFFSIZE] = {0};
    Initialize(X, U);

    while (cool == 1) {
        //readInPipe(pip, buf, BUFFSIZE);
        //if(buf[0] != 0x0)
        {
            sscanf(strtok(buf, ","), "%lf", &posx);
            printf("%.4lf\n", posx);
            sscanf(strtok(NULL, ","), "%lf", &posy);
            printf("%.4lf\n", posy);
            sscanf(strtok(NULL, ","), "%lf", &heading);
            printf("%.4lf\n", heading);
        }
        double pozyxInfo[2] = {posx, posy};

        Encoder(U, encoderData);
        Dynamics(X, U);
        updatePosPozyx(X, pozyxInfo, counter);
        Control(X, U);
        setMotorPWM(U, PWM);
        sprintf(outbuf, "%d,%d",PWM[0],PWM[1]);
        //writeOutPipe(pip, outbuf, BUFFSIZE);

        if (counter > 2/dt){
            delete();
        }
        double queueInsert[3] = {counter, X[0], X[1]};
        insert(queueInsert);
        printf("X: %.2f, Y: %.2f, Heading: %.2f, Velocity: %.2f, Steering Angle: %.2f,  Index: %d\n", X[0], X[1], X[2], U[0], U[1], Index);
        double testAngle = U[1] * 180 / M_PI;
        counter += 1; //(counter %10) == 0
        wait(1); // wait 0.1 seconds
    }
}

void Initialize(double X[3], double U[2]){
    X[0] = 1.1;
    X[1] = 8.0;
    X[2] = -pi/2;
    U[0] = 1.0;
    U[1] = 0.0;
    //printf("START OF INITIALIZE() \n");
    //printf("U[0] = %f \n", U[0]);
    //printf("U[1] = %f \n", U[1]);
    //printf("X[0] = %f \n", x[0]);
    //printf("X[1] = %f \n", X[1]);
    //printf("XBar[0] = %f \n", XBar[0]);
    //printf("XBar[1] = %f \n", XBar[1]);
    //printf("thetaC = %f \n", thetaC);
    //printf("END OF INITIALIZE \n");
}

void updatePosPozyx(double X[3], double pozyxInput[2], int counter){
        double muPosTime = .07;
        double updatePos[2];
        if (size() > 1.9 / dt){
            int index = muPosTime/dt;
            search(counter-index, X_old_predicted);
            updatePos[0] = pozyxInput[0] - X_old_predicted[0];
            updatePos[1] = pozyxInput[1] - X_old_predicted[1];
            X[0] += updatePos[0]/100;
            X[1] += updatePos[1]/100;
        }
    }

void setMotorPWM(double U[2], double PWM[2]) {
    double steerAngle;
    int steerAnglePWM = 0;
    int driveSpeedPWM = 0;
    steerAngle = (180 / pi ) * U[1];

    while ((steerAngle < -180) || (steerAngle > 180)) {
        if (steerAngle < -180) {
            steerAngle += 360;
        } else if (steerAngle > 180) {
            steerAngle -= 360;
        }
    }

    steerAngle += 90.0;
    for(int i = 0; i < sizeof(driveTable) / sizeof(driveTable[0]); i++){
        if(abs(U[0] - driveTable[i][1]) < 0.3) //U[0] - 0.3 < driveTable[i][1] && U[0] + 0.3 > driveTable[i][1])
        {
            driveSpeedPWM = driveTable[i][0];
            U[0] = driveTable[i][1];
            break;
        }
    }

    // Scan steer curve
    for(int i = 0; i < sizeof(steerTable) / sizeof(steerTable[0]); i++)
    {
        if(abs(steerAngle - steerTable[i][1] ) < 7 )//steerAngle - 7 < steerTable[i][1] && steerAngle + 7 > steerTable[i][1])
        {
            steerAnglePWM = steerTable[i][0];
            U[1] = (steerTable[i][1] - 90) / 57.295779513082323;
            break;
        }
    }

    if (steerAngle > 130.0) {
        steerAnglePWM = 88;
        U[1] = (steerTable[14][1] - 90) / 57.295779513082323;
    } else if (steerAngle < 45.0) {
        steerAnglePWM = 60;
        U[1] = (steerTable[0][1] - 90) / 57.295779513082323;
    }

    if (driveSpeedPWM == 0)
    {
        driveSpeedPWM = 78;
        U[0] = driveTable[0][1];
    }

    if (steerAnglePWM == 0)
    {
        steerAnglePWM = 74;
        U[1] = (steerTable[7][1] - 90) / 57.295779513082323;
    }

    PWM[0] = driveSpeedPWM;
    PWM[1] = steerAnglePWM;
}

void Dynamics(double X[3], double U[2]){
    X[0] += U[0] * cos(X[2]) * dt;
    X[1] += U[0] * sin(X[2]) * dt;
    X[2] += U[0] * tan(U[1]) / 0.27 * dt;

    while(X[2] > 2 * M_PI){
        X[2] -= 2 * M_PI;
    }

    while(X[2] < 0.0){
        X[2] += 2 * M_PI;
    }
}

void Control(double X[3], double U[2]) {
    double halfPlane = 0;
    int resetIntegral = 0;
    halfPlane = checkHalfPlane(X);
    if (halfPlane > 0){
        if (Index == (sizeof(Array) / (sizeof(Array[0])) - 1)){
            Index = 0;
        }else{
            Index = Index + 1;
        }
        resetIntegral = 1;
    }else{
        resetIntegral = 0;
    }

    if (Array[Index][0] == 0){
        controlCircle(X, U, resetIntegral);
    } else {
        controlLine(X, U);
    }
}

double checkHalfPlane(double X[3]) {
    double P[2] = {Array[Index][7], Array[Index][8]};
    double N[2] = {Array[Index][5], Array[Index][6]};
    double vec1[2] = {X[0] - P[0], X[1] - P[1]};
    for (int i = 0; i < 2; i++)
        checkHalfPlaneResult += vec1[i]*N[i];
    printf("CHPR = %f", checkHalfPlaneResult);
    return checkHalfPlaneResult;
}

void controlCircle(double X[3], double U[2], int resetIntegral) {
    printf("\nStart of Control Circle \n");
    printf("\nIndex = %d\n", Index);
    static double oldD_circ;
    static double integralFactor;
    double error;
    double derivCircle;
    double center[2] = {Array[Index][1], Array[Index][2]};
    double Rcar_1 = center[0] - X[0];
    double Rcar_2 = center[1] - X[1];
    double Rcar = sqrt((Rcar_1*Rcar_1+Rcar_2*Rcar_2));
    error = Rcar - Array[Index][3];

    double circleKP = -0.4;
    double circleKD = -0.5;
    double circleKI = -0.01;
    if(Array[Index][4] != 0)
    {
        circleKP = -circleKP;
        circleKD = -circleKD;
        circleKI = -circleKI;
    }

    if(resetIntegral == 1)
    {
        integralFactor = 0;
        derivCircle = 0;
    }else{
        derivCircle = (error - oldD_circ)/dt;
    }

    U[1] = (error * circleKP) + (integralFactor * circleKI) + (derivCircle * circleKD);
    U[0] = velocity;
    oldD_circ = error;
    integralFactor += error*dt;
}

void controlLine(double X[3], double U[2]) {
    //printf("\nSTART OF CONTROLLINE\n");
    static double oldD;
    static double derivLine;
    A[0] = Array[Index][1];
    A[1] = Array[Index][2];
    B[0] = Array[Index][3];
    B[1] = Array[Index][4];
    //printf("A0 = %f\n", A[0]);
    //printf("A1 = %f\n", A[1]);
    //printf("B0 = %f\n", B[0]);
    //printf("B1 = %f\n", B[1]);
    deltaX = B[0] - A[0];
    deltaY = B[1] - A[1];
    //printf("deltaX = %f\n", deltaX);
    //printf("deltaY = %f\n", deltaY);

    angle = atan2(deltaY, deltaX);
    //printf("angle = %f\n", angle);
    double R[3][3] = {
            {cos(angle), -sin(angle), A[0]},
            {sin(angle), cos(angle),  B[1]},
            {0,          0,           1}
    };
    //printf("R = \n%f %f %f \n%f %f %f\n %f %f %f\n", R[0][0], R[0][1], R[0][2], R[1][0], R[1][1], R[1][2], R[2][0], R[2][1], R[2][2]);

    for (int i = 0; i < 3; i++) {
        determinant = determinant +
                      (R[0][i] * (R[1][(i + 1) % 3] * R[2][(i + 2) % 3] - R[1][(i + 2) % 3] * R[2][(i + 1) % 3]));
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            inverse[i][j] = ((R[(j + 1) % 3][(i + 1) % 3] * R[(j + 2) % 3][(i + 2) % 3]) -
                             (R[(j + 1) % 3][(i + 2) % 3] * R[(j + 2) % 3][(i + 1) % 3])) / determinant;
        }
    }

    double XBar[3] = {X[0], X[1], 1};
    double  d = inverse[1][0] * XBar[0] + inverse[1][1] * XBar[1] + inverse[1][2] * XBar[2];
    //printf("d = %f\n", d);
    //printf("oldD = %f\n", oldD);
    //printf("D1 = %f\n", D[0]);
    //printf("D2 = %f\n", D[1]);
    //printf("D3 = %f\n", D[2]);
    derivLine = (d - oldD) / dt;

    thetaDot = (d * LineKP) + (derivLine * LineKD);
    //printf("Deriv = %f\n", deriv);
    //printf("thetaDot = %f\n", thetaDot);

    U[0] = velocity;
    U[1] = thetaDot;
    oldD = d;
    printf("CONTROL:  U = [%f, %f]\n", U[0], U[1]);
    //printf("deriv = %f\n", deriv);
    //printf("oldD = %f\n \n", oldD);
}

int size(){
    struct node *temp;
    temp = front;
    int cnt = 0;
    while (temp){
        temp = temp->link;
        cnt++;
    }
    return cnt;
}

void search(int index, double out[2]){
    struct node *temp;
    temp = front;
    int cnt = 0;
    while (temp){
        if (temp->index == index){
            X_old_predicted[0] = temp->data1;
            X_old_predicted[1] = temp->data2;
        }
        temp = temp->link;
    }
}

void delete(){
    struct node *temp;
    temp = front;
    if (front == NULL){
        front = rear = NULL;
    }else{
        front = front->link;
        free(temp);
    }
}

void insert(double pozInput[3]){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->index = pozInput[0];
    temp->data1 = pozInput[1];
    temp->data2 = pozInput[2];
    temp->link = NULL;
    if (rear == NULL){
        front = rear = temp;
    }else{
        rear->link = temp;
        rear = temp;
    }
}

void Encoder(double U[2], float encoderData){
    static int counter1;
    static int counter2;
    static float buffer;
    encoderData = -1; // for testing
    while(counter1 < 3 && counter2 < 5){
        if (0 < encoderData && encoderData < 500){
            buffer += 46.019423 / encoderData;
            counter1 += 1;
        }
        counter2 += 1;
    }

    if (counter1 == 3){
        if (0 < buffer && buffer < 10){
            U[0] = buffer/3;
        }
        counter1 = 0;
        counter2 = 0;
    }else{
        U[0] = U[0];
        counter1 = 0;
        counter2 = 0;
    }
}

void wait( int seconds ){
    int i, j, k;
    for(i = 0; i < seconds; i++){
        for(j = 0; j < wait_loop0; j++){
            for(k = 0; k < wait_loop1; k++){
                int volatile t = 120 * j * i + k;
                t = t + 5;
            }
        }
    }
}