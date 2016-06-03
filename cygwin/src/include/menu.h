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
*/


#ifndef MENU_H_
#define MENU_H_

extern int y, x;	

#define MMAX 10  // Main Menu Max
#define SCMAX 8 // System Config Max
#define NMAX  10 // Network Menu Max
#define SOMAX 10 // Software Menu Max
#define SIMAX 6 // System Information Max


/* Names of Menus from the Main Menu */

static char MainMenuName[] = "Systems Managament Main Menu";
static char SystemCfgMenu[] = "System Configuration";
static char NetworkMenu[] = "Network Managment";
static char SoftwareMenu[] = "Software Managment";
static char SIMenu[] = "System Information";

static char MnuMesg[] = "Please move the cursor to desired item and press Enter";

 static char FKEY1[] = "F1=Help		F2=Refresh		F3=Cancel";
 static char FKEY2[] = "F9=Shell		F10=Quit		Enter=Do"; 			/*Controls on bottom */










#endif
