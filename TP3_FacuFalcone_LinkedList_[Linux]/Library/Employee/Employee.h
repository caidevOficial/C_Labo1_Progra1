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
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

typedef struct {
    int id;
    char nombre[128];
    int sueldo;
    int horasTrabajadas;
}Employee;

/**
 * @brief 	Inicializa el array en NULL.
 * @param employees
 * @param lenEmployees
 * @return	Retorna 1 si logra hacerlo, sino 0.
 */
int initEmployees(Employee **employees, int lenEmployees);

/**
 * @brief		Busca un indice libre de empleado.
 * @param pIndex
 * @param employees
 * @param lenEmployees
 * @return	Retorna el indice encontrado, sino -1.
 */
int findEmptyIndexEmployee(int *pIndex, LinkedList **employees,
		int lenEmployees);

/**
 * @brief		Busca en el array el indice, segun ID del empleado.
 * @param employee
 * @param lenEmployee
 * @param idEmployee
 * @return	Retorna el indice, sino retorna -1.
 */
int findEmployeeByID(Employee *employee, int lenEmployee, int idEmployee);

/**
 * @brief Busca el indice del empleado pasado por id
 * @param pArrayListEmployee
 * @param id
 * @return	Retorna el indice del empleado o -1 si no lo encuentra.
 */
int employee_SearchForId(LinkedList* pArrayListEmployee, int id);

/**
 * @brief
 * @param index
 * @param Employees
 */
void addEmployeeToArray(int *pIndex, LinkedList *employees);

/**
 * @brief 	Imprime un empleado.
 * @param employee
 * @return	Retorna 1 si salio bien, sino retorna 0.
 */
int showEmployee(Employee *employee);

/**
 * @brief		Imprime la lista de empleados.
 * @param employee
 * @param lenEmployee
 * @return	Retorna 1 si pudo, sino 0.
 */
int showEmployees(Employee **employee, int lenEmployee);

/**
 * @brief Construye empleado.
 * @return Retorna el empleado.
 */
Employee* employee_new();

/**
 * @brief  Construye el nuevo empleado con los datos.
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @param sueldoStr
 * @return Retorna el empleado.
 */
Employee* employee_newParam(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr);

/**
 * @brief Borra el espacio de employee.
 * @param this
 */
void employee_delete(Employee* this);

/**
 * @brief	Ordena los empleados segun eliga el usuario.
 * @param pArrayListEmployee
 * @return	Retorna 1 si pudo, sino 0.
 */
int employee_sortEmployee(LinkedList *pArrayListEmployee);

/**
 * @brief 		Ordena los empleados segun id.
 * @param idOne
 * @param idTwo
 * @return		Si el primero es mayor, retorna 1, si son iguales 0 y si es menor -1.
 */
int employee_sortByID(void *idOne, void *idTwo);

/**
 * @brief 	Ordena empleados segun salario
 * @param salaryOne
 * @param salaryTwo
 * @return 	Si el primero es mayor, retorna 1, si son iguales 0 y si es menor -1.
 */
int employee_sortBySalary(void *salaryOne, void *salaryTwo);

/**
 * @brief		Ordena empleados segun nombre.
 * @param nameOne
 * @param nameTwo
 * @return	Si el primero es mayor, retorna 1, si son iguales 0 y si es menor -1.
 */
int employee_sortByName(void *nameOne, void *nameTwo);

/**
 * @brief 	Ordena empleados segun horas.
 * @param thisUno
 * @param thisDos
 * @return	Si el primero es mayor, retorna 1, si son iguales 0 y si es menor -1.
 */
int employee_sortByHours(void *thisUno, void *thisDos);

#endif // employee_H_INCLUDED
