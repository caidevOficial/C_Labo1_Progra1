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
 * Type: Recuperatorio segundo parcial - Laboratorio 1.
 * Version     : Beta 1.1.2 [Beta v1.1.2] - FacuFalcone_ABM_Pandemia_[Linux]
 * ============================================================================
 */

#include "Pandemia.h"

#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>

#include "../Pandemia/Getters/Getters.h"
#include "../Pandemia/Setters/Setters.h"

// Constructors
ePais* Entity_new() {
	ePais *newObject;
	newObject = (ePais*) calloc(sizeof(ePais), 1);

	return newObject;
}

ePais* Entity_newParam(char *id, char *pais, char *infectados,	char *recuperados, char* muertos) {
	ePais *newObject;
	newObject = Entity_new();

	int auxId;
	int auxrecuperados;
	int auxMuertos;
	int auxInfectados;

	auxId = atoi(id);
	auxrecuperados = atoi(recuperados);
	auxMuertos = atoi(muertos);
	auxInfectados = atoi(infectados);

	if (newObject != NULL && id != NULL && pais != NULL && infectados != NULL && recuperados != NULL && muertos != NULL ) {
		Entity_setID(newObject, &auxId);
		Entity_setCountry(newObject, pais);
		Entity_setInfecteds(newObject, auxInfectados);
		Entity_setRecovered(newObject, auxrecuperados);
		Entity_setDeads(newObject, auxMuertos);
	}
	return newObject;
}

/* Function/SortBy: [Infectados] */
int Entity_sortInfectados(void *infect1, void *infect2) {
int infect_1;
int infect_2;
int success = 0; // si los tiempos son iguales, devuelve 0

Entity_getInfected(infect1, &infect_1);
Entity_getInfected(infect2, &infect_2);

if (infect_1 > infect_2) {
	success = 1;
} else if (infect_1 < infect_2) {
	success = -1;
	}
	return success;
}
