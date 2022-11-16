//usr/bin/cc "$0" "comms.c" -lm && exec ./a.out "$@"
#include <math.h>
#include "comms.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFFSIZE 512
/* Variable Definitions */
int controlIndex = 0;
// double controlArray[17][9] = {
//   {1, 1, 9, 1, 2, 0, -1, 1, 2},
//   {0, 2.1, 2.1, 1, 1, 1, 0, 2, 1},
//   {1, 2, 1, 6, 2, 1, 0, 6, 2},
//   {1, 6, 2, 10, 1.5, 1, 0, 9.8, 1.5},
//   {0, 9.9, 2.6, 1, 1, 0, 1, 10.8, 2.5},
//   {1, 11, 2.5, 11, 5, 0, 1, 11, 5},
//   {0, 10, 4.9, 1, 1, 0, -1, 9, 5},
//   {0, 7.9, 5.1, 1, 0, -1, 0, 8, 4},
//   {1, 8, 4, 4, 4.5, -1, 0, 4.2, 4.5},
//   {0, 4.1, 5.6, 1, 0, 0, 1, 3, 5.3},
//   {1, 3, 5.5, 3, 8, 0, 1, 3, 7.6},
//   {0, 4.1, 7.9, 1, 0, 1, 0, 3.8, 9},
//   {1, 4, 9, 10, 9, 1, 0, 10.1, 9},
//   {0, 10, 10.5, 1.5, 1, -1, 0, 10, 12},
//   {1, 10, 12, 6, 10, -1, 0, 6, 10},
//   {1, 6, 10, 2, 10, -1, 0, 2, 10},
//   {0, 2, 9, 1, 1, 0, -1, 1, 9}
// };
// //line
// double controlArray[1][9] = {
//   {1, 10.927, 9.55, 5.366, 9.464, -1, 0, -100, 0}};
// //circle
// double controlArray[1][9] = {
//   {0, 9.415, 9.592, 0.5, 1, 0, 1, 0, 100}};
//minitrack
double controlArray[4][9] = {
  {1, 9.352, 11.069, 6.823, 11.054, -1, 0, 6.7, 11.054}, 
  {0, 6.857, 9.552, 0.5, 1, 1, 0, 6.9, 8.037}, 
  {1, 6.959, 8.037, 9.446, 8.058, 1, 0, 9.4, 8.058},
  {0, 9.415, 9.592, 0.5, 1, -1, 0, 9.2, 11.069}
};



double driveTable[4][2] = {{78, .92}, {80, 1.56}, {82, 2.19}, {84, 2.61}}; 
double steerTable[15][2] = {
  {54, 45}, {56, 45}, {58, 55},  {60, 60},
  {62, 70}, {64, 75}, {66, 80}, {68, 85},
  {70, 90}, {72, 95},  {74, 105},  {76, 110}, 
  {80, 115}, {82, 120}, {84, 125}, {86, 130}
};
double dt = .05;
double v = 1;
int counter = 0;
//wait 
int wait_loop0 = 10000/10;
int wait_loop1 = 6000;

// for microprocessor without timer, if it has a timer refer to vendor documentation and use it instead.
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
//end wait
double pozyxInput[2];
double X_old_predicted[2];

/* Queue */
struct node
{
double index;
double data1;
double data2;
struct node *link;
}*front, *rear;

double X_old_predicted[2];
void insert(); // Function used to insert the element into the queue
void delet(); // Function used to delete the elememt from the queue
void serch(int index, double X_old_predicted[2]); // Function used to display all the elements in the queue according to FIFO rule
int size();

double out[2] = {0, 0};

void insert(double pozInput[3])
{
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
        front = rear = NULL;
        }
        else
        {
        front = front->link;
        free(temp);
        }
}
        
        
void serch(int index, double X_old_predicted[2])
{
struct node *temp;
temp = front;
while (temp)
{
    if (temp->index == index){
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
temp = temp->link;
cnt++;
}
return cnt;
}
/* End Queue */

/* Function Declarations */
void AutoCodeTopLevel(void);
void AutoCodeInitialize(double X[3], double U[2]);
void AutoCodeEstimatePos(double X[3], double U[2]);
double AutoCodeCheckHalfPlane(double X[3]);
void AutoCodeControl(double X[3], double U[2]);
void AutoCodeControlCircle(double X[3], double U[2], int resetIntegral);
void AutoCodeControlLine(double X[3], double U[2]);
void AutoCodeUpdatePosPozyx(double X[3], double pozyxInput[2], int counter);
void AutoCodeSetMotorPWM(double U[2], int PWM[2]);
void AutoCodeEncoder(double U[2], float encoderData);

void main(){
  AutoCodeTopLevel();
}
/* Function Definitions */
void AutoCodeTopLevel(void)
{
  double X[3];
  double U[2];
  int PWM[2];
  double samplePozyxInput[2] = {X[0] + .4,X[1] + .1};
  float encoderData;
  //comms
  double heading;
	double posx;
	double posy;
  struct Pipes pip;
	pip = openPipes();
	char buf[BUFFSIZE] = {0};
	char outbuf[BUFFSIZE] = {0};
  AutoCodeInitialize(X, U);

  while(1){
    printf("X: %.2f, Y: %.2f, Heading: %.2f, Velocity: %.2f, Steering angle: %.2f\n",X[0],X[1],X[2],U[0],U[1]);
    //AutoCodeEncoder(encoderData, U);
    readInPipe(pip, buf, BUFFSIZE);
    if (buf[0] != 0x0){
    sscanf(strtok(buf, ","), "%lf", &posx);
		printf("%.4lf\n", posx);
		sscanf(strtok(NULL, ","), "%lf", &posy);
		printf("%.4lf\n", posy);
		sscanf(strtok(NULL, ","), "%lf", &heading);
		printf("%.4lf\n", heading);

		}
    double pozyxInfo[2] = {posx, posy};

    AutoCodeEstimatePos(X, U);
    //AutoCodeUpdatePosPozyx(X, samplePozyxInput, counter);
    AutoCodeControl(X, U);
    
    AutoCodeSetMotorPWM(U, PWM);
    sprintf(outbuf, "%d,%d", PWM[0], PWM[1]);
    writeOutPipe(pip, outbuf, BUFFSIZE);
    
    if(counter > 2/dt){
      delet();
    }
    double queueInsert[3] = {counter, X[0],X[1]};
    insert(queueInsert);
    counter +=1; 
    //wait(1);
  }
}

void AutoCodeInitialize(double X[3], double U[2])
{
  X[0] = 9.3;  //line: 10.9, circle: 9.3
  X[1] = 11;  //line: 8.5, circle: 11
  X[2] = M_PI;
  U[0] = 1.0;
  U[1] = 0.0;
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
  else{
    U[0] = U[0];
    counter1 = 0;
    counter2 = 0;  
  }
  
}
void AutoCodeEstimatePos(double X[3], double U[2])
{
  /* X = X_dot * dt + X */
  X[0] += U[0] * cos(X[2]) * dt;
  /* velocity * dt + current x_location */
  X[1] += U[0] * sin(X[2]) * dt;
  /* velocity * dt + current y_location */
  X[2] += U[0] * tan(U[1]) / 0.27 * dt;
  while(X[2] > 2*M_PI){
    X[2] -= 2* M_PI;
  }
  while(X[2] < 0.0){
    X[2] += 2* M_PI;
  }
}
void AutoCodeUpdatePosPozyx(double X[3], double pozyxInput[2], int counter){
  double muPosTime = .07;
  double updatePos[2];
  if (size() > 1.9 / dt){
    int index = -muPosTime/dt;
    serch(counter-index, X_old_predicted);
    updatePos[0] = pozyxInput[0] - X_old_predicted[0];
    updatePos[1] = pozyxInput[1] - X_old_predicted[1];
    X[0] += updatePos[0]/100;
    X[1] += updatePos[1]/100;

  }
}
double AutoCodeCheckHalfPlane(double X[3])
{
  double H = 0.0;
  double P[2] = {controlArray[controlIndex][7],controlArray[controlIndex][8]};
  double N[2] = {controlArray[controlIndex][5],controlArray[controlIndex][6]};
  double v1[2] = {X[0] - P[0], X[1] - P[1]};
  for (int i = 0; i < 2; i++)
        H += v1[i]*N[i];

  return H;
}
void AutoCodeControl(double X[3], double U[2])
{
  int resetIntegral = 0;
  
    if (AutoCodeCheckHalfPlane(X) > 0.0) {
      if(controlIndex == (sizeof(controlArray) / sizeof(controlArray[0])-1)){
        controlIndex = 0;
      }
      else{
        controlIndex += 1;
      }
      resetIntegral = 1;
    } 
    else {
      resetIntegral = 0;
    }

    if (controlArray[controlIndex][0] == 0) {
      AutoCodeControlCircle(X, U, resetIntegral);
    } else {
      AutoCodeControlLine(X, U);
    }
}
void AutoCodeControlCircle(double X[3], double U[2], int resetIntegral)
{
  static double oldD_circle;
  static double integral;
  double deriv;
  double error;
  double center[2] = {controlArray[controlIndex][1], controlArray[controlIndex][2]};
  double Rcar1 = center[0] - X[0];
  double Rcar2 = center[1] - X[1];
  error = (sqrt(Rcar1*Rcar1 + Rcar2*Rcar2) - controlArray[controlIndex][3]);
  
  double kp = -2;
  double kd = -.5;
  double ki = -.01;

  if (controlArray[controlIndex][4] != 0){
    kp = -kp;
    kd = -kd;
    ki = -ki;
  }

  if(resetIntegral == 1){
    integral = 0;
    deriv = 0;
  }
  else{
    deriv = (error - oldD_circle)/dt;
  
  }
  U[1] = error*kp + integral*ki + kd*deriv;
  U[0] = v;
  oldD_circle = error;
  integral +=  error*dt;
}
void AutoCodeControlLine(double X[3], double U[2])
{
  static double deriv;
  static double oldD_line;
  double angle = atan2((controlArray[controlIndex][4] - controlArray[controlIndex][2]),(controlArray[controlIndex][3] - controlArray[controlIndex][1]));
  double R[3][3] = {
                    {cos(angle), -sin(angle), controlArray[controlIndex][1]},
                    {sin(angle), cos(angle), controlArray[controlIndex][2]},
                    {0, 0, 1}
                    };
  double determinant = 0;
  for(int i=0;i<3;i++){
      determinant = determinant + (R[0][i]*(R[1][(i+1)%3]*R[2][(i+2)%3] - R[1][(i+2)%3]*R[2][(i+1)%3]));
      //printf("determinant: %.5f\n", determinant);
  }
  double inv[3][3];
  for(int i=0;i<3;i++){
      for(int j=0;j<3;j++)
          inv[i][j] =  ((R[(j+1)%3][(i+1)%3] * R[(j+2)%3][(i+2)%3]) - (R[(j+1)%3][(i+2)%3]*R[(j+2)%3][(i+1)%3]))/ determinant;
  }
  double D = 0;
  double X_bar[3] = {X[0], X[1], 1};

  D = inv[1][0] * X_bar[0] + inv[1][1] * X_bar[1] + inv[1][2] * X_bar[2];

  double kp = -.4;
  double kd = -.5;
  deriv = (D - oldD_line)/dt;
  //printf("oldD_line: %.5f D[0][1]: %.5f Deriv: %.5f\n", oldD_line, D[1]), deriv;
  U[1] = D * kp + kd*deriv;
  U[0] = v;
  oldD_line = D;
}
void AutoCodeSetMotorPWM(double U[2], int PWM[2])
{
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

  // Scan drive curve
  for(int i = 0; i < sizeof(driveTable) / sizeof(driveTable[0]); i++)
  {
    if(abs(U[0] - driveTable[i][1]) < 0.3)
    {
      driveSpeedPWM = driveTable[i][0];
      U[0] = driveTable[i][1];
      break;
    }
  }

  // Scan steer curve
  for(int i = 0; i < sizeof(steerTable) / sizeof(steerTable[0]); i++)
  {
    if(abs(steerAngle - steerTable[i][1] ) < 7 )
    {
      steerAnglePWM = steerTable[i][0];
      U[1] = (steerTable[i][1] - 90)/ 57.295579513082323;
      break;
    }
  }
  if (steerAngle > 130.0) {
    steerAnglePWM = 88;
    U[1] = (steerTable[14][1] - 90) / 57.295579513082323;
    /* shift max angle to center around 0 b/c 90 is straight line */
  } else if (steerAngle < 45.0) {
    steerAnglePWM = 60;
    U[1] = (steerTable[0][1] - 90) / 57.295579513082323;
    /*  shift min angle to center around 0 b/c 90 is straight line */
  }

  if(driveSpeedPWM == 0){
    driveSpeedPWM = 78;
    U[0] = driveTable[0][1];
  }
  
  if(steerAnglePWM == 0){
    steerAnglePWM = 74;
    U[1] = (steerTable[7][1] - 90)/ 57.295579513082323;
  }

  /* print('An error occured in motor model. U_bar = %d: %d' + driveCurve +
   * steerAngle); */
  PWM[0] = driveSpeedPWM;
  PWM[1] = steerAnglePWM;
}
