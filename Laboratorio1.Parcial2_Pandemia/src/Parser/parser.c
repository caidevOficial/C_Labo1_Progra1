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

#include "../LinkedList.h"
#include "../Pandemia/Pandemia.h"

int parser_ObjectFromText(FILE *pFile, LinkedList *this) {
	ePais *pObject;
	char auxID[128];
	char pais[128];
	char infectados[128];
	char recuperados[128];
	char muertos[128];

	int success = 0;
	int firstElement = 1;

	if (pFile != NULL) {
		while (!feof(pFile)) {
			if (firstElement) {
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, pais, recuperados, infectados, muertos);
				firstElement = 0;
			}
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxID, pais, recuperados, infectados, muertos);
			pObject = Entity_newParam(auxID, pais,recuperados, infectados,muertos);

			if (pObject != NULL) {
				ll_add(this, pObject);
				success = 1;
			}
		}
	}
	return success;
}
