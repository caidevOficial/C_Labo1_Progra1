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
#include "../../../LinkedList.h"
#include "../../Parser/parser.h"
#include "../../Employee/Getters/Getters.h"
#include "../../Validate/caidevValidate.h"

int employee_getHigherID(Employee* this,int* id){
    int sucess = -1;

    if(this != NULL){ // si el array no es null, obtengo los datos
        employee_getID(this,id);
        sucess = 0;
    }
    return sucess;
}

int saveAsText_maxID(FILE* pFile, LinkedList* pArrayListEmployee,int* maxID){
    Employee* Employee;

    int ID;
    int len_LL;
    int sucess = 0;
    int biggerID;
    int flag = 0;

    if(pFile != NULL && pArrayListEmployee != NULL){	//si el archivo y el array no son null..
        len_LL = ll_len(pArrayListEmployee);	// obtengo el tamanho del array.

        for(int i=0; i<len_LL; i++){	// recorro el array.
            Employee = ll_get(pArrayListEmployee,i);	// copio la estructura del empleado del indice.
            employee_getHigherID(Employee,&ID);	//obtengo toda la info del empleado.
            if(flag==0 || ID>biggerID){
            	biggerID = ID;
            	flag=1;
            }
            sucess = 1;
        }
    }
    *maxID = biggerID;
    return sucess;
}

int controller_saveAsTextMaxID(FILE* pFile,char* path, LinkedList* pArrayListEmployee){
    int sucess = 0;
    int maxID;

    if(pFile !=NULL && saveAsText_maxID(pFile,pArrayListEmployee,&maxID)){ //si el archivo no es null y pude escribir, retorno 1
        sucess = 1;
        fprintf(pFile,"%d\n",maxID+1);	//escribo los datos de cada empleado en el archivo.
    }
    return sucess;
}
