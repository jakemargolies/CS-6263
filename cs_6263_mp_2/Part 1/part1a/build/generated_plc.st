PROGRAM part_1a
  VAR
    Input0 AT %IX1.0 : BOOL;
    Input1 AT %IX1.1 : BOOL;
    Output0 AT %QX1.0 : BOOL;
    Output1 AT %QX1.1 : BOOL;
  END_VAR
  VAR
    TP0 : TP;
    NOT14_OUT : BOOL;
    AND13_OUT : BOOL;
  END_VAR

  NOT14_OUT := NOT(Output0);
  AND13_OUT := AND(NOT14_OUT, Input0);
  TP0(IN := AND13_OUT, PT := T#6s);
  Output0 := TP0.Q;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : part_1a;
  END_RESOURCE
END_CONFIGURATION
