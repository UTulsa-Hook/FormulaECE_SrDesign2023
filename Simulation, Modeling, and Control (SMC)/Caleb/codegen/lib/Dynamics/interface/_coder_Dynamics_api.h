/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Dynamics_api.h
 *
 * Code generation for function 'Dynamics'
 *
 */

#ifndef _CODER_DYNAMICS_API_H
#define _CODER_DYNAMICS_API_H

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
void Dynamics(real_T U[2], real_T X[3]);

void Dynamics_api(const mxArray *const prhs[2], const mxArray **plhs);

void Dynamics_atexit(void);

void Dynamics_initialize(void);

void Dynamics_terminate(void);

void Dynamics_xil_shutdown(void);

void Dynamics_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_Dynamics_api.h) */
