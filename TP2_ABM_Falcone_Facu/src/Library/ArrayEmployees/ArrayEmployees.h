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
 * 							#Biblioteca
 *
 * About: Versionar
 * El primero (X) se le conoce como version mayor y nos indica la version
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como version menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revision y nos indica que se hizo una revision del
 * 		codigo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : 1.1.1 [Release Candidate v1.1]
 *
 * @author	CaiDev - FacuFalcone
 * ============================================================================
 */

#ifndef LIBRARY_ARRAYEMPLOYEES_ARRAYEMPLOYEES_H_
#define LIBRARY_ARRAYEMPLOYEES_ARRAYEMPLOYEES_H_


typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

/**
 * @brief	To indicate that all position in the array are empty,
 * 			this function put the flag (isEmpty) in TRUE in all
 *			position of the array
 * @param	list Employee* Pointer to array of employees
 * @param	len int Array length
 * @return	int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
*/
int initEmployees(Employee* list, int len);

/**
 * @fn int FindFreePlace(Employee[], int)
 * @brief	Busca el indice libre.
 * @param 	vec
 * @param 	len
 * @return	Retorna el indice si lo encuentra o -1 si no.
 */
int FindFreePlace(Employee vec[], int len);

/**
 * @brief	add in a existing list of employees the values received as parameters
 * 			in the first empty position
 * @param	list employee*
 * @param	len int
 * @param	id int
 * @param	name[] char
 * @param	lastName[] char
 * @param	salary float
 * @param	sector int
 * @return	int Return (-1) if Error [Invalid length or NULL pointer or without
 *			free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * @brief find an Employee by Id en returns the index position in array.
 * @param	list Employee*
 * @param	len int
 * @param	id int
 * @return	Return employee index position or (-1) if [Invalid length or NULL
 *			pointer received or employee not found]
 *
*/
int findEmployeeById(Employee* list, int len,int id);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order);

/**
 * @fn void showEmployee(Employee)
 * @brief
 * @param emplo
 */
void showEmployee(Employee emplo);

/**
 * @fn int chargeEmployeeData(Employee*, int, int*)
 * @brief	Pide datos para cargar el empleado al array.
 * @param 	list
 * @param 	listLen
 * @param 	thisID
 * @return	Retorna 1 si logra cargar el empleado o sino -1.
 */
int chargeEmployeeData(Employee* list, int listLen, int* thisID);

/**
 * @fn int printEmployees(Employee*, int)
 * @brief
 * @param list
 * @param length
 * @return
 */
int printEmployees(Employee* list, int length);

/**
 * @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
 * @brief
 * @param list
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param salary
 * @param sector
 * @return
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * @brief find an Employee by Id en returns the index position in array.
 *
 * @param	list Employee*
 * @param	len int
 * @param	id int
 * @return	Return employee index position or (-1) if [Invalid length or NULL
 *			pointer received or employee not found]
*/
int findEmployeeById(Employee* list, int len,int id);

/** \brief 	Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param 	list Employee*
* \param 	len int
* \param 	id int
* \return 	int Return (-1) if Error [Invalid length or NULL pointer or if can't
*			find a employee] - (0) if Ok
*/
int removeEmployee(Employee* list, int len, int id);

/**
 * @fn void totalAverageSalary(int*, float*, Employee[], int)
 * @brief	Print the sum of all salarys and the average of them.
 * @param 	totalSalary
 * @param 	averageSalary
 * @param 	list
 * @param 	len
 */
void totalAverageSalary(int* totalSalary, float* averageSalary,Employee list[],int len);

/**
 * @fn void knowHowManySalaryBigger(float*, int, Employee[], int)
 * @brief Print on screen the employees that hav a bigger salary than the average.
 * @param averageSalary
 * @param flag
 * @param list
 * @param len
 */
void knowHowManySalaryBigger(float* averageSalary,int flag, Employee list[],int len);

/**
 * @fn int sortEmployees(Employee*, int, int)
 * @brief	ordena la lista de empleados por apellido y sector, ascendente o descendente.
 * @param 	list
 * @param 	len
 * @param 	order
 * @return	Retorna -1 si no pudo ordenar o 1 si pudo.
 */
int sortEmployees(Employee* list, int len, int order);

/**
 * @fn void showEmployee(Employee)
 * @brief	Muestra los datos de un empleado.
 * @param emplo
 */
void showEmployee(Employee emplo);

/**
 * @fn void modifyEmployee(Employee[], int)
 * @brief 	Modifica los datos del empleado.
 * @param 	vec
 * @param 	tam
 */
void modifyEmployee(Employee vec[], int tam);


/**
 * @fn int printEmployees(Employee*, int)
 * @brief	Imprime en pantalla todos los empleados.
 * @param 	list
 * @param 	length
 * @return	0.
 */
int printEmployees(Employee* list, int length);

/**
 * @fn int menu()
 * @brief 	Muestra el menu del abm.
 * @return	Retorna la opcion elegida.
 */
char menu();
/**
 * @fn int ABM(void)
 * @brief	Ejecuta todas las funciones del ABM
 * @return opcion elegida.
 */
int ABM(void);

#endif /* LIBRARY_ARRAYEMPLOYEES_ARRAYEMPLOYEES_H_ */
