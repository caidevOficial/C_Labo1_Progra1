/*
 * almuerzos.h
 *
 *  Created on: 11 may. 2020
 *      Author: Facu
 */
#include "comidas.h"
#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef BIBLIOTECA_ALMUERZOS_H_
#define BIBLIOTECA_ALMUERZOS_H_


typedef struct{
	int id;
	int idComida;
	int idEmpleado;
	eFecha fecha;
	int isEmpty;
}eAlmuerzo;



void inicializarAlumuerzos(eAlmuerzo almuerzo[],int tam);



/*mostrar id de almuerzo, id de empleado, nomrbe de empleado, nombre de comida, fecha de almuerzo*/
void mostrarAlmuerzo(eAlmuerzo almuerzo,eEmpleado vec[],int tamEmp,eComida comida[],int tamCom);

void mostrarAlmuerzos(eAlmuerzo almuerzos[],int tama, eEmpleado vec[],int tamEmp,eComida comida[],int tamCom);

int altaAlmuerzo(int IDAlmuerzo, eAlmuerzo almuerzo[],int tama, eEmpleado empleados[],int tamEmp,eSector sectores[], int tamsec,eComida comida[],int tamCom);

int buscarLibreAlmuerzo(eAlmuerzo vec[], int tam);


#endif /* BIBLIOTECA_ALMUERZOS_H_ */
