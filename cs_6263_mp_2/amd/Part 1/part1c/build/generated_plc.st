PROGRAM part1c
  VAR
    Input0 AT %IX1.0 : BOOL;
    Output0 AT %QX1.0 : BOOL;
  END_VAR
  VAR
    Oscillator : BOOL;
    TON0 : TON;
    TOF0 : TOF;
    TON1 : TON;
    CTU0 : CTU;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
    OR59_OUT : BOOL;
  END_VAR

  TON0(IN := NOT(Oscillator) AND Input0, PT := T#6000ms);
  TOF0(IN := TON0.Q, PT := T#6000ms);
  Oscillator := TOF0.Q;
  Output0 := NOT(Oscillator) AND Input0;
  TON1(IN := Input0, PT := T#30s);
  R_TRIG1(CLK := Output0);
  R_TRIG2(CLK := R_TRIG1.Q);
  CTU0(CU := R_TRIG2.Q, PV := 6);
  OR59_OUT := OR(TON1.Q, CTU0.Q);
  IF OR59_OUT THEN
    Output0 := TRUE; (*set*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : part1c;
  END_RESOURCE
END_CONFIGURATION
