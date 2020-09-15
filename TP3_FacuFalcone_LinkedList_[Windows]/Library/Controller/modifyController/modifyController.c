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
#include "../registerController/registerController.h"
#include "../../Controller/Controller.h"
#include "../../Employee/Getters/Getters.h"
#include "../../Employee/Setters/Setters.h"
#include "../../Employee/Employee.h"
#include "../../Validate/caidevValidate.h"
#include "../../Parser/parser.h"
#include "../../../LinkedList.h"

int selectedOptionMenu() {
	int optionChoosen;
	printf("\n\n    [Bot_Apu] OPCIONES:"
			"\n    [1] Modificar nombres."
			"\n    [2] Modificar sueldos."
			"\n    [3] Modificar horas trabajadas."
			"\n    [4] Cancelar."
			"\n    Opcion:");
	utn_getNumero(&optionChoosen, " Opcion elegida [1-4]: ",
			"Error, opcion incorrecta.", 1, 4, 5);
	return optionChoosen;
}

int controller_editEmployee(LinkedList *pArrayListEmployee) {
	Employee *pEmployee;
	int sucess = 0;
	int idEmployee;
	int maxID;
	int salaryEmployee;
	int hoursWorked;
	int index;

	char selectedOption = 'y';
	char nameEmployee[100];
	system("cls"); // windows
	//system("clear"); // linux
	if (pArrayListEmployee != NULL) {
		obtainID(&maxID);
		/* Muestro pEmployees y pido el ID */
		controller_ListEmployee(pArrayListEmployee);
		printf("    [Bot_Apu]: Seleccionas entre [1-%d]\n",(maxID-1));
		utn_getNumero(&idEmployee, "    [Bot_Apu]: Ingreses el ID a modificar: ",
				"    [Bot_Apu]: ID incorrectos, por favor reingreses.\n", 1, (maxID-1), 5);

		/* Busco que exista el ID */
		index = employee_SearchForId(pArrayListEmployee,idEmployee);

		if (index == -1) {
			printf("\n    [Bot_Apu]: El empleados ID: %d no existes.\n", idEmployee);
		} else {
			pEmployee = ll_get(pArrayListEmployee, index);
			system("cls"); // windows
			//system("clear"); // linux
			showEmployee(pEmployee);

			do {
				switch (selectedOptionMenu()) {
				case 1:
					system("cls"); // windows
					//system("clear"); // linux
					showEmployee(pEmployee);
					if(utn_getNombre(nameEmployee, sizeof(nameEmployee),
							"    [Bot_Apu]: Ingreses nuevo nombres: ",
							"    [Bot_Apu]: Nombres incorrectos, reingreses.\n", 5)){
						uppercaselInitial(nameEmployee);
						employee_setName(pEmployee, nameEmployee);
						printf("    [Bot_Apu]: Nombres actualizados con exitos!\n"
								"    [Bot_Apu]: Listes de nuevos los empleados para ver los cambios\n");
						sucess = 1;
						selectedOption = 'n';
					}
					break;
				case 2:
					system("cls"); // windows
					//system("clear"); // linux
					showEmployee(pEmployee);
					if(utn_getNumero(&salaryEmployee,
							"    [Bot_Apu]: Ingreses nuevo sueldos [25k-75k]: ",
							"    [Bot_Apu]: Sueldos incorrectos, reingreses.\n", 25000, 75000, 5)){
						employee_setSalary(pEmployee, salaryEmployee);
						printf("    [Bot_Apu]: Sueldos actualizados con exitos!\n"
							   "    [Bot_Apu]: Listes de nuevos los empleados para ver los cambios\n");
						sucess = 1;
						selectedOption = 'n';
					}
					break;
				case 3:
					system("cls"); // windows
					//system("clear"); // linux
					showEmployee(pEmployee);
					if(utn_getNumero(&hoursWorked,
							"    [Bot_Apu]: Ingreses nuevas horas trabajadas [1h-160h]: ",
							"    [Bot_Apu]: Horas incorrectas, reingreses.\n", 1, 160, 5)){
						employee_setHoursWorked(pEmployee, hoursWorked);

						printf("    [Bot_Apu]: Horas actualizadas con exito! \n"
							   "    [Bot_Apu]: Listes de nuevos los empleados para ver los cambios\n");
						sucess = 1;
						selectedOption = 'n';
					}
					break;
				case 4:
					printf("\n    [Bot_Apu]: [Warning!] Cancelandos operacion.\n");
					selectedOption = 'n';
					sucess = 0;
					break;
				default:
					printf("    [Bot_Apu]: [ERROR]. Opcion invalidas, escojas [1-4]\n");
				}
				//printf("    [Bot_Apu]: Desea realizar otras operacion?\n");
				system("pause");
				system("cls"); // windows
				//system("clear); // linux
			} while (selectedOption == 'y');
		}
	}
	return sucess;
}
