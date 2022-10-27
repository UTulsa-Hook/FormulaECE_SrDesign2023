/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Circle_api.c
 *
 * MATLAB Coder version            : 5.4
 * C/C++ source code generated on  : 23-Oct-2022 14:33:48
 */

/* Include Files */
#include "_coder_Circle_api.h"
#include "_coder_Circle_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

static real_T Array[117];

static uint32_T Array_guard;

static real_T Index;

static uint32_T Index_guard;

static real_T dt;

static uint32_T dt_guard;

static real_T velocity;

static uint32_T velocity_guard;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131626U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "Circle",                                             /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static void Circle_once(void);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[117]);

static const mxArray *b_emlrt_marshallOut(const real_T u);

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_Index,
                                 const char_T *identifier);

static const mxArray *c_emlrt_marshallOut(const real_T u[2]);

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *XBar,
                                   const char_T *identifier))[3];

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_Array,
                             const char_T *identifier, real_T y[117]);

static const mxArray *emlrt_marshallOut(const real_T u[117]);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3];

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[117]);

static real_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[3];

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
static void Circle_once(void)
{
  velocity_guard = 0U;
  dt_guard = 0U;
  Index_guard = 0U;
  Array_guard = 0U;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                real_T y[117]
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[117])
{
  g_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real_T u)
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
 *                const mxArray *b_Index
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_Index,
                                 const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(b_Index), &thisId);
  emlrtDestroyArray(&b_Index);
  return y;
}

/*
 * Arguments    : const real_T u[2]
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const real_T u[2])
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
 * Arguments    : const emlrtStack *sp
 *                const mxArray *XBar
 *                const char_T *identifier
 * Return Type  : real_T (*)[3]
 */
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *XBar,
                                   const char_T *identifier))[3]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[3];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(XBar), &thisId);
  emlrtDestroyArray(&XBar);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *b_Array
 *                const char_T *identifier
 *                real_T y[117]
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *b_Array,
                             const char_T *identifier, real_T y[117])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(b_Array), &thisId, y);
  emlrtDestroyArray(&b_Array);
}

/*
 * Arguments    : const real_T u[117]
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u[117])
{
  static const int32_T iv[2] = {13, 9};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 9; b_i++) {
    for (c_i = 0; c_i < 13; c_i++) {
      pData[i + c_i] = u[c_i + 13 * b_i];
    }
    i += 13;
  }
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[3]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[3]
{
  real_T(*y)[3];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                real_T ret[117]
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[117])
{
  static const int32_T dims[2] = {13, 9};
  real_T(*r)[117];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[117])emlrtMxGetData(src);
  for (i = 0; i < 117; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
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
 * Return Type  : real_T (*)[3]
 */
static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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
 * Arguments    : const mxArray * const prhs[2]
 *                const mxArray **plhs
 * Return Type  : void
 */
void Circle_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*XBar)[3];
  real_T(*U)[2];
  real_T resetIntegral;
  st.tls = emlrtRootTLSGlobal;
  U = (real_T(*)[2])mxMalloc(sizeof(real_T[2]));
  /* Marshall function inputs */
  XBar = e_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "XBar");
  resetIntegral =
      c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "resetIntegral");
  /* Marshall in global variables */
  MEXGlobalSyncInFunction(&st);
  /* Invoke the target function */
  Circle(*XBar, resetIntegral, *U);
  /* Marshall out global variables */
  MEXGlobalSyncOutFunction(true);
  /* Marshall function outputs */
  *plhs = c_emlrt_marshallOut(*U);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Circle_atexit(void)
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
  Circle_xil_terminate();
  Circle_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Circle_initialize(void)
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
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    Circle_once();
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void Circle_terminate(void)
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
 * Arguments    : const emlrtStack *sp
 * Return Type  : void
 */
void MEXGlobalSyncInFunction(const emlrtStack *sp)
{
  const mxArray *tmp;
  /* Marshall in global variables */
  tmp = emlrtGetGlobalVariable((const char_T *)"Array");
  if (tmp != NULL) {
    emlrt_marshallIn(sp, tmp, "Array", Array);
    Array_guard = 1U;
  }
  tmp = emlrtGetGlobalVariable((const char_T *)"Index");
  if (tmp != NULL) {
    Index = c_emlrt_marshallIn(sp, tmp, "Index");
    Index_guard = 1U;
  }
  tmp = emlrtGetGlobalVariable((const char_T *)"dt");
  if (tmp != NULL) {
    dt = c_emlrt_marshallIn(sp, tmp, "dt");
    dt_guard = 1U;
  }
  tmp = emlrtGetGlobalVariable((const char_T *)"velocity");
  if (tmp != NULL) {
    velocity = c_emlrt_marshallIn(sp, tmp, "velocity");
    velocity_guard = 1U;
  }
}

/*
 * Arguments    : boolean_T skipDirtyCheck
 * Return Type  : void
 */
void MEXGlobalSyncOutFunction(boolean_T skipDirtyCheck)
{
  /* Marshall out global variables */
  if (skipDirtyCheck || (Array_guard != 0U)) {
    emlrtPutGlobalVariable((const char_T *)"Array", emlrt_marshallOut(Array));
  }
  if (skipDirtyCheck || (Index_guard != 0U)) {
    emlrtPutGlobalVariable((const char_T *)"Index", b_emlrt_marshallOut(Index));
  }
  if (skipDirtyCheck || (dt_guard != 0U)) {
    emlrtPutGlobalVariable((const char_T *)"dt", b_emlrt_marshallOut(dt));
  }
  if (skipDirtyCheck || (velocity_guard != 0U)) {
    emlrtPutGlobalVariable((const char_T *)"velocity",
                           b_emlrt_marshallOut(velocity));
  }
}

/*
 * File trailer for _coder_Circle_api.c
 *
 * [EOF]
 */
