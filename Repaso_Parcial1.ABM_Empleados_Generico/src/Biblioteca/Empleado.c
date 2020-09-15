/*
 * Empleado.c
 *
 *  Created on: 8 may. 2020
 *      Author: Facu
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "caidevEstructuras.h"
#include "caidevValidate.h"
//#include "caidevDataWareHouse.h"
#include "Empleado.h"
#include "Sector.h"

void cargarEmpleado(eEmpleado emp){
	printf("cargar ID: ");
	scanf("%d", &emp.id);

	printf("cargar nombre: ");
	fflush(stdin);
	myGets(emp.nombre,sizeof(emp.nombre));

	printf("cargar edad: ");
	scanf("%d", &emp.edad);

	printf("cargar sexo: ");
	fflush(stdin);
	scanf("%c", &emp.sexo);

	printf("cargar sueldo: ");
	scanf("%f", &emp.sueldo);

	printf("cargar Dia Ingreso: ");
	scanf("%d", &emp.fechaIngreso.dia);
	printf("cargar mes Ingreso: ");
	scanf("%d", &emp.fechaIngreso.mes);
	printf("cargar Anho Ingreso: ");
	scanf("%d", &emp.fechaIngreso.anho);
}

void mostrarEmpleado( eEmpleado emp, eSector sectores[], int tamsec){
    char descripcion [20];
    cargarDescripcionSector(descripcion, emp.idSector, sectores,  tamsec);
    printf("\n%d    %10s          %c          %d      %.2f   %02d/%02d/%d    %10s \n", emp.id, emp.nombre, emp.sexo, emp.edad, emp.sueldo, emp.fechaIngreso.dia, emp.fechaIngreso.mes, emp.fechaIngreso.anho, descripcion);
}
void mostrarEmpleados(eEmpleado vec[], int tam, eSector sector[], int tamSec){
	printf("\n###################### Listado de empleados ######################## \n");
	printf("   Id       Nombre        Sexo        Edad     Sueldo     FechaIngreso     Sector\n");

	for (int i = 0;i<tam;i++){
		if (vec[i].isEmpty==0){
			mostrarEmpleado(vec[i], sector,tamSec);
		}
	}
}

void ordenarEmpleados(eEmpleado vec[], int tam){
	// burbujeo
	eEmpleado auxEmpleado;
	for (int i = 0; i<tam-1; i++){
		for (int j = i+1; j<tam;j++){
			// criterio de ordenamiento por sexo y sueldo mayor a menor
			if(vec[i].sexo > vec[j].sexo){
				auxEmpleado = vec[i];
				vec[i] = vec[j];
				vec[j] = auxEmpleado;
			}
			else if (vec[i].sexo == vec[j].sexo && vec[i].sueldo < vec[j].sueldo){
				auxEmpleado = vec[i];
				vec[i] = vec[j];
				vec[j] = auxEmpleado;
			}
			/*
			if(lista[i].id > lista[j].id){
				auxEmpleado = lista[i];
				lista[i] = lista[j];
				lista[j] = auxEmpleado;
			}*/
		}
	}
}


void ordenarEmpleadosPorNombre(eEmpleado lista[], int cantidad){
	eEmpleado auxEmpleado;

	for(int i = 0; i < cantidad - 1; i++){
		for(int j = i+1; j < cantidad; j++){
			//de menor a mayor
			if(strcmp(lista[i].nombre, lista[j].nombre) > 0){
				auxEmpleado = lista[i];
				lista[i] = lista[j];
				lista[j] = auxEmpleado;
			}
		}
	}
}

void ordenarEmpleadosPorSexoyNombre(eEmpleado lista[], int cantidad){
	eEmpleado auxEmpleado;

	for(int i = 0; i < cantidad - 1; i++){
		for(int j = i+1; j < cantidad; j++){
			//de menor a mayor
			if(lista[i].sexo > lista[j].sexo){
				auxEmpleado = lista[i];
				lista[i] = lista[j];
				lista[j] = auxEmpleado;
			}
			else if(lista[i].sexo == lista[j].sexo && (strcmp(lista[i].nombre, lista[j].nombre) > 0)){
				//si comparo f y f o m y m, compara por nombre y swapea por orden alfabetico
				auxEmpleado = lista[i];
				lista[i] = lista[j];
				lista[j] = auxEmpleado;
			}
		}
	}
}

void inicializarEmpleados(eEmpleado vec[], int tam){

	for(int i=0;i<tam;i++){
		vec[i].isEmpty=1;
	}
}

int buscarLibre(eEmpleado vec[], int tam){
	int i;
	int retorno = -1;
	for(i = 0; i < tam; i++){
		if (vec[i].isEmpty){
			retorno = i;
			break;
		}
	}
	return retorno;
}

int buscarEmpleado(int id, eEmpleado vec[], int tam, eSector sectores[], int tamSec){
	int i;
	int retorno = -1;
	for(i = 0; i < tam; i++){
		if (vec[i].id == id && vec[i].isEmpty==0){
			retorno = i;
			break;
		}
	}
	return retorno;
}
/*
int asignarID(int* idActual, int* idProxima){
	int idAsignada;
	idAsignada = *idActual;
	*idProxima = *idActual;
	return idAsignada;
}*/

int altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec){
	int indiceLibre = buscarLibre(vec,tam);
	eEmpleado auxEmpleado;
	int sumaID = 0;

	if (indiceLibre != -1){
			 printf("Ingrese nombre: ");
			fflush(stdin);
			myGets(auxEmpleado.nombre,sizeof(auxEmpleado.nombre));

			printf("Ingrese sexo: ");
			fflush(stdin);
			scanf("%c",&auxEmpleado.sexo);

			printf("Ingrese edad: ");
			scanf("%d",&auxEmpleado.edad);

			printf("Ingrese sueldo: ");
			scanf("%f",&auxEmpleado.sueldo);

			printf("Ingrese el dia de ingreso:");
			scanf("%d",&auxEmpleado.fechaIngreso.dia);

			printf("Ingrese el mes de ingreso:");
			scanf("%d",&auxEmpleado.fechaIngreso.mes);

			printf("Ingrese el anio de ingreso:");
			scanf("%d",&auxEmpleado.fechaIngreso.anho);

			listarSectores(sectores,tamSec);
			printf("\ningrese sector: ");
			scanf("%d", &auxEmpleado.idSector);

			auxEmpleado.isEmpty = 0;
			sumaID = 1;
			vec[indiceLibre] = auxEmpleado;
		/*}
		else{
			printf("Ya existe un empleado registrado bajo esa ID.\n");
		}*/
	}
	else{
		printf("No hay espacio.");
	}
	return sumaID;
}

void bajaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec){
    int indice;
    int id;
    char confirma = 's';

    system("cls");
    printf("*** Baja Empleado ***\n\n");
    printf("Ingrese id a eliminar: \n");
    scanf("%d",&id);

    indice = buscarEmpleado(id,vec,tam,sectores,tamSec);
    if (indice ==-1){

       	 printf("No hay registro de un empleado con el ID: %d \n",indice);
    }
    else{
		mostrarEmpleado(vec[indice],sectores,tamSec);
		printf("\nConfirma baja?: ");
		fflush(stdin);
		scanf("%c", &confirma);
		if(confirma== 's'){
			vec[indice].isEmpty = 1;
			printf("Se ha realizado la baja con exito!!\n");
		}
		else{
			printf("Operacion cancelada\n");
		}
	}
    system("pause");
}

void modificarEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec){
	int id;
	int indice;
	char confirma;
	eEmpleado auxEmpleadoChange;

	int opcionModificar;

	system("cls");
	printf("** Modificar Empleado **\n\n");
	printf("Ingrese id: ");
	scanf("%d", &id);

	indice = buscarEmpleado(id, vec, tam,sectores,tamSec); //devuelve la posicion donde esta el empleado, o -1

	if(indice == -1){
		printf("El ID: %d no existe en sistema.\n", id);
	}
	else{
		printf("El empleado con el ID: %d es: ", id);
		mostrarEmpleado(vec[indice],sectores,tamSec);
		printf("\nQue desea Modificar?");
		printf("\n1 - Nombre."
			   "\n2 - Edad."
			   "\n3 - Sexo."
			   "\n4 - Salario."
			   "\n5 - Fecha de ingreso."
			   "\n6 - Salir.\n");
				scanf("%d",&opcionModificar);
		do{
			switch(opcionModificar){
			case 1: // change Name
				printf("\nModificar nombre? 's' o 'n': ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 's'){
					//hacer submenu para decidir que modificar
					//en este caso modifico solo uno:
					printf("\nIngrese nuevo nombre: ");
					//gets(auxEmpleadoChange.nombre);
					fflush(stdin);
					myGets(auxEmpleadoChange.nombre,sizeof(auxEmpleadoChange.nombre));
					strncpy(vec[indice].nombre,auxEmpleadoChange.nombre,sizeof(vec[indice].nombre));
					printf("\nSe ha actualizado el nombre con exito.\n");
				}
				else{
					printf("\nSe ha cancelado la operacion.\n");
					confirma ='n';
				}
				break;
			case 2:
				printf("\nModificar sueldo? 's' o 'n': ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 's'){
					printf("\nIngrese nueva edad: ");
					scanf("%d", &auxEmpleadoChange.edad);
					vec[indice].edad = auxEmpleadoChange.edad;
					printf("\nSe ha actualizado el sueldo con exito.\n");
				}
				else{
					printf("\nSe ha cancelado la operacion.\n");
					confirma ='n';
				}
				break;
			case 3: //change sex
				printf("\nModificar sexo? 's' o 'n': ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 's'){
					//hacer submenu para decidir que modificar
					//en este caso modifico solo uno:
					printf("\nIngrese nuevo sexo: ");
					scanf("%c",&auxEmpleadoChange.sexo);
					vec[indice].sexo = auxEmpleadoChange.sexo;
					printf("\nSe ha actualizado el sexo con exito.\n");
				}
				else{
					printf("\nSe ha cancelado la operacion.\n");
					confirma ='n';
				}
				break;
			case 4: // change salary
				printf("\nModificar sueldo? 's' o 'n': ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 's'){
					//hacer submenu para decidir que modificar
					//en este caso modifico solo uno:
					printf("\nIngrese nuevo sueldo: ");
					scanf("%f", &auxEmpleadoChange.sueldo);
					vec[indice].sueldo = auxEmpleadoChange.sueldo;
					printf("\nSe ha actualizado el sueldo con exito.\n");
				}
				else{
					printf("\nSe ha cancelado la operacion.\n");
					confirma ='n';
				}

				break;
			case 5: //change enter date
				printf("\nModificar nombre? 's' o 'n': ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 's'){
					//hacer submenu para decidir que modificar
					//en este caso modifico solo uno:
					printf("\nIngrese el dia de ingreso: ");
					scanf("%d", &auxEmpleadoChange.fechaIngreso.dia);
					printf("\nIngrese el mes de ingreso: ");
					scanf("%d", &auxEmpleadoChange.fechaIngreso.mes);
					printf("\nIngrese el anho de ingreso: ");
					scanf("%d", &auxEmpleadoChange.fechaIngreso.mes);
					vec[indice].fechaIngreso = auxEmpleadoChange.fechaIngreso;
					printf("\nSe ha actualizado el nombre con exito.");
				}
				else{
					printf("\nSe ha cancelado la operacion.\n");
					confirma ='n';
				}
				break;
			default:
				confirma ='n';
				break;
			}
			system("pause");
		}while(confirma=='s');
	}
}
/*
void hardcodear(eEmpleado vec[], int cant){
	for (int i = 0; i<cant; i++){
		vec[i].id = ids[i];
		strcpy (vec[i].nombre, nombre[i]);
		vec[i].sexo = sexos[i];
		vec[i].edad = edades[i];
		vec[i].sueldo = sueldos[i];
		vec[i].fechaIngreso.dia = dias[i];
		vec[i].fechaIngreso.mes = meses[i];
		vec[i].fechaIngreso.anho = anho[i];
		vec[i].idSector = idsSectores[i];
		vec[i].isEmpty = 0;
	}
}*/

void listarEmpleadosPorAnio(eEmpleado vec[], int tam, eSector sectores[], int tamSec){
    int anio;
    int hayEmpleados = 0;

    system("cls");
    printf("** Listado de empleados por anio de ingreso **\n\n");
    printf("\n Ingrese anio:");
    scanf("%d", &anio);
    system("cls");

    printf("   Id       Nombre        Sexo        Edad     Sueldo     FechaIngreso\n");

    for (int i=0; i< tam; i++){
        if (vec[i].isEmpty == 0 && vec[i].fechaIngreso.anho== anio){
            mostrarEmpleado(vec[i],sectores,tamSec);
            hayEmpleados = 1;
        }
    }
    if ( hayEmpleados == 0){
        printf("\nNo hay empleados que hayan ingresado ese anio. \n");
    }

}

void mostrarEmpleadas(eEmpleado vec[], int tam, eSector sectores[], int tamSec){
	char sexo;
	//int hayEmpleados = 0;

	system("cls");
	printf("** Listado de empleados por anio de ingreso **\n\n");
	printf("\n Ingrese anio:");
	scanf("%c", &sexo);
	system("cls");
	printf("   Id       Nombre        Sexo        Edad     Sueldo     FechaIngreso\n");
	for (int i = 0;i<tam;i++){
		if (vec[i].isEmpty==0 && vec[i].sexo == 'f'){
			mostrarEmpleado(vec[i],sectores,tamSec);
			//hayEmpleados = 1;
		}
	}
}

void listarEmpleadasMujeres(eEmpleado vec[], int tam, eSector sectores[], int tamSec){
    int hayEmpleadas = 0;
    printf("\n*** Listado Empleadas ***\n\n");
    printf("   Id       Nombre        Sexo        Edad     Sueldo     FechaIngreso\n");

    for (int i=0; i< tam; i++){
        if (vec[i].isEmpty == 0 && vec[i].sexo == 'f'){
            mostrarEmpleado(vec[i],sectores,tamSec);
            hayEmpleadas = 1;
        }
    }

    if ( hayEmpleadas == 0){
        printf("\nNo hay empleadas mujeres   que listar \n");
    }
}

int cargarNombreEmpleado(char nombre[], int idSector,eEmpleado empleados[], int tam){
	int pudo = 0;
	for (int i=0;i<tam;i++){
		if(empleados[i].id == idSector){
			strcpy(nombre, empleados[i].nombre);
			pudo = 1;
		}
	}
	return pudo;
}

int cargarDescripcionSector(char descripcion[], int idSector,eSector sectores[], int tamSec){
	int pudo = 0;
	for (int i=0;i<tamSec;i++){
		if(sectores[i].id == idSector){
			strcpy(descripcion, sectores[i].descripcion);
			pudo = 1;
		}
	}
	return pudo;
}


int menu(){
	char opcionElegida;

	printf("**** MENU ****\n"
	"Escoja una opcion para operar: \n"
	"A - Alta Empleado.\n"
	"B - Modificar Empleado.\n"
	"C - Baja Empleado.\n"
	"D - Ordenar Empleados.\n"
	"E - Listar Empleado.\n"
	"F - Informes.\n"
	"G - Mostrar Almuerzos.\n"
	"H - Alta Almuerzos.\n"
	"I - Salir.\n");
	fflush(stdin);
	scanf("%c",&opcionElegida);
	opcionElegida = tolower(opcionElegida);

	return opcionElegida;
}
