/**
   @file bmeipc.h

   @brief BME IPC function interface
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
int32_t bme_read(void *msg, int32_t bytes);

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
int32_t bme_write(const void *msg, int32_t bytes);

/**
 * Close connection to BME server
 *
 * @ingroup bmeipc
 */
void bme_disconnect(void);

/**
 * Open connection to BME server
 *
 * @ingroup bmeipc
 *
 * @return socket descriptor on success, -1 on error
 */
int32_t bme_connect(void);

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
int32_t bme_send_get_reply(const void *smsg, int32_t sbytes,
                           void *rmsg, int32_t rbytes, int32_t * rbytes_act);

/**
 * Get a PID of BME server.
 *
 * @return  PID on success, -1 on error
 */
int32_t bme_get_server_pid(void);

/**
 * Read BME cookie
 *
 * @param fd socket descriptor to receive cookie from
 * @param cookie cookie
 *
 * @return  0 on success, -1 on error
 */
int32_t bme_cookie_read(int32_t fd, const char *cookie);

/**
 * Write BME cookie
 *
 * @param fd socket descriptor to send cookie to
 * @param cookie cookie
 *
 * @return  0 on success, -1 on error
 */
int32_t bme_cookie_write(int32_t fd, const char *cookie);

#endif /* BMEIPC_H */
