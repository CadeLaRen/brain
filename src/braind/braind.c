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
/* brain daemon; primary server process that services requests to translate
 between natural language and meanings, and visa-versa. */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdarg.h>

#include "conf.h"
#include "../util/util.h"
#include "log.h"
#include "err.h"

#include "kn.h"
#include "nl.h"


void brain_uds_start(void);


/* handle fatal errors */
void fatal(char const *in_message, ...)
{
    va_list args;
    va_start(args, in_message);
    lvprintf(BRAIN_ERROR, in_message, args);
    va_end(args);
    exit(EXIT_FAILURE);
}


static void start_daemon(void)
{
    /* initalize basic logging to screen/syslog 
     until configuration loaded */
    log_init(NULL, SYSLOG_DAEMON);
    
    /* load the configuration file */
    load_config();
    
    /* initalize the knowledge network
     and natural language processing engine */
    if (kn_startup()) fatal("couldn't initalize knowledge network");
    if (nl_startup()) fatal("couldn't initalize natural language engine");
    
    /* start the request handling service */
    brain_uds_start();
}


int main(int argc, const char * argv[])
{
    start_daemon(); /* only if the command line arguments request it */
    
    
    
    
    return 0;
}
