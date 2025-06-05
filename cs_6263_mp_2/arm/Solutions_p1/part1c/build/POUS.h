#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM PART1C
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,INPUT0)
  __DECLARE_VAR(BOOL,OUTPUT0)
  __DECLARE_VAR(BOOL,OSCILLATOR)
  TON TON0;
  TOF TOF0;
  CTU CTU0;
  __DECLARE_VAR(BOOL,BOMB)
  __DECLARE_VAR(INT,COUNTUP)
  __DECLARE_VAR(BOOL,TRUEBOOL)
  TON TON1;
  R_TRIG R_TRIG1;

} PART1C;

void PART1C_init__(PART1C *data__, BOOL retain);
// Code part
void PART1C_body__(PART1C *data__);
#endif //__POUS_H
