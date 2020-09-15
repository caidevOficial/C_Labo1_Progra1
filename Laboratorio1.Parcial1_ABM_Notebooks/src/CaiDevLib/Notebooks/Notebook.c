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

#include "../Fecha/fecha.h"
#include "../Validate/caidevValidate.h"
#include "../Tipo/Tipo.h"
#include "../Marca/marca.h"
#include "../Cliente/Cliente.h"

#include "Notebook.h"

int initNotebook(Notebook* list, int lenNote){
	int retornoNotebook = -1;

	for(int i=0;i<lenNote;i++){
		list[i].id = 0;
		retornoNotebook = 1;
	}
	return retornoNotebook;
}

int buscarLibreNotebook(Notebook vec[], int len){
	int i;
	int retorno = -1;
	for(i = 0; i < len; i++){
		if (vec[i].id==0){
			retorno = i;
			break;
		}
	}
	return retorno;
}

int buscarNotebookPorId(Notebook notebook[], int tamN, int idNotebook){
	int index = -1;

	for(int i = 0; i < tamN; i++){
		if(notebook[i].id == idNotebook && notebook[i].id > 0){
			index = i;
			break;
		}
	}
	return index;
}

int cargaNotebook(Notebook* list, int len, int id, int tipo,int precio,char modelo[],int marca,int idCliente, int index){
	int sucess = -1;
	Notebook auxiliar;

	if(list!=NULL && len > 0){

			auxiliar.id = id;
			auxiliar.tipo = tipo;
			auxiliar.precio = precio;
			strcpy(auxiliar.modelo, modelo);
			auxiliar.marca = marca;
			auxiliar.idCliente = idCliente;
			sucess = 0;
			list[index]=auxiliar;
	}
	return sucess;
}

int altaNotebook(int* idNotebookLibre, Notebook notebook[], int tamNotebook,Marca marca[],int tamMarca,Tipo tipo[],int tamTipo, Cliente clientes[], int tamClientes){

	int index;
	int isLoaded = -1;
	Notebook auxNotebook;
	int newId;
	newId = *idNotebookLibre;
	//system("cls"); 		// Windows
	system("clear"); // Linux
	printf("  ����������������������������������������������ͻ\n");
	printf("  �         ���     Alta  Notebook    ۲�        �\n");
	printf("  ����������������������������������������������ͻ\n");

	if((notebook!=NULL && tamNotebook>0)){
		index = buscarLibreNotebook(notebook,tamNotebook);
		if (index <0){
			printf("  �        La memoria esta llena.       �\n");
		}
		else{
			listarMarcas(marca,tamMarca);
			utn_getNumero(&auxNotebook.marca,
					"  �      Indique marca de notebook      �\n"
					"  �         Respuesta: ",
					"  �     Marca incorrecta, seleccione    �\n"
					"  �         entre [1000-1003].          �\n", 1000, 1003, 5);
			//system("cls"); 		// Windows
			system("clear"); // Linux
			listarTipos(tipo,tamTipo);
			utn_getNumero(&auxNotebook.tipo,
					"  �      Indique tipo de notebook       �\n"
					"\n  �         Respuesta: : ",
					"  �       Tipo incorrecto, seleccione   �\n"
					"  �           entre [5000-5003].        �\n", 5000, 5003, 5);
			//system("cls"); 		// Windows
			system("clear"); // Linux
			utn_getNombre(auxNotebook.modelo, 20, "\n  � [Poseidon] [Hades]\n"
													"  � [Zeus] [Odin]\n"
													"  � [Thor] [Loki]\n"
													"  � Indique el nombre de modelo\n"
													"  � de la notebook: ", "\n  � Modelo incorrecto, reintente.\n", 5);
			//system("cls"); 		// Windows
			system("clear"); // Linux
			utn_getNumeroFlotante(&auxNotebook.precio, "\n  � Indique precio entre [$5k - $60k]: \n  � Respuesta: $ ", "\n  � Precio incorrecto, no existe la inflacion aqui.", 5000, 60000, 5);
			auxNotebook.id = newId;

			//system("cls"); 		// Windows
			system("clear"); // Linux
			listarClientes(clientes,tamClientes);
			utn_getNumero(&auxNotebook.idCliente,"\nIndique el ID del cliente: ", "\nID incorrecta, Guiese con la lista.\n",1,13,2 );
			if(encontrarClientePorID(clientes,tamClientes,auxNotebook.idCliente)>-1){
				if(cargaNotebook(notebook, tamNotebook, auxNotebook.id, auxNotebook.tipo,auxNotebook.precio,auxNotebook.modelo,auxNotebook.marca,auxNotebook.idCliente,index)==-1){
					printf("\n  � Error de carga.");
				}
				else {
					printf("\n  � Cargada con Exito! \n");
					isLoaded = 1;
					(*idNotebookLibre)++;
				}
			}
			else{
				printf("\n  � Cliente inexistente. \n");
			}
		}
	}
	return isLoaded;
}

int cargarDescripcionNotebook(char descripcion[], int idNotebook,
								Notebook list[], int tamNotebook){
	int pudo = 0;
	for (int i=0;i<tamNotebook;i++){
		if(list[i].id == idNotebook){
			strcpy(descripcion, list[i].modelo);
			pudo = 1;
		}
	}
	return pudo;
}

int encontrarNotebookPorID(Notebook* list, int len,int id){
	int i;
	int retorno = -1;
	for(i = 0; i < len; i++){
		if (list[i].id == id && list[i].id>0){
			retorno = i;
			break;
		}
	}
	return retorno;
}

void mostrarNotebook(Notebook note, Tipo tipos[], int lenTipos, Marca marcas[], int lenMarcas, Cliente clientes[], int tamClientes){
	char tipo[20];
	char marca[20];
	char nombreCliente[20];

	cargarDescripcionCliente(nombreCliente,note.idCliente,clientes,tamClientes);
	cargarDescripcionMarca(marca,note.marca,marcas,lenMarcas);
	cargarDescripcionTipo(tipo,note.tipo,tipos,lenTipos);
	printf(" �  %d 	%10s %10s    %10s   %.2f %10s   �\n", note.id, note.modelo,marca,tipo,note.precio,nombreCliente);
}

int listarNotebook(Notebook* list, int length, Tipo tipos[], int lenTipos, Marca marcas[], int lenMarcas, Cliente clientes[], int tamClientes){
	//printf("\n    ������������������������������������������ͻ\n");
	printf(" ��������������������������������������������������������������������͹\n");
	printf(" �            ���    Lista de Notebooks   ۲�                         �\n");
	printf(" �  ID	     Modelo 	Marca        Tipo     Precio        Cliente   �\n");
	for (int i = 0;i<length;i++){
		if (list[i].id>0){
			mostrarNotebook(list[i], tipos, lenTipos, marcas, lenMarcas,clientes,tamClientes);
		}
	}
	return 0;
}

// LISTAR NOTEBOOK POR MARCA Y PRECIO
int ordenarNotebooks(Notebook* list, int len, Tipo tipos[], int lenTipos, Marca marcas[],int lenMarcas, Cliente clientes[], int tamClientes){
	Notebook notebook;
     int everythingOK = 0;

     	 // ordenar por marca y precio
        for(int i=0; i<len-1; i++){
            for(int j=i+1; j<len; j++){
                if(strcmp(list[j].marca,list[i].marca)>0){
                	notebook = list[i];
                    list[i] = list[j];
                    list[j] = notebook;
                }
                else if(strcmp(list[j].marca,list[i].marca)==0 &&
					list[i].precio>list[j].precio){
                	notebook = list[i];
                    list[i] = list[j];
                    list[j] = notebook;
                }
            }
        }
        everythingOK = 1;
        system("cls");
		printf(" ������������������������������������������������������ͻ\n");
		printf(" �           ���   Ordenar   Notebook   ۲�             �\n");
		printf(" �        ���   Criterio: Marca y Precio   ۲�          �\n");
		printf(" ������������������������������������������������������͹\n");

        listarNotebook(list,len,tipos,lenTipos,marcas,lenMarcas,clientes,tamClientes);

    return everythingOK;
}


int bajaNotebook(Notebook* list, int len, int id, Tipo tipos[],int lenTipos,Marca marcas[],int lenMarcas, Cliente clientes[], int tamClientes){

	int retorno = 0;
	int indice = -1;

	system("cls");
	printf(" ����������������������������������������������ͻ\n");
	printf(" �         ���     Baja  Notebook    ۲�        �\n");
	printf(" ����������������������������������������������ͻ\n");

	indice= encontrarNotebookPorID(list,len,id);
	if(indice == -1){
		printf("    � no existe notebook  id ID: %d.      �\n",id);
		system("pause");
	}
	else{
		mostrarNotebook(list[indice], tipos, lenTipos, marcas, lenMarcas,clientes,tamClientes);
		list[indice].id = 0;
		printf("    �         notebook removida!!         �\n");
		retorno = 1;
		system("pause");
	}
	return retorno;
}

void modificarNotebook(Notebook vec[], int tam, Tipo tipos[],int lenTipos, Marca marcas[], int lenMarcas, Cliente clientes[], int tamClientes){

	int id;
	int indice;
	char confirma;
	int opcionModificar;
	Notebook auxNotebook;

	system("cls");
	printf("** Modify Notebook **\n\n");
	listarNotebook(vec,tam,tipos,lenTipos,marcas,lenMarcas,clientes,tamClientes);
	utn_getNumero(&id,"\ningrese la id de notebook a modificar: ","\niD incorrecta.: ",1,2000,200);
	indice = encontrarNotebookPorID(vec,tam,id); //devuelve la posicion donde esta la notebook, o -1

	if(indice == -1){
		printf("\nla notebook ID: %d no existe.", id);
	}
	else{
		printf("\nla notebook con el ID: %d es: \n", id);
		printf("   Id       Modelo        Marca     tipo     Precio\n");
		mostrarNotebook(vec[indice], tipos, lenTipos, marcas, lenMarcas,clientes,tamClientes);
		printf("\nque queres modificar?");
		printf("\n1 - Precio."
			   "\n2 - Tipo."
			   "\n3 - Volver.\n");
				scanf("%d",&opcionModificar);
		do{
			switch(opcionModificar){
			case 1: // cambiar precio
				printf("\nCambiar Precio? y/n: ");
				//fflush(stdin);		//Windows
				__fpurge(stdin); // Linux
				scanf("%c", &confirma);
				if(confirma == 'y'){
					if (utn_getNumeroFlotante(&auxNotebook.precio,"\n ingrese nuevo precio [5k - 50k]: ","\nprecio incorrecto. ",5000,50000,2)==0){
						vec[indice].precio = auxNotebook.precio;
						printf("\nModificado!.\n");
					}

				}
				else{
					printf("\nOperacion cancelada.\n");
					confirma ='n';
				}
				break;
			case 2: // Cambiar Tipo
				printf("\nCambiar Tipo? y/n: ");
				//fflush(stdin);		//Windows
				__fpurge(stdin); // Linux
				scanf("%c", &confirma);
				if(confirma == 'y'){
					listarTipos(tipos,lenTipos);
					utn_getNumero(&auxNotebook.tipo,"\nAsigne un nuevo tipo:","\nERROR, el tipo es entre 5000 & 6000.",5000,6000,2);
					vec[indice].tipo = auxNotebook.tipo;
					printf("\nModificado.\n");
				}
				else{
					printf("\nOperacion cancelada.\n");
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
