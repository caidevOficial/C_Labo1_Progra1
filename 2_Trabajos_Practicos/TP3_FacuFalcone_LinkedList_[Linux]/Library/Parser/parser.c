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

//#include <stdio.h>//windows
#include <stdio_ext.h>//linux
#include <stdlib.h>
#include "../Employee/Employee.h"
#include "../../LinkedList.h"
#include "parser.h"

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	Employee *pEmployee;

	char auxID[100];
	char auxName[100];
	char hoursWorked[100];
	char salary[100];

	int sucess = 0;
	int firstElement = 1;

	if (pFile != NULL) {
		while (!feof(pFile)) {
			if (firstElement) {
				fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxID, auxName,
						hoursWorked,salary);
				firstElement = 0;
			}
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxID, auxName,
					hoursWorked,salary);
			pEmployee = employee_newParam(auxID, auxName, hoursWorked,salary);

			if (pEmployee != NULL) {
				ll_add(pArrayListEmployee, pEmployee);
				sucess = 1;
			}
		}
	}
	return sucess;
}

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	Employee *pEmployee;
	int sucess = 0;

	if (pFile != NULL) {	//mientras el archivo no sea nulo, entro al bucle
		while (!feof(pFile)) {		// mientras no sea final de archivo, bucleo
			pEmployee = employee_new(); // inicializo
			if (fread(pEmployee, sizeof(Employee), 1, pFile) == 1) {
				ll_add(pArrayListEmployee, pEmployee); // copio lo de pEmplo en el array
			}
		}
		sucess = 1;
	}
	return sucess;
}
