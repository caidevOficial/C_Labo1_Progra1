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
#include "Setters.h"

#include <stdio_ext.h>//linux
#include <stdlib.h>
#include <string.h>
#include "../../Controller/Controller.h"
#include "../../Validate/caidevValidate.h"
#include "../../LinkedList.h"
#include "../Pandemia.h"

/* Setters: [ID] */
int Entity_setID(ePais *this, int *id) {
	int success = 0;

	if (this != NULL) {
		if (id >= 0) {
			this->id = *id;
			success = 1;
		}
	}
	return success;
}

/* Setters: [PAIS] */
int Entity_setCountry(ePais *this, char *pais) {
	int success = 0;

	if (this != NULL && pais != NULL) {
		strncpy(this->pais, pais, 10);
		success = 1;
	}
	return success;
}

/* Setters: [MUERTOS] */
int Entity_setDeads(ePais *this, int muertos) {
	int success = 0;

	if (this != NULL) {
		if (muertos >= 0) {
			this->muertos = muertos;
			success = 1;
		}
	}
	return success;
}

/* Setters: [RECUPERADOS] */
int Entity_setRecovered(ePais *this, int recu) {
	int success = 0;

	if (this != NULL) {
		if (recu >= 0) {
			this->recuperados = recu;
			success = 1;
		}
	}
	return success;
}

/* Setters: [INFECTADOS] */
int Entity_setInfecteds(ePais *this, int infect) {
	int success = 0;

	if (this != NULL) {
		if (infect >= 0) {
			this->infectados = infect;
			success = 1;
		}
	}
	return success;
}
