/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Control_api.h
 *
 * Code generation for function 'Control'
 *
 */

#ifndef _CODER_CONTROL_API_H
#define _CODER_CONTROL_API_H

/* Include files */
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
void Control(real_T X_bar[3], real_T U[2]);

void Control_api(const mxArray *prhs, const mxArray **plhs);

void Control_atexit(void);

void Control_initialize(void);

void Control_terminate(void);

void Control_xil_shutdown(void);

void Control_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_Control_api.h) */
