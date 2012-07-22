/**
   @file bmeipc.h

   @brief BME IPC function interface
   <p>
   Copyright (C) 2010 Nokia Corporation.

   @author Markus Lehtonen <markus.lehtonen@nokia.com>
   @author Matti Halme <matti.halme@nokia.com>

   This file is part of libopenbme.

   Libbme is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License
   version 2.1 as published by the Free Software Foundation.

   Libbme is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with libopenbme. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef BMEIPC_H
#define BMEIPC_H

#include <stdint.h>

#define BME_SRV_SOCK_PATH "/tmp/.bmesrv"
#define BME_SRV_COOKIE    "BMentity"

/* System message codes (not related to battery management) */
enum bme_sysmsg_e
{
  BME_SYSMSG_GETPID = 0x8000,   /* beyond ISI reuests range */
  BME_SYSMSG_PROXY_OPEN,
  BME_SYSMSG_PROXY_CLOSE,
  BME_SYSMSG_PROXY_GETTIME      /* 0x8003 get bme statistics */
};

/* for BME_SYSMSG_PROXY_GETTIME replies */
#define BME_LAST_STAT_IDX 32
typedef int32_t bmestat_t[BME_LAST_STAT_IDX];

/**
 * Retrieve statistics from BME server
 *
 * @param sd socket descriptor
 * @param stat the bmestat_t structure to populate
 *
 * @return nonzero if successful, -1 on error
 *
 * @ingroup bmeipc
 */
int32_t bmeipc_stat(int32_t sd, bmestat_t *stat);

/* NB! these values are not absolute. they may be wrong, as they were gathered
 * by sending a BME_SYSMSG_PROXY_GETTIME and making an awful lot of guesswork
 * based on the values returned. You have been warned. YMMV. */

/* offset inside bmestat_t to look for charger state */
#define CHARGER_STATE 1
#define CHARGER_STATE_CONNECTED 1

/* offset inside bmestat_t to look for charging state */
#define CHARGING_STATE 3
#define CHARGING_STATE_STARTED 1

/* offset inside bmestat_t to look for charging time (in minutes) */
#define CHARGING_TIME 5

/* offset inside bmestat_t to look for battery state */
#define BATTERY_STATE 7
#define BATTERY_STATE_LOW  2
#define BATTERY_STATE_FULL 4

/* offsets for battery bars inside bmestat_t */
#define BATTERY_LEVEL_MAX 8
#define BATTERY_LEVEL_NOW 9

/* offset inside bmestat_t for how many minutes the battery has left */
#define BATTERY_TIME_LEFT 11

/* how many percent the battery has left (note: never seems to hit 100?) */
#define BATTERY_LEVEL_PCT 16

/* end BME_SYSMSG_PROXY_GETTIME stuff */

/** Generic message */
typedef struct bmeipc_msg_s
{
  uint16_t type;
  uint16_t subtype;
} bmeipc_msg_t;

/** Server PID reply */
typedef struct bmeipc_pid_s
{
  uint32_t zero;
  uint32_t pid;
} bmeipc_pid_t;

/**
 * Receive BME data from socket
 *
 * @param fd socket descriptor
 * @param msg data address
 * @param bytes data size
 *
 * @return number of bytes read, -1 on error
 *
 * @ingroup bmeipc
 */
int32_t bme_packet_read(int32_t fd, void *msg, int32_t bytes);
int32_t bme_read(int32_t fd, void *msg, int32_t bytes);

/**
 * Send BME data to socket.
 *
 * @param fd socket descriptor
 * @param msg data address
 * @param bytes data size
 *
 * @return  number of bytes send, -1 on error
 *
 * @ingroup bmeipc
 */
int32_t bme_packet_write(int32_t fd, const void *msg, int32_t bytes);
int32_t bme_write(int32_t fd, const void *msg, int32_t bytes);

/**
 * Close connection to BME server
 *
 * @param sd The bme descriptor to close.
 *
 * @ingroup bmeipc
 */
void bmeipc_close(int32_t sd);

/**
 * Open connection to BME server
 *
 * @ingroup bmeipc
 *
 * @return socket descriptor on success, -1 on error
 */
int32_t bmeipc_open(void);

/* -------------------- BME messaging primitives -------------------- */

/** Send message to the server and get reply
 *
 * @param smsg address of a message to send
 * @param sbytes size of message to send
 * @param rmsg address of a reply buffer
 * @param rbytes size of reply buffer
 * @rbytes_act: actual size of reply got from the server
 *
 * @return  >= 0 on success, -1 on error
 *    NB: if rmsg is NULL reply status is returned
 */
int32_t bme_send_get_reply(int32_t fd, const void *smsg, int32_t sbytes,
                           void *rmsg, int32_t rbytes, int32_t * rbytes_act);

/**
 * Get a PID of BME server.
 *
 * @return  PID on success, -1 on error
 */
int32_t bme_get_server_pid(int32_t fd);

#endif /* BMEIPC_H */
