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

//#include <stdio.h>//windows
#include <stdio_ext.h>//linux
#include <stdlib.h>
#include <string.h>

#include "../Pandemia.h"
#include "Getters.h"

int Entity_getID(ePais *this, int *id) {
	int success = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		success = 1;
	}
	return success;
}

/* Getter: [Pais] */
int Entity_getCountry(ePais *this, char *pais) {
	int success = 0;

	if (this != NULL && pais != NULL) {
		strcpy(pais, this->pais);
		success = 1;
	}
	return success;
}

int Entity_getInfected(ePais *this, int *infec) {
	int success = 0;

	if (this != NULL && infec != NULL) {
		*infec = this->infectados;
		success = 1;
	}
	return success;
}

int Entity_getRecovered(ePais *this, int *recu) {
	int success = 0;

	if (this != NULL && recu != NULL) {
		*recu = this->recuperados;
		success = 1;
	}
	return success;
}

int Entity_getDeads(ePais *this, int *muertos) {
	int success = 0;

	if (this != NULL && muertos != NULL) {
		*muertos = this->muertos;
		success = 1;
	}
	return success;
}
