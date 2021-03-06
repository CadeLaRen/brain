/*
 
 Brain Rarely Accepts Incoherent Nonsense (BRAIN)
 Copyright 2012-2013 Joshua Hawcroft
 
 This file is part of BRAIN.
 
 BRAIN is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 BRAIN is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with BRAIN.  If not, see <http://www.gnu.org/licenses/>.
 
 */
#ifndef BRAIN_CONFIG_H
#define BRAIN_CONFIG_H

#ifdef HAVE_CONFIG_H
#include "compile.h"

#else
#define PACKAGE_STRING "BRAIN"
#define PACKAGE_BUGREPORT "dev@joshhawcroft.org"
#define PACKAGE_URL "http://joshhawcroft.org/"

#endif


/* default configuration;
 (ordinarily these will be set by make) */
#ifndef BRAIN_CONFIG
#define BRAIN_CONFIG "/etc/brain/brain.conf"
#endif
#ifndef BRAIN_BIN_DIR
#define BRAIN_BIN_DIR "/usr/local/brain/bin/"
#endif
#ifndef BRAIN_THOUGHTS_DIR
#define BRAIN_THOUGHTS_DIR "/usr/local/brain/thoughts/"
#endif
#ifndef BRAIN_SOCKET
#define BRAIN_SOCKET "/var/run/braind.sock"
#endif
#ifndef BRAIN_PID
#define BRAIN_PID "/var/run/braind.pid"
#endif
#ifndef BRAIN_LOG
#define BRAIN_LOG "/var/log/brain.log"
#endif


/* can be overridden by the brain.conf */
#define BRAIN_BUFFER 16384



/* deprecated */
#define BRAIN_CONFIG_DIR "/etc/brain/"
#define BRAIN_CONFIG_FILE "brain.conf"

#define BRAIND_SERVER_SOCK "/var/run/braind.sock"

#define BRAIND_INSTALL_DIR "/usr/local/sbin/brain/"


#endif



