/*
 ============================================================================
 Name        : Clase_Miercoles_29_4.c
 Author      : FacuFalcone - CaiDev
 Version     :
 Copyright   : Software Libre
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblioteca/caidevEstructuras.h"
#include "Biblioteca/almuerzos.h"
#include "Biblioteca/comidas.h"
#include "Biblioteca/Empleado.h"
#include "Biblioteca/Sector.h"

#define CANTHARDCODE 6
#define TAM 100		// Tamanho vector empleados
#define TAMSECTOR 5	// Tamanho vector sectores
#define TAMA 10		// Tamanho vector almuerzo
#define TAMCOM 20	// Tamanho vector comidas


int main(void) {
	int proximoID = 1000;
	int proximoIDAlmuerzo = 20000;
	char seguir = 's';
	char confirma = 's';

	eEmpleado lista[TAM] = {};
	eSector sectores[TAMSECTOR] = {{1,"Sistemas"},{2, "RRHH"},{3, "Compras"},{4,"Ventas"},{5,"Contable"}};
	eAlmuerzo almuerzo[TAMA];
	eComida comidas[TAMCOM];
	inicializarEmpleados(lista, TAM);
	inicializarAlumuerzos(almuerzo,TAMA);
	//hardcodear(lista, CANTHARDCODE);
	proximoID += 5;

	do{
		switch(menu()){
		//case 'A':
		case 'a': // Alta Empleado
			printf("Alta.\n");
			if(altaEmpleado(lista, TAM, sectores,TAMSECTOR)){
				proximoID++;
			}
			printf("\nEmpleado/a cargado con exito!\n");
			//altaEmpleado(proximoID, lista, TAM);  hacerla para que el id se ponga automatico y sea incremental
			break;
		//case 'B':
		case 'b': // Modificar Empleado
			printf("Modificar.\n");
			modificarEmpleado(lista, TAM,sectores,TAMSECTOR);
			break;
		//case 'C':
		case 'c': // Baja Empleado
			printf("Baja.\n");
			bajaEmpleado(lista,TAM,sectores,TAMSECTOR);
			break;
		//case 'D':
		case 'd': //Ordenar Empleado -> subMenu para ordenar por nombre, id, sexo, sueldo.
			printf("Ordenar.\n");
			ordenarEmpleados(lista,TAM);
			break;
		//case 'E':
		case 'e': //Listar Empleado
			printf("Listar.\n");
			mostrarEmpleados(lista, TAM, sectores, TAMSECTOR);
			break;
		//case 'F':
		case 'f': //Informes
			printf("Informes.\n");
			informes(lista, menuInforme(),TAM,sectores,TAMSECTOR);
			break;
		case 'g': // mostrar Almuerzos
			mostrarAlmuerzos(almuerzo,TAMA,lista,TAM,comidas,TAMCOM);
			break;
		case 'h': //Alta almuerzos
			if(altaAlmuerzo(proximoIDAlmuerzo,almuerzo,TAMA,lista,TAM,sectores,TAMSECTOR,comidas,TAMCOM)){
				proximoIDAlmuerzo++;
			}
			break;
		//case 'G':
		case 'i': // Salir
			printf("Confirma Salida?. s/n\n");
			fflush(stdin);
			scanf("%c",&confirma);
			if (confirma == 's'){
				printf("Gracias, vuelvas prontos! \n");
				seguir = 'n';
			}
			break;
		default:
			printf("Opcion invalida, vuelva a elegir.\n");
			break;
		}
		confirma = tolower(confirma);
		system("pause");
		system("cls");
	}while(seguir=='s');
	return EXIT_SUCCESS;
}


