/**
   @file bmeipccookie.c

   @brief BME IPC extra cookie functions
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

#include "bmeipc.h"
#include "bmeipc-internal.h"
#include "bmeipccookie.h"

int bme_cookie_read(int fd, const char *cookie)
{
  return _bme_cookie_read(fd, cookie);
}

int bme_cookie_write(int fd, const char *cookie)
{
  return _bme_cookie_write(fd, cookie);
}
