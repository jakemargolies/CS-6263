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





static inline BOOL __PART3_EQ__BOOL__UINT1(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART3 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ39_ENO,);
  __res = EQ__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ39_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __PART3_MOVE__UINT__UINT2(BOOL EN,
  UINT IN,
  PART3 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE48_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE48_ENO,,__TMP_ENO);
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
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE9_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE9_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PART3_EQ__BOOL__UINT5(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART3 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ12_ENO,);
  __res = EQ__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ12_ENO,,__TMP_ENO);
  return __res;
}

static inline BOOL __PART3_EQ__BOOL__UINT6(BOOL EN,
  UINT __PARAM_COUNT,
  UINT IN1,
  UINT IN2,
  PART3 *data__)
{
  BOOL __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_EQ25_ENO,);
  __res = EQ__BOOL__UINT(EN,
    &__TMP_ENO,
    __PARAM_COUNT,
    IN1,
    IN2);
  __SET_VAR(,data__->_TMP_EQ25_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __PART3_MOVE__UINT__UINT7(BOOL EN,
  UINT IN,
  PART3 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE36_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE36_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __PART3_MOVE__UINT__UINT8(BOOL EN,
  UINT IN,
  PART3 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE23_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE23_ENO,,__TMP_ENO);
  return __res;
}

void PART3_init__(PART3 *data__, BOOL retain) {
  __INIT_VAR(data__->CARSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PEDBUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CARREDLIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CARYELLOWLIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CARGREENLIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PEDREDLIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PEDGREENLIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->WAIT_TO_CROSS,0,retain)
  __INIT_VAR(data__->SLOW_CARS,1,retain)
  __INIT_VAR(data__->PED_XING,2,retain)
  __INIT_VAR(data__->ALL_RED,3,retain)
  SR_init__(&data__->SR0,retain);
  TON_init__(&data__->TON0,retain);
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON2,retain);
  __INIT_VAR(data__->RESET_BUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ39_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ39_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE48_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE48_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ4_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ4_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE9_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE9_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ12_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ12_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ25_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ25_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE36_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE36_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE23_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE23_OUT,0,retain)
}

// Code part
void PART3_body__(PART3 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_EQ39_OUT,,__PART3_EQ__BOOL__UINT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->WAIT_TO_CROSS,),
    data__));
  __SET_VAR(data__->,CARGREENLIGHT,,__GET_VAR(data__->_TMP_EQ39_OUT,));
  __SET_VAR(data__->,PEDREDLIGHT,,__GET_VAR(data__->_TMP_EQ39_OUT,));
  __SET_VAR(data__->SR0.,EN,,__GET_VAR(data__->_TMP_EQ39_OUT,));
  __SET_VAR(data__->SR0.,S1,,(__GET_VAR(data__->PEDBUTTON,) && __GET_VAR(data__->_TMP_EQ39_OUT,)));
  __SET_VAR(data__->SR0.,R,,__GET_VAR(data__->RESET_BUTTON,));
  SR_body__(&data__->SR0);
  __SET_VAR(data__->,_TMP_MOVE48_OUT,,__PART3_MOVE__UINT__UINT2(
    (BOOL)(!(__GET_VAR(data__->CARSENSOR,)) && __GET_VAR(data__->SR0.Q1,)),
    (UINT)__GET_VAR(data__->SLOW_CARS,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE48_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE48_OUT,));
  };
  __SET_VAR(data__->,_TMP_EQ4_OUT,,__PART3_EQ__BOOL__UINT3(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->SLOW_CARS,),
    data__));
  __SET_VAR(data__->,PEDREDLIGHT,,__GET_VAR(data__->_TMP_EQ4_OUT,));
  __SET_VAR(data__->,CARYELLOWLIGHT,,__GET_VAR(data__->_TMP_EQ4_OUT,));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->_TMP_EQ4_OUT,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 3, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,_TMP_MOVE9_OUT,,__PART3_MOVE__UINT__UINT4(
    (BOOL)__GET_VAR(data__->TON0.Q,),
    (UINT)__GET_VAR(data__->PED_XING,),
    data__));
  if (__GET_VAR(data__->_TMP_MOVE9_ENO,)) {
    __SET_VAR(data__->,STATE,,__GET_VAR(data__->_TMP_MOVE9_OUT,));
  };
  __SET_VAR(data__->,PEDGREENLIGHT,,!(__GET_VAR(data__->_TMP_EQ39_OUT,)));
  __SET_VAR(data__->,CARREDLIGHT,,!(__GET_VAR(data__->_TMP_EQ39_OUT,)));
  __SET_VAR(data__->,CARYELLOWLIGHT,,!(__GET_VAR(data__->_TMP_EQ39_OUT,)));
  __SET_VAR(data__->,CARGREENLIGHT,,!(__GET_VAR(data__->_TMP_EQ4_OUT,)));
  __SET_VAR(data__->,CARREDLIGHT,,!(__GET_VAR(data__->_TMP_EQ4_OUT,)));
  __SET_VAR(data__->,PEDGREENLIGHT,,!(__GET_VAR(data__->_TMP_EQ4_OUT,)));
  __SET_VAR(data__->,_TMP_EQ12_OUT,,__PART3_EQ__BOOL__UINT5(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->PED_XING,),
    data__));
  __SET_VAR(data__->,CARYELLOWLIGHT,,!(__GET_VAR(data__->_TMP_EQ12_OUT,)));
  __SET_VAR(data__->,PEDREDLIGHT,,!(__GET_VAR(data__->_TMP_EQ12_OUT,)));
  __SET_VAR(data__->,CARGREENLIGHT,,!(__GET_VAR(data__->_TMP_EQ12_OUT,)));
  __SET_VAR(data__->,CARREDLIGHT,,__GET_VAR(data__->_TMP_EQ12_OUT,));
  __SET_VAR(data__->,PEDGREENLIGHT,,__GET_VAR(data__->_TMP_EQ12_OUT,));
  __SET_VAR(data__->,_TMP_EQ25_OUT,,__PART3_EQ__BOOL__UINT6(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)2,
    (UINT)__GET_VAR(data__->STATE,),
    (UINT)__GET_VAR(data__->ALL_RED,),
    data__));
  __SET_VAR(data__->,CARYELLOWLIGHT,,!(__GET_VAR(data__->_TMP_EQ25_OUT,)));
  __SET_VAR(data__->,PEDREDLIGHT,,__GET_VAR(data__->_TMP_EQ25_OUT,));
  __SET_VAR(data__->,CARGREENLIGHT,,!(__GET_VAR(data__->_TMP_EQ25_OUT,)));
  __SET_VAR(data__->,CARREDLIGHT,,__GET_VAR(data__->_TMP_EQ25_OUT,));
  __SET_VAR(data__->,PEDGREENLIGHT,,!(__GET_VAR(data__->_TMP_EQ25_OUT,)));
  __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->_TMP_EQ25_OUT,));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->,_TMP_MOVE36_OUT,,__PART3_MOVE__UINT__UINT7(
    (BOOL)__GET_VAR(data__->TON2.Q,),
    (UINT)__GET_VAR(data__->WAIT_TO_CROSS,),
    data__));
  __SET_VAR(data__->,RESET_BUTTON,,__GET_VAR(data__->_TMP_MOVE36_ENO,));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->_TMP_EQ12_OUT,));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,_TMP_MOVE23_OUT,,__PART3_MOVE__UINT__UINT8(
    (BOOL)__GET_VAR(data__->TON1.Q,),
    (UINT)__GET_VAR(data__->ALL_RED,),
    data__));

  goto __end;

__end:
  return;
} // PART3_body__() 





