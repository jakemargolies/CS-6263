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





inline UINT __PART2_MOVE__UINT__UINT1(BOOL EN,
  UINT IN,
  PART2 *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->MOVE26_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->MOVE26_ENO,,__TMP_ENO);
  return __res;
}

void PART2_init__(PART2 *data__, BOOL retain) {
  __INIT_VAR(data__->POSX_B0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POSX_B1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POSX_B2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POSX_B3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POSY_B0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POSY_B1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POSY_B2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POSY_B3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TARGETX_B0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TARGETX_B1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TARGETX_B2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TARGETX_B3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TARGETY_B0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TARGETY_B1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TARGETY_B2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TARGETY_B3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVEUP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVEDOWN,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVELEFT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVERIGHT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->POSX_UINT,0,retain)
  __INIT_VAR(data__->BOOL_TO_UINT1_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_UINT2_OUT,0,retain)
  __INIT_VAR(data__->MUL17_OUT,0,retain)
  __INIT_VAR(data__->ADD24_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_UINT3_OUT,0,retain)
  __INIT_VAR(data__->MUL18_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_UINT4_OUT,0,retain)
  __INIT_VAR(data__->MUL19_OUT,0,retain)
  __INIT_VAR(data__->ADD23_OUT,0,retain)
  __INIT_VAR(data__->ADD25_OUT,0,retain)
  __INIT_VAR(data__->MOVE26_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MOVE26_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_UINT5_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_UINT6_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_UINT7_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_UINT8_OUT,0,retain)
}

// Code part
void PART2_body__(PART2 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,BOOL_TO_UINT1_OUT,,BOOL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->POSX_B0,)));
  __SET_VAR(data__->,BOOL_TO_UINT2_OUT,,BOOL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->POSX_B1,)));
  __SET_VAR(data__->,MUL17_OUT,,MUL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->BOOL_TO_UINT2_OUT,),
    (UINT)2));
  __SET_VAR(data__->,ADD24_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->BOOL_TO_UINT1_OUT,),
    (UINT)__GET_VAR(data__->MUL17_OUT,)));
  __SET_VAR(data__->,BOOL_TO_UINT3_OUT,,BOOL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->POSX_B2,)));
  __SET_VAR(data__->,MUL18_OUT,,MUL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->BOOL_TO_UINT3_OUT,),
    (UINT)4));
  __SET_VAR(data__->,BOOL_TO_UINT4_OUT,,BOOL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->POSX_B3,)));
  __SET_VAR(data__->,MUL19_OUT,,MUL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->BOOL_TO_UINT4_OUT,),
    (UINT)8));
  __SET_VAR(data__->,ADD23_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->MUL18_OUT,),
    (UINT)__GET_VAR(data__->MUL19_OUT,)));
  __SET_VAR(data__->,ADD25_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->ADD24_OUT,),
    (UINT)__GET_VAR(data__->ADD23_OUT,)));
  __SET_VAR(data__->,MOVE26_OUT,,__PART2_MOVE__UINT__UINT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (UINT)__GET_VAR(data__->ADD25_OUT,),
    data__));
  if (__GET_VAR(data__->MOVE26_ENO,)) {
    __SET_VAR(data__->,POSX_UINT,,__GET_VAR(data__->MOVE26_OUT,));
  };
  __SET_VAR(data__->,BOOL_TO_UINT5_OUT,,BOOL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->POSY_B0,)));
  __SET_VAR(data__->,BOOL_TO_UINT6_OUT,,BOOL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->POSY_B1,)));
  __SET_VAR(data__->,BOOL_TO_UINT7_OUT,,BOOL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->POSY_B2,)));
  __SET_VAR(data__->,BOOL_TO_UINT8_OUT,,BOOL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->POSY_B3,)));

  goto __end;

__end:
  return;
} // PART2_body__() 





