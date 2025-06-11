PROGRAM part3
  VAR
    CarSensor AT %IX0.0 : BOOL;
    PedButton AT %IX0.1 : BOOL;
    CarRedLight AT %QX0.0 : BOOL;
    CarYellowLight AT %QX0.1 : BOOL;
    CarGreenLight AT %QX0.2 : BOOL;
    PedRedLight AT %QX0.3 : BOOL;
    PedGreenLight AT %QX0.4 : BOOL;
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
