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


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>

#include "App.Header\ecuaciones.h"



//OPERACIONES DEL SWITCH

int caseIngresoPrimerNumero(int* numero1Auxiliar, int* numero2Auxiliar, int* pFlagNum1){
	int primerOpcionElegida;
	int flag1;
	system("color 0E"); // Screen: Black - Text: Light Yellow
	borrarPantallaYPonerMenuVacio();
	*numero1Auxiliar = ingresoNumero(); // Pongo primer numeral
	*pFlagNum1 = 1; // actualizo su flag
	flag1 = *pFlagNum1; // copio el flag
	borrarPantallaYPonerMenu(1, *numero1Auxiliar, *numero2Auxiliar); // pongo el menu nuevo con el 1er operando
	printf("  ->|   Hint: Continua por la opcion [2]   |<-\n");
	primerOpcionElegida = opcionElegidaPorUsuario();
		do{
			if (flag1==1 && (primerOpcionElegida!=5 && primerOpcionElegida!=2)){
				borrarPantallaYPonerMenu(1, *numero1Auxiliar, *numero2Auxiliar);
				printf("  ->|    ERROR: Continua por opcion [2]    |<-\n");
				printf("  ->|   ERROR: Para Salir usa opcion [5]   |<-\n");
				primerOpcionElegida = opcionElegidaPorUsuario();
			}
		}while (primerOpcionElegida!=2 && primerOpcionElegida!=5);

	return primerOpcionElegida;
}

int caseIngresoSegundoNumero(int* numero1Auxiliar, int* numero2Auxiliar, int* pFlag1, int* pFlag2){
	int opcionElegida;
	int flag1;
	system("color 04"); // Screen: Black - Text: Red
	flag1= *pFlag1;
	if (flag1==1){
		borrarPantallaYPonerMenu(1,*numero1Auxiliar, *numero2Auxiliar);
		*numero2Auxiliar = ingresoNumero();
		*pFlag2 = 1;
		borrarPantallaYPonerMenu(2,*numero1Auxiliar, *numero2Auxiliar);
		printf("  ->|   Hint: Continua por la opcion [3]   |<-\n");
		opcionElegida = opcionElegidaPorUsuario();
		do{
			if (opcionElegida!=5 && opcionElegida!=3){
				borrarPantallaYPonerMenu(2,*numero1Auxiliar, *numero2Auxiliar);
				printf("  ->|    ERROR: Continua por opcion [3]    |<-\n");
				printf("  ->|       Para Salir usa opcion [5]      |<-\n");
				opcionElegida = opcionElegidaPorUsuario();
			}
		}while (opcionElegida!=3 && opcionElegida!=5);
	}
	else{
		borrarPantallaYPonerMenuVacio();
		printf("  ->|ERROR: Deberias empezar por opcion [1]|<-\n");
		printf("  ->|       Para Salir usa opcion [5]      |<-\n");
		opcionElegida = opcionElegidaPorUsuario();
	}
	return opcionElegida;
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


// FUNCION PRINCIPAL

int CalculadorApp(){
	system("color 02"); // Screen: Black - Text: Green
	opening();

	// Variables de resultados
	double resultadoSuma;
	double resultadoResta;
	double resultadoMult;
	double resultadoDiv;
	double factorialA;
	double factorialB;

	// Variables de operandos
	int numero1Auxiliar;
	int numero2Auxiliar;

	//Respuesta de bucle
	char respuesta = 's';

	//Opcion seleccionada del menu
	//int opcion2;
	int opcionElegida; // Switch ppal.
	int opcionSubMenu; //Switch secundario.

	//Flags
	int flagNum1 = 0;
	int flagNum2 = 0;
	int flagResultados = 0;
	int flagMostrarResultados = 0;

	borrarPantallaYPonerMenuVacio();
	printf("  ->|    Hint: Empeza por la opcion [1]    |<-\n");
	opcionElegida = opcionElegidaPorUsuario();
	do{
		switch(opcionElegida){
		case 1: //ingreso primer numero

			opcionElegida = caseIngresoPrimerNumero(&numero1Auxiliar, &numero2Auxiliar, &flagNum1);
			break;
		case 2: // ingreso segundo numero
			opcionElegida = caseIngresoSegundoNumero(&numero1Auxiliar, &numero2Auxiliar, &flagNum1, &flagNum2);

			break;
		case 3: // "calcular" resultados
			system("color 0D"); // Screen: Black - Text: Light Violet
			if (flagNum2==0 && flagNum1==1){
					borrarPantallaYPonerMenu(1, numero1Auxiliar, numero2Auxiliar);
					printf("     ______________________________________\n");
					printf("  ->|ERROR: Deberias continuar x opcion [2]|<-\n");
					printf("  ->|ERROR:    Para Salir usa opcion [5]   |<-\n");
					opcionElegida = opcionElegidaPorUsuario();
				}
				else {
					if (flagNum1==0){
						borrarPantallaYPonerMenuVacio();
						printf("     ______________________________________\n");
						printf("  ->|ERROR: Deberias continuar x opcion [1]|<-\n");
						printf("  ->|ERROR:    Para Salir usa opcion [5]   |<-\n");
						opcionElegida = opcionElegidaPorUsuario();
					}
					else {
						resultadoSuma = suma(numero1Auxiliar,numero2Auxiliar);
						resultadoResta = resta(numero1Auxiliar,numero2Auxiliar);
						resultadoMult = multiplicacion(numero1Auxiliar,numero2Auxiliar);
						resultadoDiv = division(numero1Auxiliar,numero2Auxiliar);

						if (numero1Auxiliar>(-1)){
							factorialA = factorial(numero1Auxiliar);
						}

						if (numero2Auxiliar>(-1)){
							factorialB = factorial(numero2Auxiliar);
						}
						opcionElegida = mostrarMensajeErrorResultado(numero1Auxiliar, numero2Auxiliar, &flagNum1, &flagResultados);
					}
				}
			break;
		case 4: //mostrar resultados
			system("color 03"); // Screen: Black - Text: Light Blue


				if (flagResultados==1){
					flagMostrarResultados = 1;
					do{
						system("cls"); // En windows
						//system("clear"); // En Linux
						menuSuperiorAppB(numero1Auxiliar,numero2Auxiliar);
						resultadoSRM(&numero1Auxiliar, &numero2Auxiliar, '+', &resultadoSuma,1);
						resultadoSRM(&numero1Auxiliar, &numero2Auxiliar, '-', &resultadoResta,1);
						resultadoSRM(&numero1Auxiliar, &numero2Auxiliar, '*', &resultadoMult,1);
						resultadoSRM(&numero1Auxiliar, &numero2Auxiliar, '/', &resultadoDiv,1);
						resultadoSRM(&numero1Auxiliar, &numero2Auxiliar, '!', &factorialA,1);
						resultadoSRM(&numero1Auxiliar, &numero2Auxiliar, '!', &factorialB,2);
						printf("    |______________________________________|\n");
						menuInferiorApp2();
						printf("  ->|  Hint: Salir o Volver usa Opcion [5] |<-\n");

						opcionElegida = opcionElegidaPorUsuario();
					}while(opcionElegida!=5);
				}
				else{
					if ((flagResultados==0)&&(flagNum2==1)){
						borrarPantallaYPonerMenu(2,numero1Auxiliar,numero2Auxiliar);
						printf("  ->|ERROR: Deberias continuar x opcion [3]|<-\n");
					}
					else{
						if ((flagNum2==0)&&(flagNum1==1)){
						borrarPantallaYPonerMenu(1,numero1Auxiliar,numero2Auxiliar);
						printf("  ->|ERROR: Deberias continuar x opcion [2]|<-\n");
						}
						else {
							borrarPantallaYPonerMenuVacio();
							printf("  ->|ERROR: Deberias empezar por opcion [1]|<-\n");
						}
					opcionElegida = opcionElegidaPorUsuario();
					}
				}
			break;
		case 5: //mostrar Sub Menu para salir o re-ingresar
			mostrarSubMenuSalir();
			opcionElegida = opcionElegidaPorUsuario();
			opcionSubMenu = opcionElegida;
			switch(opcionSubMenu){
				case 1: // Salir: Blue DeathScreen
					respuesta = caseSalir();
					break;
				case 2: // Vuelve a ingresar operandos
					respuesta = 's';
					fflush(stdin);
					// Vuelve las 4 Flags a 0
					resetFlags(&flagNum1);
					resetFlags(&flagNum2);
					resetFlags(&flagResultados);
					resetFlags(&flagMostrarResultados);
					opcionElegida = 1;
					system("cls"); // En windows
					system("color 02"); // Screen: Black - Text: Green
					borrarPantallaYPonerMenuVacio();
					opcionElegida = opcionElegidaPorUsuario();
					break;
				default:
					break;
			}
			break;
		default: // Redireccionamiento
			if ((flagResultados==0)&&(flagNum2==1)){ //
				borrarPantallaYPonerMenu(2,numero1Auxiliar, numero2Auxiliar);
				printf("  ->|    ERROR: Continua por opcion [3]    |<-\n");
				opcionElegida = opcionElegidaPorUsuario();
			}
			else{
				if((flagNum2==0)&&(flagNum1==1)){
				borrarPantallaYPonerMenu(1,numero1Auxiliar, numero2Auxiliar);
				printf("  ->|    ERROR: Continua por opcion [2]    |<-\n");
				opcionElegida = opcionElegidaPorUsuario();
				}
				else{
					if (flagNum1==0){
						borrarPantallaYPonerMenuVacio();
						printf("  ->|     ERROR: Empieza por opcion [1]    |<-\n");
						opcionElegida = opcionElegidaPorUsuario();
					}
				}
			}
			break;
		}
	}while(respuesta=='s');

	return 0;
}
