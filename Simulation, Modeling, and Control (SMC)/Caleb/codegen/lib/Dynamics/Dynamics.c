/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Dynamics.c
 *
 * Code generation for function 'Dynamics'
 *
 */

/* Include files */
#include "Dynamics.h"
#include <math.h>

/* Function Definitions */
void Dynamics(const double U[2], double X[3])
{
  double d;
  /* UNTITLED3 Summary of this function goes here */
  /*    Detailed explanation goes here */
  d = sin(X[2]);
  /* X = X_dot * dt + X */
  X[0] += U[0] * cos(X[2]) * 0.01;
  /* x velocity * dt + current x_location */
  X[1] += U[0] * d * 0.01;
  /* y velocity * dt + current y_location */
  X[2] += U[0] * tan(U[1]) / 0.27 * 0.01;
  /* d_thetaC * dt + current thetaC */
  /* drawPoolEnvironment(); */
  /* drawCar([X(1), X(2)], X(3), U(2), 5); */
}

/* End of code generation (Dynamics.c) */
