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
 * #CalculadorApp
 *
 * About: Versionar
 * El primero (X) se le conoce como versión mayor y nos indica la versión
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como versión menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revisión y nos indica que se hizo una revisi�n del
 * 		c�digo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : 3.4.2 [Release Candidate v3.4]
 * ============================================================================
 */
/*
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif*/

//#include <Windows.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include "logOut.h"

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


int animacionShutdown(){
	int i;
	for (i=0;i<101;i=i+20){
		//system("cls"); // En windows
		system("clear"); // En Linux
		system("color 17"); // Screen: Blue - Text: White
		interfazShutdown();
		printf("           |    -> Reiniciando sistema %d%c <-     |\n",i,'%');
		if (i<100){
			sleep(750);
		}
		else{
			sleep(1250);
		}
	}
	sleep(1500);
	printf("           |          -> Shutting Down <-          |\n");
	sleep(1500);
	printf("           |         -> Ojala apruebe <3 <-        |\n");
	sleep(2000);
	//system("cls"); // En windows
	system("clear"); //en linux

	return 0;
}

char caseSalir(){
	char respuesta;
	//system("cls"); // En windows
	system("clear"); // En Linux
	system("mode con: cols=50 lines=12");
	animacionShutdown();
	respuesta = 'n';
	fflush(stdin);

	return respuesta;
}
