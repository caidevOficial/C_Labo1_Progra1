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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "../Library.Validate/caidevValidate.h"

int initEmployees(Employee* list, int len){
int retorno = -1;
	for(int i=0;i<len;i++){
		list[i].isEmpty = 1;
		retorno = 0;
		}
return retorno;
}

int FindFreePlace(Employee vec[], int len){
	int i;
	int retorno = -1;
	for(i = 0; i < len; i++){
		if (vec[i].isEmpty){
			retorno = i;
			break;
		}
	}
	return retorno;
}

void menuSector(){
	printf("[1] Systems.\n"
		   "[2] Engineering.\n"
		   "[3] Design.\n"
		   "[4] Finances.\n");
}


char menu(){
	char opcionElegida;

	printf("MENU\n");
	printf("Escoja una opcion para operar: \n");
	printf("[A] Alta Empleado.\n");
	printf("[B] Modificar Empleado.\n");
	printf("[C] Baja Empleado.\n");
	printf("[D] Informes.\n");
	printf("[E] Salir.\n");
	fflush(stdin);
	getString(&opcionElegida,sizeof(opcionElegida));
	opcionElegida = tolower(opcionElegida);

	return opcionElegida;
}

int chargeEmployeeData(Employee* list, int listLen, int* thisID){
	int isLoaded = -1;
	Employee auxEmployee;
	int newId;
	newId = *thisID;

	if((list!=NULL && listLen>0)){
		utn_getNombre(auxEmployee.name, 51, "Please, write the name: ", "Wrong Name, please retype.\n", 5);
		utn_getNombre(auxEmployee.lastName, 51, "Write Lastname: ", "Wrong Last name, please retype.\n", 5);
		utn_getNumeroFlotante(&auxEmployee.salary, "Write salary [0-300k]: ", "Wrong salary, this company is not so millionaire.\n", 0, 300000.00, 5);
		menuSector();
		utn_getNumero(&auxEmployee.sector, "Write sector [1-4]: ", "Wrong sector.\n", 1, 4, 5);
		if(addEmployee(list, listLen, newId, auxEmployee.name,auxEmployee.lastName,auxEmployee.salary,auxEmployee.sector)==-1){
			printf("\nLoad error 404.\n");
		}
		else {
			isLoaded = 1;
			(*thisID)++;
		}
	}
	return isLoaded;
}

int findEmployeeById(Employee* list, int len,int id){
	int i;
	int retorno = -1;
	for(i = 0; i < len; i++){
		if (list[i].id == id && list[i].isEmpty==0){
			retorno = i;
			break;
		}
	}
	return retorno;
}

void totalAverageSalary(int* totalSalary, float* averageSalary,Employee list[],int len){
	int totalSalaryEmployee = 0;
	int totalEmployee = 0;
	float averageSalaryEmployee = 0;

	for(int i = 0; i < len; i++){
			if (list[i].isEmpty==0){
				totalSalaryEmployee += list[i].salary;
				totalEmployee++;
				//break;
			}
		}
	*totalSalary = totalSalaryEmployee;
	if (totalEmployee!=0){
		averageSalaryEmployee = (float)totalSalaryEmployee/totalEmployee;
		*averageSalary = averageSalaryEmployee;
	}
	printf("\nThe Total Salary is $ %d\n",totalSalaryEmployee);
	printf("The Average Salary is $ %.2f\n",averageSalaryEmployee);
}

void knowHowManySalaryBigger(float* averageSalary,int flag, Employee list[],int len){
	for(int i = 0; i < len; i++){
			if (list[i].salary > *averageSalary && list[i].isEmpty == 0){
				showEmployee(list[i]);
				flag = 1;
			}
	}
}

int sortEmployees(Employee* list, int len, int order){
    Employee employee;
    int sortOrder = order;
    int everythingOK = -1;

     if(sortOrder==1){
        for(int i=0; i<len-1; i++){ //Ascending
            for(int j=i+1; j<len; j++){
                if(strcmp(list[j].lastName,list[i].lastName)<0){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0 &&
                			list[i].sector>list[j].sector){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
            }
        }
        everythingOK = 1;
    }

    if(sortOrder==0){
        for(int i=0; i<len-1; i++){ //Descending
            for(int j=i+1; j<len; j++) {
                if(strcmp(list[j].lastName,list[i].lastName)>0){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
                else if(strcmp(list[j].lastName, list[i].lastName) == 0 &&
                				list[i].sector<list[j].sector){
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
            }
        }
        everythingOK = 1;
    }

    printEmployees(list,len);
    return everythingOK;
}

void showEmployee(Employee emplo){
   printf("\n    %d    %10s   %10s   %.2f       %d", emplo.id, emplo.name,emplo.lastName,emplo.salary,emplo.sector);
}

int printEmployees(Employee* list, int length){
	printf("\n###################### Employee List ######################## \n");
	printf("     Id        Name        LastName     Salary    Sector\n");
	//printf("\n   [%d]    [%-10s] [-%10s]         [%.2f]       [%d]\n"

	for (int i = 0;i<length;i++){
		if (list[i].isEmpty==0){
			showEmployee(list[i]);
		}
	}
	printf("\n________________________________________________________________\n");
	return 0;
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
	int sucess = -1;
	int index;
	Employee auxiliar;

	if(list!=NULL && len > 0){
		index = FindFreePlace(list,len); // buscar libre
			if (index <0){
				printf("\nThe memory is full.");
			}
			else{
			auxiliar.id = id;
			strcpy(auxiliar.name, name);
			strcpy(auxiliar.lastName, lastName);
			auxiliar.salary = salary;
			auxiliar.sector = sector;
			auxiliar.isEmpty = 0;
			sucess = 0;
			list[index]=auxiliar;
		}
	}
	return sucess;
}

void modifyEmployee(Employee vec[], int tam){

	int id;
	int indice;
	char confirma;
	Employee auxEmpleadoChange;

	int opcionModificar;

	system("cls");
	printf("** Modify Employee **\n\n");
	printEmployees(vec,tam);

	utn_getNumero(&id,"\nPlease, type the ID: ","\nWrong ID, please retype: ",500,2000,200);

	indice = findEmployeeById(vec,tam,id); //devuelve la posicion donde esta el empleado, o -1

	if(indice == -1)
	{
		printf("\nThe ID: %d does not exist in the system.", id);
	}
	else
	{
		printf("\nThe employee with the ID: %d is: \n", id);
		printf("     Id        Name        LastName     Salary    Sector");
		printf("\n__________________________________________________________");
		showEmployee(vec[indice]);
		printf("\n__________________________________________________________");
		printf("\nWhat do you want modify?");
		printf("\n1 - Name."
			   "\n2 - Last Name."
			   "\n3 - Salary."
			   "\n4 - Sector."
			   "\n5 - Go Back.\n");
				scanf("%d",&opcionModificar);
		do{
			switch(opcionModificar){
			case 1: // change Name
				printf("\nModify name? y/n: ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 'y'){
					if (utn_getNombre(auxEmpleadoChange.name,51,"Type a new name: \n","ERROR, Invalid name format\n",0)==0){
						strncpy(vec[indice].name,auxEmpleadoChange.name,51);
						printf("\nUpgrade sucess!.\n");
					}

				}
				else{
					printf("\nOperation cancelled.\n");
					confirma ='n';
				}
				break;
			case 2: // change Last Name
				printf("\nModify last name? y/n: ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 'y'){

					if(utn_getNombre(auxEmpleadoChange.lastName,51,"\nType a new last name: ","\nERROR, Invalid last name format.",0)==0){
						strncpy(vec[indice].lastName,auxEmpleadoChange.lastName,51);
						printf("\nUpgrade sucess!.\n");
					}
				}
				else{
					printf("\nOperation cancelled.\n");
					confirma ='n';
				}
				break;
			case 3: // Salary
				printf("\nModify Salary? y/n: ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 'y'){
					//printf("\nIngrese nueva edad: ");
					utn_getNumeroFlotante(&auxEmpleadoChange.salary,"\nType new salary: ","\nERROR, type a value between 15k & 75k.",15000,75000,2);
					//scanf("%d", &auxEmpleadoChange.edad);
					vec[indice].salary = auxEmpleadoChange.salary;
					printf("\nUpgrade sucess.\n");
				}
				else{
					printf("\nOperacion cancelled.\n");
					confirma ='n';
				}
				break;
			case 4: // Sector
				printf("\nModify sector? y/n: ");
				fflush(stdin);
				scanf("%c", &confirma);
				if(confirma == 'y'){
					utn_getNumero(&auxEmpleadoChange.sector,"\nAssign new sector:","\nERROR, type a sector between 1 & 5.",1,5,2);
					vec[indice].sector = auxEmpleadoChange.sector;
					printf("\nUpgrade sucess.\n");
				}
				else{
					printf("\nOperacion cancelled.\n");
					confirma ='n';
				}
				break;
			default:
				confirma ='n';
				break;
			}
			system("pause");
		}while(confirma=='s');
	}
}


int removeEmployee(Employee* list, int len, int id){

	int retorno = -1;
	int indice = -1;

	indice= findEmployeeById(list,len,id);

	if(indice == -1){
		printf("There isnt an employee with the ID: %d.\n",id);
		system("pause");
	}
	else{
		showEmployee(list[indice]);
		list[indice].isEmpty = 1;
		printf("An employee has been removed!!\n");
		retorno = 0;
		system("pause");
	}
	return retorno;
}
