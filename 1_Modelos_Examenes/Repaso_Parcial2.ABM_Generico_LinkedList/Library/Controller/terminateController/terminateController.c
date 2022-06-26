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
 * Version     : Beta 3.0.0 [Beta v3.0.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
 * ============================================================================
 */

//#include <stdio.h> //windows
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Controller.h"
#include "../../../inc/LinkedList.h"
#include "../../Object/Getters/Getters.h"
#include "../../Object/Object.h"
#include "../../Parser/parser.h"
#include "../../Validate/caidevValidate.h"
#include "../registerController/registerController.h"

int controller_removeObject(LinkedList *this) {
	Object *thisObject;

	int sucess = 0;
	int index;
	int idObject;
	int obtainedID;
	int confirmOption;
	int maxID;
	obtainID(&maxID);
	if (this != NULL) {
		controller_ListObject(this); // imprimo lista
		utn_getNumero(&idObject,
				"    [Bot_Sanctuary]: Ingrese ID a dar de baja\n    [De la Lista]: ", //pido el ID a borrar
				"    [Bot_Sanctuary]: ID incorrecto, reingrese. ", 1,
				(maxID - 1), 5);

		index = Object_SearchForId(this,
				idObject); // busco el indice de la ID

		thisObject = ll_get(this, index); // obtengo el elemento del indice
		Object_getID(thisObject, &obtainedID); // obtengo la id del indice

		if (obtainedID == idObject) {
			showObject(thisObject); // muestro al caballero seleccionado
			utn_getNumero(&confirmOption,
					"\n\n    [Bot_Sanctuary]: Dar de baja al Caballero?"
							"\n    [1] Dar de baja [Enviar al inframundo]."
					"\n    [2] Cancelar."
							"\n    [Bot_Sanctuary]: Ingrese opcion: ",
					"    [Bot_Sanctuary]: Error, escoja opciones [1-2]: ", 1,
					2, 3);

			switch (confirmOption) {
			case 1:
				ll_remove(this, index); // borro el empleado
				Object_delete(thisObject); // borro el auxiliar de la funcion
				sucess = 1;
				break;
			case 2:
				sucess = 0;
				break;
			default:
				//printf("\n    [Bot_Sanctuary]: [ERROR] Opcion invalida.\n");
				break;
			}
		}
	}
	return sucess;
}
