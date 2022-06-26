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
 * 							#Biblioteca
 *
 * About: Versionar
 * El primero (X) se le conoce como version mayor y nos indica la version
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como version menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revision y nos indica que se hizo una revision del
 * 		codigo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : 1.1.13 [Release Candidate v1.1]
 *
 * @author	CaiDev - FacuFalcone
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

//Bibliotecas
#include "Library/Library.Validate/caidevValidate.h"
#include "Library/ArrayEmployees/ArrayEmployees.h"

#define LEN 10
#define HARCO 10

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
		system("cls"); // En windows
		//system("clear"); // En Linux
		system("color 17"); // Screen: Blue - Text: White
		interfazShutdown();
		printf("           |    -> Reiniciando sistema %d%c <-     |\n",i,'%');
		if (i<100){
			Sleep(750);
		}
		else{
			Sleep(1250);
		}
	}
	Sleep(1500);
	printf("           |          -> Shutting Down <-          |\n");
	Sleep(1500);
	printf("           |       -> Ojala apruebe <3 ;) <-       |\n");
	Sleep(2000);
	system("cls"); // En windows
	//system("clear"); //en linux

	return 0;
}

char caseSalir(){
	char respuesta;
	system("cls"); // En windows
	//system("clear"); // En Linux
	system("mode con: cols=50 lines=12");
	animacionShutdown();
	respuesta = 'n';
	fflush(stdin);

	return respuesta;
}

int ABM(void){
	char confirm = 'y';
	Employee list[HARCO] = {//  ID - NAME -    SURNAME -   SALARY - SECTOR -  Empty
									{1000,"Facu",		"Falcone",	95000,		1, 		0},
									{1001,"Caidev",		"Sama",		56000,		1,		0},
									{1002,"Albafica",	"dePiscis",	90000,		2,		0},
									{1003,"Afrodita",	"dePiscis",	86000,		3,		0},
									{1004,"Mu",			"deAries",	55000,		3,		0}};
	//Employee list[LEN];
	int id;
	int freeId = 1005;
	int sortOrder;
	char answer = 'y';
	int totalSalary;
	float averageSalary;

	//Datos ABM para cargar los datos #DESCOMENTAR SI NO SE HARDCODEA
	//initEmployees(list,LEN); // Comentar para hardcodear

	// menu de opciones
	do{
		switch( menu()){
		case 'a': // Alta
			system("cls");
			printf("*** Employee registration ***\n\n");
			chargeEmployeeData(list, LEN, &freeId);

			break;
		case 'b': // Modificacion
			modifyEmployee(list,LEN);
			break;
		case 'c': // Baja
			system("cls");
			printf("*** Unsuscribe Employee ***\n\n");
			printEmployees(list,HARCO); // muestro los empleados.
			utn_getNumero(&id,"\nPlease, type The ID to remove: ","\nERROR, please retype: ",0,5000,10);
			removeEmployee(list, LEN, id);
			break;
		case 'd': // Sort
			system("cls");
			printf("*** Report Menu ***\n\n");

			printf("What do you want to do?\n"
					"[0] - Sort Descending. [Lastname - sector]\n"
					"[1] - Sort Ascending.  [Lastname - sector]\n"
					"[2] - Total & average Salary. \n"
					"[3] - Qtty Employees w/ Bigger salary than the average\n");
			utn_getNumero(&sortOrder,"\nPlease, type an option: ","\nERROR, please retype: ",0,3,10);
			if (sortOrder==0){ // Descending
				sortEmployees(list,LEN,sortOrder);
			}
			else if (sortOrder==1){ // Ascending
				sortEmployees(list,LEN,sortOrder);
			}
			else if (sortOrder==2){
				totalAverageSalary(&totalSalary, &averageSalary,list,LEN);
			}
			else if (sortOrder==3){
				if (&averageSalary >=0){
					knowHowManySalaryBigger(&averageSalary,1, list,LEN);
				}
				else{
					printf("\nYou need to calculate the average Salary first.\n");
				}
			}

			break;

		case 'e': // Get Out
			printf("Confirm?. y/n\n");
			fflush(stdin);
			getString(&confirm,sizeof(confirm));
			if (confirm == 'y'){
				printf("Gracias, vuelvas prontos! \n");
				answer = caseSalir();
				//answer = 'n';
			}
			break;
		default: // Error
			printf("\nIncorrect Option, please retype from A to G:");
			break;


		}
		system("pause");
		system("cls");
	}while(answer=='y');

	return EXIT_SUCCESS;
}
