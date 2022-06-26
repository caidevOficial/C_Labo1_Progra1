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

#include "../../LinkedList.h"

/**
 * @brief 	Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * @param 	pFile
 * @param 	pArrayListEmployee
 * @return	Retorna 1 si pudo, sino 0.
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/**
 * @brief 	Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * @param 	pFile
 * @param 	pArrayListEmployee
 * @return	Retorna 1 si pudo, sino 0.
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
