/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_AutoCodeTopLevel_mex.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 23-Oct-2022 11:05:30
 */

#ifndef _CODER_AUTOCODETOPLEVEL_MEX_H
#define _CODER_AUTOCODETOPLEVEL_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_AutoCodeCheckHalfPlane_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                               int32_T nrhs,
                                               const mxArray *prhs[1]);

void unsafe_AutoCodeControlCircle_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                              int32_T nrhs,
                                              const mxArray *prhs[2]);

void unsafe_AutoCodeControlLine_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                            int32_T nrhs,
                                            const mxArray *prhs[1]);

void unsafe_AutoCodeControl_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                        int32_T nrhs, const mxArray *prhs[1]);

void unsafe_AutoCodeEstimatePos_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                            int32_T nrhs,
                                            const mxArray *prhs[2]);

void unsafe_AutoCodeInitialize_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                           int32_T nrhs);

void unsafe_AutoCodeSetMotorPWM_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                            int32_T nrhs,
                                            const mxArray *prhs[1]);

void unsafe_AutoCodeTopLevel_mexFunction(int32_T nlhs, int32_T nrhs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_AutoCodeTopLevel_mex.h
 *
 * [EOF]
 */
