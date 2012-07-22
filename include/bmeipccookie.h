/**
   @file bmeipc.h

   @brief BME IPC extra cookie functions
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

#ifndef BMEIPCCOOKIE_H
#define BMEIPCCOOKIE_H

#include <stdint.h>

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

#endif /* BMEIPCCOOKIE_H */
