void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->_TMP_ADD10_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SEL15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,_TMP_EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,)));
  __SET_VAR(data__->,_TMP_SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (UINT)__GET_VAR(data__->_TMP_ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->_TMP_SEL15_OUT,));
  __SET_VAR(data__->,_TMP_AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->_TMP_AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





static inline BOOL __PART3_EQ__BOOL__UINT1(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART3 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ1_ENO,);
  __res = EQ__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ1_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __PART3_MOVE__UINT__UINT2(BOOL EN,
  UINT IN,
  PART3 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE42_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE42_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PART3_EQ__BOOL__UINT3(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART3 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ4_ENO,);
  __res = EQ__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ4_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __PART3_MOVE__UINT__UINT4(BOOL EN,
  UINT IN,
  PART3 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE47_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE47_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PART3_EQ__BOOL__UINT5(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART3 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ7_ENO,);
  __res = EQ__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ7_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __PART3_MOVE__UINT__UINT6(BOOL EN,
  UINT IN,
  PART3 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE50_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE50_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PART3_EQ__BOOL__UINT7(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART3 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ10_ENO,);
  __res = EQ__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ10_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __PART3_MOVE__UINT__UINT8(BOOL EN,
  UINT IN,
  PART3 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE53_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE53_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PART3_EQ__BOOL__UINT9(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART3 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ13_ENO,);
  __res = EQ__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ13_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __PART3_MOVE__UINT__UINT10(BOOL EN,
  UINT IN,
  PART3 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE56_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE56_ENO,,__TMP_ENO);
  return __res;
}

void PART3_init__(PART3 *data__, BOOL retain) {
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->WAIT_FOR_REQUEST,0,retain)
  __INIT_VAR(data__->WAIT_FOR_TRAFFIC,1,retain)
  __INIT_VAR(data__->SLOW_CARS,2,retain)
  __INIT_VAR(data__->PED_XING,3,retain)
  __INIT_VAR(data__->ALL_RED,4,retain)
  __INIT_VAR(data__->CAR_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PED_BUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAR_RED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAR_YELLOW,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAR_GREEN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PED_RED,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PED_GREEN,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->YELLOW_DELAY,__time_to_timespec(1, 0, 3, 0, 0, 0),retain)
  __INIT_VAR(data__->PED_XING_DELAY,__time_to_timespec(1, 0, 15, 0, 0, 0),retain)
  __INIT_VAR(data__->ALL_RED_DELAY,__time_to_timespec(1, 0, 1, 0, 0, 0),retain)
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  __INIT_VAR(data__->_TMP_EQ1_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ1_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE42_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE42_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ4_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ4_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE47_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE47_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ7_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ7_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE50_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE50_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ10_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ10_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE53_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE53_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ13_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE56_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE56_OUT,0,retain)
}

// Code part
void PART3_body__(PART3 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_EQ1_OUT,,__PART3_EQ__BOOL__UINT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->WAIT_FOR_REQUEST,),
    data__));
  __SET_VAR(data__->,CAR_GREEN,,__GET_VAR(data__->_TMP_EQ1_OUT,));
  __SET_VAR(data__->,CAR_YELLOW,,!(__GET_VAR(data__->_TMP_EQ1_OUT,)));
  __SET_VAR(data__->,CAR_RED,,!(__GET_VAR(data__->_TMP_EQ1_OUT,)));
  __SET_VAR(data__->,PED_GREEN,,!(__GET_VAR(data__->_TMP_EQ1_OUT,)));
  __SET_VAR(data__->,PED_RED,,__GET_VAR(data__->_TMP_EQ1_OUT,));
  __SET_VAR(data__->,_TMP_MOVE42_OUT,,__PART3_MOVE__UINT__UINT2(
    (BOOL)(__GET_VAR(data__->PED_BUTTON,) && __GET_VAR(data__->_TMP_EQ1_OUT,)),
    (UINT)__GET_VAR(data__->WAIT_FOR_TRAFFIC,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE42_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE42_OUT,));
  };
  __SET_VAR(data__->,_TMP_EQ4_OUT,,__PART3_EQ__BOOL__UINT3(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->WAIT_FOR_TRAFFIC,),
    data__));
  __SET_VAR(data__->,CAR_GREEN,,__GET_VAR(data__->_TMP_EQ4_OUT,));
  __SET_VAR(data__->,CAR_YELLOW,,!(__GET_VAR(data__->_TMP_EQ4_OUT,)));
  __SET_VAR(data__->,CAR_RED,,!(__GET_VAR(data__->_TMP_EQ4_OUT,)));
  __SET_VAR(data__->,PED_GREEN,,!(__GET_VAR(data__->_TMP_EQ4_OUT,)));
  __SET_VAR(data__->,PED_RED,,__GET_VAR(data__->_TMP_EQ4_OUT,));
  __SET_VAR(data__->,_TMP_MOVE47_OUT,,__PART3_MOVE__UINT__UINT4(
    (BOOL)(!(__GET_VAR(data__->CAR_SENSOR,)) && __GET_VAR(data__->_TMP_EQ4_OUT,)),
    (UINT)__GET_VAR(data__->SLOW_CARS,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE47_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE47_OUT,));
  };
  __SET_VAR(data__->,_TMP_EQ7_OUT,,__PART3_EQ__BOOL__UINT5(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->SLOW_CARS,),
    data__));
  __SET_VAR(data__->,CAR_GREEN,,!(__GET_VAR(data__->_TMP_EQ7_OUT,)));
  __SET_VAR(data__->,CAR_YELLOW,,__GET_VAR(data__->_TMP_EQ7_OUT,));
  __SET_VAR(data__->,CAR_RED,,!(__GET_VAR(data__->_TMP_EQ7_OUT,)));
  __SET_VAR(data__->,PED_GREEN,,!(__GET_VAR(data__->_TMP_EQ7_OUT,)));
  __SET_VAR(data__->,PED_RED,,__GET_VAR(data__->_TMP_EQ7_OUT,));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->_TMP_EQ7_OUT,));
  __SET_VAR(data__->TON0.,PT,,__GET_VAR(data__->YELLOW_DELAY,));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,_TMP_MOVE50_OUT,,__PART3_MOVE__UINT__UINT6(
    (BOOL)__GET_VAR(data__->TON0.Q,),
    (UINT)__GET_VAR(data__->PED_XING,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE50_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE50_OUT,));
  };
  __SET_VAR(data__->,_TMP_EQ10_OUT,,__PART3_EQ__BOOL__UINT7(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->PED_XING,),
    data__));
  __SET_VAR(data__->,CAR_GREEN,,!(__GET_VAR(data__->_TMP_EQ10_OUT,)));
  __SET_VAR(data__->,CAR_YELLOW,,!(__GET_VAR(data__->_TMP_EQ10_OUT,)));
  __SET_VAR(data__->,CAR_RED,,__GET_VAR(data__->_TMP_EQ10_OUT,));
  __SET_VAR(data__->,PED_GREEN,,__GET_VAR(data__->_TMP_EQ10_OUT,));
  __SET_VAR(data__->,PED_RED,,!(__GET_VAR(data__->_TMP_EQ10_OUT,)));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->_TMP_EQ10_OUT,));
  __SET_VAR(data__->TON1.,PT,,__GET_VAR(data__->PED_XING_DELAY,));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,_TMP_MOVE53_OUT,,__PART3_MOVE__UINT__UINT8(
    (BOOL)__GET_VAR(data__->TON1.Q,),
    (UINT)__GET_VAR(data__->ALL_RED,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE53_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE53_OUT,));
  };
  __SET_VAR(data__->,_TMP_EQ13_OUT,,__PART3_EQ__BOOL__UINT9(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->ALL_RED,),
    data__));
  __SET_VAR(data__->,CAR_GREEN,,!(__GET_VAR(data__->_TMP_EQ13_OUT,)));
  __SET_VAR(data__->,CAR_YELLOW,,!(__GET_VAR(data__->_TMP_EQ13_OUT,)));
  __SET_VAR(data__->,CAR_RED,,__GET_VAR(data__->_TMP_EQ13_OUT,));
  __SET_VAR(data__->,PED_GREEN,,!(__GET_VAR(data__->_TMP_EQ13_OUT,)));
  __SET_VAR(data__->,PED_RED,,__GET_VAR(data__->_TMP_EQ13_OUT,));
  __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->_TMP_EQ13_OUT,));
  __SET_VAR(data__->TON2.,PT,,__GET_VAR(data__->ALL_RED_DELAY,));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->,_TMP_MOVE56_OUT,,__PART3_MOVE__UINT__UINT10(
    (BOOL)__GET_VAR(data__->TON2.Q,),
    (UINT)__GET_VAR(data__->WAIT_FOR_REQUEST,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE56_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE56_OUT,));
  };

  goto __end;

__end:
  return;
} // PART3_body__() 





