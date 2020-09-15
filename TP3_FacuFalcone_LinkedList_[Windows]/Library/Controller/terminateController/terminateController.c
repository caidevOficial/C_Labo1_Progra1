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
 * About: Versionar
 * El primero (X) se le conoce como version mayor y nos indica la version
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como version menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revision y nos indica que se hizo una revision del
 * 		codigo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : RC 6.13.2020 [Release Candidate v6.13] - FacuFalcone_LinkedList
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Controller.h"
#include "../../Employee/Employee.h"
#include "../../Employee/Getters/Getters.h"
#include "../../../LinkedList.h"
#include "../../Parser/parser.h"
#include "../../Validate/caidevValidate.h"
#include "../registerController/registerController.h"

int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	Employee *pEmployee;

	int sucess = 0;
	int index;
	int idEmployee;
	int obtainedID;
	int confirmOption;
	int maxID;
	obtainID(&maxID);
	if (pArrayListEmployee != NULL) {
		controller_ListEmployee(pArrayListEmployee); // imprimo lista
		utn_getNumero(&idEmployee, "    [Bot_Apu]: Ingrese ID a dar de baja\n    [De la Lista]: ", //pido el ID a borrar
				"    [Bot_Apu]: ID incorrecto, reingrese. ", 1, (maxID-1), 5);

		index = employee_SearchForId(pArrayListEmployee, idEmployee); // busco el indice de la ID

		pEmployee = ll_get(pArrayListEmployee, index); // obtengo el elemento del indice
		employee_getID(pEmployee, &obtainedID); // obtengo la id del indice

		if (obtainedID == idEmployee) {
			utn_getNumero(&confirmOption,"\n\n    [Bot_Apu]: Dar de bajas al empleados?"
					"\n    [1] Dar de bajas."
					"\n    [2] Cancelar."
					"\n    [Bot_Apu]: Ingreses opcion: ",
					"    [Bot_Apu]: Error, escojas opciones [1-2]: ",1,2,3);

			switch (confirmOption) {
			case 1:
				ll_remove(pArrayListEmployee, index); // borro el empleado
				employee_delete(pEmployee); // borro el auxiliar de la funcion
				sucess = 1;
				break;
			case 2:
				sucess = 0;
				break;
			default:
				//printf("\n    [Bot_Apu]: [ERROR] Opcion invalidas.\n");
				break;
			}
		}
	}
	return sucess;
}
