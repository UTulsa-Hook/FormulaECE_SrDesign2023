/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: Circle.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 23-Oct-2022 14:33:48
 */

#ifndef CIRCLE_H
#define CIRCLE_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

/* Variable Declarations */
extern double Array[117];
extern double Index;
extern double dt;
extern double velocity;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void Circle(const double XBar[3], double resetIntegral, double U[2]);

extern void Circle_initialize(void);

extern void Circle_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for Circle.h
 *
 * [EOF]
 */
