/*
 * comidas.c
 *
 *  Created on: 11 may. 2020
 *      Author: Facu
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "comidas.h"

void mostrarComida(eComida comida[],int tam){
	printf("Lista de comida");
	for(int i = 0;i<tam;i++){
		printf("  %d    %10s    %5.2f\n", comida[i].id,comida[i].descripcion,comida[i].precio);
	}
}

int cargarDescripcionComida(char descripcion[], int idComida,
								eComida comidas[], int tam){
	int pudo = 0;
	for (int i=0;i<tam;i++){
		if(comidas[i].id == idComida){
			strcpy(descripcion, comidas[i].descripcion);
			pudo = 1;
		}
	}
	return pudo;
}
