/*
 * ============================================================================
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 * ============================================================================
 *
 * About: Versionar
 * El primero (X) se le conoce como version mayor y nos indica la version
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como version menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revision y nos indica que se hizo una revision del
 * 		codigo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : RC 6.13.2020 [Release Candidate v6.13] - FacuFalcone_LinkedList
 * ============================================================================
 */
/*
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif*/
#include <unistd.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void sleepWindowsOrLinux(int time){
	Sleep((time*500)); //windows (milisecs)
	//sleep(time); //linux (secs)
}

void opening(){
	system("color 03");
	system("mode con: cols=50 lines=32");
	printf("         ______________________ \n");
	sleepWindowsOrLinux(1);
	printf("        |######################|\n");
	sleepWindowsOrLinux(1);
	printf("        |######################|\n");
	sleepWindowsOrLinux(1);
	printf("        |######################|\n");
	sleepWindowsOrLinux(1);
	printf("        |#####|    \n");
	sleepWindowsOrLinux(1);
	printf("        |#####|                  __   __ \n");
	sleepWindowsOrLinux(1);
	printf("        |#####|                 |##| |##|\n");
	sleepWindowsOrLinux(1);
	printf("        |##############|     ___|##|_|##|___\n");
	sleepWindowsOrLinux(1);
	printf("        |##############|    |###############|\n");
	sleepWindowsOrLinux(1);
	printf("        |##############|    |###############|\n");
	sleepWindowsOrLinux(1);
	printf("        |#####|              ___|##| |##|___\n");
	sleepWindowsOrLinux(1);
	printf("        |#####|             |###############|\n");
	sleepWindowsOrLinux(1);
	printf("        |#####|             |###############|\n");
	sleepWindowsOrLinux(1);
	printf("        |#####|                 |##| |##|\n");
	sleepWindowsOrLinux(1);
	printf("        |#####|                 |##| |##|\n\n");
	sleepWindowsOrLinux(3);
	printf("            Freeware Born in Berazategui!\n");
	sleepWindowsOrLinux(3);
	printf("                  System Loading...\n");
	sleepWindowsOrLinux(4);
	printf("               Validating Resources...\n");
	sleepWindowsOrLinux(2);
	printf("               Resources Validated!\n\n\n");
	sleepWindowsOrLinux(2);
	printf("  Welcome to #TP3_LinkedList! [Windows version]\n\n\n");
	sleepWindowsOrLinux(2);
	system("cls"); // windows
	//system("clear"); // linux
}
