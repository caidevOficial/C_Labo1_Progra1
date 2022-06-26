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
#include <string.h>
#include "../Employee.h"
#include "../../Controller/Controller.h"
#include "../../Validate/caidevValidate.h"
#include "../../../LinkedList.h"

int employee_getID(Employee *this, int *id) {
	int sucess = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		sucess = 1;
	}
	return sucess;
}


int employee_getName(Employee *this, char *name) {
	int sucess = 0;

	if (this != NULL && name != NULL) {
		strcpy(name, this->nombre);
		sucess = 1;
	}
	return sucess;
}

int employee_getHoursWorked(Employee *this, int *hoursWorked) {
	int sucess = 0;

	if (this != NULL && hoursWorked != NULL) {
		*hoursWorked = this->horasTrabajadas;
		sucess = 1;
	}
	return sucess;
}

int employee_getSalary(Employee *this, int *salary) {
	int sucess = 0;

	if (this != NULL && salary != NULL) {
		*salary = this->sueldo;
		sucess = 1;
	}
	return sucess;
}

