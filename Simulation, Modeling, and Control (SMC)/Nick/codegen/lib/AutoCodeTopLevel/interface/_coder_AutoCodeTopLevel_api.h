/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_AutoCodeTopLevel_api.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 23-Oct-2022 11:05:30
 */

#ifndef _CODER_AUTOCODETOPLEVEL_API_H
#define _CODER_AUTOCODETOPLEVEL_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
real_T AutoCodeCheckHalfPlane(real_T X_bar[3]);

void AutoCodeCheckHalfPlane_api(const mxArray *prhs, const mxArray **plhs);

void AutoCodeControl(real_T X[3], real_T U[2]);

void AutoCodeControlCircle(real_T X_bar[3], real_T resetIntegral, real_T U[2]);

void AutoCodeControlCircle_api(const mxArray *const prhs[2],
                               const mxArray **plhs);

void AutoCodeControlLine(real_T X[3], real_T U[2]);

void AutoCodeControlLine_api(const mxArray *prhs, const mxArray **plhs);

void AutoCodeControl_api(const mxArray *prhs, const mxArray **plhs);

void AutoCodeEstimatePos(real_T X[3], real_T U[2]);

void AutoCodeEstimatePos_api(const mxArray *const prhs[2],
                             const mxArray **plhs);

void AutoCodeInitialize(real_T X[3], real_T U[2]);

void AutoCodeInitialize_api(int32_T nlhs, const mxArray *plhs[2]);

void AutoCodeSetMotorPWM(real_T U[2], real_T PWM[2]);

void AutoCodeSetMotorPWM_api(const mxArray *prhs, const mxArray **plhs);

void AutoCodeTopLevel(void);

void AutoCodeTopLevel_api(void);

void AutoCodeTopLevel_atexit(void);

void AutoCodeTopLevel_initialize(void);

void AutoCodeTopLevel_terminate(void);

void AutoCodeTopLevel_xil_shutdown(void);

void AutoCodeTopLevel_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_AutoCodeTopLevel_api.h
 *
 * [EOF]
 */
