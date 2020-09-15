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
 *
 * Version     : Beta 1.3.0 [Beta v1.3.0] - FacuFalcone_LinkedList_Bicicletas_[Linux]
 * ============================================================================
 */

//#include <stdio.h>//windows
#include <stdio_ext.h>//linux
#include <stdlib.h>
#include <string.h>

#include "../Bici.h"

/* Getter: [ID] */
int Object_getID(eBicicleta *this, int *id) {
	int sucess = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		sucess = 1;
	}
	return sucess;
}

/* Getter: [Tipo] */
int Object_getTipo(eBicicleta *this, char *tipo) {
	int sucess = 0;

	if (this != NULL && tipo != NULL) {
		strcpy(tipo, this->tipo);
		sucess = 1;
	}
	return sucess;
}

/* Getter: [Duenho] */
int Object_getDuenho(eBicicleta *this, char *duenho) {
	int sucess = 0;

	if (this != NULL && duenho != NULL) {
		strcpy(duenho, this->duenho);
		sucess = 1;
	}
	return sucess;
}

/* Getter: [Tiempo] */
int Object_getTiempo(eBicicleta *this, int *tiempo) {
	int sucess = 0;

	if (this != NULL && tiempo != NULL) {
		*tiempo = this->tiempo;
		sucess = 1;
	}
	return sucess;
}
