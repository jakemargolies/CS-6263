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





void PART1C_init__(PART1C *data__, BOOL retain) {
  __INIT_VAR(data__->INPUT0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OUTPUT0,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OSCILLATOR,__BOOL_LITERAL(FALSE),retain)
  TON_init__(&data__->TON0,retain);
  TOF_init__(&data__->TOF0,retain);
  CTU_init__(&data__->CTU0,retain);
  __INIT_VAR(data__->BOMB,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->COUNTUP,6,retain)
  __INIT_VAR(data__->TRUEBOOL,1,retain)
  TON_init__(&data__->TON1,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
}

// Code part
void PART1C_body__(PART1C *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->TON0.,IN,,(!(__GET_VAR(data__->OSCILLATOR,)) && __GET_VAR(data__->INPUT0,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 6000, 0, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->TON0.Q,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 6000, 0, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,OSCILLATOR,,__GET_VAR(data__->TOF0.Q,));
  __SET_VAR(data__->,OUTPUT0,,(__GET_VAR(data__->BOMB,) || (!(__GET_VAR(data__->OSCILLATOR,)) && __GET_VAR(data__->INPUT0,))));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->OUTPUT0,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,PV,,__GET_VAR(data__->COUNTUP,));
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->INPUT0,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 30000, 0, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,BOMB,,((__GET_VAR(data__->BOMB,) || __GET_VAR(data__->CTU0.Q,)) || __GET_VAR(data__->TON1.Q,)));

  goto __end;

__end:
  return;
} // PART1C_body__() 





