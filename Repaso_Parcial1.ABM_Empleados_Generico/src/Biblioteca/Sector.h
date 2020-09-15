/*
 * Sector.h
 *
 *  Created on: 8 may. 2020
 *      Author: Facu
 */

#ifndef BIBLIOTECA_SECTOR_H_
#define BIBLIOTECA_SECTOR_H_

typedef struct{
	int id;
	char descripcion[20];
}eSector;

void listarSectores(eSector sectores[], int tamSec);

#endif /* BIBLIOTECA_SECTOR_H_ */
