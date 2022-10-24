/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 23-Oct-2022 11:05:30
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "AutoCodeTopLevel.h"

/* Function Declarations */
static void argInit_1x2_real_T(double result[2]);

static void argInit_1x3_real_T(double result[3]);

static double argInit_real_T(void);

static void main_AutoCodeCheckHalfPlane(void);

static void main_AutoCodeControl(void);

static void main_AutoCodeControlCircle(void);

static void main_AutoCodeControlLine(void);

static void main_AutoCodeEstimatePos(void);

static void main_AutoCodeInitialize(void);

static void main_AutoCodeSetMotorPWM(void);

static void main_AutoCodeTopLevel(void);

/* Function Definitions */
/*
 * Arguments    : double result[2]
 * Return Type  : void
 */
static void argInit_1x2_real_T(double result[2])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : double result[3]
 * Return Type  : void
 */
static void argInit_1x3_real_T(double result[3])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 3; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_AutoCodeCheckHalfPlane(void)
{
  double b_dv[3];
  double H;
  /* Initialize function 'AutoCodeCheckHalfPlane' input arguments. */
  /* Initialize function input argument 'X_bar'. */
  /* Call the entry-point 'AutoCodeCheckHalfPlane'. */
  argInit_1x3_real_T(b_dv);
  H = AutoCodeCheckHalfPlane(b_dv);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_AutoCodeControl(void)
{
  double b_dv[3];
  double U[2];
  /* Initialize function 'AutoCodeControl' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'AutoCodeControl'. */
  argInit_1x3_real_T(b_dv);
  AutoCodeControl(b_dv, U);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_AutoCodeControlCircle(void)
{
  double b_dv[3];
  double U[2];
  /* Initialize function 'AutoCodeControlCircle' input arguments. */
  /* Initialize function input argument 'X_bar'. */
  /* Call the entry-point 'AutoCodeControlCircle'. */
  argInit_1x3_real_T(b_dv);
  AutoCodeControlCircle(b_dv, argInit_real_T(), U);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_AutoCodeControlLine(void)
{
  double b_dv[3];
  double U[2];
  /* Initialize function 'AutoCodeControlLine' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'AutoCodeControlLine'. */
  argInit_1x3_real_T(b_dv);
  AutoCodeControlLine(b_dv, U);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_AutoCodeEstimatePos(void)
{
  double X[3];
  double b_dv[2];
  /* Initialize function 'AutoCodeEstimatePos' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Initialize function input argument 'U'. */
  /* Call the entry-point 'AutoCodeEstimatePos'. */
  argInit_1x3_real_T(X);
  argInit_1x2_real_T(b_dv);
  AutoCodeEstimatePos(X, b_dv);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_AutoCodeInitialize(void)
{
  double X[3];
  double U[2];
  /* Call the entry-point 'AutoCodeInitialize'. */
  AutoCodeInitialize(X, U);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_AutoCodeSetMotorPWM(void)
{
  double PWM[2];
  double b_dv[2];
  /* Initialize function 'AutoCodeSetMotorPWM' input arguments. */
  /* Initialize function input argument 'U'. */
  /* Call the entry-point 'AutoCodeSetMotorPWM'. */
  argInit_1x2_real_T(b_dv);
  AutoCodeSetMotorPWM(b_dv, PWM);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_AutoCodeTopLevel(void)
{
  /* Call the entry-point 'AutoCodeTopLevel'. */
  AutoCodeTopLevel();
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_AutoCodeCheckHalfPlane();
  main_AutoCodeControl();
  main_AutoCodeControlCircle();
  main_AutoCodeControlLine();
  main_AutoCodeEstimatePos();
  main_AutoCodeInitialize();
  main_AutoCodeSetMotorPWM();
  main_AutoCodeTopLevel();
  /* Terminate the application.
You do not need to do this more than one time. */
  AutoCodeTopLevel_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
