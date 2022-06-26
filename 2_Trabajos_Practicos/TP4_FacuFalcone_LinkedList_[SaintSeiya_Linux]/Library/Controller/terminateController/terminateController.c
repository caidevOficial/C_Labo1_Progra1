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
 * Version     : Beta 3.3.0 [Beta v3.3.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
 * ============================================================================
 */

//#include <stdio.h> //windows
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Controller.h"
#include "../../../inc/LinkedList.h"
#include "../../KnightOfZodiac/KnightZodiac.h"
#include "../../KnightOfZodiac/Getters/Getters.h"
#include "../../Parser/parser.h"
#include "../../Validate/caidevValidate.h"
#include "../registerController/registerController.h"

int controller_removeKnightZodiac(LinkedList *pArrayListKnightZodiac) {
	KnightZodiac *pKnightZodiac;

	int sucess = 0;
	int index;
	int idKnightZodiac;
	int obtainedID;
	int confirmOption;
	int maxID;
	obtainID(&maxID);
	if (pArrayListKnightZodiac != NULL) {
		controller_ListKnightZodiac(pArrayListKnightZodiac); // imprimo lista
		utn_getNumero(&idKnightZodiac,
		"    [Bot_Sanctuary]: Ingrese ID a dar de baja\n    [De la Lista]: ", //pido el ID a borrar
		"    [Bot_Sanctuary]: ID incorrecto, reingrese. ", 1,(maxID - 1), 5);

		index = KnightZodiac_SearchForId(pArrayListKnightZodiac,
				idKnightZodiac); // busco el indice de la ID

		pKnightZodiac = ll_get(pArrayListKnightZodiac, index); // obtengo el elemento del indice
		KnightZodiac_getID(pKnightZodiac, &obtainedID); // obtengo la id del indice

		if (obtainedID == idKnightZodiac) {
			showKnightZodiac(pKnightZodiac); // muestro al caballero seleccionado
			utn_getNumero(&confirmOption,
			"\n\n    [Bot_Sanctuary]: Dar de baja al Caballero?"
			"\n    [1] Dar de baja [Enviar al inframundo]."
			"\n    [2] Cancelar."
			"\n    [Bot_Sanctuary]: Ingrese opcion: ",
			"    [Bot_Sanctuary]: Error, escoja opciones [1-2]: ", 1, 2, 3);

			switch (confirmOption) {
			case 1:
				ll_remove(pArrayListKnightZodiac, index); // borro el empleado
				KnightZodiac_delete(pKnightZodiac); // borro el auxiliar de la funcion
				sucess = 1;
				break;
			case 2:
				sucess = 0;
				break;
			default:
				break;
			}
		}
	}
	return sucess;
}
