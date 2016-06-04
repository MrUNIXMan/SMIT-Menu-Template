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
#include <fstab.h>    // fstab

/* Custom Headers for SMIT */

#include "../include/smit.h"   // SMIT.h header
#include "../include/menu.h"	// Menu Specific header
#include "../shared/shared.h"   // Shared Functions


struct fstab *fs;
int PADCREATEDFS = 0;
int maxfs;


/* Process the fstab information and Place them on the PAD */

int process_fstab(void)
{
    int counter, line;
    counter = 1;
    line = 15;
    setfsent();
    while((fs = getfsent() )) 
    {
	(void)mvwprintw(SPAREPAD, line, 2,  "%s", fs->fs_spec);
	(void)mvwprintw(SPAREPAD, line, 18,  "%s", fs->fs_vfstype);
	(void)mvwprintw(SPAREPAD, line, 28,  "%s", fs->fs_file);
	(void)mvwprintw(SPAREPAD, line, 48,  "%s", "FSTAB");
	wmove(SPAREPAD, line++, 2);
	counter++;
	maxfs =  counter;
	mvprintw(5, y-5, "%d", maxfs);

	/* See shared.c for prefresh() */
	refresh_pad();
	
    }
    /* Keep this outside of the loop it causes infinate loop on 1st entry */
    endfsent();

    return 0;
}



int filesystem_manager_main()
{

    int key;
    
    while(key !='q')
    {

	/* See shared.c for the TUI drawing  as it is re-usable code */
        draw_mgrtui();
	
	int py, px; /* Pads X and Y */
	
        attron(A_BOLD);
        mvaddstr(1, y-21, "Filesystems Manager");
        
        mvaddstr(5, 4, "Filesystem");
        mvaddstr(5, 20, "Type");
        mvaddstr(5, 30, "Mount Point");

        mvaddstr(5, 50, "State");
        
        mvaddstr(5, y-20, "Total Entries: ");
        	/* Shows total users on system */
	mvprintw(5, y-5, "%d", maxfs);
	refresh();

        
        
        if(PADCREATEDFS != 1)
        {
    	    SPAREPAD = newpad(200, 100);
            getmaxyx(SPAREPAD, py, px);
    	    scrollok(SPAREPAD, TRUE);
    	    PADCREATEDFS = 1;
    	}
    	
        
        process_fstab();
        /* See Spare.c for refresh_Pad and prefresh() */
	refresh_pad();
        
        
        
        key = getch();
    }




    return 0;
}
