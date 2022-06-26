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

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "../animacionMenu.h"

// UI CALCULADORA - Pantalla

void parteSuperiorMenu(){
	printf("     ______________________________________ \n");
	printf("    |**************************************|\n");
	printf("    |********** #CalculadorApp! ***********|\n");
	printf("    |****** By Facu Falcone - CaiDev ******|\n");
	printf("    |______________________________________|\n");

}

void menuSuperiorAppVacio(){
	parteSuperiorMenu();
	printf("    |                                      | \n");
	printf("    | [1] Ingresar 1\247er Numero: [A=X]      |\n");
	printf("    | [2] Ingresar 2\247do Numero: [B=Y]      |\n");
	printf("    | [3] Calcular Resultados              |\n");
	printf("    |______________________________________| \n");

}

void menuSuperiorAppA(int num1){
	parteSuperiorMenu();
	printf("    |                                      | \n");
	printf("    | [1] Ingresar 1\247er Numero: [A=%d]        \n",num1);
	printf("    | [2] Ingresar 2\247do Numero: [B=Y]      |\n");
	printf("    | [3] Calcular Resultados              |\n");
	printf("    |______________________________________| \n");

}

void menuSuperiorAppB(int num1, int num2){
	parteSuperiorMenu();
	printf("    |                                      | \n");
	printf("    | [1] Ingresar 1\247er Numero: [A=%d]      \n",num1);
	printf("    | [2] Ingresar 2\247do Numero: [B=%d]      \n",num2);
	printf("    | [3] Calcular Resultados              |\n");
	printf("    |______________________________________| \n");
}

void datosCentrales(){
	printf("     ______________________________________\n");
	printf("    |---------------- [Datos] -------------|\n");
	printf("    |--------------------------------------|\n");
	printf("    |-------- SUMA --------- [A+B]         |\n");
	printf("    |-------- RESTA -------- [A-B]         |\n");
	printf("    |---- MULTIPLICACION --- [AxB]         |\n");
	printf("    |------- DIVISION ------ [A/B]         |\n");
	printf("    |------- FACTORIAL --- [A!][B!]        |\n");
	printf("    |______________________________________|\n");
}

void datosCentralesA(int num1){
	printf("     ______________________________________\n");
	printf("    |---------------- [Datos] -------------|\n");
	printf("    |--------------------------------------|\n");
	printf("    |-------- SUMA --------- [(%d)+B] \n",num1);
	printf("    |-------- RESTA -------- [(%d)-B] \n",num1);
	printf("    |---- MULTIPLICACION --- [(%d)xB] \n",num1);
	printf("    |------- DIVISION ------ [(%d)/B] \n",num1);
	printf("    |------- FACTORIAL --- [(%d)!][B!] \n",num1);
	printf("    |______________________________________| \n");
}

void datosCentralesB(int num1,int num2){
	printf("     ______________________________________\n");
	printf("    |---------------- [Datos] -------------|\n");
	printf("    |--------------------------------------|\n");
	printf("    |-------- SUMA -------- [(%d)+(%d)]\n",num1,num2);
	printf("    |-------- RESTA ------- [(%d)-(%d)]     \n",num1,num2);
	printf("    |---- MULTIPLICACION -- [(%d)x(%d)]     \n",num1,num2);
	printf("    |------- DIVISION ----- [(%d)/(%d)]     \n",num1,num2);
	printf("    |------- FACTORIAL --- [(%d)!][(%d)!]   \n",num1,num2);
	printf("    |______________________________________| \n");
}

void menuInferiorApp2(){
	printf("     ______________________________________\n");
	printf("    | [4] Mostrar Resultados---------------|\n");
	printf("    | [5] Salir----------------------------|\n");
	printf("    |______________________________________| \n");
}
// UI CALCULADORA - Input Opciones de Menu

int opcionElegidaPorUsuario(){
	int opcion2;
	printf("  ->|                                      |<-\n");
	printf("  ->|----- ALERT: Escoja una opcion: ");
	scanf("%d",&opcion2);
	return opcion2;
}

// UI CALCULADORA - Pantalla Resultados

void mensajeResultados(){
	printf("     ______________________________________\n");
	printf("    |------------ [Resultados]-------------|\n");
	printf("    |--------------------------------------|\n");
}

double resultadoSRM(int* num1, int* num2, char operacion, double* resultadoVar, int marcaFact){

	switch (operacion){
		case '+':// SUMA
		case '-':// RESTA
		case '*':// MULTIPLICACION
			printf("    | El resultado de [(%d)%c(%d)] es %.f           \n",*num1,operacion,*num2, *resultadoVar);
			break;
		case '/': // DIVISION
			if (*num2==0){
				printf("    | No se puede dividir por 0 u.u        |\n");
			}
			else{
				printf("    | El resultado de [(%d)%c(%d)] es %.2f        \n",*num1,operacion,*num2,*resultadoVar);
			}
			break;
		case '!':
			// FACTORIAL 1 Y 2
			if (marcaFact==1){
				if (*num1>-1&&*num1<33){
					printf("    | El Factorial de  [(%d!)] es [Aprox]  |\n",*num1);
					printf("    | %.f        \n",*resultadoVar);
				}
				else if(*num1>32){
					printf("    | El factorial de %d Excede El Rango  \n",*num1);
						}
						else if (*num1<0){
							printf("    | Imposible Calcular El Factorial De %d\n",*num1);
						}
				}
			else if (marcaFact==2){
				if (*num2>-1&&*num2<33){
					printf("    | El Factorial de  [(%d!)] es [Aprox]  |\n",*num2);
					printf("    | %.f        \n",*resultadoVar);
				}
				else if(*num2>32){
					printf("    | El factorial de %d Excede El Rango  \n",*num2);
						}
						else if (*num2<0){
							printf("    | Imposible Calcular El Factorial De %d\n",*num2);
						}
			}
			break;
		default:
			break;
	}
return 0;
}


void borrarPantallaYPonerMenuVacio(){
		system("cls"); // En windows
		//system("clear"); // En Linux
		menuSuperiorAppVacio();
		datosCentrales();
		menuInferiorApp2();

}

void borrarPantallaYPonerMenu(int opcion, int num1, int num2){
	if (opcion==1){
		system("cls"); // En windows
		//system("clear"); // En Linux
		menuSuperiorAppA(num1);
		datosCentralesA(num1);
		menuInferiorApp2();
	}
	else if (opcion==2){
		system("cls"); // En windows
		//system("clear"); // En Linux
		menuSuperiorAppB(num1,num2);
		datosCentralesB(num1,num2);
		menuInferiorApp2();
	}
}

int mostrarMensajeErrorResultado(int num1, int num2, int* flag2, int* flagR){
	int opcionElegida;
	int flagCopia = *flag2;

	if ((flagCopia==1)){
	borrarPantallaYPonerMenu(2, num1, num2);
	fflush(stdin);
	*flagR = 1;
	borrarPantallaYPonerMenu(2, num1, num2);
	animacionCargaResultados();
	borrarPantallaYPonerMenu(2, num1, num2);
	printf("     ______________________________________ \n");
	printf("  ->|--------- [Resultados listos] --------|<-\n");
	printf("  ->|------ Digite el [4] para verlos -----|<- \n");
	printf("  ->|   Hint: Continua por la opcion [4]   |<-\n");
	printf("  ->|______________________________________|<-\n");

	opcionElegida = opcionElegidaPorUsuario();
		do{
			if (*flagR==1 && (opcionElegida!=5 && opcionElegida!=4)){
				borrarPantallaYPonerMenu(2, num1, num2);
				printf("  ->|    ERROR: Continua por opcion [4]    |<-\n");
				printf("  ->|   ERROR: Para Salir usa opcion [5]   |<-\n");
				opcionElegida = opcionElegidaPorUsuario();
			}
		}while (opcionElegida!=4 && opcionElegida!=5);
	}
	else{

		opcionElegida = opcionElegidaPorUsuario();
	}
	return opcionElegida;
}


void mostrarSubMenuSalir(){
	system("color 47");
	system("cls"); // En windows
	//system("clear"); // En Linux
	parteSuperiorMenu();
	printf("    |               WARNING!               | \n");
	printf("    |               WARNING!               |\n");
	printf("    |               WARNING!               |\n");
	printf("    |               WARNING!               |\n");
	printf("    |______________________________________| \n");
	printf("     ______________________________________\n");
	printf("  ->|___________SubMenu_Salir._____________|<-\n");
	printf("  ->|   1 -    Salir de la App.            |<-\n");
	printf("  ->|   2 - Ingresar nuevos numeros.       |<-\n");
	printf("  ->|______________________________________|<-\n");
}
