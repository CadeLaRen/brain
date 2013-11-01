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
/* configuration file loader and globals */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "../config.h"
#include "../util/util.h"
#include "../util/confscan.h"
#include "conf.h"
#include "log.h"
#include "err.h"


#define CONFIG_ERROR -1
#define CONFIG_OK 0

#define BRAIND_LOG_NAME "braind.log"


static void use_log_file(char const *in_name)
{
    /* reinit the logging */
    log_init(make_name(in_name, BRAIND_LOG_NAME), SYSLOG_DAEMON);
}


static int scan_conf_line_(long in_line_number, char const *in_key, char const *in_value)
{
    if (strcmp(in_key, "log-dir") == 0)
        use_log_file(in_value);
    
    /*if (strcmp(in_key, "thought-dir") == 0)
        g_script_dir = strdup(in_value);
    else if (strcmp(in_key, "log-dir") == 0)
        g_log_dir = strdup(in_value);
    else
    {
        fprintf(stderr, "Unknown configuration option \"%s\" on line %ld of brain.conf.\n", in_key, in_line_number);
        return CONFIG_ERROR;
    }*/
    return CONFIG_OK;
}


void load_config(void)
{
    int err;
    char *config_file = brain_strdup(make_name(BRAIN_CONFIG_DIR, BRAIN_CONFIG_FILE));
    lprintf(BRAIN_ERROR, "not enough memory to load configuration file");
    if ( ( err = confscan(config_file, &scan_conf_line_)) )
    {
        switch (err)
        {
            case ENOENT:
                lprintf(BRAIN_ERROR, "configuration file %s not found", config_file);
                break;
            case EACCES:
                lprintf(BRAIN_ERROR, "insufficient privileges to access configuration file %s", config_file);
                break;
            default:
                lprintf(BRAIN_ERROR, "error %d reading configuration file %s", err, config_file);
                break;
        }
        exit(EXIT_FAILURE);
    }
}

