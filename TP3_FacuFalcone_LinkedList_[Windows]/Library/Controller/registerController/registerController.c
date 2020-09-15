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
#include "../../Employee/Employee.h"
#include "../../Employee/Getters/Getters.h"
#include "../../Employee/Setters/Setters.h"
#include "../../../LinkedList.h"
#include "../../Parser/parser.h"
#include "registerController.h"
#include "../../Validate/caidevValidate.h"
#include "../saveMaxID_toText/saveToText_maxID.h"

/**
 * @brief me genera un id nuevo
 * solo puede ser llamada por una funcion de aca
 * @return	Retorna 1 si pudo, sino 0.
 */
int obtainID(int* id){
	int sucess = 0;
	int newID;
	//*id = 1001; //la inicializo con 1001
	FILE* pFile;
	pFile = fopen("lastID.txt","r"); // abro el archivo.
	if(pFile!=NULL){
		fscanf(pFile, "%d\n", &newID);
		//fread(&newID,sizeof(int),1,pFile); //leo la ultima id guardada.
		*id = newID;
		fclose(pFile); // lo cierro si lo pude abrir.
		sucess = 1;
	}
	return sucess;
}

int upgradeID(int id){
	int nextID = ++id; // nextID vale id+1
	// ++id es lo mismo que (id++)
	int sucess = 0;
	FILE* pFile;
	pFile = fopen("lastID.txt","w"); // abre el texto
	if(pFile!=NULL){
		fprintf(pFile,"%d\n",nextID);
		//fwrite(&nextID,sizeof(int),1,pFile); //guarda la id en binario
		fclose(pFile); // lo cierro si lo pude abrir.
		sucess = 1;
	}
	return sucess;
}
/**
 * @brief lee la ultima id del bin y la actualiza con la nueva.
 */
/*
void controllerAlta(){
	int id;
	obtainID(&id); //obtiene la proxima id
	printf("ID: %d",id); // la muestro por si acaso
	upgradeID(id); //actualizo con la nueva id que obtuve
}*/

int controller_addEmployee(LinkedList *pArrayListEmployee) {
	Employee *pEmployee;
	pEmployee = employee_new();

	int sucess = 0;
	int idForUse;
	int hoursWorked;
	int salaryEmployee;
	char nameEmployee[128];

	if (pArrayListEmployee != NULL) {
		obtainID(&idForUse); // Obtengo el ID al leerlo desde el archivo "lastID.txt" .
		printf("    [Bot_Apu]: El altas se asignara con el ID: %d\n",idForUse);
		//------------------- Pido Nombre
		utn_getNombre(nameEmployee, 128, "    [Bot_Apu]: Ingrese un nombre: ",
				"    [Bot_Apu]: Nombre incorrecto, reingrese.", 5);
		uppercaselInitial(nameEmployee); //--------- Normalizo en minuscula e inicial mayuscula
		//------------------- Pido Salario
		utn_getNumero(&salaryEmployee, "    [Bot_Apu]: Ingrese Salario [25k-75k]: $ ",
				"    [Bot_Apu]: Salario incorrecto, reintente.", 25000, 75000, 5);
		//------------------- Pido Horas
		utn_getNumero(&hoursWorked, "    [Bot_Apu]: Ingrese Horas trabajadas [1h-160h]: ",
				"    [Bot_Apu]: Salario incorrecto, reintente.", 1, 160, 5);

		if (pEmployee != NULL) {
			employee_setID(pEmployee, &idForUse);
			employee_setName(pEmployee, nameEmployee);
			employee_setSalary(pEmployee, salaryEmployee);
			employee_setHoursWorked(pEmployee, hoursWorked);
			ll_add(pArrayListEmployee, pEmployee);
			upgradeID(idForUse); // guarda en el archivo idForUse+1 en "lastID.txt"
			sucess = 1;
		}
	}
	return sucess;
}
