/*
 * Sector.c
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
#include "caidevDataWareHouse.h"
#include "Empleado.h"
#include "Sector.h"


void listarSectores(eSector sectores[], int tamSec) {

	system("cls");
	printf("** Listado sectores **\n\n");
	printf("   Id       Descripcion\n");

	for (int i=0; i< tamSec; i++){
		printf("\n%d    %10s\n",sectores[i].id, sectores[i].descripcion);
	}
}

