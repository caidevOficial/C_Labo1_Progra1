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

//#include <Windows.h>
#include "logOut.h"
#include <unistd.h>
//#include <stdio_ext.h> // linux
#include <stdio.h> // windows
#include <stdlib.h>
#include "logIn.h"

int interfazShutdown(){
	system("mode con: cols=80 lines=30");
	printf("\nA problem has been detected and Windows has been shut down to prevent damage\n"
			"to your computer.\n\n"
			"ITS_A_JOKE_JAJAJAJA.\n\n"
			"if this is the first time you've seen this stop error screen,\n"
			"restart your computer. If this screen appears again, follow\n"
			"these steps:\n\n"
			"1 - Enjoy a delicious cup of coffee, watching this freeware.\n"
			"2 - Rate this practical work with a 10/10.\n"
			"3 - Be always happy.\n\n"
			"If problems continue, disable or remove any newly installed hardware\n"
			"or freeware. Disable BIOS memory options such as caching or shadowing.\n"
			"If you need to use Safe Mode to remove or disable components, restart\n"
			"your computer, press F8 to select Advanced Startup Options, and then\n"
			"Select Safe Mode.\n\n"
			"Technical Information:\n\n"
			"*** STOP: 0x00000098 (0x986C83A0, 0X01C7DAB7, 0X0002A300, 0X00000000)\n\n"
			"                       ITS_A_JOKE :D\n\n");
	return 0;
}


void animacionShutdown(){
	//int i;
	/*for (i=0;i<101;i=i+20){
		//system("cls"); // En windows
		system("clear"); // En Linux
		system("color 17"); // Screen: Blue - Text: White
		interfazShutdown();
		//printf("           |    -> Reiniciando sistema %d%c <-     |\n",i,'%');
		//if (i<100){
		//	sleep(750);
		//}
		//else{
		//	sleep(1250);
		//}
	}*/
	system("color 17"); // Screen: Blue - Text: White
	interfazShutdown();
	sleepWindowsOrLinux(2);
	printf("      |          -> [Bot_Apu] Saliendos del programas <-          |\n");
	sleepWindowsOrLinux(2);
	printf("      |         -> [Bot_Apu]: Gracias, vuelvas prontos! <-        |\n");
	sleepWindowsOrLinux(2);
	system("cls"); // En windows
	//system("clear"); //en linux
}

char caseSalir(){
	char respuesta;
	system("cls"); // En windows
	//system("clear"); // En Linux
	system("mode con: cols=50 lines=12");
	animacionShutdown();
	respuesta = 'n';
	//__fpurge(stdin); // linux
	fflush(stdin); // windows

	return respuesta;
}
