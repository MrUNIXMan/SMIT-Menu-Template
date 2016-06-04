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
--------------------------------------------------------------------------------------- */
#include <stdio.h>  // Standard IO;
#include <stdlib.h> // standard lib

//#include <ncurses/ncurses.h> // Alternative Solaris Header
#include <ncurses.h> // Ncurses header



#include <unistd.h>  // Unistd header
#include <string.h>  // String header

#include "../include/menu.h" // Menu.h 
#include "../shared/shared.h"

/* This draws a box on stdscr */
int x, y;

//WINDOW *SPAREWIN;

void draw_screen_outline()
{
//	int x, y;
    clear();
    getmaxyx(stdscr, x,y);
    box(stdscr, ACS_VLINE, ACS_HLINE);
    refresh();

}


void draw_mgrtui()
{
    int sy, sx;
    draw_screen_outline();
    place_function_keys();
    
    mvprintw(1, 2, "Press 'q' to quit");
    mvhline(3,1, ACS_HLINE, y-3);
    mvvline(1, y-23, ACS_VLINE, 2);
    
    
    SPAREWIN = newwin(x-12, y-4, 6, 2);
    getmaxyx(SPAREWIN, sy, sx);
    box(SPAREWIN, ACS_VLINE, ACS_HLINE);
    wrefresh(SPAREWIN);
    refresh();

}

void place_function_keys()
{
    int x,y; 
    getmaxyx(stdscr, y, x);
    
    attron(A_BOLD);
    mvaddstr(y-4, 2, FKEY1);
    mvaddstr(y-3, 2, FKEY2);
    attroff(A_BOLD);


}

/* Used by Both Forms */

void refresh_pad()
{

	/* prefresh arguments 
	  
	          prefresh(PAD NAME, pminrow, pmincol, sminrow, smincol, smaxrow, smaxcol); 
	          prefresh(SPAREPAD,15, 1, 7, 3,14, 15); */
	          
	          int sy, sx;
	          getmaxyx(SPAREWIN, sy,sx);
	          
	           prefresh(SPAREPAD,15, 1, 7, 3,sy+4, sx-2);


}
