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





static inline BOOL __PART4_EQ__BOOL__UINT1(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART4 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ3_ENO,);
  __res = EQ__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ3_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __PART4_MOVE__UINT__UINT2(BOOL EN,
  UINT IN,
  PART4 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE41_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE41_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PART4_EQ__BOOL__UINT3(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART4 *data__)
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

static inline UINT __PART4_MOVE__UINT__UINT4(BOOL EN,
  UINT IN,
  PART4 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE11_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE11_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PART4_EQ__BOOL__UINT5(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART4 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ17_ENO,);
  __res = EQ__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ17_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __PART4_MOVE__UINT__UINT6(BOOL EN,
  UINT IN,
  PART4 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE19_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE19_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PART4_EQ__BOOL__UINT7(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART4 *data__)
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

static inline UINT __PART4_MOVE__UINT__UINT8(BOOL EN,
  UINT IN,
  PART4 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE24_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE24_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __PART4_MOVE__UINT__UINT9(BOOL EN,
  UINT IN,
  PART4 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE27_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE27_ENO,,__TMP_ENO);
  return __res;
}

void PART4_init__(PART4 *data__, BOOL retain) {
  __INIT_VAR(data__->MAIN_SW_BTN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAR_SENSOR_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAR_SENSOR_2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GREEN_ENTR_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->GREEP_PKG_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RED_ENTR_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RED_PKG_LIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MAIN_SW_INDICATOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->STATE_SYSTEM_OFF,0,retain)
  __INIT_VAR(data__->STATE_NO_CARS,1,retain)
  __INIT_VAR(data__->STATE_CAR_ENTERING,2,retain)
  __INIT_VAR(data__->STATE_CAR_EXITING,3,retain)
  __INIT_VAR(data__->SYSTEM_OFF,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->NO_CARS,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAR_ENTERING,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CAR_EXITING,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ3_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ3_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE41_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE41_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ10_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ10_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE11_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE11_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ17_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ17_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE19_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE19_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ7_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ7_OUT,__BOOL_LITERAL(FALSE),retain)
  F_TRIG_init__(&data__->F_TRIG1,retain);
  __INIT_VAR(data__->_TMP_MOVE24_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE24_OUT,0,retain)
  F_TRIG_init__(&data__->F_TRIG2,retain);
  __INIT_VAR(data__->_TMP_MOVE27_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE27_OUT,0,retain)
}

// Code part
void PART4_body__(PART4 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_EQ3_OUT,,__PART4_EQ__BOOL__UINT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->STATE_SYSTEM_OFF,),
    data__));
  __SET_VAR(data__->,SYSTEM_OFF,,__GET_VAR(data__->_TMP_EQ3_OUT,));
  __SET_VAR(data__->,_TMP_MOVE41_OUT,,__PART4_MOVE__UINT__UINT2(
    (BOOL)(__GET_VAR(data__->MAIN_SW_BTN,) && __GET_VAR(data__->SYSTEM_OFF,)),
    (UINT)__GET_VAR(data__->STATE_NO_CARS,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE41_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE41_OUT,));
  };
  __SET_VAR(data__->,MAIN_SW_INDICATOR,,!(__GET_VAR(data__->SYSTEM_OFF,)));
  __SET_VAR(data__->,_TMP_EQ10_OUT,,__PART4_EQ__BOOL__UINT3(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->STATE_NO_CARS,),
    data__));
  __SET_VAR(data__->,NO_CARS,,__GET_VAR(data__->_TMP_EQ10_OUT,));
  __SET_VAR(data__->,GREEN_ENTR_LIGHT,,(!(__GET_VAR(data__->SYSTEM_OFF,)) && __GET_VAR(data__->NO_CARS,)));
  __SET_VAR(data__->,GREEP_PKG_LIGHT,,(!(__GET_VAR(data__->SYSTEM_OFF,)) && __GET_VAR(data__->NO_CARS,)));
  __SET_VAR(data__->,RED_ENTR_LIGHT,,!(__GET_VAR(data__->NO_CARS,)));
  __SET_VAR(data__->,RED_PKG_LIGHT,,!(__GET_VAR(data__->NO_CARS,)));
  __SET_VAR(data__->,_TMP_MOVE11_OUT,,__PART4_MOVE__UINT__UINT4(
    (BOOL)(__GET_VAR(data__->CAR_SENSOR_1,) && __GET_VAR(data__->NO_CARS,)),
    (UINT)__GET_VAR(data__->STATE_CAR_ENTERING,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE11_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE11_OUT,));
  };
  __SET_VAR(data__->,_TMP_EQ17_OUT,,__PART4_EQ__BOOL__UINT5(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->STATE_CAR_ENTERING,),
    data__));
  __SET_VAR(data__->,CAR_ENTERING,,__GET_VAR(data__->_TMP_EQ17_OUT,));
  __SET_VAR(data__->,_TMP_MOVE19_OUT,,__PART4_MOVE__UINT__UINT6(
    (BOOL)(__GET_VAR(data__->CAR_SENSOR_2,) && __GET_VAR(data__->NO_CARS,)),
    (UINT)__GET_VAR(data__->STATE_CAR_EXITING,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE19_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE19_OUT,));
  };
  __SET_VAR(data__->,_TMP_EQ7_OUT,,__PART4_EQ__BOOL__UINT7(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->STATE_CAR_EXITING,),
    data__));
  __SET_VAR(data__->,CAR_EXITING,,__GET_VAR(data__->_TMP_EQ7_OUT,));
  __SET_VAR(data__->F_TRIG1.,CLK,,__GET_VAR(data__->CAR_SENSOR_2,));
  F_TRIG_body__(&data__->F_TRIG1);
  __SET_VAR(data__->,_TMP_MOVE24_OUT,,__PART4_MOVE__UINT__UINT8(
    (BOOL)(__GET_VAR(data__->F_TRIG1.Q,) && __GET_VAR(data__->CAR_ENTERING,)),
    (UINT)__GET_VAR(data__->STATE_NO_CARS,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE24_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE24_OUT,));
  };
  __SET_VAR(data__->F_TRIG2.,CLK,,__GET_VAR(data__->CAR_SENSOR_1,));
  F_TRIG_body__(&data__->F_TRIG2);
  __SET_VAR(data__->,_TMP_MOVE27_OUT,,__PART4_MOVE__UINT__UINT9(
    (BOOL)(__GET_VAR(data__->F_TRIG2.Q,) && __GET_VAR(data__->CAR_EXITING,)),
    (UINT)__GET_VAR(data__->STATE_NO_CARS,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE27_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE27_OUT,));
  };

  goto __end;

__end:
  return;
} // PART4_body__() 





