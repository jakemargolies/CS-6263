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
    car_sensor AT %IX0.0 : BOOL;
    ped_button AT %IX0.1 : BOOL;
    car_red AT %QX0.0 : BOOL;
    car_yellow AT %QX0.1 : BOOL;
    car_green AT %QX0.2 : BOOL;
    ped_red AT %QX0.3 : BOOL;
    ped_green AT %QX0.4 : BOOL;
  END_VAR
  VAR
    TON0 : TON;
    yellow_delay : TIME := T#3s;
    ped_xing_delay : TIME := T#15s;
    all_red_delay : TIME := T#1s;
    TON1 : TON;
    TON2 : TON;
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

  _TMP_EQ1_OUT := EQ(EN := TRUE, IN1 := state, IN2 := wait_for_request, ENO => _TMP_EQ1_ENO);
  car_green := _TMP_EQ1_OUT;
  car_yellow := NOT(_TMP_EQ1_OUT);
  car_red := NOT(_TMP_EQ1_OUT);
  ped_green := NOT(_TMP_EQ1_OUT);
  ped_red := _TMP_EQ1_OUT;
  _TMP_MOVE42_OUT := MOVE(EN := ped_button AND _TMP_EQ1_OUT, IN := wait_for_traffic, ENO => _TMP_MOVE42_ENO);
  IF _TMP_MOVE42_ENO THEN
      state := _TMP_MOVE42_OUT;
  END_IF;
  _TMP_EQ4_OUT := EQ(EN := TRUE, IN1 := state, IN2 := wait_for_traffic, ENO => _TMP_EQ4_ENO);
  car_green := _TMP_EQ4_OUT;
  car_yellow := NOT(_TMP_EQ4_OUT);
  car_red := NOT(_TMP_EQ4_OUT);
  ped_green := NOT(_TMP_EQ4_OUT);
  ped_red := _TMP_EQ4_OUT;
  _TMP_MOVE47_OUT := MOVE(EN := NOT(car_sensor) AND _TMP_EQ4_OUT, IN := slow_cars, ENO => _TMP_MOVE47_ENO);
  IF _TMP_MOVE47_ENO THEN
      state := _TMP_MOVE47_OUT;
  END_IF;
  _TMP_EQ7_OUT := EQ(EN := TRUE, IN1 := state, IN2 := slow_cars, ENO => _TMP_EQ7_ENO);
  car_green := NOT(_TMP_EQ7_OUT);
  car_yellow := _TMP_EQ7_OUT;
  car_red := NOT(_TMP_EQ7_OUT);
  ped_green := NOT(_TMP_EQ7_OUT);
  ped_red := _TMP_EQ7_OUT;
  TON0(IN := _TMP_EQ7_OUT, PT := yellow_delay);
  _TMP_MOVE50_OUT := MOVE(EN := TON0.Q, IN := ped_xing, ENO => _TMP_MOVE50_ENO);
  IF _TMP_MOVE50_ENO THEN
      state := _TMP_MOVE50_OUT;
  END_IF;
  _TMP_EQ10_OUT := EQ(EN := TRUE, IN1 := state, IN2 := ped_xing, ENO => _TMP_EQ10_ENO);
  car_green := NOT(_TMP_EQ10_OUT);
  car_yellow := NOT(_TMP_EQ10_OUT);
  car_red := _TMP_EQ10_OUT;
  ped_green := _TMP_EQ10_OUT;
  ped_red := NOT(_TMP_EQ10_OUT);
  TON1(IN := _TMP_EQ10_OUT, PT := ped_xing_delay);
  _TMP_MOVE53_OUT := MOVE(EN := TON1.Q, IN := all_red, ENO => _TMP_MOVE53_ENO);
  IF _TMP_MOVE53_ENO THEN
      state := _TMP_MOVE53_OUT;
  END_IF;
  _TMP_EQ13_OUT := EQ(EN := TRUE, IN1 := state, IN2 := all_red, ENO => _TMP_EQ13_ENO);
  car_green := NOT(_TMP_EQ13_OUT);
  car_yellow := NOT(_TMP_EQ13_OUT);
  car_red := _TMP_EQ13_OUT;
  ped_green := NOT(_TMP_EQ13_OUT);
  ped_red := _TMP_EQ13_OUT;
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
