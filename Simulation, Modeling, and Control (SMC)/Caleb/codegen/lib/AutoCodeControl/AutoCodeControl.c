/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: AutoCodeControl.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 24-Oct-2022 14:58:55
 */

/* Include Files */
#include "AutoCodeControl.h"
#include <math.h>

/* Function Definitions */
/*
 * UNTITLED6 Summary of this function goes here
 *    Detailed explanation goes here
 *
 * Arguments    : const double X[3]
 *                double U[2]
 * Return Type  : void
 */
void AutoCodeControl(const double X[3], double U[2])
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
  controlIndex = 0;
  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
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
  if (controlArray[controlIndex] == 0.0) {
    /* UNTITLED7 Summary of this function goes here */
    /*    Detailed explanation goes here */
    /* persistent */
    /*  persistent */
    scale = 3.3121686421112381E-170;
    absxk = fabs(1.0 - X[0]);
    if (absxk > 3.3121686421112381E-170) {
      Rcar = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      Rcar = t * t;
    }
    absxk = fabs(9.0 - X[1]);
    if (absxk > scale) {
      t = scale / absxk;
      Rcar = Rcar * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      Rcar += t * t;
    }
    Rcar = scale * sqrt(Rcar);
    /* ki = 0.5; % for testing */
    if (resetIntegral == 1) {
      absxk = 0.0;
    } else {
      absxk = (Rcar - 1.0) / 0.1;
    }
    /* set the steering angle with PD controller to steer towards line */
    U[1] = (Rcar - 1.0) * 0.4 + 0.5 * absxk;
    U[0] = 1.0;
    /* velocity */
    /* persistent */
  } else {
    /*  persistent */
    /* create the transformation matrix world to line */
    absxk = X[0];
    scale = X[1];
    for (controlIndex = 0; controlIndex < 3; controlIndex++) {
      D[controlIndex] = ((double)a[controlIndex] * absxk +
                         (double)a[controlIndex + 3] * scale) +
                        (double)a[controlIndex + 6];
    }
    /* -0.4 */
    /*  -0.5 */
    /* set the steering angle with PD controller to steer towards line */
    U[1] = D[1] * -0.4 + -0.5 * (D[1] / 0.1);
    U[0] = 1.0;
    /* velocity */
    /* persistent */
  }
}

/*
 * File trailer for AutoCodeControl.c
 *
 * [EOF]
 */
