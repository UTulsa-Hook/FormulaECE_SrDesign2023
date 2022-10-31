//usr/bin/cc "$0" "comms.c" -lm && exec ./a.out "$@"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comms.h"

#define BUFFSIZE 512

int wait_loop0 = 10000 / 10;
int wait_loop1 = 6000;

/*CONTROL ARRAYS*/

/*int controlArray[17][9] = {{1, 1, 9, 1, 2, 0, -1, 1, 2},
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
                        {0, 2, 9, 1, 1, 0, -1, 1, 9}};
                        */

/*TESTS*/
// LINE
// int controlArray[2][9]={{1,10,10,10,-10,-1,0,0,0},
//                           {0,0,0,0,0,0,0,0,0}};
// int controlArray[2][9] = {{1, 1, 9, 1, 1, 0, -1, 1, 2}};  // with pozyx
// CIRCLE
// int controlArray[2][9] = {{0, 10, 10, 0.5, 0, -1, 0, 0, 0},
//                           {0, 0, 0, 0, 0, 0, 0, 0, 0}};
// int controlArray[1][9] = {{0, 8.2, 9.5, 0.5, 0, -1, 0, 0, 0}}; //for pozyx

// minitrack
/*double controlArray[4][9] = {
    {1, 9.352, 11.069, 6.823, 11.054, -1, 0, 6.7, 11.054},
    {0, 6.857, 9.552, 1.5, 1, 1, 0, 6.9, 8.037},
    {1, 6.959, 8.037, 9.446, 8.058, 1, 0, 9.4, 8.058},
    {0, 9.415, 9.592, 1.5, 1, -1, 0, 9.2, 11.069}};*?*/
/*END TESTS*/

/// below are unused tests
// xline
// NO double controlArray[1][9] = {
//{1, 10.927, 9.55, 5.366, 9.464, -1, 0, -100, 0}};
// NO circle
// x double controlArray[1][9] = {
//    {0, 9.415, 9.592, 1.5, 1, 0, 1, 0, 100}}
int controlArray[4][9] = {{0, 10, 10, 0.5, 0, 0, -1, 10.5, 10},
                          {1, 10.5, 10, 10.5, 9, 0, -1, 10.5, 9},
                          {0, 10, 9, 0.5, 0, 0, 1, 9.5, 9},
                          {1, 9.5, 9, 9.5, 10, 0, 1, 9.5, 10}};  // test track
/* NO int controlArray[4][9] = {{1, 1, 9, 1, 2, 0, -1, 1, 2},
                          {0, 2.1, 2.1, 1, 1, 1, 0, 2, 1 */

/*END CONTROL ARRAYS*/

/*PWM TABLES*/

/*int driveTable[4][2] = {{78, 4.6}, {80, 7.8}, {82, 11.0}, {84, 13.1}}; //
 * sample data pwm, speed;*/
int driveTable[4][2] = {
    {78, 0.92}, {80, 1.56}, {82, 2.19}, {84, 2.61}};  // sample data pwm, speed;

/*int steerTable[16][2] = {{60, 45}, {62, 45}, {64, 55}, {66, 60},
                        {68, 70}, {70, 75}, {72, 80}, {74, 90},
                        {76, 95}, {78, 105}, {80, 110}, {82, 115},
                        {84, 120}, {86, 125}, {88, 130}}; // sample data pwm,
   angle
*/

#define centeredDrive 70
int steerTable[19][2] = {{centeredDrive - 16, 45},  {centeredDrive - 16, 50},
                         {centeredDrive - 14, 55},  {centeredDrive - 12, 60},
                         {centeredDrive - 10, 65},  {centeredDrive - 8, 70},
                         {centeredDrive - 6, 75},   {centeredDrive - 4, 80},
                         {centeredDrive - 2, 85},   {centeredDrive, 90},
                         {centeredDrive + 2, 95},   {centeredDrive + 4, 100},
                         {centeredDrive + 6, 105},  {centeredDrive + 8, 110},
                         {centeredDrive + 10, 115}, {centeredDrive + 12, 120},
                         {centeredDrive + 14, 125}, {centeredDrive + 16, 130},
                         {centeredDrive + 14, 135}};

/*END PWM TABLES*/

int controlIndex;
double sigmaSteering;  // needs to be in rad
double signmaDrive;
double signmaPos;
double sigmaPosTime;
double muPosTime;
double dt = 0.05;
double velocity = 1;
int counter = 0;
double X_old_predicted[2];
double pozyxInput[2];
float encoderData;
double Rcar;
double U[2];
double X[3];
double U_bar[2];
double X_bar[3];
double PWM[2];

void main();
void TopLevel();
void Initialize();
void Pozyx(double X[3], double pozyxInput[2], int counter);
void Control(double U[2], double X[3]);
void Dynamics(double U[2], double X[3]);
void MotorModel(double U[2], double PWM[2]);
void controlCircle(double X[3], double U[2], int resetIntegral);
void controlLine(double X[3], double U[2]);
void Encoder(double U[2], float encoderData);
double HalfPlane(double X[3]);
void delete ();
void insert(double pozInput[3]);
void wait(int seconds);
void search(int index, double X_old_predicted[2]);
int size();

void main() { TopLevel(); }

void TopLevel() {
  Initialize();

  int counter = 0;

  double samplePozyxInput[2];
  samplePozyxInput[0] = X[0];  // + 0.4;
  samplePozyxInput[1] = X[1];  // + 0.1;

  /*Stuff to send/receive data for HW interfacing*/
  struct Pipes pip;
  pip = openPipes();
  double heading;
  double posx;
  double posy;

  char buf[BUFFSIZE] = {0};
  char outbuf[BUFFSIZE] = {0};
  /* END of HW interfacing*/

  while (1) {
    readInPipe(pip, buf, BUFFSIZE);
    if (buf[0] != 0x0) {
      sscanf(strtok(buf, ","), "%lf", &posx);
      printf("%.4lf\n", posx);
      sscanf(strtok(NULL, ","), "%lf", &posy);
      printf("%.4lf\n", posy);
      sscanf(strtok(NULL, ","), "%lf", &heading);
      printf("%.4lf\n", heading);
    }

    double pozyxInfo[2] = {posx, posy};

    // X_bar =
    Encoder(U, encoderData);
    // Pozyx(X, samplePozyxInput, counter);
    // U_bar =
    Control(U, X);
    // U =
    MotorModel(U, PWM);
    // X =
    Dynamics(U, X);
    sprintf(outbuf, "%.4lf,%.4lf", PWM[0], PWM[1]);
    writeOutPipe(pip, outbuf, BUFFSIZE);

    if (counter > 2 / dt) {
      delete ();
    }

    double queueItem[3] = {counter, X[0], X[1]};
    insert(queueItem);
    // printf("\n: %f y: %f counter: %f \n", X[0], X[1], counter);
    printf("Index: %d  X: %f  Y: %f  Theta: %f Counter: %d\n", controlIndex,
           X[0], X[1], X[2], counter);

    counter += 1;
    // pause(dt);
  }
}

void Initialize() {
  /*Track INIT*/

  // X[0] = 1.1;
  // X[1] = 8;
  // X[2] = 4.71;//*(180/3.14);//(3/2)*3.14;

  // line Test INIT
  // X[0] = 1;    // line
  // X[1] = 7.5;  // line
  // X[2] = -M_PI / 2;

  // circTest INIT
  // X[0] = 9.5;  // circ
  // X[1] = 9.3;    // circ
  // X[2] = -M_PI / 2;

  // minitrack INIT
  X[0] = 10;    // 9.3;  // test2
  X[1] = 10.5;  // test2
  X[2] = 0;

  // NOT Test Track
  // X[0] = 11.6;
  // X[1] = 10;
  // X[2] = 3.14/2;
  //

  // X[0] = 10.9;//line2
  // X[1] = 8.5;//line2

  U[0] = velocity;
  U[1] = 0;

  controlIndex = 0;
  sigmaSteering = 5 * (M_PI) / 180;  // needs to be in rad
  signmaDrive = 0.2;
  signmaPos = 0.1;
  sigmaPosTime = 0.1;
  muPosTime = 0.07;
}

void Encoder(double U[2], float encoderData) {
  static int counter1;
  static int counter2;
  static float buffer;
  encoderData = -1;  // for testing
  while (counter1 < 3 && counter2 < 5) {
    if (0 < encoderData && encoderData < 500) {
      buffer += 46.019423 / encoderData;
      counter1 += 1;
    }
    counter2 += 1;
  }

  if (counter1 == 3) {
    if (0 < buffer && buffer < 10) {
      U[0] = buffer / 3;
    }
    counter1 = 0;
    counter2 = 0;
  } else {
    U[0] = U[0];
    counter1 = 0;
    counter2 = 0;
  }
}

void Dynamics(double U[2], double X[3]) {
  // printf("In Dynamics\n");
  double v;
  v = U[0];
  double thetaS;
  thetaS = U[1];
  double theta;
  theta = X[2];

  // double X_dot[3];// = {v*cos(theta), v*sin(theta), v*tan(thetaS)/.27};
  // printf("\nBefore:\nx: %f y: %f z: %f \n", X[0], X[1], X[2]);
  // printf("v: %f, theta:%f, dt: %f",v,theta,dt);
  X[0] = v * cos(theta) * dt + X[0];  // x velocity * dt + current x_location
  X[1] = v * sin(theta) * dt + X[1];  // y velocity * dt + current y_location
  X[2] = (v * tan(thetaS) / .27) * dt + X[2];
  while (X[2] > 2 * M_PI) {
    X[2] -= 2 * M_PI;
  }

  while (X[2] < 0.0) {
    X[2] += 2 * M_PI;
  }
  // X = X2;
  // printf("\nAfter:\nx: %f y: %f z: %f \n", X[0], X[1], X[2]);

  // return X;
}

void Control(double U[2], double X[3]) {
  // printf("inside Control");
  int resetIntegral;
  resetIntegral = 0;

  if (HalfPlane(X) > 0) {
    if (controlIndex == (sizeof(controlArray) / sizeof(controlArray[0])) - 1) {
      controlIndex = 0;
    } else {
      controlIndex = controlIndex + 1;
    }

    resetIntegral = 1;

  } else {
    resetIntegral = 0;
  }

  if (controlArray[controlIndex][0] == 0) {
    controlCircle(X, U, resetIntegral);
  } else {
    // U =
    controlLine(X, U);
  }

  // return U;
}

void controlCircle(double X[3], double U[2], int resetIntegral) {
  static double oldD;
  static double integralFactor;
  double x;
  double y;
  double thetaC;
  double lambda;
  double Rcirc;
  double center[2];
  //  static int t;
  static double deriv;
  double Rcar;
  double error;
  double ki;
  double kp;
  double kd;

  x = X[0];
  y = X[1];
  thetaC = X[2];

  lambda = controlArray[controlIndex][4];
  Rcirc = controlArray[controlIndex][3];
  center[0] = controlArray[controlIndex][1];
  center[1] = controlArray[controlIndex][2];
  // int Rcar = norm(center - {x,y});

  Rcar = sqrt((center[0] - x) * (center[0] - x) +
              (center[1] - y) * (center[1] - y));

  error = Rcar - Rcirc;

  ki = 0.01;
  kp = 0.4;
  kd = 0.5;
  if (lambda == 0) {
    kp = -kp;
    kd = -kd;
    ki = -ki;
  }
  // else{
  //   kp = 0.4;
  // kd = 0.5;
  // ki = 0.01;
  //}

  if (resetIntegral == 1) {
    deriv = 0;
    integralFactor = 0;

  } else {
    deriv = (error - oldD) / dt;
  }

  // set the steering angle with PD controller to steer towards line
  // int thetaS = error*kp + integralFactor * ki + kd*deriv;
  U[0] = velocity;                                       // velocity
  U[1] = error * kp + integralFactor * ki + kd * deriv;  // thetaS;
  oldD = error;
  integralFactor = integralFactor + error * dt;

  // return U;
}

void controlLine(double X[3], double U[2]) {
  static double deriv;
  static double oldD;
  double X_bar[3];
  // static int lineToFollow;
  double D;
  D = 0;

  // double xdiff = controlArray[controlIndex][4] -
  // controlArray[controlIndex][2]; double ydiff = controlArray[controlIndex][5]
  // - controlArray[controlIndex][3]; double angle = atan(ydiff/xdiff);////
  double angle;
  angle =
      atan2((controlArray[controlIndex][4] - controlArray[controlIndex][2]),
            (controlArray[controlIndex][3] - controlArray[controlIndex][1]));
  double R[3][3] = {{cos(angle), -sin(angle), controlArray[controlIndex][1]},
                    {sin(angle), cos(angle), controlArray[controlIndex][2]},
                    {0, 0, 1}};

  double inverse[3][3];
  double determinant = 0;

  // To calculate inverse in controlLine
  for (int i = 0; i < 3; i++) {
    determinant =
        determinant + (R[0][i] * (R[1][(i + 1) % 3] * R[2][(i + 2) % 3] -
                                  R[1][(i + 2) % 3] * R[2][(i + 1) % 3]));
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      inverse[i][j] =
          ((R[(j + 1) % 3][(i + 1) % 3] * R[(j + 2) % 3][(i + 2) % 3]) -
           (R[(j + 1) % 3][(i + 2) % 3] * R[(j + 2) % 3][(i + 1) % 3])) /
          determinant;
    }
  }
  // int D[] = inverse * {X_bar[0],X_bar[1], 1};

  X_bar[0] = X[0];
  X_bar[1] = X[1];
  X_bar[2] = 1;
  D = inverse[1][0] * X_bar[0] + inverse[1][1] * X_bar[1] +
      inverse[1][2] * X_bar[2];

  // double v = 2;
  double kp;
  kp = -0.8;
  double kd;
  kd = -0.5;
  deriv = (D - oldD) / dt;

  // set the steering angle with PD controller to steer towards line
  // double thetaS = D*kp + kd*deriv;
  // double Acc = 0.2; //m/s/s
  U[0] = velocity;             // velocity
  U[1] = D * kp + kd * deriv;  // thetaS;
  oldD = D;
}

double HalfPlane(double X[3]) {
  // X[] = {X[0], X[1]};
  double P[2];
  double N[2];
  double result;
  double vec1[2];
  result = 0;
  P[0] = controlArray[controlIndex][7];
  P[1] = controlArray[controlIndex][8];

  N[0] = controlArray[controlIndex][5];
  N[1] = controlArray[controlIndex][6];

  vec1[0] = X[0] - P[0];
  vec1[1] = X[1] - P[1];

  for (int i = 0; i < 2; i++) {
    result += vec1[i] * N[i];
  }
  // printf("HP: Result: %f\n", result);

  return result;
}

void Pozyx(double X[3], double pozyxInput[2], int counter) {
  double updatePos[2];
  double index;
  muPosTime = .07;
  if (size() > 1.9 / dt) {
    index = muPosTime / dt;
    search(counter - index, X_old_predicted);

    updatePos[0] = pozyxInput[0] - X_old_predicted[0];
    updatePos[1] = pozyxInput[1] - X_old_predicted[1];

    X[0] = X[0] + (updatePos[0] / 100);
    X[1] = X[1] + (updatePos[1] / 100);
  }

  // return X_bar;
}

void MotorModel(double U[2], double PWM[2]) {
  double driveCurvePWM = 0;
  double steerCurvePWM = 0;

  // double driveCurve = U[0];
  double steerCurve;
  steerCurve = (180 / (M_PI)) * U[1];

  while (steerCurve < -180 || steerCurve > 180) {
    if (steerCurve < -180) {
      steerCurve = steerCurve + 360;
    } else if (steerCurve > 180.0) {
      steerCurve = steerCurve - 360;
    }
  }

  steerCurve = steerCurve + 90;

  for (int i = 0; i < (sizeof(driveTable) / sizeof(driveTable[0])); i++) {
    // if(driveCurve >= 0.5 * driveTable[i][2] && driveCurve <= 1.5 *
    // driveTable[i][2]){
    if (abs(U[0] - driveTable[i][1]) < 0.3) {
      // U[0] = driveTable[i][2];
      driveCurvePWM = driveTable[i][0];  // 2];
      U[0] = driveTable[i][1];
      break;
    }
  }
  // for(i=0;i<(sizeof(steerTable)/sizeof(steerTable[0]));i++){
  //    if(steerCurve >= 0.9 * steerTable[i][2] && steerCurve <= 1.1 *
  //    steerTable[i][2]){
  //       U[1] = ((3.14)/180)*steerTable[i][2]-90;
  //       steerCurvePWM = steerTable[i][2];
  //      break;

  //}

  //}
  for (int i = 0; i < sizeof(steerTable) / sizeof(steerTable[0]); i++) {
    if (abs(steerCurve - steerTable[i][1]) < 7) {
      steerCurvePWM = steerTable[i][0];
      U[1] = (steerTable[i][1] - 90) / (180 / M_PI);
      break;
    }
  }

  if (driveCurvePWM == 0) {
    driveCurvePWM = 78;
    U[0] = driveTable[0][1];
  }

  if (steerCurve > 130) {
    steerCurvePWM = 88;
    // U[1] = ((3.14)/180)*40;
    U[1] = (steerTable[14][1] - 90) / (180 / M_PI);
  } else if (steerCurve < 45) {
    steerCurvePWM = 60;
    //  U[1] = ((3.14)/180)*-45;
    U[1] = (steerTable[0][1] - 90) / (180 / M_PI);
  }
  if (driveCurvePWM == 0) {
    driveCurvePWM = 78;
    U[0] = driveTable[0][1];
  }

  if (steerCurvePWM == 0)  // change for straight
  {
    steerCurvePWM = 74;
    U[1] = (steerTable[7][1] - 90) / (180 / M_PI);
  }

  PWM[0] = driveCurvePWM;
  PWM[1] = steerCurvePWM;
}

//  if( ((driveCurvePWM >= 78) && (driveCurvePWM <= 84)) && ((steerCurvePWM <=
//  88) && (steerCurvePWM >= 60)) ){
// printf('ok');
//  }
// else{
//  U = [0 0];
// }
//  printf('An error occured in motor model. U_bar = %d: %d', driveCurve,
//  steerCurve);

// if(includeUncertainty == 1){
//  if(U_bar ~= Ubar_hold){
//    uncert[0] = normrnd(0, sigmaDrive);
//  uncert[1] = normrnd(0, sigmaSteering);
//}
//}

// rad2deg(U(2))

/*Priority Queue*/
struct node {
  double index;
  double data1;
  double data2;
  struct node *link;
} * front, *rear;

void insert(double pozInput[3]) {
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->index = pozInput[0];
  temp->data1 = pozInput[1];
  temp->data2 = pozInput[2];
  temp->link = NULL;
  if (rear == NULL) {
    front = rear = temp;
  } else {
    rear->link = temp;
    rear = temp;
  }
}

void delete () {
  struct node *temp;
  temp = front;
  if (front == NULL) {
    // printf("Queue underflow\n");
    front = rear = NULL;
  } else {
    // printf("The deleted element from the queue is: %f\n", front->data1);
    front = front->link;
    free(temp);
  }
}

void search(int index, double X_old_predicted[2]) {
  struct node *temp;
  temp = front;
  int cnt = 0;

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

  while (temp) {
    // printf("%d\n", temp->data);
    temp = temp->link;
    cnt++;
  }
  // printf("%d\n", cnt);
  return cnt;
}

/* Time Delay method*/
void wait(int seconds) {  // this function needs to be finetuned for the
                          // specific microprocessor
  int i, j, k;
  for (i = 0; i < seconds; i++) {
    for (j = 0; j < wait_loop0; j++) {
      for (k = 0; k < wait_loop1;
           k++) {  // waste function, volatile makes sure it is not being
                   // optimized out by compiler
        int volatile t = 120 * j * i + k;
        t = t + 5;
      }
    }
  }
}
