/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Control.c
 *
 * Code generation for function 'Control'
 *
 */

/* Include files */
#include "Control.h"
#include <math.h>

/* Variable Definitions */
static double oldD;

static double integralFactor;

static double b_oldD;

static boolean_T isInitialized_Control = false;

/* Function Declarations */
static void controlCircle_init(void);

static void controlLine_init(void);

/* Function Definitions */
static void controlCircle_init(void)
{
  oldD = 0.0;
  integralFactor = 0.0;
}

static void controlLine_init(void)
{
  b_oldD = 0.0;
}

double Control(const double X_bar[3])
{
  static const double controlArray[153] = {
      1.0, 0.0,  1.0,  1.0, 0.0,  1.0,  0.0,  0.0,  1.0,  0.0,  1.0,  0.0,  1.0,
      0.0, 1.0,  1.0,  0.0, 1.0,  2.1,  2.0,  6.0,  9.9,  11.0, 10.0, 7.9,  8.0,
      4.1, 3.0,  4.1,  4.0, 10.0, 10.0, 6.0,  2.0,  9.0,  2.1,  1.0,  2.0,  2.6,
      2.5, 4.9,  5.1,  4.0, 5.6,  5.5,  7.9,  9.0,  10.5, 12.0, 10.0, 9.0,  1.0,
      1.0, 6.0,  10.0, 1.0, 11.0, 1.0,  1.0,  4.0,  1.0,  3.0,  1.0,  10.0, 1.5,
      6.0, 2.0,  1.0,  2.0, 1.0,  2.0,  1.5,  1.0,  5.0,  1.0,  0.0,  4.5,  0.0,
      8.0, 0.0,  9.0,  1.0, 10.0, 10.0, 1.0,  0.0,  1.0,  1.0,  1.0,  0.0,  0.0,
      0.0, -1.0, -1.0, 0.0, 0.0,  1.0,  1.0,  -1.0, -1.0, -1.0, 0.0,  -1.0, 0.0,
      0.0, 0.0,  1.0,  1.0, -1.0, 0.0,  0.0,  1.0,  1.0,  0.0,  0.0,  0.0,  0.0,
      0.0, -1.0, 1.0,  2.0, 6.0,  9.8,  10.8, 11.0, 9.0,  8.0,  4.2,  3.0,  3.0,
      3.8, 10.1, 10.0, 6.0, 2.0,  1.0,  2.0,  1.0,  2.0,  1.5,  2.5,  5.0,  5.0,
      4.0, 4.5,  5.3,  7.6, 9.0,  9.0,  12.0, 10.0, 10.0, 9.0};
  static const signed char a[9] = {0, 1, 0, -1, 0, 0, 9, -1, 1};
  double D[3];
  double Rcar;
  double absxk;
  double scale;
  double t;
  int controlIndex;
  int resetIntegral;
  if (!isInitialized_Control) {
    Control_initialize();
  }
  /* UNTITLED2 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /* global controlArray; */
  /* global controlIndex; */
  /* 0, 5, 5, 3, 0, 1, 0, 100, 100]; */
  controlIndex = 0;
  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*      global controlArray; */
  /*      global controlIndex; */
  /* 0, 5, 5, 3, 0, 1, 0, 100, 100]; */
  /* result = sign((x - P)' * N); */
  scale = (X_bar[0] - 1.0) * 0.0 + -(X_bar[1] - 2.0);
  if (scale < 0.0) {
    scale = -1.0;
  } else if (scale > 0.0) {
    scale = 1.0;
  } else if (scale == 0.0) {
    scale = 0.0;
  }
  if (scale > 0.0) {
    controlIndex = 1;
    resetIntegral = 1;
  } else {
    resetIntegral = 0;
  }
  if (controlArray[controlIndex] == 0.0) {
    /* UNTITLED3 Summary of this function goes here */
    /*    Detailed explanation goes here */
    /*      global controlArray; */
    /*      global controlIndex; */
    /*      global velocity; */
    /*      global dt; */
    /* 0, 5, 5, 3, 0, 1, 0, 100, 100]; */
    if (resetIntegral == 1) {
      integralFactor = 0.0;
    }
    scale = 3.3121686421112381E-170;
    absxk = fabs(1.0 - X_bar[0]);
    if (absxk > 3.3121686421112381E-170) {
      Rcar = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      Rcar = t * t;
    }
    absxk = fabs(9.0 - X_bar[1]);
    if (absxk > scale) {
      t = scale / absxk;
      Rcar = Rcar * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      Rcar += t * t;
    }
    Rcar = scale * sqrt(Rcar);
    if (resetIntegral == 1) {
      scale = 0.0;
    } else {
      scale = ((Rcar - 1.0) - oldD) / 0.01;
    }
    /* set the steering angle with PD controller to steer towards line */
    U[1] = ((Rcar - 1.0) * 0.4 + integralFactor * 0.00035) + 0.5 * scale;
    U[0] = 2.0;
    /* velocity */
    oldD = Rcar - 1.0;
    integralFactor += (Rcar - 1.0) * 0.01;
    /*      if(plotting) */
    /*          if t == 0 */
    /*              integralPlot = plot(t, integralFactor, 'k') */
    /*              hold on */
    /*              xlabel('t (s)') */
    /*              ylabel('Integral Component of Controller'); */
    /*          else */
    /*              set(integralPlot, 'Xdata', [get(integralPlot,'Xdata') t],
     * 'Ydata', [get(integralPlot,'Ydata') integralFactor]) */
    /*          end */
    /*          t = t + dt; */
    /*      end */
  } else {
    /*      global dt; */
    /*      global controlArray; */
    /*      global controlIndex; */
    /*      global velocity; */
    /* 0, 5, 5, 3, 0, 1, 0, 100, 100]; */
    /*      lineToFollow1 = [1 1; 9 2]; %controlLine1 = [1 9; 1 2]; */
    /*      lineToFollow2 = [1 9; 2 2]; %controlLine2 = [9 2; 1 2];  */
    /*      lineToFollow3 = [9 9; 2 5]; %controlLine3 = [9 5; 9 2];  */
    /*      lineToFollow4 = [9 5; 5 5]; %controlLine4 = [9 5; 5 5];  */
    /*      lineToFollow5 = [5 5; 5 9]; %controlLine5 = [5 9; 5 5];  */
    /*      lineToFollow6 = [5 1; 9 9]; %controlLine6 = [5 9; 1 9];  */
    /* lineToFollow = lineToFollow1; */
    /*      halfPlane1 =
     * dot([X_bar(1);X_bar(2)]-[lineToFollow1(1,2);lineToFollow1(2,2)],[0 -1]);
     */
    /*      halfPlane2 =
     * dot([X_bar(1);X_bar(2)]-[lineToFollow2(1,2);lineToFollow2(2,2)],[1 0]);
     */
    /*      halfPlane3 =
     * dot([X_bar(1);X_bar(2)]-[lineToFollow3(1,2);lineToFollow3(2,2)],[0 1]);
     */
    /*      halfPlane4 =
     * dot([X_bar(1);X_bar(2)]-[lineToFollow4(1,2);lineToFollow4(2,2)],[-1 0]);
     */
    /*      halfPlane5 =
     * dot([X_bar(1);X_bar(2)]-[lineToFollow5(1,2);lineToFollow5(2,2)],[0 1]);
     */
    /*      halfPlane6 =
     * dot([X_bar(1);X_bar(2)]-[lineToFollow6(1,2);lineToFollow6(2,2)],[-1 0]);
     */
    /*      if halfPlane1 > 0 && halfPlane2 < 0 */
    /*          lineToFollow = lineToFollow2; */
    /*          halfPlane2 =
     * dot([X_bar(1);X_bar(2)]-[lineToFollow2(1,2);lineToFollow2(2,2)],[1 0]);
     */
    /*      elseif halfPlane2 > 0 && halfPlane3 < 0 */
    /*          lineToFollow = lineToFollow3; */
    /*      elseif halfPlane3 > 0 && halfPlane4 < 0 */
    /*          lineToFollow = lineToFollow4; */
    /*      elseif halfPlane4 > 0 && halfPlane5 < 0 && halfPlane6 < 0 */
    /*          lineToFollow = lineToFollow5; */
    /*      elseif halfPlane5 > 0 && halfPlane6 < 0 */
    /*          lineToFollow = lineToFollow6; */
    /*      elseif halfPlane1 < 0 && halfPlane6 > 0 */
    /*          lineToFollow = lineToFollow1; */
    /*      end */
    /* create the transformation matrix world to line */
    scale = X_bar[0];
    absxk = X_bar[1];
    for (controlIndex = 0; controlIndex < 3; controlIndex++) {
      D[controlIndex] = ((double)a[controlIndex] * scale +
                         (double)a[controlIndex + 3] * absxk) +
                        (double)a[controlIndex + 6];
    }
    /* set the steering angle with PD controller to steer towards line */
    U[1] = D[1] * -0.4 + -0.5 * ((D[1] - b_oldD) / 0.01);
    /* m/s/s */
    U[0] = 1.0;
    /* velocity */
    b_oldD = D[1];
  }
}

void Control_initialize(void)
{
  controlCircle_init();
  controlLine_init();
  isInitialized_Control = true;
}

void Control_terminate(void)
{
  /* (no terminate code required) */
  isInitialized_Control = false;
}

/* End of code generation (Control.c) */
