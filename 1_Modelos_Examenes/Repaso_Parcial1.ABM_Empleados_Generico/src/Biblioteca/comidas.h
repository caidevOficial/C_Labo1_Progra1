/*
 * comidas.h
 *
 *  Created on: 11 may. 2020
 *      Author: Facu
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef BIBLIOTECA_COMIDAS_H_
#define BIBLIOTECA_COMIDAS_H_

typedef struct{
	int id;
	char descripcion[20];
	float precio;
}eComida;

int cargarDescripcionComida(char descripcion[], int idComida,eComida comidas[], int tam);

void mostrarComida(eComida comida[],int tam);

#endif /* BIBLIOTECA_COMIDAS_H_ */
