/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: AutoCodeControl.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 23-Oct-2022 10:56:16
 */

/* Include Files */
#include "AutoCodeControl.h"
#include "coder_posix_time.h"
#include <math.h>


/* Variable Definitions */
int controlIndex = 1;
double controlArray[17][9];

controlArray =   {
              {1, 1, 9, 1, 2, 0, -1, 1, 2}, 
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
              {0, 2, 9, 1, 1, 0, -1, 1, 9}
};

double driveTable[4][2];
double steerTable[15][2];

driveTable = {
            {78, 0.92}, 
            {80, 1.56}, 
            {82, 2.19},
            {84, 2.61}
}; //% sample data pwm, speed;

steerTable = {
          {60, 45},
          {62, 45},
          {64, 55}, 
          {66, 60},
          {68, 70},
          {70, 75},
          {72, 80},
          {74, 90},
          {76, 95}, 
          {78, 105}, 
          {80, 110}, 
          {82, 115},
          {84, 120},
          {86, 125},
          {88, 130}
}; // % sample data pwm, angle

double dt = 0.1;
double velocity = 1;
int counter = 0;
double pozyxInput[2];
double X[3];
double U[2];
int resetIntegral[1];
double PWM[2];
double oldD_circ = 0;
double oldD_line = 0;
double integralFactor = 0;


// Some queue stuff...
struct node
{
    double index;
double data1;
double data2;
struct node *link;
} *front, *rear;

double X_old_predicted[2];

void insert(); // Function used to insert the element into the queue
void delet(); // Function used to delete the elememt from the queue
void serch(int index, double out[2]); // Function used to display all the elements in the queue according to FIFO rule
int size();


double x[2];
double out[2] = {0, 0};
int sizeMeUpButterCup;

/* Function Definitions */
void AutoCodeInitialize(double X[3], double U[2]);
void AutoCodeEstimatePos(double X[3], double U[2]);
double AutoCodeCheckHalfPlane(double X[3]);
void AutoCodeControl(double X[3], double U[2]);
void AutoCodeControlCircle(double X[3], int resetIntegral[1]);
void AutoCodeControlLine(double X[3]);
void AutoCodeSetMotorPWM(double U[2], double PWM[2]);
void AutoCodeUpdatePosPozyx(double X[3], double pozyxInput[2], int counter);
/*
 * UNTITLED6 Summary of this function goes here
 *    Detailed explanation goes here
 *
 * Arguments    : const double X[3]
 *                double U[2]
 * Return Type  : void
 */

void AutoCodeTopLevel(void)
{
  //coderTimespec b_timespec;
  double X[3];
  double X_dot[3];
  double U[2];
  double unusedExpr[2];
  double Rcar;
  double samplePozyxInput[2] = {0, 0};

  AutoCodeInitialize(X, U);
  /* global */
  /*      oldPos = PriorityQueue(1); */
  //b_timespec.tv_sec = 0.0;
  //b_timespec.tv_nsec = 1.0E+8;
  while (1) {
    /* while 1 */
    /* UNTITLED4 Summary of this function goes here */
    /*    Detailed explanation goes here */
    /* global */
    /* X = X_dot * dt + X */
    AutoCodeEstimatePos(X, U);
    AutoCodeUpdatePosPozyx(X, samplePozyxInput, counter);
    AutoCodeControl(X, U);
    AutoCodeSetMotorPWM(U, PWM);

    if (counter > 2/dt)
    {
      delet();
    }
    double queueInsert[3] = {counter, X[0], X[1]};
    insert(queueInsert);
    counter += 1;

  }
}

void AutoCodeInitialize(double X[3], double U[2])
{
  X[0] = 1.1;
  X[1] = 8.0;
  X[2] = -1.5707963267948966;
  /*  sample data pwm, speed; */
  /*  sample data pwm, angle */
  /* set the initial angle of the car */
  /* x, y, thetaC */
  U[0] = 1.0;
  U[1] = 0.0;
  /* , vel, thetaS */
}


void AutoCodeEstimatePos(double X[3], double U[2])
{
  /* global */
  /* X = X_dot * dt + X */
  X[0] += U[0] * cos(X[2]) * 0.1;
  /* x velocity * dt + current x_location */
  X[1] += U[0] * sin(X[2]) * 0.1;
  /* y velocity * dt + current y_location */
  X[2] += U[0] * tan(U[1]) / 0.27 * 0.1;
  /* d_thetaC * dt + current thetaC */
}

double AutoCodeCheckHalfPlane(double X[3])
{
  double x[2];
  x[0] = X[0];
  x[1] = X[1];
  double result = 0.0;


  double P[2] = {controlArray[controlIndex][7], controlArray[controlIndex][8]};
  double N[2] = {controlArray[controlIndex][5], controlArray[controlIndex][6]};

  double vec1[1][2] = {
                      {x[0] - P[0]},
                      {x[1] - P[1]}
                      };

  for (int i = 0; i < 2; i++)
      result += vec1[1][i]*N[i];
  return result;
}

void AutoCodeControl(double X[3], double U[2])
{
  double sign;

  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*
  absxk = (X[0] - 1.0) * 0.0 + -(X[1] - 2.0);
  if (absxk < 0.0) {
    absxk = -1.0;
  } else if (absxk > 0.0) {
    absxk = 1.0;
  } else if (absxk == 0.0) {
    absxk = 0.0;
  }
  if (absxk > 0.0) {
    controlIndex = 1;
    resetIntegral = 1;
  } else {
    resetIntegral = 0;
  }
  */

  sign = AutoCodeCheckHalfPlane(X);

  if (sign > 0){
    if (controlIndex == sizeof(controlArray) / sizeof(controlArray[0]) - 1)
    {
      controlIndex = 0;
    }else
      {
        controlIndex += 1;
      }
      resetIntegral[1] = 1;
  }
  else
  {
    resetIntegral[1] = 0;
  }

  if (controlArray[controlIndex][1] == 0) 
  {
    AutoCodeControlCircle(X, resetIntegral);
  } else {
    AutoCodeControlLine(X);
  }
}

void AutoCodeControlCircle(double X[3], int resetIntegral[1])
{
  double D[3];
  double absxk;
  double scale;
  double norm;
  double error;
  double deriv;

  double center[1][2] = {
                        {controlArray[controlIndex][1]},
                        {controlArray[controlIndex][2]}
                        };
  double Rcar_1 = center[0][0] - X[0];
  double Rcar_2 = center[0][1] - X[1];

  double Rcar = sqrt((Rcar_1*Rcar_1+Rcar_2*Rcar_2)/(Rcar_1+Rcar_2));

  error = Rcar - controlArray[controlIndex][3]; // Rcar - Rcirc

  double kp = -0.4;
  double kd = -0.5;
  double ki = 0.00035;

  if(controlArray[controlIndex][4] != 0) // Lambda CW = 0, CCW = 1
  {
    kp = -kp;
    kd = -kd;
    ki = -ki;
  }

  if(resetIntegral[1] == 1)
  {
    integralFactor = 0;
    deriv = 0;
  }else
  {
    deriv = (error - oldD_circ)/dt;
  }

  U[1] = error*kp + integralFactor*ki + kd*deriv;
  U[0] = velocity;
  oldD_circ = error;
  integralFactor += error*dt;

}

void AutoCodeControlLine(double X[3])
{
  double angle;
  double determinant = 0;
  double inverse[3][3];
  double D[1][3];

  angle = atan((controlArray[controlIndex][4] - controlArray[controlIndex][2])/
                controlArray[controlIndex][3] - controlArray[controlIndex][1]);
  double R[3][3] = {
                    {cos(angle), -sin(angle), controlArray[controlIndex][1]},
                    {sin(angle), cos(angle), controlArray[controlIndex][2]},
                    {0,           0,          1                 }
                    };
  for(int i=0;i<3;i++)
  {
    determinant = determinant + (R[0][i]*(R[1][(i+1)%3]*R[2][(i+2)%3] - R[1][(i+2)%3]*R[2][(i+1)%3]));
  }

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
    {
      inverse[i][j] = ((R[(j+1)%3][(i+1)%3] * R[(j+2)%3][(i+2)%3]) - (R[(j+1)%3][(i+2)%3]*R[(j+2)%3][(i+1)%3]))/ determinant;
    }
  }

  double X_bar[1][3] = {{X[0], X[1], {1}}};

  for(int i = 0;i<3;i++){
    for(int j = 0;j<3;j++){
      D[0][i] += inverse[i][j] * X_bar[1][j];
    }
  }

  double kp = -0.4;
  double kd = -0.5;
  double deriv = (D[0][1] - oldD_line)/dt;

  U[1] = D[0][1]*kp + kd * deriv;
  U[0] = velocity;
  oldD_line = D[0][1];

}

void AutoCodeSetMotorPWM(double U[2], double PWM[2])
{
  double steerAngle;
  int steerAnglePWM;
  int driveSpeedPWM;
  double PWM[2];
  /*  sample data pwm, speed; */
  /*  sample data pwm, angle */
  steerAnglePWM = 0;
  driveSpeedPWM = 0;
  steerAngle = 57.295779513082323 * U[1];
  while ((steerAngle < -180.0) || (steerAngle > 180.0)) {
    if (steerAngle < -180.0) {
      steerAngle += 360.0;
    } else if (steerAngle > 180.0) {
      steerAngle -= 360.0;
    }
  }
  steerAngle += 90.0;

  // Scan drive curve
  for(int i = 0; i < sizeof(driveTable) / sizeof(driveTable[0]); i++)
  {
    if(driveSpeedPWM == 0 && U[0] - 0.3 < driveTable[i][1] && U[0] + 0.3 > driveTable[i][1])
    {
      driveSpeedPWM = driveTable[i][0];
      U[0] = driveTable[i][1];
    }
  }

  // Scan steer curve
  for(int i = 0; i < sizeof(steerTable) / sizeof(steerTable[0]); i++)
  {
    if(steerAnglePWM == 0 && steerAngle - 7 < steerTable[i][1] && steerAngle + 7 > steerTable[i][1])
    {
      steerAnglePWM = steerTable[i][0];
      U[1] = steerTable[i][1];
    }
  }

  if (steerAngle > 130.0) {
    steerAnglePWM = 88;
    U[1] = steerTable[14][1];
  } else if (steerAngle < 45.0) {
    steerAnglePWM = 60;
    U[1] = steerTable[0][1];
  }

  if (driveSpeedPWM == 0)
  {
    driveSpeedPWM = 78;
    U[0] = driveTable[0][1];
  }

  if (steerAnglePWM == 0)
  {
    steerAnglePWM = 74;
    U[1] = steerTable[7][1];
  }

  PWM[0] = driveSpeedPWM;
  PWM[1] = steerAnglePWM;
}

void AutoCodeUpdatePosPozyx(double X[3], double pozyxInput[2], int counter;)
{
  double muPosTime = 0.7; 
  double updatePos[2];
  if (size() > 1.9 / dt)
  {
    int index = (int)muPosTime/dt;
    serch(counter-index, X_old_predicted);
    updatePos[0] = pozyxInput[0] - X_old_predicted[0];
    updatePos[1] = pozyxInput[1] - X_old_predicted[1];
    X[0] += updatePos[0]/10;
    X[1] += updatePos[1]/10;
  }
}


// Some queue stuff...
void insert(double pozInput[3])
{

struct node *temp;
temp = (struct node*)malloc(sizeof(struct node));

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
        //printf("Queue underflow\n");
        front = rear = NULL;
        }
        else
        {
        //printf("The deleted element from the queue is: %f\n", front->data1);
        front = front->link;
        free(temp);
        }
        }
        
        
void serch(int index, double X_old_predicted[2])
{
struct node *temp;
temp = front;
int cnt = 0;

while (temp){
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
    //printf("%d\n", temp->data);
    temp = temp->link;
    cnt++;
    }
    //printf("%d\n", cnt);
    return cnt;
}


/*
 * File trailer for AutoCodeControl.c
 *
 * [EOF]
 */



