/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: AutoCodeControl.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 23-Oct-2022 18:35:10
 */

#ifndef AUTOCODECONTROL_H
#define AUTOCODECONTROL_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void AutoCodeInitialize(double X[3], double U[2]);
extern void AutoCodeEstimatePos(double X[3], double U[2]);
extern double AutoCodeCheckHalfPlane(double X[3]);
extern void AutoCodeControl(double X[3], double U[2]);
extern void AutoCodeControlCircle(double X[3], double U[2], int resetIntegral);
extern void AutoCodeControlLine(double X[3], double U[2]);
extern void AutoCodeSetMotorPWM(double U[2], float PWM[2]);
extern void AutoCodeUpdatePosPozyx(double X[3], double pozyxInput[2], int counter);
extern void AutoCodeTopLevel(void);
#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for AutoCodeControl.h
 *
 * [EOF]
 */
