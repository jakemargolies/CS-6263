PROGRAM part4
  VAR
    main_sw_btn AT %IX0.0 : BOOL;
    car_sensor_1 AT %IX0.1 : BOOL;
    car_sensor_2 AT %IX0.2 : BOOL;
    green_entr_light AT %QX0.0 : BOOL;
    greep_pkg_light AT %QX0.1 : BOOL;
    red_entr_light AT %QX0.2 : BOOL;
    red_pkg_light AT %QX0.3 : BOOL;
    main_sw_indicator AT %QX0.4 : BOOL;
  END_VAR
  VAR
    state : UINT := 0;
    state_system_off : UINT := 0;
    state_no_cars : UINT := 1;
    state_car_entering : UINT := 2;
    state_car_exiting : UINT := 3;
    system_off : BOOL;
    no_cars : BOOL;
    car_entering : BOOL;
    car_exiting : BOOL;
    _TMP_EQ3_ENO : BOOL;
    _TMP_EQ3_OUT : BOOL;
    _TMP_MOVE41_ENO : BOOL;
    _TMP_MOVE41_OUT : UINT;
    _TMP_EQ10_ENO : BOOL;
    _TMP_EQ10_OUT : BOOL;
    _TMP_MOVE11_ENO : BOOL;
    _TMP_MOVE11_OUT : UINT;
    _TMP_EQ17_ENO : BOOL;
    _TMP_EQ17_OUT : BOOL;
    _TMP_MOVE19_ENO : BOOL;
    _TMP_MOVE19_OUT : UINT;
    _TMP_EQ7_ENO : BOOL;
    _TMP_EQ7_OUT : BOOL;
    F_TRIG1 : F_TRIG;
    _TMP_MOVE24_ENO : BOOL;
    _TMP_MOVE24_OUT : UINT;
    F_TRIG2 : F_TRIG;
    _TMP_MOVE27_ENO : BOOL;
    _TMP_MOVE27_OUT : UINT;
  END_VAR

  _TMP_EQ3_OUT := EQ(EN := TRUE, IN1 := state, IN2 := state_system_off, ENO => _TMP_EQ3_ENO);
  system_off := _TMP_EQ3_OUT;
  _TMP_MOVE41_OUT := MOVE(EN := main_sw_btn AND system_off, IN := state_no_cars, ENO => _TMP_MOVE41_ENO);
  IF _TMP_MOVE41_ENO THEN
      state := _TMP_MOVE41_OUT;
  END_IF;
  main_sw_indicator := NOT(system_off);
  _TMP_EQ10_OUT := EQ(EN := TRUE, IN1 := state, IN2 := state_no_cars, ENO => _TMP_EQ10_ENO);
  no_cars := _TMP_EQ10_OUT;
  green_entr_light := no_cars;
  greep_pkg_light := no_cars;
  red_entr_light := NOT(no_cars);
  red_pkg_light := NOT(no_cars);
  _TMP_MOVE11_OUT := MOVE(EN := car_sensor_1 AND no_cars, IN := state_car_entering, ENO => _TMP_MOVE11_ENO);
  IF _TMP_MOVE11_ENO THEN
      state := _TMP_MOVE11_OUT;
  END_IF;
  _TMP_EQ17_OUT := EQ(EN := TRUE, IN1 := state, IN2 := state_car_entering, ENO => _TMP_EQ17_ENO);
  car_entering := _TMP_EQ17_OUT;
  _TMP_MOVE19_OUT := MOVE(EN := car_sensor_2 AND no_cars, IN := state_car_exiting, ENO => _TMP_MOVE19_ENO);
  IF _TMP_MOVE19_ENO THEN
      state := _TMP_MOVE19_OUT;
  END_IF;
  _TMP_EQ7_OUT := EQ(EN := TRUE, IN1 := state, IN2 := state_car_exiting, ENO => _TMP_EQ7_ENO);
  car_exiting := _TMP_EQ7_OUT;
  F_TRIG1(CLK := car_sensor_2);
  _TMP_MOVE24_OUT := MOVE(EN := F_TRIG1.Q AND car_entering, IN := state_no_cars, ENO => _TMP_MOVE24_ENO);
  IF _TMP_MOVE24_ENO THEN
      state := _TMP_MOVE24_OUT;
  END_IF;
  F_TRIG2(CLK := car_sensor_1);
  _TMP_MOVE27_OUT := MOVE(EN := F_TRIG2.Q AND car_exiting, IN := state_no_cars, ENO => _TMP_MOVE27_ENO);
  IF _TMP_MOVE27_ENO THEN
      state := _TMP_MOVE27_OUT;
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : part4;
  END_RESOURCE
END_CONFIGURATION
