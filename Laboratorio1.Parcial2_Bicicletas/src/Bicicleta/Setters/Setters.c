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
#include "../../Controller/Controller.h"
#include "../../Validate/caidevValidate.h"
#include "../../LinkedList.h"
#include "Setters.h"
#include "../Bici.h"

/* Setters: [ID] */
int Object_setID(eBicicleta *this, int *id) {
	int sucess = 0;

	if (this != NULL) {
		if (id >= 0) {
			this->id = *id;
			sucess = 1;
		}
	}
	return sucess;
}

/* Setters: [Duenho] */
int Object_setDuenho(eBicicleta *this, char *duenho) {
	int sucess = 0;

	if (this != NULL && duenho != NULL) {
		strncpy(this->duenho, duenho, 10);
		sucess = 1;
	}
	return sucess;
}

/* Setters: [Tipo] */
int Object_setTipo(eBicicleta *this, char *tipo) {
	int sucess = 0;

	if (this != NULL && tipo != NULL) {
		strncpy(this->tipo, tipo, 10);
		sucess = 1;
	}
	return sucess;
}

/* Setters: [Tiempo] */
int Object_setTiempo(eBicicleta *this, int tiempo) {
	int sucess = 0;

	if (this != NULL) {
		if (tiempo >= 0) {
			this->tiempo = tiempo;
			sucess = 1;
		}
	}
	return sucess;
}
