TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    _TMP_ADD10_OUT : UINT;
    _TMP_EQ13_OUT : BOOL;
    _TMP_SEL15_OUT : UINT;
    _TMP_AND7_OUT : BOOL;
  END_VAR

  _TMP_ADD10_OUT := ADD(COUNTER, 1);
  _TMP_EQ13_OUT := EQ(N, _TMP_ADD10_OUT);
  _TMP_SEL15_OUT := SEL(_TMP_EQ13_OUT, _TMP_ADD10_OUT, 0);
  COUNTER := _TMP_SEL15_OUT;
  _TMP_AND7_OUT := AND(_TMP_EQ13_OUT, TRIG);
  py_eval(TRIG := _TMP_AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM part3
  VAR
    state : UINT := 0;
    wait_for_request : UINT := 0;
    wait_for_traffic : UINT := 1;
    slow_cars : UINT := 2;
    ped_xing : UINT := 3;
    all_red : UINT := 4;
  END_VAR
  VAR
    car_sensor : BOOL;
    ped_button : BOOL;
    car_red : BOOL;
    car_yellow : BOOL;
    car_green : BOOL;
    ped_red : BOOL;
    ped_green : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    yellow_delay : TIME := T#3s;
    ped_xing_delay : TIME := T#15s;
    all_red_delay : TIME := T#1s;
    TON1 : TON;
    TON2 : TON;
    waiting_for_request : BOOL := 0;
    waiting_for_traffic : BOOL := 0;
    slowing_cars : BOOL := 0;
    peds_xing : BOOL := 0;
    turning_all_red : BOOL := 0;
    _TMP_EQ1_ENO : BOOL;
    _TMP_EQ1_OUT : BOOL;
    _TMP_MOVE42_ENO : BOOL;
    _TMP_MOVE42_OUT : UINT;
    _TMP_EQ4_ENO : BOOL;
    _TMP_EQ4_OUT : BOOL;
    _TMP_MOVE47_ENO : BOOL;
    _TMP_MOVE47_OUT : UINT;
    _TMP_EQ7_ENO : BOOL;
    _TMP_EQ7_OUT : BOOL;
    _TMP_MOVE50_ENO : BOOL;
    _TMP_MOVE50_OUT : UINT;
    _TMP_EQ10_ENO : BOOL;
    _TMP_EQ10_OUT : BOOL;
    _TMP_MOVE53_ENO : BOOL;
    _TMP_MOVE53_OUT : UINT;
    _TMP_EQ13_ENO : BOOL;
    _TMP_EQ13_OUT : BOOL;
    _TMP_MOVE56_ENO : BOOL;
    _TMP_MOVE56_OUT : UINT;
  END_VAR

  car_green := waiting_for_request OR waiting_for_traffic;
  _TMP_EQ1_OUT := EQ(EN := TRUE, IN1 := state, IN2 := wait_for_request, ENO => _TMP_EQ1_ENO);
  waiting_for_request := _TMP_EQ1_OUT;
  _TMP_MOVE42_OUT := MOVE(EN := ped_button AND _TMP_EQ1_OUT, IN := wait_for_traffic, ENO => _TMP_MOVE42_ENO);
  IF _TMP_MOVE42_ENO THEN
      state := _TMP_MOVE42_OUT;
  END_IF;
  ped_green := peds_xing;
  ped_red := NOT(peds_xing);
  _TMP_EQ4_OUT := EQ(EN := TRUE, IN1 := state, IN2 := wait_for_traffic, ENO => _TMP_EQ4_ENO);
  waiting_for_traffic := _TMP_EQ4_OUT;
  _TMP_MOVE47_OUT := MOVE(EN := NOT(car_sensor) AND _TMP_EQ4_OUT, IN := slow_cars, ENO => _TMP_MOVE47_ENO);
  IF _TMP_MOVE47_ENO THEN
      state := _TMP_MOVE47_OUT;
  END_IF;
  car_red := peds_xing OR turning_all_red;
  car_yellow := slowing_cars;
  _TMP_EQ7_OUT := EQ(EN := TRUE, IN1 := state, IN2 := slow_cars, ENO => _TMP_EQ7_ENO);
  slowing_cars := _TMP_EQ7_OUT;
  TON0(IN := _TMP_EQ7_OUT, PT := yellow_delay);
  _TMP_MOVE50_OUT := MOVE(EN := TON0.Q, IN := ped_xing, ENO => _TMP_MOVE50_ENO);
  IF _TMP_MOVE50_ENO THEN
      state := _TMP_MOVE50_OUT;
  END_IF;
  _TMP_EQ10_OUT := EQ(EN := TRUE, IN1 := state, IN2 := ped_xing, ENO => _TMP_EQ10_ENO);
  peds_xing := _TMP_EQ10_OUT;
  TON1(IN := _TMP_EQ10_OUT, PT := ped_xing_delay);
  _TMP_MOVE53_OUT := MOVE(EN := TON1.Q, IN := all_red, ENO => _TMP_MOVE53_ENO);
  IF _TMP_MOVE53_ENO THEN
      state := _TMP_MOVE53_OUT;
  END_IF;
  _TMP_EQ13_OUT := EQ(EN := TRUE, IN1 := state, IN2 := all_red, ENO => _TMP_EQ13_ENO);
  turning_all_red := _TMP_EQ13_OUT;
  TON2(IN := _TMP_EQ13_OUT, PT := all_red_delay);
  _TMP_MOVE56_OUT := MOVE(EN := TON2.Q, IN := wait_for_request, ENO => _TMP_MOVE56_ENO);
  IF _TMP_MOVE56_ENO THEN
      state := _TMP_MOVE56_OUT;
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : part3;
  END_RESOURCE
END_CONFIGURATION
