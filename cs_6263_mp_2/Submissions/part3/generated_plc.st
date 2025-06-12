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

(*DBG:char md5[] = "a41a5a14bdb6280b5a3068632e3430d0";*)
(*DBG:/**)
(*DBG: * This file is part of OpenPLC Runtime*)
(*DBG: **)
(*DBG: * Copyright (C) 2023 Autonomy, GP Orcullo*)
(*DBG: * Based on the work by GP Orcullo on Beremiz for uC*)
(*DBG: **)
(*DBG: * This program is free software; you can redistribute it and/or*)
(*DBG: * modify it under the terms of the GNU General Public License*)
(*DBG: * as published by the Free Software Foundation; either version 2*)
(*DBG: * of the License, or (at your option) any later version.*)
(*DBG: **)
(*DBG: * This program is distributed in the hope that it will be useful,*)
(*DBG: * but WITHOUT ANY WARRANTY; without even the implied warranty of*)
(*DBG: * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the*)
(*DBG: * GNU General Public License for more details.*)
(*DBG: **)
(*DBG: * You should have received a copy of the GNU General Public License*)
(*DBG: * along with this program; If not, see <http://www.gnu.org/licenses/>.*)
(*DBG: **)
(*DBG: */*)
(*DBG:*)
(*DBG:#include <stdbool.h>*)
(*DBG:*)
(*DBG:#include "iec_types_all.h"*)
(*DBG:#include "POUS.h"*)
(*DBG:*)
(*DBG:#define SAME_ENDIANNESS      0*)
(*DBG:#define REVERSE_ENDIANNESS   1*)
(*DBG:*)
(*DBG:uint8_t endianness;*)
(*DBG:*)
(*DBG:*)
(*DBG:extern PART3 RES0__INSTANCE0;*)
(*DBG:*)
(*DBG:static const struct {*)
(*DBG:    void *ptr;*)
(*DBG:    __IEC_types_enum type;*)
(*DBG:} debug_vars[] = {*)
(*DBG:    {&(RES0__INSTANCE0.CARSENSOR), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.PEDBUTTON), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.CARREDLIGHT), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.CARYELLOWLIGHT), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.CARGREENLIGHT), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.PEDREDLIGHT), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.PEDGREENLIGHT), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.STATE), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.WAIT_TO_CROSS), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.SLOW_CARS), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.PED_XING), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.ALL_RED), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.SR0.EN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.SR0.ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.SR0.S1), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.SR0.R), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.SR0.Q1), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON0.EN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON0.ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON0.IN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON0.PT), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON0.Q), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON0.ET), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON0.STATE), SINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON0.PREV_IN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON0.CURRENT_TIME), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON0.START_TIME), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON1.EN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON1.ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON1.IN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON1.PT), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON1.Q), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON1.ET), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON1.STATE), SINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON1.PREV_IN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON1.CURRENT_TIME), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON1.START_TIME), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON2.EN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON2.ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON2.IN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON2.PT), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON2.Q), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON2.ET), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON2.STATE), SINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON2.PREV_IN), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON2.CURRENT_TIME), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.TON2.START_TIME), TIME_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0.RESET_BUTTON), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_EQ39_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_EQ39_OUT), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE48_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE48_OUT), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_EQ4_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_EQ4_OUT), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE9_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE9_OUT), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_EQ12_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_EQ12_OUT), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_EQ25_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_EQ25_OUT), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE36_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE36_OUT), UINT_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE23_ENO), BOOL_ENUM},*)
(*DBG:    {&(RES0__INSTANCE0._TMP_MOVE23_OUT), UINT_ENUM},*)
(*DBG:};*)
(*DBG:*)
(*DBG:#define VAR_COUNT               64*)
(*DBG:*)
(*DBG:uint16_t get_var_count(void)*)
(*DBG:{*)
(*DBG:    return VAR_COUNT;*)
(*DBG:}*)
(*DBG:*)
(*DBG:size_t get_var_size(size_t idx)*)
(*DBG:{*)
(*DBG:    if (idx >= VAR_COUNT)*)
(*DBG:    {*)
(*DBG:        return 0;*)
(*DBG:    }*)
(*DBG:    switch (debug_vars[idx].type) {*)
(*DBG:    case UINT_ENUM:*)
(*DBG:        return sizeof(UINT);*)
(*DBG:    case TIME_ENUM:*)
(*DBG:        return sizeof(TIME);*)
(*DBG:    case BOOL_ENUM:*)
(*DBG:        return sizeof(BOOL);*)
(*DBG:    case SINT_ENUM:*)
(*DBG:        return sizeof(SINT);*)
(*DBG:    default:*)
(*DBG:        return 0;*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void *get_var_addr(size_t idx)*)
(*DBG:{*)
(*DBG:    void *ptr = debug_vars[idx].ptr;*)
(*DBG:*)
(*DBG:    switch (debug_vars[idx].type) {*)
(*DBG:    case UINT_ENUM:*)
(*DBG:        return (void *)&((__IEC_UINT_t *) ptr)->value;*)
(*DBG:    case TIME_ENUM:*)
(*DBG:        return (void *)&((__IEC_TIME_t *) ptr)->value;*)
(*DBG:    case BOOL_ENUM:*)
(*DBG:        return (void *)&((__IEC_BOOL_t *) ptr)->value;*)
(*DBG:    case SINT_ENUM:*)
(*DBG:        return (void *)&((__IEC_SINT_t *) ptr)->value;*)
(*DBG:    default:*)
(*DBG:        return 0;*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void force_var(size_t idx, bool forced, void *val)*)
(*DBG:{*)
(*DBG:    void *ptr = debug_vars[idx].ptr;*)
(*DBG:*)
(*DBG:    if (forced) {*)
(*DBG:        size_t var_size = get_var_size(idx);*)
(*DBG:        switch (debug_vars[idx].type) {*)
(*DBG:        case UINT_ENUM: {*)
(*DBG:            memcpy(&((__IEC_UINT_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_UINT_t *) ptr)->value = *((UINT *) val);*)
(*DBG:            ((__IEC_UINT_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        case TIME_ENUM: {*)
(*DBG:            memcpy(&((__IEC_TIME_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_TIME_t *) ptr)->value = *((TIME *) val);*)
(*DBG:            ((__IEC_TIME_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        case BOOL_ENUM: {*)
(*DBG:            memcpy(&((__IEC_BOOL_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_BOOL_t *) ptr)->value = *((BOOL *) val);*)
(*DBG:            ((__IEC_BOOL_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        case SINT_ENUM: {*)
(*DBG:            memcpy(&((__IEC_SINT_t *) ptr)->value, val, var_size);*)
(*DBG:            //((__IEC_SINT_t *) ptr)->value = *((SINT *) val);*)
(*DBG:            ((__IEC_SINT_t *) ptr)->flags |= __IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:        default:*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:    } else {*)
(*DBG:        switch (debug_vars[idx].type) {*)
(*DBG:        case UINT_ENUM:*)
(*DBG:            ((__IEC_UINT_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        case TIME_ENUM:*)
(*DBG:            ((__IEC_TIME_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        case BOOL_ENUM:*)
(*DBG:            ((__IEC_BOOL_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        case SINT_ENUM:*)
(*DBG:            ((__IEC_SINT_t *) ptr)->flags &= ~__IEC_FORCE_FLAG;*)
(*DBG:            break;*)
(*DBG:        default:*)
(*DBG:            break;*)
(*DBG:        }*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void swap_bytes(void *ptr, size_t size) *)
(*DBG:{*)
(*DBG:    uint8_t *bytePtr = (uint8_t *)ptr;*)
(*DBG:    size_t i;*)
(*DBG:    for (i = 0; i < size / 2; ++i) *)
(*DBG:    {*)
(*DBG:        uint8_t temp = bytePtr[i];*)
(*DBG:        bytePtr[i] = bytePtr[size - 1 - i];*)
(*DBG:        bytePtr[size - 1 - i] = temp;*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void trace_reset(void)*)
(*DBG:{*)
(*DBG:    for (size_t i=0; i < VAR_COUNT; i++) *)
(*DBG:    {*)
(*DBG:        force_var(i, false, 0);*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void set_trace(size_t idx, bool forced, void *val)*)
(*DBG:{*)
(*DBG:    if (idx >= 0 && idx < VAR_COUNT) *)
(*DBG:    {*)
(*DBG:        if (endianness == REVERSE_ENDIANNESS)*)
(*DBG:        {*)
(*DBG:            // Aaaaarghhhh... Stupid AVR is Big Endian.*)
(*DBG:            swap_bytes(val, get_var_size(idx));*)
(*DBG:        }*)
(*DBG:*)
(*DBG:        force_var(idx, forced, val);*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)
(*DBG:void set_endianness(uint8_t value)*)
(*DBG:{*)
(*DBG:    if (value == SAME_ENDIANNESS || value == REVERSE_ENDIANNESS)*)
(*DBG:    {*)
(*DBG:        endianness = value;*)
(*DBG:    }*)
(*DBG:}*)
(*DBG:*)