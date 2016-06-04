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

Description: Menu File

Contains Menus

----------------------------------------------------------------------------------------
*/

/* Default headers for SMIT  on all systems*/

#include <stdio.h>  // Standard IO;
#include <stdlib.h> // standard lib

#include <ncurses.h> // Ncurses header
//#include <ncurses/ncurses.h> // alternative location

#include <unistd.h>  // Unistd header
#include <string.h>  // String header

/* Custom Headers for SMIT */

#include "../include/smit.h"   // SMIT.h header
#include "../include/menu.h"	// Menu Specific header
#include "../shared/shared.h"


/* Main Menu */

/* [MAX] - Values for each menu is found in menu.h
 * 
 * 
 */ 
char mainmenuitems[MMAX] [34] = {"System Information",
								"User & Group Manager",
								"Filesystems Manager",
								"Software",
								"Network Managment",
								"Systems Configuration",
								"Help",
								"About OpenSMIT",
								"Quit"};	
/* System Information Menu */

char sysinfoitems [SIMAX] [34] = {"Systems Spec",
								 "Show Logged in Users",
								 "Show Mounted Filesystems",
								 "Show Disk Spaces",
								 "Show loaded Kernel Modules",
								 "Exit from System Information"};
/* System Configuration */

char syscfgitems [SCMAX] [34] = {"Edit boot loader file",
								 "Edit /etc/hosts",
								 "Edit /etc/rc.conf",
								 "Edit /etc/fstab",
								 "Edit /etc/X11/xorg.conf",
								 "Kernel Configuration Manager",
								 "Help",
								 "Quit the Configuration Menu"};
								
void menu_details()
{
	int y, x;	
	getmaxyx(stdscr, y,x);
	clear();
	box(stdscr, ACS_VLINE, ACS_HLINE);
	attron(A_BOLD);
	mvaddstr(3, 2, MnuMesg);
	place_function_keys();
//	mvaddstr(y-4,2, FKEY1); /* Bottom Bar */
//	mvaddstr(y-3,2, FKEY2); /* Bottom Bar */
	attroff(A_BOLD);
	
}


/* Main Menu Specific Stuff */


void process_main_menu(int mmitem)
{
	
	menu_details();
	attron(A_BOLD);
	mvaddstr(1, 27, MainMenuName);
	attroff(A_BOLD);
	
	int MainMenuCTR;
	
	
	/* Show the Menu Items */
	
	for (MainMenuCTR=0; MainMenuCTR < MMAX; MainMenuCTR++)
		{
			if(MainMenuCTR==mmitem)
			
				attron(A_REVERSE);
				mvaddstr(5+(MainMenuCTR*1), 5, mainmenuitems[MainMenuCTR]);
				attroff(A_REVERSE);
			
		}
	refresh();
	
}

void process_sysinfo_menu(int siitem)
{
	menu_details();
	attron(A_BOLD);
	mvaddstr(1, 27, SIMenu);
	attroff(A_BOLD);
	
	
	int SIMenuCTR;
	
	
	/* Show the Menu Items */
	
	for (SIMenuCTR=0; SIMenuCTR < SIMAX; SIMenuCTR++)
		{
			if(SIMenuCTR==siitem)
			
				attron(A_REVERSE);
				mvaddstr(5+(SIMenuCTR*1), 5, sysinfoitems[SIMenuCTR]);
				attroff(A_REVERSE);
			
		}
	refresh();
	
	
}

void process_sysconf_menu(int scitem)
{
	menu_details();
	attron(A_BOLD);
	mvaddstr(1, 27, SystemCfgMenu);
	attroff(A_BOLD);
	
	
	int SCMenuCTR;
	
	
	/* Show the Menu Items */
	
	for (SCMenuCTR=0; SCMenuCTR < SCMAX; SCMenuCTR++)
		{
			if(SCMenuCTR==scitem)
			
				attron(A_REVERSE);
				mvaddstr(5+(SCMenuCTR*1), 5, syscfgitems[SCMenuCTR]);
				attroff(A_REVERSE);
			
		}
	refresh();
	
	
}


void draw_menu_screen(char menutype[])
{
//	draw_screen_outline();
	
	
	/* Draw the Main Menu */
	if(strcmp(menutype, "main") == 0)
	{
		
		int MMITEMS=0, MMKey;
		
		while(MMITEMS != 8) {
			process_main_menu(MMITEMS);
			refresh();
			
			do 
			{
				MMKey = getch();
				switch(MMKey)
				{
					case KEY_UP:
					 MMITEMS--;
					 if(MMITEMS < 0) MMITEMS = MMAX-1;
					break;
					case KEY_DOWN:
					 MMITEMS++;
					 if(MMITEMS > MMAX) MMITEMS = 0;
					break;
					
				}
				process_main_menu(MMITEMS);
				refresh();
				} while(MMKey != '\n');
				
				/* Main Menu Responses */
				
				if(MMITEMS == 0)
				{
					draw_menu_screen("sysinfo");
					
				}
				
				if (MMITEMS == 1)
				{
				     user_manager_main();
				}
				
				if (MMITEMS == 2)
				{
				     filesystem_manager_main();
				}
				
				if (MMITEMS == 3)
				{
				     group_manager_main();
				}
				
				if(MMITEMS == 5)
				{
					draw_menu_screen("syscfg");
					
				}
				
	
		}
	}  // End of Strcmp 
	
	/* System Info Menu */
	
	if(strcmp(menutype, "sysinfo") == 0) 
	{
		int SIItems, SIKey;
		SIItems = 0;
		
		while(SIItems != 5) {
			process_sysinfo_menu(SIItems);
			refresh();
			
			do 
			{
				SIKey = getch();
				switch(SIKey)
				{
					case KEY_UP:
					 SIItems--;
					 if(SIItems < 0) SIItems = SIMAX-1;
					break;
					case KEY_DOWN:
					 SIItems++;
					 if(SIItems > SIMAX) SIItems = 0;
					break;
					
				}
				process_sysinfo_menu(SIItems);
				refresh();
				} while(SIKey != '\n');
		
		
		process_sysinfo_menu(SIItems);
		//draw_screen_outline();
	}	
		
  } // End of Strcmp
  
  
  /* System Config Menu */
	
	if(strcmp(menutype, "syscfg") == 0) 
	{
		int SCItems, SCKey;
		SCItems = 0;
		
		while(SCItems != 7) {
			process_sysconf_menu(SCItems);
			refresh();
			
			do 
			{
				SCKey = getch();
				switch(SCKey)
				{
					case KEY_UP:
					 SCItems--;
					 if(SCItems < 0) SCItems = SCMAX-1;
					break;
					case KEY_DOWN:
					 SCItems++;
					 if(SCItems > SCMAX) SCItems = 0;
					break;
					
				}
				process_sysconf_menu(SCItems);
				refresh();
				} while(SCKey != '\n');
		
		
		process_sysconf_menu(SCItems);
//		draw_screen_outline();
	}	
		
  } // End of Strcmp
	
	
	
	
}  // End of Function
