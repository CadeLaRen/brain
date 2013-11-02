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
/* brain shell; command-line interface to make requests of, and receive output
 from the BRAIN system */

#include "ui.h"
#include "client.h"
#include "error.h"


int main(int argc, const char * argv[])
{
    
    /* need to handle command line args,
     and read configuration file for brain, and for brsh here */
    
    client_connect("/Users/josh/brain/brain.sock");
    brsh();
    
    return 0;
}

