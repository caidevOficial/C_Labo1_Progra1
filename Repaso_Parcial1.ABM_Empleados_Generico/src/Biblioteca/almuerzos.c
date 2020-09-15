/*
 * almuerzo.c
 *
 *  Created on: 11 may. 2020
 *      Author: Facu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleado.h"
#include "comidas.h"
#include "Sector.h"
#include "almuerzos.h"


void inicializarAlumuerzos(eAlmuerzo almuerzo[],int tam){
	for(int i=0;i<tam;i++){
		almuerzo[i].isEmpty=1;
	}
}

/*mostrar id de almuerzo, id de empleado, nomrbe de empleado, nombre de comida, fecha de almuerzo*/
void mostrarAlmuerzo(eAlmuerzo almuerzo,eEmpleado empleados[],int tamEmp,eComida comida[],int tamCom){
	char nombreEmpleado[20];
	char nombreComida[20];

	cargarNombreEmpleado(nombreEmpleado, almuerzo.idEmpleado,empleados,tamEmp);
	cargarDescripcionComida(nombreComida, almuerzo.idComida, comida, tamCom);
	printf("   %d    %d    %10s    %10s    %d/%d/%d",almuerzo.id,almuerzo.idEmpleado,nombreEmpleado,nombreComida,almuerzo.fecha.dia,almuerzo.fecha.mes,almuerzo.fecha.anho);
}

void mostrarAlmuerzos(eAlmuerzo almuerzo[],int tama, eEmpleado empleados[],int tamEmp,eComida comida[],int tamCom){
	int flag=0;
	system("cls");
	printf("listado almuerzos");
	printf("    ID    id empleado    Nombre    Comida    Fecha");
	for (int i =0;i<tama;i++){
		if(almuerzo[i].isEmpty==0){
			mostrarAlmuerzo(almuerzo[i],empleados,tamEmp,comida,tamCom);
		}
	}
	if(flag==0){
		printf("No hay almuerzos cargados");
	}
	printf("\n\n");
}
int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam){
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

int altaAlmuerzo(int id, eAlmuerzo almuerzo[],int tama, eEmpleado empleados[],
					int tamEmp,eSector sectores[], int tamsec,eComida comida[],int tamCom){
	int todoOk = 0;
	int index;
	eAlmuerzo nuevoAlmuerzo;

	system("cls");
	printf("***** Alta Almuerzo *****\n\n");
	index = buscarLibreAlmuerzo(almuerzo,tama);
	if(index==-1){
		printf("no hay lugar para otro almuerzo.");
	}
	else{
		mostrarEmpleados(empleados,tamEmp,sectores,tamsec);
		printf("ingrese id empleado:");
		scanf("%d",&nuevoAlmuerzo.idEmpleado);

		mostrarComida(comida,tamCom);
		printf("ingrese id comida:");
		scanf("%d",&nuevoAlmuerzo.idComida);

		printf("cargar fecha: ");
		scanf("%d/%d/%d", &nuevoAlmuerzo.fecha.dia,&nuevoAlmuerzo.fecha.mes,&nuevoAlmuerzo.fecha.anho);

		nuevoAlmuerzo.isEmpty = 0;
		nuevoAlmuerzo.id = id;
		almuerzo[index] = nuevoAlmuerzo;

	}

return todoOk;

}
