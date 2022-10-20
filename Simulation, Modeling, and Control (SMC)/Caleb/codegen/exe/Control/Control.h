/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Control.h
 *
 * Code generation for function 'Control'
 *
 */

#ifndef CONTROL_H
#define CONTROL_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern double Control(const double X_bar[3]);

extern void Control_initialize(void);

extern void Control_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (Control.h) */
