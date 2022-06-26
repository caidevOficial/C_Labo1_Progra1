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
#include "../Employee/Employee.h"
#include "../Employee/Getters/Getters.h"
#include "../Employee/Setters/Setters.h"
#include "../../LinkedList.h"
#include "../Parser/parser.h"
#include "../Validate/caidevValidate.h"
#include "Controller.h"

#include "saveMaxID_toText/saveToText_maxID.h"

/**
 * @brief 	Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * @param path
 * @param pArrayListEmployee
 * @return	Retorna 1 si pudo cargar, sino retorna 0.
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	FILE* pFile; // para leer los empleados
	FILE*pFile2; //para guardar la proxima ID

	int sucess = 0;

	pFile = fopen(path, "r");
	pFile2 = fopen("lastID.txt","w");
	if (pFile != NULL) {
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		fclose(pFile);
		sucess = 1;
		/*if(pFile2 == NULL){
				for (int i = 0; i < ll_len(pArrayListEmployee); i++) {
					auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
					employee_getID(auxEmployee,&actualID);
					printf("%id",actualID);
					if(actualID > higherID){
						higherID = actualID;
						fprintf(pFile2,"%d\n",higherID);

					}
					//
				}
				fwrite(auxEmployee, sizeof(Employee), 1, pFile);

			}*/
		//fclose(pFile2);
		//fclose(pFile);
		//printf("%d\n",higherID);
	}
	if(controller_saveAsTextMaxID(pFile2,"maxID.txt", pArrayListEmployee)){
		fclose(pFile2);
	}

    return sucess;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *pFile;
	FILE* pFile2;
	int sucess = 0;
	pFile = fopen(path, "rb");
	pFile2 = fopen("lastID.txt","w");
	if (pFile != NULL) {
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		sucess = 1;
	}
	// leo los datos cargados y Guardo el MaxID en archivo de texto
	if(controller_saveAsTextMaxID(pFile2,"maxID.txt", pArrayListEmployee)){
			fclose(pFile2);
		}
	fclose(pFile);

    return sucess;
}

int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	Employee *pEmployee;
	int sucess = 0;
	int id;
	int salaryEmployee;
	int hoursWorked;
	char name[128];

	if (pArrayListEmployee == NULL) {
		printf("\n    [Bot_Apu]: No hay empleados para listar.\n");
	} else {
		printf("    ____________________________________\n"
			   "      ID     Nombre       Horas  Sueldo \n"
			   "    ____________________________________\n");
		sucess = 1;

		for (int i = 0; i < ll_len(pArrayListEmployee); i++) {
			pEmployee = ll_get(pArrayListEmployee, i);
			employee_getID(pEmployee, &id);
			employee_getName(pEmployee, name);
			employee_getSalary(pEmployee, &salaryEmployee);
			employee_getHoursWorked(pEmployee, &hoursWorked);
			printf("    [%4d] [%10s] [%5d] [$%5d] \n", id, name, hoursWorked,salaryEmployee);
		}
	}
	return sucess;
}

int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int sucess = 0;
	if (pArrayListEmployee != NULL) {
		employee_sortEmployee(pArrayListEmployee);
		sucess = 1;
	}
	return sucess;
}

int employee_getAllInfo(Employee* this,char* name,int* hours,int* salary,int* id){
    int sucess = -1;

    if(this != NULL){ // si el array no es null, obtengo los datos
        employee_getName(this,name);
        employee_getHoursWorked(this,hours);
        employee_getSalary(this,salary);
        employee_getID(this,id);
        sucess = 0;
    }
    return sucess;
}

int saveAsTextFormat_Csv(FILE* pFile, LinkedList* pArrayListEmployee){
    Employee* Employee;

    int ID;
    int hours;
    int salary;
    int len_LL;
    int sucess = 0;
    int flagHeader = 1;
    char name[1000];

    if(pFile != NULL && pArrayListEmployee != NULL){ //si el archivo y el array no son null..
        len_LL = ll_len(pArrayListEmployee);	// obtengo el tamanho del array.

        for(int i=0; i<len_LL; i++){	// recorro el array.
            Employee = ll_get(pArrayListEmployee,i);	// copio la estructura del empleado del indice.
            employee_getAllInfo(Employee,name,&hours,&salary,&ID); //obtengo toda la info del empleado.
            if(flagHeader){
            	fprintf(pFile,"%s,%s,%s,%s\n","ID","NAME","HOURS","SALARY");
            	flagHeader = 0;
            }
            fprintf(pFile,"%d,%s,%d,%d\n",ID,name,hours,salary);	//escribo los datos de cada empleado en el archivo.
            sucess = 1;
        }
    }
    return sucess;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee){
    int sucess = 0;
    FILE* pFile = fopen(path,"w"); // abro el archivo

    if(pFile !=NULL && saveAsTextFormat_Csv(pFile,pArrayListEmployee)){ //si el archivo no es null y pude escribir, retorno 1
        sucess = 1;
    }
    fclose(pFile); // cierro el archivo.
    ll_clear(pArrayListEmployee); //vacio el array
    return sucess;
}

int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
	FILE *pFile;
	Employee *auxEmployee;

	int sucess = 0;

	if (pArrayListEmployee != NULL && path != NULL) {
		pFile = fopen(path, "wb");

		for (int i = 0; i < ll_len(pArrayListEmployee); i++) {
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(auxEmployee, sizeof(Employee), 1, pFile);
		}
		fclose(pFile);
		ll_clear(pArrayListEmployee);
		sucess = 1;
	}
	return sucess;
}
