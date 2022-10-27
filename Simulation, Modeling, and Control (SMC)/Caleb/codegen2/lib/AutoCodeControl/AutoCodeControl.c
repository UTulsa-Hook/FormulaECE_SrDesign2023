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
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comms.h"

#define BUFFSIZE 512


/* Hardware interfacing and communication stuff*/
#define INFILENAME "pytoc"
#define OUTFILENAME "ctopy"

struct Pipes openPipes() {
    struct Pipes ret = {0,0};
    if ((ret.in = open(INFILENAME, O_RDONLY)) < 0) {
        fprintf(stderr,"Error: open infile");
    	return ret;
    }

    if ((ret.out = open(OUTFILENAME, O_WRONLY)) < 0) {
        fprintf(stderr,"Error: open outfile");
    	return ret;
	}
    return ret;
}

int wait_loop0 = 10000/10;
int wait_loop1 = 6000;

/* Variable Definitions */
int controlIndex = 0;

// double controlArray[17][9] =   {
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

//line
double controlArray[1][9] = {
  {1, 10.927, 9.55, 5.366, 9.464, -1, 0, -100, 0}};

// //circle
// double controlArray[1][9] = {
//   {0, 9.415, 9.592, 1.5, 1, 0, 1, 0, 100}};

//minitrack
// double controlArray[4][9] = {
//   {1, 9.352, 11.069, 6.823, 11.054, 0, -1, 6.7, 11.054}, 
//   {0, 6.857, 9.552, 1.5, 1, 1, 0, 6.9, 8.037}, 
//   {1, 6.959, 8.037, 9.446, 8.058, 1, 0, 9.4, 8.058},
//   {0, 9.415, 9.592, 1.5, 1, -1, 0, 9.2, 11.069}
// };

double driveTable[4][2] = {
  {78, 0.92}, 
  {80, 1.56}, 
  {82, 2.19},
  {84, 2.61}
}; //% sample data pwm, speed;

double steerTable[15][2] = {
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

double dt = 0.01;
double velocity = 1;
double pozyxInput[2];


// Some queue stuff...
struct node
{
  double index;
  double data1;
  double data2;
  struct node *link;
} *front, *rear;

double X_old_predicted[2];

double x[2];
double out[2] = {0, 0};
int sizeMeUpButterCup;

/* Function Definitions */
void AutoCodeInitialize(double X[3], double U[2]);
void AutoCodeEstimatePos(double X[3], double U[2]);
double AutoCodeCheckHalfPlane(double X[3]);
void AutoCodeControl(double X[3], double U[2]);
void AutoCodeControlCircle(double X[3], double U[2], int resetIntegral);
void AutoCodeControlLine(double X[3], double U[2]);
void AutoCodeSetMotorPWM(double U[2], int PWM[2]);
void AutoCodeUpdatePosPozyx(double X[3], double pozyxInput[2], int counter);
void AutoCodeEncoder(double U[2], float encoderData);
void AutoCodeTopLevel(void);

/*Priority Queue Prototypes*/
void insert(); // Function used to insert the element into the queue
void delet(); // Function used to delete the elememt from the queue
void serch(int index, double out[2]); // Function used to display all the elements in the queue according to FIFO rule
int size();

void wait(int seconds);

/*
 * UNTITLED6 Summary of this function goes here
 *    Detailed explanation goes here
 *
 * Arguments    : const double X[3]
 *                double U[2]
 * Return Type  : void
 */

void main(){
  AutoCodeTopLevel();
}

void AutoCodeTopLevel(void)
{
  //coderTimespec b_timespec;
  double X[3];
  double X_dot[3];
  double U[2];
  int counter = 0;
  int PWM[2];
  float encoderData;
  double Rcar;

  /*Stuff to send/receive data for HW interfacing*/
  struct Pipes pip;
	pip = openPipes();
  double heading;
	double posx;
	double posy;

	char buf[BUFFSIZE] = {0};
	char outbuf[BUFFSIZE] = {0};
  /* END of HW interfacing*/

  AutoCodeInitialize(X, U);

  //double samplePozyxInput[2] = {X[0]+0.4, X[1]+0.1};

  while (1) {
    /* while 1 */
    /* UNTITLED4 Summary of this function goes here */
    /*    Detailed explanation goes here */
    /* global */
    /* X = X_dot * dt + X */
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
    AutoCodeEstimatePos(X, U);
    //AutoCodeUpdatePosPozyx(X, pozyxInfo, counter);
    AutoCodeControl(X, U);
    AutoCodeSetMotorPWM(U, PWM);
    sprintf(outbuf, "%d,%d",PWM[0],PWM[1]);
    writeOutPipe(pip, outbuf, BUFFSIZE);

    if (counter > 2/dt)
    {
      delet();
    }
    double queueInsert[3] = {counter, X[0], X[1]};
    insert(queueInsert);
    printf("X: %.2f, Y: %.2f, Heading: %.2f, Velocity: %.2f, Steering Angle: %.2f\n", X[0], X[1], X[2], U[0], U[1]);
    double testAngle = U[1] * 180 / M_PI;
    counter += 1; //(counter %10) == 0
    //wait(1); // wait 0.1 seconds

  }
}

void AutoCodeInitialize(double X[3], double U[2])
{
  X[0] = 10.9; // Testing! Xpos: 9.3 for Circ/HalfTrack, 10.9 for line; 1 for track
  X[1] = 8.5; // Testing! Ypos: 11 for circ/halftrack, 9.5 for line; 8ish for track
  X[2] = M_PI; //-1.5707963267948966; // Testing! heading: pi for circ/halftrack/line, -pi/2 for track
  /*  sample data pwm, speed; */
  /*  sample data pwm, angle */
  /* set the initial angle of the car */
  /* x, y, thetaC */
  U[0] = 1.0;
  U[1] = 0.0;
  /* , vel, thetaS */
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
  /* global */
  /* X = X_dot * dt + X */
  X[0] += U[0] * cos(X[2]) * dt;
  /* x velocity * dt + current x_location */
  X[1] += U[0] * sin(X[2]) * dt;
  /* y velocity * dt + current y_location */
  X[2] += U[0] * tan(U[1]) / 0.27 * dt;
  while(X[2] > 2 * M_PI)
  {
    X[2] -= 2 * M_PI;
  }

  while(X[2] < 0.0)
  {
    X[2] += 2 * M_PI;
  }
  /* d_thetaC * dt + current thetaC */
}

double AutoCodeCheckHalfPlane(double X[3])
{
  //double x[2];
  //x[0] = X[0];
  //x[1] = X[1];
  double result = 0.0;


  double P[2] = {controlArray[controlIndex][7], controlArray[controlIndex][8]};
  double N[2] = {controlArray[controlIndex][5], controlArray[controlIndex][6]};

  double vec1[2] = {X[0] - P[0], X[1] - P[1]};

  for (int i = 0; i < 2; i++)
    result += vec1[i]*N[i];
  return result;
}

void AutoCodeControl(double X[3], double U[2])
{
  double sign;
  int resetIntegral = 0;

  sign = AutoCodeCheckHalfPlane(X);

  if (sign > 0){
    if (controlIndex == (sizeof(controlArray) / (sizeof(controlArray[0])) - 1))
    {
      controlIndex = 0;
    }else
      {
        controlIndex += 1;
      }
      resetIntegral = 1;
  }
  else
  {
    resetIntegral = 0;
  }

  if (controlArray[controlIndex][0] == 0) 
  {
    AutoCodeControlCircle(X, U, resetIntegral);
  } else {
    AutoCodeControlLine(X, U);
  }
}

void AutoCodeControlCircle(double X[3], double U[2], int resetIntegral)
{
  static double oldD_circ;
  static double integralFactor;
  double error;
  double deriv;

  double center[2] = {controlArray[controlIndex][1], controlArray[controlIndex][2]};

  double Rcar_1 = center[0] - X[0];
  double Rcar_2 = center[1] - X[1];

  double Rcar = sqrt((Rcar_1*Rcar_1+Rcar_2*Rcar_2)); ///(Rcar_1+Rcar_2)

  error = Rcar - controlArray[controlIndex][3]; // Rcar - Rcirc

  double kp = -0.4;
  double kd = -0.5;
  double ki = -0.01;

  if(controlArray[controlIndex][4] != 0) // Lambda CW = 0, CCW = 1
  {
    kp = -kp;
    kd = -kd;
    ki = -ki;
  }

  if(resetIntegral == 1)
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

void AutoCodeControlLine(double X[3], double U[2])
{
  static double oldD_line;
  static double deriv;
  double angle = 0;
  double determinant = 0;
  double inverse[3][3];
  double D = 0;

  angle = atan2((controlArray[controlIndex][4] - controlArray[controlIndex][2]),
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

  double X_bar[3] = {X[0], X[1], 1};


  D = inverse[1][0] * X_bar[0] + inverse[1][1] * X_bar[1] + inverse[1][2] * X_bar[2];

  double kp = -0.4;
  double kd = -0.5;
  deriv = (D - oldD_line)/dt;

  U[1] = D*kp + kd * deriv;
  U[0] = velocity;
  oldD_line = D;

}

void AutoCodeSetMotorPWM(double U[2], int PWM[2])
{
  double steerAngle;
  int steerAnglePWM = 0;
  int driveSpeedPWM = 0;
  /*  sample data pwm, speed; */
  /*  sample data pwm, angle */
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

void AutoCodeUpdatePosPozyx(double X[3], double pozyxInput[2], int counter)
{
  double muPosTime = .07; // CHANGE ME PLEASE!! 
  double updatePos[2];
  if (size() > 1.9 / dt)
  {
    int index = muPosTime/dt;
    serch(counter-index, X_old_predicted);
    updatePos[0] = pozyxInput[0] - X_old_predicted[0];
    updatePos[1] = pozyxInput[1] - X_old_predicted[1];
    X[0] += updatePos[0]/100;
    X[1] += updatePos[1]/100;
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

/*Some communication/HW interfacing stuff*/
int readInPipe(struct Pipes file, char *buf, int bufsize) {
    return read(file.in, buf, bufsize);
}

void writeOutPipe(struct Pipes file, char *outbuf, int bufsize) {
	write(file.out, outbuf, bufsize);
}

void closePipes(struct Pipes file) {
    unlink(INFILENAME);
    unlink(OUTFILENAME);
    close(file.in);
    close(file.out);
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


/*
 * File trailer for AutoCodeControl.c
 *
 * [EOF]
 */



