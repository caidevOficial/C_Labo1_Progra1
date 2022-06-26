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
 * Version     : Beta 3.0.0 [Beta v3.0.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
 * ============================================================================
 */

#include <unistd.h>
//#include <windows.h>
//#include <stdio.h> // windows
#include <stdio_ext.h> //linux
#include <stdlib.h>

void saintSeiyaAnimation() {
	printf(
			"                    ..######.....###....####.##....##.########...\n"
					"                    .##....##...##.##....##..###...##....##......\n"
					"                    .##........##...##...##..####..##....##......\n"
					"                    ..######..##.....##..##..##.##.##....##...... \n"
					"                    .......##.#########..##..##..####....##...... \n"
					"                    .##....##.##.....##..##..##...###....##......\n"
					"                    ..######..##.....##.####.##....##....##......\n\n"

					"                    ..######..########.####.##....##....###... \n"
					"                    .##....##.##........##...##..##....##.##.. \n"
					"                    .##.......##........##....####....##...##. \n"
					"                    ..######..######....##.....##....##.....##\n"
					"                    .......##.##........##.....##....#########\n"
					"                    .##....##.##........##.....##....##.....## \n"
					"                    ..######..########.####....##....##.....## \n");
}

void sleepWindowsOrLinux(int time){
	//Sleep((time*1000)); //windows (milisecs)
	sleep((time)); //linux (secs)
}

void opening(int animF, int animLoad) {
	//system("color 03");
	//system("mode con: cols=50 lines=32");
	printf("                    ______________________ \n");
	sleepWindowsOrLinux(animF);
	printf("                   |######################|\n");
	sleepWindowsOrLinux(animF);
	printf("                   |######################|\n");
	sleepWindowsOrLinux(animF);
	printf("                   |######################|\n");
	sleepWindowsOrLinux(animF);
	printf("                   |#####|    \n");
	sleepWindowsOrLinux(animF);
	printf("                   |#####|                  __   __ \n");
	sleepWindowsOrLinux(animF);
	printf("                   |#####|                 |##| |##|\n");
	sleepWindowsOrLinux(animF);
	printf("                   |##############|     ___|##|_|##|___\n");
	sleepWindowsOrLinux(animF);
	printf("                   |##############|    |###############|\n");
	sleepWindowsOrLinux(animF);
	printf("                   |##############|    |###############|\n");
	sleepWindowsOrLinux(animF);
	printf("                   |#####|              ___|##| |##|___\n");
	sleepWindowsOrLinux(animF);
	printf("                   |#####|             |###############|\n");
	sleepWindowsOrLinux(animF);
	printf("                   |#####|             |###############|\n");
	sleepWindowsOrLinux(animF);
	printf("                   |#####|                 |##| |##|\n");
	sleepWindowsOrLinux(animF);
	printf("                   |#####|                 |##| |##|\n\n");
	sleepWindowsOrLinux(animF);
	printf("                       Freeware Born in Berazategui!\n");
	sleepWindowsOrLinux(animF);
	printf("                             System Loading...\n");
	sleepWindowsOrLinux(animLoad);
	printf("                          Validating Resources...\n");
	sleepWindowsOrLinux(animLoad);
	printf("                          Resources Validated!\n\n\n");
	sleepWindowsOrLinux(animF);
	printf("                Welcome to #TP4_LinkedList_[SaintSeiya]!\n"
			"                             [Linux Version]\n\n");
	sleepWindowsOrLinux((animLoad * 3));
	//system("cls"); // windows
	system("clear"); // linux
		saintSeiyaAnimation();
	sleepWindowsOrLinux(3);
		system("clear");
}
