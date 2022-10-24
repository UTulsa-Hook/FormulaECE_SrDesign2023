/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_AutoCodeTopLevel_api.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 23-Oct-2022 11:05:30
 */

/* Include Files */
#include "_coder_AutoCodeTopLevel_api.h"
#include "_coder_AutoCodeTopLevel_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131611U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "AutoCodeTopLevel",                                   /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static const mxArray *b_emlrt_marshallOut(const real_T u[2]);

static real_T c_emlrt_marshallIn(const emlrtStack *sp,
                                 const mxArray *resetIntegral,
                                 const char_T *identifier);

static void c_emlrt_marshallOut(const real_T u[3], const mxArray *y);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *d_emlrt_marshallOut(const real_T u[3]);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *U,
                                   const char_T *identifier))[2];

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *X_bar,
                                 const char_T *identifier))[3];

static const mxArray *emlrt_marshallOut(const real_T u);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2];

static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2];

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[3]
 */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u[2]
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real_T u[2])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {1, 2};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *resetIntegral
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp,
                                 const mxArray *resetIntegral,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(resetIntegral), &thisId);
  emlrtDestroyArray(&resetIntegral);
  return y;
}

/*
 * Arguments    : const real_T u[3]
 *                const mxArray *y
 * Return Type  : void
 */
static void c_emlrt_marshallOut(const real_T u[3], const mxArray *y)
{
  static const int32_T iv[2] = {1, 3};
  emlrtMxSetData((mxArray *)y, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)y, &iv[0], 2);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u[3]
 * Return Type  : const mxArray *
 */
static const mxArray *d_emlrt_marshallOut(const real_T u[3])
{
  static const int32_T i = 0;
  static const int32_T i1 = 3;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *U
 *                const char_T *identifier
 * Return Type  : real_T (*)[2]
 */
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *U,
                                   const char_T *identifier))[2]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(U), &thisId);
  emlrtDestroyArray(&U);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *X_bar
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *X_bar,
                                 const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(X_bar), &thisId);
  emlrtDestroyArray(&X_bar);
  return y;
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[2]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2]
{
  real_T(*y)[2];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[3]
 */
static real_T (*g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3]
{
  static const int32_T dims[2] = {1, 3};
  real_T(*ret)[3];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[3])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[2]
 */
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2]
{
  static const int32_T dims[2] = {1, 2};
  real_T(*ret)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[2])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void AutoCodeCheckHalfPlane_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*X_bar)[3];
  real_T H;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  X_bar = emlrt_marshallIn(&st, emlrtAlias(prhs), "X_bar");
  /* Invoke the target function */
  H = AutoCodeCheckHalfPlane(*X_bar);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(H);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray **plhs
 * Return Type  : void
 */
void AutoCodeControlCircle_api(const mxArray *const prhs[2],
                               const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*X_bar)[3];
  real_T(*U)[2];
  real_T resetIntegral;
  st.tls = emlrtRootTLSGlobal;
  U = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  /* Marshall function inputs */
  X_bar = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "X_bar");
  resetIntegral =
      c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "resetIntegral");
  /* Invoke the target function */
  AutoCodeControlCircle(*X_bar, resetIntegral, *U);
  /* Marshall function outputs */
  *plhs = b_emlrt_marshallOut(*U);
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void AutoCodeControlLine_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*X)[3];
  real_T(*U)[2];
  st.tls = emlrtRootTLSGlobal;
  U = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  /* Marshall function inputs */
  X = emlrt_marshallIn(&st, emlrtAlias(prhs), "X");
  /* Invoke the target function */
  AutoCodeControlLine(*X, *U);
  /* Marshall function outputs */
  *plhs = b_emlrt_marshallOut(*U);
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void AutoCodeControl_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*X)[3];
  real_T(*U)[2];
  st.tls = emlrtRootTLSGlobal;
  U = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  /* Marshall function inputs */
  X = emlrt_marshallIn(&st, emlrtAlias(prhs), "X");
  /* Invoke the target function */
  AutoCodeControl(*X, *U);
  /* Marshall function outputs */
  *plhs = b_emlrt_marshallOut(*U);
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray **plhs
 * Return Type  : void
 */
void AutoCodeEstimatePos_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *prhs_copy_idx_0;
  real_T(*X)[3];
  real_T(*U)[2];
  st.tls = emlrtRootTLSGlobal;
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs[0], 0, true, -1);
  /* Marshall function inputs */
  X = emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "X");
  U = e_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "U");
  /* Invoke the target function */
  AutoCodeEstimatePos(*X, *U);
  /* Marshall function outputs */
  c_emlrt_marshallOut(*X, prhs_copy_idx_0);
  *plhs = prhs_copy_idx_0;
}

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[2]
 * Return Type  : void
 */
void AutoCodeInitialize_api(int32_T nlhs, const mxArray *plhs[2])
{
  real_T(*X)[3];
  real_T(*U)[2];
  X = (real_T(*)[3])mxMalloc(sizeof(real_T[3]));
  U = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  /* Invoke the target function */
  AutoCodeInitialize(*X, *U);
  /* Marshall function outputs */
  plhs[0] = d_emlrt_marshallOut(*X);
  if (nlhs > 1) {
    plhs[1] = b_emlrt_marshallOut(*U);
  }
}

/*
 * Arguments    : const mxArray *prhs
 *                const mxArray **plhs
 * Return Type  : void
 */
void AutoCodeSetMotorPWM_api(const mxArray *prhs, const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*PWM)[2];
  real_T(*U)[2];
  st.tls = emlrtRootTLSGlobal;
  PWM = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  /* Marshall function inputs */
  U = e_emlrt_marshallIn(&st, emlrtAlias(prhs), "U");
  /* Invoke the target function */
  AutoCodeSetMotorPWM(*U, *PWM);
  /* Marshall function outputs */
  *plhs = b_emlrt_marshallOut(*PWM);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void AutoCodeTopLevel_api(void)
{
  /* Invoke the target function */
  AutoCodeTopLevel();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void AutoCodeTopLevel_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  AutoCodeTopLevel_xil_terminate();
  AutoCodeTopLevel_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void AutoCodeTopLevel_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void AutoCodeTopLevel_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_AutoCodeTopLevel_api.c
 *
 * [EOF]
 */
