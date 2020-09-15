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

//#include <stdio.h> // windows
#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "../Controller/Controller.h"
#include "Setters/Setters.h"
#include "Getters/Getters.h"
#include "../Validate/caidevValidate.h"
#include "../../LinkedList.h"
#include "../../MainApp/MainApp.h"

// Constructors
Employee* employee_new() {
	Employee *newEmployee;
	newEmployee = (Employee*) calloc(sizeof(Employee), 1);
	/*
	if (newEmployee != NULL) {
		newEmployee->id = 0;
		strcpy(newEmployee->nombre, " ");
		newEmployee->horasTrabajadas = 0;
		newEmployee->sueldo = 0;
	 }*/
	return newEmployee;
}

Employee* employee_newParam(char *id, char *name, char *hoursWorked,
		char *salary) {
	Employee *newEmployee;
	newEmployee = employee_new();

	int auxId;
	int auxHoras;
	int auxSueldo;

	auxId = atoi(id);
	auxHoras = atoi(hoursWorked);
	auxSueldo = atoi(salary);

	if (newEmployee != NULL && id != NULL && name != NULL && hoursWorked != NULL
			&& salary != NULL) {
		employee_setID(newEmployee, &auxId);
		employee_setName(newEmployee, name);
		employee_setSalary(newEmployee, auxSueldo);
		employee_setHoursWorked(newEmployee, auxHoras);
	}
	return newEmployee;
}

// Searchers
int employee_SearchForId(LinkedList* pArrayListEmployee, int id){
    int retorno = -1;
    int idAux;
    Employee* pEmployee;

    for(int index = 0; index < ll_len(pArrayListEmployee); index++){
        pEmployee = ll_get(pArrayListEmployee, index);
        if(employee_getID(pEmployee, &idAux) == 1 &&
           idAux == id){
            retorno = index;
        }
    }
    return retorno;
}

//
int showEmployee(Employee *employee) {
	int sucess = 0;
	int id;
	char name[128];
	int salary;
	int hours;

	if (employee != NULL) {
		employee_getName(employee,name);
		employee_getSalary(employee,&salary);
		employee_getHoursWorked(employee,&hours);
		employee_getID(employee,&id);
		printf("    __________________________________\n"
			   "       ID    Nombre    Horas Sueldo\n");
		printf("    [%4d] [%10s] [%3d] [$%d]\n", id, name,hours,salary);
		printf("    __________________________________\n");
		sucess = 1;
	}
	return sucess;
}

int showEmployees(Employee **employee, int lenEmployee) {

	int sucess = 0;
	int hasEmployees = 0;

	//printf("en SHOWEMPLO\n");
	if (employee != NULL) {
		for (int i = 0; i < lenEmployee; i++) {
			if (*(employee + i) != NULL) {
				hasEmployees = 1;
				printf("    __________________________________\n"
					   "       ID    Nombre    Horas Sueldo\n");
				showEmployee(*(employee + i));
			}
		}
		if (hasEmployees == 0) {
			printf("    [Bot_Apu]: No hay Empleados para mostrar");
		}
		sucess = 1;
	}
	return sucess;
}

//Destructors
void employee_delete(Employee *this) {
	if (this != NULL) {
		free(this);
	}
}

int showMenuForSort(){
	int option;
	utn_getNumero(&option,"\n\n    [Bot_Apu]: [OPCIONES]"
	"\n    [1] Ordernar listas de empleados por nombres."
	"\n    [2] Ordenar listas de empleados por sueldo."
	"\n    [3] Ordenar listas de empleados por horas trabajadas."
			"\n    [4] Ordenar listas de empleados por ID."
			"\n    [5] Cancelar."
	"\n    [Opcion]:",
	"    [Bot_Apu]: [ERROR]: Oh Calcutas! Opcion incorrectas, Elijas entre [1-4]",1,4,5);
	return option;
}

/* Funtion: [Sort] */
int employee_sortEmployee(LinkedList *pArrayListEmployee) {
	int sucess = 0;
	//system("cls"); //windows
	system("clear"); //linux

	if (pArrayListEmployee != NULL) {
		switch (showMenuForSort()) {
		case 1: /* NOMBRE */
			//system("cls"); //windows
			system("clear"); //linux
			printf("\n    [Bot_Apu]: [Ordenando Lista]\n"
							"    [Bot_Apu]: [Por favor, aguarde unos segundos!]\n"
							"    [Bot_Apu]: [Juro por los numerosos brazos de  ]\n"
							"    [Bot_Apu]: [Vishnu que solos tardaras un poquitos!]\n");
			ll_sort(pArrayListEmployee, employee_sortByName, 1);
			controller_ListEmployee(pArrayListEmployee);
			sucess = 1;
			break;
		case 2: /* HORAS */
			//system("cls"); //windows
			system("clear"); //linux
			printf("\n    [Bot_Apu]: [Ordenando Lista]\n"
							"    [Bot_Apu]: [Por favor, aguarde unos segundos!]\n"
							"    [Bot_Apu]: [Juro por los numerosos brazos de  ]\n"
							"    [Bot_Apu]: [Vishnu que solos tardaras un poquitos!]\n");
			ll_sort(pArrayListEmployee, employee_sortBySalary, 1);
			controller_ListEmployee(pArrayListEmployee);
			sucess = 1;
			break;
		case 3: /* SUELDO */
			//system("cls"); //windows
			system("clear"); //linux
			printf("\n    [Bot_Apu]: [Ordenando Lista]\n"
							"    [Bot_Apu]: [Por favor, aguarde unos segundos!]\n"
							"    [Bot_Apu]: [Juro por los numerosos brazos de  ]\n"
							"    [Bot_Apu]: [Vishnu que solos tardaras un poquitos!]\n");
			ll_sort(pArrayListEmployee, employee_sortByHours, 1);
			controller_ListEmployee(pArrayListEmployee);
			sucess = 1;
			break;
		case 4: /* ID */
			//system("cls"); //windows
			system("clear"); //linux
			printf("\n    [Bot_Apu]: [Ordenando Lista]\n"
							"    [Bot_Apu]: [Por favor, aguarde unos segundos!]\n"
							"    [Bot_Apu]: [Juro por los numerosos brazos de  ]\n"
							"    [Bot_Apu]: [Vishnu que solos tardaras un poquitos!]\n");
			ll_sort(pArrayListEmployee, employee_sortByID, 1);
			controller_ListEmployee(pArrayListEmployee);
			sucess = 1;
			break;
		case 5:
			/* SALIR */
			//opcion = 4;
			printf("\n    [Bot_Apu]: [Accion cancelada]\n");
			sucess = 0;
			break;
		default:
			printf("\n    [Bot_Apu]: [Error 404: Opcion no encontrada]\n");
		}

	}
	//getchar(); // linux
	enterToContinue(); //linux
	//system("pause"); //windows
	return sucess;
}

/* Function/SortBy: [ID] */
int employee_sortByID(void *idOne, void *idTwo) {
	int id1;
	int id2;
	int sucess = 0; // si los id son iguales, devuelve 0

	employee_getID(idOne, &id1);
	employee_getID(idTwo, &id2);

	if (id1 > id2) {
		sucess = 1;
	} else if (id1 < id2) {
		sucess = -1;
	}
	return sucess;
}

/* Function/SortBy: [Salary] */
int employee_sortBySalary(void *salaryOne, void *salaryTwo) {
	int salary1;
	int salary2;
	int sucess = 0; // si los salarios son iguales, devuelve 0

	employee_getSalary(salaryOne, &salary1);
	employee_getSalary(salaryTwo, &salary2);

	if (salary1 > salary2) {
		sucess = 1;
	} else if (salary1 < salary2) {
		sucess = -1;
	}
	return sucess;
}

/* Function/SortBy: [Name] */
int employee_sortByName(void *nameOne, void *nameTwo) {
	char name1[128];
	char name2[128];
	int sucess = 0;

	employee_getName(nameOne, name1);
	employee_getName(nameTwo, name2);

	if (strcmp(name1, name2) > 0) {
		sucess = 1;
	} else if (strcmp(name1, name2) < 0) {
		sucess = -1;
	}

	return sucess;
}

/* Function/SortBy: [WorkingHours] */
int employee_sortByHours(void *thisOne, void *thisToo) {
	int hoursOne;
	int hoursToo;
	int retorno = 0;

	employee_getHoursWorked(thisOne, &hoursOne);
	employee_getHoursWorked(thisToo, &hoursToo);

	if (hoursOne > hoursToo) {
		retorno = 1;
	} else if (hoursOne < hoursToo) {
		retorno = -1;
	}

	return retorno;
}
