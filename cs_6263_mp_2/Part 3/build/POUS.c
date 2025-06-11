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
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
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

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void PART3_init__(PART3 *data__, BOOL retain) {
  __INIT_VAR(data__->CARSENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PEDBUTTON,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CARREDLIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CARYELLOWLIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CARGREENLIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PEDREDLIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PEDGREENLIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SLOWDOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PEDXING,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ALLRED,__BOOL_LITERAL(FALSE),retain)
  SR_init__(&data__->SR0,retain);
  TON_init__(&data__->TON0,retain);
  SR_init__(&data__->SR1,retain);
  TON_init__(&data__->TON1,retain);
  SR_init__(&data__->SR2,retain);
  TON_init__(&data__->TON2,retain);
  __INIT_VAR(data__->AND10_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AND36_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->AND28_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OR38_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PART3_body__(PART3 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,CARGREENLIGHT,,((!(__GET_VAR(data__->ALLRED,)) && !(__GET_VAR(data__->SLOWDOWN,))) && !(__GET_VAR(data__->PEDXING,))));
  __SET_VAR(data__->,PEDREDLIGHT,,!(__GET_VAR(data__->PEDXING,)));
  __SET_VAR(data__->SR0.,S1,,__GET_VAR(data__->PEDBUTTON,));
  __SET_VAR(data__->SR0.,R,,__GET_VAR(data__->ALLRED,));
  SR_body__(&data__->SR0);
  __SET_VAR(data__->,AND10_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SR0.Q1,),
    (BOOL)!(__GET_VAR(data__->CARSENSOR,))));
  __SET_VAR(data__->,AND36_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->AND10_OUT,),
    (BOOL)(!(__GET_VAR(data__->ALLRED,)) && !(__GET_VAR(data__->PEDXING,)))));
  __SET_VAR(data__->,SLOWDOWN,,__GET_VAR(data__->AND36_OUT,));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->SLOWDOWN,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 3, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->SR1.,S1,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->SR1.,R,,__GET_VAR(data__->ALLRED,));
  SR_body__(&data__->SR1);
  __SET_VAR(data__->,AND28_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->SR1.Q1,),
    (BOOL)!(__GET_VAR(data__->ALLRED,))));
  __SET_VAR(data__->,PEDXING,,__GET_VAR(data__->AND28_OUT,));
  __SET_VAR(data__->,CARYELLOWLIGHT,,__GET_VAR(data__->SLOWDOWN,));
  __SET_VAR(data__->,PEDGREENLIGHT,,__GET_VAR(data__->PEDXING,));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->PEDXING,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 15, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->TON2.,IN,,__GET_VAR(data__->ALLRED,));
  __SET_VAR(data__->TON2.,PT,,__time_to_timespec(1, 0, 1, 0, 0, 0));
  TON_body__(&data__->TON2);
  __SET_VAR(data__->SR2.,S1,,__GET_VAR(data__->TON1.Q,));
  __SET_VAR(data__->SR2.,R,,__GET_VAR(data__->TON2.Q,));
  SR_body__(&data__->SR2);
  __SET_VAR(data__->,ALLRED,,__GET_VAR(data__->SR2.Q1,));
  __SET_VAR(data__->,OR38_OUT,,OR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->PEDXING,),
    (BOOL)__GET_VAR(data__->ALLRED,)));
  __SET_VAR(data__->,CARREDLIGHT,,__GET_VAR(data__->OR38_OUT,));

  goto __end;

__end:
  return;
} // PART3_body__() 





