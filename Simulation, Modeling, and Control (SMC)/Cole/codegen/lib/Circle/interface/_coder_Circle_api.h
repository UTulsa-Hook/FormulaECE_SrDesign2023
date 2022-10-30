/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Circle_api.h
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 23-Oct-2022 14:33:48
 */

#ifndef _CODER_CIRCLE_API_H
#define _CODER_CIRCLE_API_H

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
void Circle(real_T XBar[3], real_T resetIntegral, real_T U[2]);

void Circle_api(const mxArray *const prhs[2], const mxArray **plhs);

void Circle_atexit(void);

void Circle_initialize(void);

void Circle_terminate(void);

void Circle_xil_shutdown(void);

void Circle_xil_terminate(void);

void MEXGlobalSyncInFunction(const emlrtStack *sp);

void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_Circle_api.h
 *
 * [EOF]
 */
