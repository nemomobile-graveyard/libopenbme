/**
   @file bmemsg.h

   @brief BME IPC message definitions
   <p>
   Copyright (C) 2010 Nokia Corporation.

   @author Markus Lehtonen <markus.lehtonen@nokia.com>
   @author Matti Halme <matti.halme@nokia.com>

   This file is part of libbme.

   Libbme is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License
   version 2.1 as published by the Free Software Foundation.

   Libbme is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with libbme. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BMEMSG_H
#define BMEMSG_H

#include <stdint.h>

/* Generic constants */
#define BME_INFO_NOT_KNOWN_YET        0x00
#define BME_INFO_NOT_SUPPORTED        0xFFFF
#define BME_INFO_NO_SUPPORT           0xFF

/* Battery info flags */
#define BME_BATTERY_TYPE              0x0001
#define BME_BATTERY_NOMINAL_CAPA      0x0002
#define BME_BATTERY_TEMP              0x0004
#define BME_BATTERY_VOLTAGE           0x0008
#define BME_BATTERY_VOLTAGE_TX_ON     0x0010
#define BME_BATTERY_VOLTAGE_TX_OFF    0x0020
#define BME_BATTERY_VOLTAGE_PWM_ON    0x0040
#define BME_BATTERY_VOLTAGE_PWM_OFF   0x0080
#define BME_BATTERY_GENERATION        0x0100
#define BME_BATTERY_VOLTAGE_SH_CHK    0x0200

/* Indication info flags */
#define BME_IND_CHARGER_STATE_CHANGE      0x0001
#define BME_IND_BATTERY_STATE_CHANGE      0x0002
#define BME_IND_CHARGING_STATE_CHANGE     0x0004
#define BME_IND_MONITORING_STATE_CHANGE   0x0008

/*
 * Constants below are enumerated explicitly to keep BME API consistent
 */
enum bme_info_battery_type_e {
  BME_INFO_BATTERY_TYPE_NONE    = 0,
  BME_INFO_BATTERY_TYPE_SERVICE = 1,
  BME_INFO_BATTERY_TYPE_NICKEL  = 2,
  BME_INFO_BATTERY_TYPE_LI4V1   = 3,
  BME_INFO_BATTERY_TYPE_LI4V2   = 4
};

enum bme_info_charger_status_e {
  BME_INFO_CHARGER_STATUS_DISCONNECTED  = 0,
  BME_INFO_CHARGER_STATUS_CONNECTED     = 1
};

enum bme_info_ind_charging_state_e {
  BME_INFO_CHARGING_STATE_OFF         = 1,
  BME_INFO_CHARGING_STATE_ON          = 2,
  BME_INFO_CHARGING_STATE_ALMOST_FULL = 3,
  BME_INFO_CHARGING_STATE_FULL        = 4,
  BME_INFO_CHARGING_STATE_ERROR       = 5,
  BME_INFO_CHARGING_STATE_CONTINUE    = 6
};

/*
 * Message ID's
 */
#define BME_BATTERY_INFO_REQ    0x06
#define BME_INFO_IND            0x21

/**
 * Battery info request
 */
struct emsg_battery_info_req {
  uint16_t type; /**< BME_BATTERY_INFO_REQ */
  uint16_t subtype;
  uint32_t flags;
};

/**
 * Battery info reply
 */
struct emsg_battery_info_reply {
  uint32_t zero;
  uint32_t flags;
  uint16_t state;
  uint16_t bat_type;        /* bme_info_battery_type_e */
  uint16_t nominal_capa;
  uint16_t temp;            /* Kelvin */
  uint16_t voltage;
  uint16_t voltage_tx_on;
  uint16_t voltage_tx_off;
  uint16_t voltage_pwm_on;
  uint16_t voltage_pwm_off;
  uint16_t generation;
  uint16_t voltage_sh_chk;
};

union emsg_battery_info {
  struct emsg_battery_info_req request;
  struct emsg_battery_info_reply reply;
};

/**
 * EM info indication
 */
struct emsg_info_ind {
  uint16_t type;
  uint16_t subtype;
  uint32_t flags;
  uint8_t charger_status;   /* bme_info_charger_status_e */
  uint8_t charging_state;   /* bme_info_ind_charging_state_e */
  uint8_t charging_mode;
  uint8_t batt_max_num_bars;
  uint8_t batt_bars_data;
  uint8_t batt_power_data;
  uint16_t batt_idletime;
  uint16_t batt_usetime;
};

#endif
