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
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM part3
  VAR
    CarSensor : BOOL;
    PedButton : BOOL;
    CarRedLight : BOOL;
    CarYellowLight : BOOL;
    CarGreenLight : BOOL;
    PedRedLight : BOOL;
    PedGreenLight : BOOL;
  END_VAR
  VAR
    SlowDown : BOOL;
    PedXing : BOOL;
    AllRed : BOOL;
    SR0 : SR;
    TON0 : TON;
    SR1 : SR;
    TON1 : TON;
    SR2 : SR;
    TON2 : TON;
    AND10_OUT : BOOL;
    AND36_OUT : BOOL;
    AND28_OUT : BOOL;
    OR38_OUT : BOOL;
  END_VAR

  CarGreenLight := NOT(AllRed) AND NOT(SlowDown) AND NOT(PedXing);
  PedRedLight := NOT(PedXing);
  SR0(S1 := PedButton, R := AllRed);
  AND10_OUT := AND(SR0.Q1, NOT(CarSensor));
  AND36_OUT := AND(AND10_OUT, NOT(AllRed) AND NOT(PedXing));
  SlowDown := AND36_OUT;
  TON0(IN := SlowDown, PT := T#3s);
  SR1(S1 := TON0.Q, R := AllRed);
  AND28_OUT := AND(SR1.Q1, NOT(AllRed));
  PedXing := AND28_OUT;
  CarYellowLight := SlowDown;
  PedGreenLight := PedXing;
  TON1(IN := PedXing, PT := T#15s);
  TON2(IN := AllRed, PT := T#1s);
  SR2(S1 := TON1.Q, R := TON2.Q);
  AllRed := SR2.Q1;
  OR38_OUT := OR(PedXing, AllRed);
  CarRedLight := OR38_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : part3;
  END_RESOURCE
END_CONFIGURATION
