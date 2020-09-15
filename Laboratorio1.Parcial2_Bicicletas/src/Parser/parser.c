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

#include "../LinkedList.h"
#include "../Bicicleta/Bici.h"

int parser_ObjectFromText(FILE *pFile, LinkedList *this) {
	eBicicleta *pObject;

	char auxID[128];
	char tipo[128];
	char duenho[128];
	char tiempo[128];

	int sucess = 0;
	int firstElement = 1;

	if (pFile != NULL) {
		while (!feof(pFile)) {
			if (firstElement) {
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID,	duenho, tipo, tiempo);
				firstElement = 0;
			}
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID,duenho, tipo, tiempo);
			pObject = Object_newParam(auxID, duenho,tipo, tiempo);

			if (pObject != NULL) {
				ll_add(this, pObject);
				sucess = 1;
			}
		}
	}
	return sucess;
}
