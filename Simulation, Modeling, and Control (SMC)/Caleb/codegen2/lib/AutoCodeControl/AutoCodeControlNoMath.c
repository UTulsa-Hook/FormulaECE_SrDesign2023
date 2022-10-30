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
//#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Variable Definitions */
float sin(float rad);
float cos(float rad);
float power(float base, int exp);
int fact(int n);
float tan(float moms);
float smyqrt(double num);
double atan(double x);
static volatile const double Tiny = 0x1p-1022;

float PI = 3.141592;


int controlIndex = 0;

double controlArray[17][9] =   {
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

double dt = 0.02;
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
void AutoCodeControlCircle(double X[3], double U[2], int resetIntegral);
void AutoCodeControlLine(double X[3], double U[2]);
void AutoCodeSetMotorPWM(double U[2], float PWM[2]);
void AutoCodeUpdatePosPozyx(double X[3], double pozyxInput[2], int counter);
void AutoCodeTopLevel(void);
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
  float PWM[2];
  double Rcar;
  

  AutoCodeInitialize(X, U);

  double samplePozyxInput[2] = {X[0]+0.05, X[1]-0.04};
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
    printf("X: %.2f, Y: %.2f, Heading: %.2f, Velocity: %.2f, Steering Angle: %.2f\n", X[0], X[1], X[2], U[0], U[1]);
    double testAngle = U[1] * 180 / PI;
    counter += 1; //(counter %10) == 0
    for (int i = 0; i < 100; i++)
    {
      //asm("NOP");
    }

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
    X[0] += U[0] * cos(X[2]) * dt;
    /* x velocity * dt + current x_location */
    X[1] += U[0] * sin(X[2]) * dt;
    /* y velocity * dt + current y_location */
    X[2] += U[0] * tan(U[1]) / 0.27 * dt;
    while(X[2] > 2 * PI)
    {
    X[2] -= 2 * PI;
    }

    while(X[2] < 0.0)
    {
    X[2] += 2 * PI;
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

    double Rcar = smyqrt((Rcar_1*Rcar_1+Rcar_2*Rcar_2)); ///(Rcar_1+Rcar_2)

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

    if(controlArray[controlIndex][3] - controlArray[controlIndex][1] == 0)
    {
        if((controlArray[controlIndex][4] - controlArray[controlIndex][2]) > 0)
        {
            angle = PI / 2;
        }else
        {
            angle = -PI / 2;
        }
    }
    else
    {
    angle = atan((controlArray[controlIndex][4] - controlArray[controlIndex][2]) /
                controlArray[controlIndex][3] - controlArray[controlIndex][1]);
    }
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

void AutoCodeSetMotorPWM(double U[2], float PWM[2])
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
  double muPosTime = dt; // CHANGE ME PLEASE!! WITH POZYX
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


float sin(float rad) {
    //deg %= 360; // make it less than 360
    while (rad > 2 * PI)
    {
        rad -= 2 * PI;
    }
    while (rad < -2*PI)
    {
        rad+= 2 * PI;
    }
    //rad = rad % (2 * PI);
    float sin = 0;

    int i;
    for(i = 0; i < 6; i++) { // That's Taylor series!!
        sin += power(-1, i) * power(rad, 2 * i + 1) / fact(2 * i + 1);
    }
    return sin;
}

float cos(float rad) {
     while (rad > 2 * PI)
    {
        rad -= 2 * PI;
    }
    while (rad < -2*PI)
    {
        rad+= 2 * PI;
    }
    //deg %= 360; // make it less than 360
    // rad = deg * PI / 180;
    float cos = 0;

    int i;
    for(i = 0; i < 5; i++) { // That's also Taylor series!!
        cos += power(-1, i) * power(rad, 2 * i) / fact(2 * i);
    }
    return cos;
}


float power(float base, int exp) {
    if(exp < 0) {
        if(base == 0)
            return -0; // Error!!
        return 1 / (base * power(base, (-exp) - 1));
    }
    if(exp == 0)
        return 1;
    if(exp == 1)
        return base;
    return base * power(base, exp - 1);
}

float tan(float moms) {
    float x=cos(moms);
    float y=sin(moms);
    return (y / x);
}

static double Tail(double x)
{
	{
		static const double HalfPi = 0x3.243f6a8885a308d313198a2e037ap-1;

		// For large x, generate inexact and return pi/2.
		if (0x1p53 <= x)
			return HalfPi + Tiny;
		//if (isnan(x))
		//	return x - x;
	}

	static const double p03 = -0x1.5555555554A51p-2;
	static const double p05 = +0x1.999999989EBCAp-3;
	static const double p07 = -0x1.249248E1422E3p-3;
	static const double p09 = +0x1.C71C5EDFED480p-4;
	static const double p11 = -0x1.745B7F2D72663p-4;
	static const double p13 = +0x1.3AFD7A0E6EB75p-4;
	static const double p15 = -0x1.104146B1A1AE8p-4;
	static const double p17 = +0x1.D78252FA69C1Cp-5;
	static const double p19 = -0x1.81D33E401836Dp-5;
	static const double p21 = +0x1.007733E06CEB3p-5;
	static const double p23 = -0x1.83DAFDA7BD3FDp-7;

	static const double p000 = +0x1.921FB54442D18p0;
	static const double p001 = +0x1.1A62633145C07p-54;

	double y = 1/x;

	// Square y.
	double y2 = y * y;

	return p001 - ((((((((((((
		+ p23) * y2
		+ p21) * y2
		+ p19) * y2
		+ p17) * y2
		+ p15) * y2
		+ p13) * y2
		+ p11) * y2
		+ p09) * y2
		+ p07) * y2
		+ p05) * y2
		+ p03) * y2 * y + y) + p000;
}


/*	Return arctangent(x) given that 0x1p-27 < |x| <= 1/2, with the same
	properties as atan.
*/
static double atani0(double x)
{
	static const double p03 = -0x1.555555555551Bp-2;
	static const double p05 = +0x1.99999999918D8p-3;
	static const double p07 = -0x1.2492492179CA3p-3;
	static const double p09 = +0x1.C71C7096C2725p-4;
	static const double p11 = -0x1.745CF51795B21p-4;
	static const double p13 = +0x1.3B113F18AC049p-4;
	static const double p15 = -0x1.10F31279EC05Dp-4;
	static const double p17 = +0x1.DFE7B9674AE37p-5;
	static const double p19 = -0x1.A38CF590469ECp-5;
	static const double p21 = +0x1.56CDB5D887934p-5;
	static const double p23 = -0x1.C0EB85F543412p-6;
	static const double p25 = +0x1.4A9F5C4724056p-7;

	// Square x.
	double x2 = x * x;

	return ((((((((((((
		+ p25) * x2
		+ p23) * x2
		+ p21) * x2
		+ p19) * x2
		+ p17) * x2
		+ p15) * x2
		+ p13) * x2
		+ p11) * x2
		+ p09) * x2
		+ p07) * x2
		+ p05) * x2
		+ p03) * x2 * x + x;
}


/*	Return arctangent(x) given that 1/2 < x <= 3/4, with the same properties as
	atan.
*/
static double atani1(double x)
{
	static const double p00 = +0x1.1E00BABDEFED0p-1;
	static const double p01 = +0x1.702E05C0B8155p-1;
	static const double p02 = -0x1.4AF2B78215A1Bp-2;
	static const double p03 = +0x1.5D0B7E9E69054p-6;
	static const double p04 = +0x1.A1247CA5D9475p-4;
	static const double p05 = -0x1.519E110F61B54p-4;
	static const double p06 = +0x1.A759263F377F2p-7;
	static const double p07 = +0x1.094966BE2B531p-5;
	static const double p08 = -0x1.09BC0AB7F914Cp-5;
	static const double p09 = +0x1.FF3B7C531AA4Ap-8;
	static const double p10 = +0x1.950E69DCDD967p-7;
	static const double p11 = -0x1.D88D31ABC3AE5p-7;
	static const double p12 = +0x1.10F3E20F6A2E2p-8;

	double y = x - 0x1.4000000000027p-1;

	return ((((((((((((
		+ p12) * y
		+ p11) * y
		+ p10) * y
		+ p09) * y
		+ p08) * y
		+ p07) * y
		+ p06) * y
		+ p05) * y
		+ p04) * y
		+ p03) * y
		+ p02) * y
		+ p01) * y
		+ p00;
}


/*	Return arctangent(x) given that 3/4 < x <= 1, with the same properties as
	atan.
*/
static double atani2(double x)
{
	static const double p00 = +0x1.700A7C580EA7Ep-01;
	static const double p01 = +0x1.21FB781196AC3p-01;
	static const double p02 = -0x1.1F6A8499714A2p-02;
	static const double p03 = +0x1.41B15E5E8DCD0p-04;
	static const double p04 = +0x1.59BC93F81895Ap-06;
	static const double p05 = -0x1.63B543EFFA4EFp-05;
	static const double p06 = +0x1.C90E92AC8D86Cp-06;
	static const double p07 = -0x1.91F7E2A7A338Fp-08;
	static const double p08 = -0x1.AC1645739E676p-08;
	static const double p09 = +0x1.152311B180E6Cp-07;
	static const double p10 = -0x1.265EF51B17DB7p-08;
	static const double p11 = +0x1.CA7CDE5DE9BD7p-14;

	double y = x - 0x1.c0000000f4213p-1;

	return (((((((((((
		+ p11) * y
		+ p10) * y
		+ p09) * y
		+ p08) * y
		+ p07) * y
		+ p06) * y
		+ p05) * y
		+ p04) * y
		+ p03) * y
		+ p02) * y
		+ p01) * y
		+ p00;
}


/*	Return arctangent(x) given that 1 < x <= 4/3, with the same properties as
	atan.
*/
static double atani3(double x)
{
	static const double p00 = +0x1.B96E5A78C5C40p-01;
	static const double p01 = +0x1.B1B1B1B1B1B3Dp-02;
	static const double p02 = -0x1.AC97826D58470p-03;
	static const double p03 = +0x1.3FD2B9F586A67p-04;
	static const double p04 = -0x1.BC317394714B7p-07;
	static const double p05 = -0x1.2B01FC60CC37Ap-07;
	static const double p06 = +0x1.73A9328786665p-07;
	static const double p07 = -0x1.C0B993A09CE31p-08;
	static const double p08 = +0x1.2FCDACDD6E5B5p-09;
	static const double p09 = +0x1.CBD49DA316282p-13;
	static const double p10 = -0x1.0120E602F6336p-10;
	static const double p11 = +0x1.A89224FF69018p-11;
	static const double p12 = -0x1.883D8959134B3p-12;

	double y = x - 0x1.2aaaaaaaaaa96p0;

	return ((((((((((((
		+ p12) * y
		+ p11) * y
		+ p10) * y
		+ p09) * y
		+ p08) * y
		+ p07) * y
		+ p06) * y
		+ p05) * y
		+ p04) * y
		+ p03) * y
		+ p02) * y
		+ p01) * y
		+ p00;
}


/*	Return arctangent(x) given that 4/3 < x <= 5/3, with the same properties as
	atan.
*/
static double atani4(double x)
{
	static const double p00 = +0x1.F730BD281F69Dp-01;
	static const double p01 = +0x1.3B13B13B13B0Cp-02;
	static const double p02 = -0x1.22D719C06115Ep-03;
	static const double p03 = +0x1.C963C83985742p-05;
	static const double p04 = -0x1.135A0938EC462p-06;
	static const double p05 = +0x1.13A254D6E5B7Cp-09;
	static const double p06 = +0x1.DFAA5E77B7375p-10;
	static const double p07 = -0x1.F4AC1342182D2p-10;
	static const double p08 = +0x1.25BAD4D85CBE1p-10;
	static const double p09 = -0x1.E4EEF429EB680p-12;
	static const double p10 = +0x1.B4E30D1BA3819p-14;
	static const double p11 = +0x1.0280537F097F3p-15;

	double y = x - 0x1.8000000000003p0;

	return (((((((((((
		+ p11) * y
		+ p10) * y
		+ p09) * y
		+ p08) * y
		+ p07) * y
		+ p06) * y
		+ p05) * y
		+ p04) * y
		+ p03) * y
		+ p02) * y
		+ p01) * y
		+ p00;
}


/*	Return arctangent(x) given that 5/3 < x <= 2, with the same properties as
	atan.
*/
static double atani5(double x)
{
	static const double p00 = +0x1.124A85750FB5Cp+00;
	static const double p01 = +0x1.D59AE78C11C49p-03;
	static const double p02 = -0x1.8AD3C44F10DC3p-04;
	static const double p03 = +0x1.2B090AAD5F9DCp-05;
	static const double p04 = -0x1.881EC3D15241Fp-07;
	static const double p05 = +0x1.8CB82A74E0699p-09;
	static const double p06 = -0x1.3182219E21362p-12;
	static const double p07 = -0x1.2B9AD13DB35A8p-12;
	static const double p08 = +0x1.10F884EAC0E0Ap-12;
	static const double p09 = -0x1.3045B70E93129p-13;
	static const double p10 = +0x1.00B6A460AC05Dp-14;

	double y = x - 0x1.d555555461337p0;

	return ((((((((((
		+ p10) * y
		+ p09) * y
		+ p08) * y
		+ p07) * y
		+ p06) * y
		+ p05) * y
		+ p04) * y
		+ p03) * y
		+ p02) * y
		+ p01) * y
		+ p00;
}


// See documentation above.
double atan(double x)
{
	if (x < 0)
		if (x < -1)
			if (x < -5/3.)
				if (x < -2)
					return -Tail(-x);
				else
					return -atani5(-x);
			else
				if (x < -4/3.)
					return -atani4(-x);
				else
					return -atani3(-x);
		else
			if (x < -.5)
				if (x < -.75)
					return -atani2(-x);
				else
					return -atani1(-x);
			else
				if (x < -0x1.d12ed0af1a27fp-27)
					return atani0(x);
				else
					if (x <= -0x1p-1022)
						// Generate inexact and return x.
						return (Tiny + 1) * x;
					else
						if (x == 0)
							return x;
						else
							// Generate underflow and return x.
							return x*Tiny + x;
	else
		if (x <= +1)
			if (x <= +.5)
				if (x <= +0x1.d12ed0af1a27fp-27)
					if (x < +0x1p-1022)
						if (x == 0)
							return x;
						else
							// Generate underflow and return x.
							return x*Tiny + x;
					else
						// Generate inexact and return x.
						return (Tiny + 1) * x;
				else
					return atani0(x);
			else
				if (x <= +.75)
					return +atani1(+x);
				else
					return +atani2(+x);
		else
			if (x <= +5/3.)
				if (x <= +4/3.)
					return +atani3(+x);
				else
					return +atani4(+x);
			else
				if (x <= +2)
					return +atani5(+x);
				else
					return +Tail(+x);
}

float smyqrt(double num){
    // divide the given number by 2 and store into sqrt
    float sqrtx = num / 2;
    float temp = 0;

    // use while loop to continuously checks the sqrt is not equal to the temp
    while (sqrtx != temp) // Initially temp is 0 and sqrt = num
    {
        temp = sqrtx; // assign sqrt to temp

        sqrtx = ( num / temp + temp) / 2;
     }

     return sqrtx;
}

int fact(int n) {
    return n <= 0 ? 1 : n * fact(n-1);
}


/*
 * File trailer for AutoCodeControl.c
 *
 * [EOF]
 */



