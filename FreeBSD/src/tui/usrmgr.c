/*
Copyright (c) 2015-2016, MrUNIXMan
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

* Neither the name of FreeBSD-SMIT nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------------------

Description: Usrmgr
User and Group Manager

----------------------------------------------------------------------------------------
*/

/* Default headers for SMIT  on all systems*/

#include <stdio.h>  // Standard IO;
#include <stdlib.h> // standard lib

#include <ncurses.h> // Ncurses header
//#include <ncurses/ncurses.h> // alternative location

#include <unistd.h>  // Unistd header
#include <string.h>  // String header
#include <pwd.h>    // Password Stuff

/* Custom Headers for SMIT */

#include "../include/smit.h"   // SMIT.h header
#include "../include/menu.h"	// Menu Specific header
#include "../shared/shared.h"   // Shared Functions


struct passwd *pw;
int PADCREATED = 0;
int maxuser;


/* Process the Users information and Place them on the PAD */

int process_users(void)
{
    int counter, line;
    counter = 1;
    line = 15;
    while((pw = getpwent() )) 
    {
	(void)mvwprintw(SPAREPAD, line, 2,  "%s", pw->pw_name);
	(void)mvwprintw(SPAREPAD, line, 18,  "%d", pw->pw_uid);
	(void)mvwprintw(SPAREPAD, line, 28,  "%d", pw->pw_gid);
	(void)mvwprintw(SPAREPAD, line, 48,  "%s", pw->pw_gecos);
	wmove(SPAREPAD, line++, 2);
	counter++;
	maxuser =  counter;
	mvprintw(5, y-5, "%d", maxuser);

	/* See shared.c for prefresh() */
	refresh_pad();
    }

    endpwent();
    return 0;
}



int user_manager_main()
{

    int key;
    
    while(key !='q')
    {

	/* See shared.c for the TUI drawing  as it is re-usable code */
        draw_mgrtui();
	
	int py, px; /* Pads X and Y */
	
        attron(A_BOLD);
        mvaddstr(1, y-20, "User Manager");
        
        mvaddstr(5, 4, "User");
        mvaddstr(5, 20, "User ID");
        mvaddstr(5, 30, "Group ID");

        mvaddstr(5, 50, "Comment");
        
        mvaddstr(5, y-20, "Total Users: ");
        	/* Shows total users on system */
	mvprintw(5, y-5, "%d", maxuser);
	refresh();

        
        
        if(PADCREATED != 1)
        {
    	    SPAREPAD = newpad(200, 100);
            getmaxyx(SPAREPAD, py, px);
    	    scrollok(SPAREPAD, TRUE);
    	    PADCREATED = 1;
    	}
    	
        
        process_users();
        /* See Spare.c for refresh_Pad and prefresh() */
	refresh_pad();
        
        
        
        key = getch();
    }




    return 0;
}
