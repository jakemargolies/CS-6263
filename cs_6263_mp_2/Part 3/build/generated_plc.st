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
    State : UINT := 0;
    wait_to_cross : UINT := 0;
    slow_cars : UINT := 1;
    ped_xing : UINT := 2;
    all_red : UINT := 3;
    SR0 : SR;
    TON0 : TON;
    TON1 : TON;
    TON2 : TON;
    reset_button : BOOL;
    _TMP_EQ39_ENO : BOOL;
    _TMP_EQ39_OUT : BOOL;
    _TMP_MOVE48_ENO : BOOL;
    _TMP_MOVE48_OUT : UINT;
    _TMP_EQ4_ENO : BOOL;
    _TMP_EQ4_OUT : BOOL;
    _TMP_MOVE9_ENO : BOOL;
    _TMP_MOVE9_OUT : UINT;
    _TMP_EQ12_ENO : BOOL;
    _TMP_EQ12_OUT : BOOL;
    _TMP_EQ25_ENO : BOOL;
    _TMP_EQ25_OUT : BOOL;
    _TMP_MOVE36_ENO : BOOL;
    _TMP_MOVE36_OUT : UINT;
    _TMP_MOVE23_ENO : BOOL;
    _TMP_MOVE23_OUT : UINT;
  END_VAR

  _TMP_EQ39_OUT := EQ(EN := TRUE, IN1 := State, IN2 := wait_to_cross, ENO => _TMP_EQ39_ENO);
  CarGreenLight := _TMP_EQ39_OUT;
  PedRedLight := _TMP_EQ39_OUT;
  SR0(EN := _TMP_EQ39_OUT, S1 := PedButton AND _TMP_EQ39_OUT, R := reset_button);
  _TMP_MOVE48_OUT := MOVE(EN := NOT(CarSensor) AND SR0.Q1, IN := slow_cars, ENO => _TMP_MOVE48_ENO);
  IF _TMP_MOVE48_ENO THEN
      State := _TMP_MOVE48_OUT;
  END_IF;
  _TMP_EQ4_OUT := EQ(EN := TRUE, IN1 := State, IN2 := slow_cars, ENO => _TMP_EQ4_ENO);
  PedRedLight := _TMP_EQ4_OUT;
  CarYellowLight := _TMP_EQ4_OUT;
  TON0(IN := _TMP_EQ4_OUT, PT := T#3s);
  _TMP_MOVE9_OUT := MOVE(EN := TON0.Q, IN := ped_xing, ENO => _TMP_MOVE9_ENO);
  IF _TMP_MOVE9_ENO THEN
      State := _TMP_MOVE9_OUT;
  END_IF;
  PedGreenLight := NOT(_TMP_EQ39_OUT);
  CarRedLight := NOT(_TMP_EQ39_OUT);
  CarYellowLight := NOT(_TMP_EQ39_OUT);
  CarGreenLight := NOT(_TMP_EQ4_OUT);
  CarRedLight := NOT(_TMP_EQ4_OUT);
  PedGreenLight := NOT(_TMP_EQ4_OUT);
  _TMP_EQ12_OUT := EQ(EN := TRUE, IN1 := State, IN2 := ped_xing, ENO => _TMP_EQ12_ENO);
  CarYellowLight := NOT(_TMP_EQ12_OUT);
  PedRedLight := NOT(_TMP_EQ12_OUT);
  CarGreenLight := NOT(_TMP_EQ12_OUT);
  CarRedLight := _TMP_EQ12_OUT;
  PedGreenLight := _TMP_EQ12_OUT;
  _TMP_EQ25_OUT := EQ(EN := TRUE, IN1 := State, IN2 := all_red, ENO => _TMP_EQ25_ENO);
  CarYellowLight := NOT(_TMP_EQ25_OUT);
  PedRedLight := _TMP_EQ25_OUT;
  CarGreenLight := NOT(_TMP_EQ25_OUT);
  CarRedLight := _TMP_EQ25_OUT;
  PedGreenLight := NOT(_TMP_EQ25_OUT);
  TON2(IN := _TMP_EQ25_OUT);
  _TMP_MOVE36_OUT := MOVE(EN := TON2.Q, IN := wait_to_cross, ENO => _TMP_MOVE36_ENO);
  reset_button := _TMP_MOVE36_ENO;
  TON1(IN := _TMP_EQ12_OUT);
  _TMP_MOVE23_OUT := MOVE(EN := TON1.Q, IN := all_red, ENO => _TMP_MOVE23_ENO);
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : part3;
  END_RESOURCE
END_CONFIGURATION
