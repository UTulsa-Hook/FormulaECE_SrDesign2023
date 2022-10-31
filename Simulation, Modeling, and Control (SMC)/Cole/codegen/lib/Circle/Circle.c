/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Circle.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 23-Oct-2022 14:33:48
 */

/* Include Files */
#include "Circle.h"
#include <math.h>
#include <string.h>

/* Variable Definitions */
static double oldD;
static double integralFactor;

double Array[117];
double Index;
double dt;
double velocity;
static boolean_T isInitialized_Circle = false;

/* Function Declarations */
static void Circle_init(void);

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
static void Circle_init(void)
{
  oldD = 0.0;
  integralFactor = 0.0;
}

/*
 * Arguments    : const double XBar[3]
 *                double resetIntegral
 *                double U[2]
 * Return Type  : void
 */
void Circle(const double XBar[3], double resetIntegral, double U[2])
{
  double Rcar;
  double absxk;
  double ki;
  double scale;
  double t;
  if (!isInitialized_Circle) {
    Circle_initialize();
  }
  if (resetIntegral == 1.0) {
    integralFactor = 0.0;
  }
  scale = 3.3121686421112381E-170;
  absxk = fabs(Array[(int)Index + 12] - XBar[0]);
  if (absxk > 3.3121686421112381E-170) {
    Rcar = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    Rcar = t * t;
  }
  absxk = fabs(Array[(int)Index + 25] - XBar[1]);
  if (absxk > scale) {
    t = scale / absxk;
    Rcar = Rcar * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    Rcar += t * t;
  }
  Rcar = scale * sqrt(Rcar);
  absxk = Rcar - Array[(int)Index + 38];
  if (Array[(int)Index + 51] == 0.0) {
    t = -0.4;
    Rcar = -0.5;
    ki = -1.5;
  } else {
    t = 0.4;
    Rcar = 0.5;
    ki = 1.5;
  }
  if (resetIntegral == 1.0) {
    scale = 0.0;
  } else {
    scale = (absxk - oldD) / dt;
  }
  /* set the steering angle with PID controller to steer towards line */
  U[1] = (absxk * t + integralFactor * ki) + Rcar * scale;
  U[0] = velocity;
  oldD = absxk;
  integralFactor += absxk * dt;
  /* Attempt to plot failed */
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Circle_initialize(void)
{
  static const double dv[117] = {
      1.0,  0.0, 1.0, 1.0, 0.0,  1.0,  0.0,  1.0,  0.0, 1.0, 0.0,  1.0,  0.0,
      1.0,  3.0, 3.0, 6.0, 9.0,  11.0, 9.5,  8.0,  5.0, 5.0, 9.0,  9.0,  2.0,
      9.0,  3.0, 1.0, 1.0, 3.0,  3.0,  5.0,  4.0,  6.0, 8.0, 9.5,  11.0, 10.0,
      1.0,  2.0, 6.0, 9.0, 2.0,  11.0, 1.5,  5.0,  2.0, 9.0, 1.5,  2.0,  1.0,
      3.0,  1.0, 1.0, 1.0, 1.0,  5.0,  1.0,  4.0,  0.0, 8.0, 1.0,  11.0, 1.0,
      0.0,  1.0, 1.0, 1.0, 0.0,  0.0,  0.0,  -1.0, 0.0, 1.0, -1.0, -1.0, 0.0,
      -1.0, 0.0, 0.0, 0.0, 1.0,  1.0,  -1.0, 0.0,  1.0, 0.0, 0.0,  0.0,  -1.0,
      1.0,  3.0, 6.0, 9.0, 11.0, 11.0, 8.0,  5.0,  5.0, 9.0, 9.0,  2.0,  1.0,
      3.0,  1.0, 1.0, 1.0, 3.0,  5.0,  5.0,  4.0,  7.9, 8.0, 11.0, 11.0, 10.0};
  memcpy(&Array[0], &dv[0], 117U * sizeof(double));
  velocity = 2.0;
  dt = 0.01;
  Index = 6.0;
  Circle_init();
  isInitialized_Circle = true;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Circle_terminate(void)
{
  isInitialized_Circle = false;
}

/*
 * File trailer for Circle.c
 *
 * [EOF]
 */
