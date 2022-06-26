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

#include "../Fecha/fecha.h"
#include "../Notebooks/Notebook.h"
#include "../Servicio/Servicio.h"
#include "../Validate/caidevValidate.h"

#include "Trabajo.h"

int initTrabajo(Trabajo* list, int lenTrab){
	int retornoTrabajo = -1;

	for(int i=0;i<lenTrab;i++){
		list[i].id = 0;
		retornoTrabajo = 1;
	}
	return retornoTrabajo;
}

int buscarLibreTrabajo(Trabajo vec[], int len){
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


int cargaTrabajo(Trabajo* list, int len, int idTrabajo, int idNotebook,int idServicio, Fecha fecha){
	int sucess = -1;
	int index;
	Trabajo auxiliar;

	if(list!=NULL && len > 0){
		index = buscarLibreTrabajo(list,len);
			if (index <0){
				printf("\nMemoria llena.");
			}
			else{
			auxiliar.id = idTrabajo;
			auxiliar.idNotebook = idNotebook;
			auxiliar.idServicio = idServicio;
			auxiliar.Fecha.dia = fecha.dia;
			auxiliar.Fecha.mes = fecha.mes;
			auxiliar.Fecha.anho = fecha.anho;
			sucess = 0;
			list[index]=auxiliar;
		}
	}
	return sucess;
}

int altaTrabajo(int* idTrabajoLibre, Trabajo* trabajo, int trabajoTam, Servicio* servicios, int serviTam,
		Notebook* notebooks,int tamNotebooks, Tipo* tipos, int tamTipos, Marca* marcas, int tamMarca, Cliente* clientes, int tamClientes){
	int isLoaded = -1;
	Trabajo auxiliar;
	int newId;
	newId = *idTrabajoLibre;

	if((trabajo!=NULL && trabajoTam>0)){
		// ID de trabajo autoIncremental
		auxiliar.id = newId;
		listarNotebook(notebooks,tamNotebooks,tipos,tamTipos,marcas,tamMarca,clientes,tamClientes);
		utn_getNumero(&auxiliar.idNotebook, " �  Indique ID de la Notebook: ", " � ID incorrecto, Reintente.\n", 1, 200, 5);

		if(buscarNotebookPorId(notebooks, tamNotebooks,auxiliar.idNotebook) > -1){
			//system("cls");  //Windows
			system("clear"); //Linux
			listarServicios(servicios,serviTam);
			utn_getNumero(&auxiliar.idServicio, " �  Indique ID del Servicio: ", " � ID incorrecta, Reintente.\n", 20000, 20003, 5);
			//FECHA
			utn_getNumero(&auxiliar.Fecha.dia, " �  Indique DIA del trabajo [1-31]: ", " �  Dia incorrecto, Reintente.\n", 1, 31, 5);
			utn_getNumero(&auxiliar.Fecha.mes, " �  Indique MES del trabajo [1-12]: ", " �  Mes incorrecto, Reintente.\n", 1, 12, 5);
			utn_getNumero(&auxiliar.Fecha.anho," �  Indique ANHO del trabajo [2020+]: ", " �  Anho Incorrecto, Reintente desde el 2020.\n", 2020, 2030, 5);

			if(cargaTrabajo(trabajo, trabajoTam, auxiliar.id, auxiliar.idNotebook, auxiliar.idServicio,auxiliar.Fecha)==-1){
				printf(" �  Error de carga.\n");
			}
			else {
				isLoaded = 1;
				(*idTrabajoLibre)++;
				printf(" �  Trabajo cargado con exito!\n");
			}
	    }
		else{
			printf(" �  No existe esa notebook.\n");
		}
	}
	return isLoaded;
}

int encontrarTrabajoPorID(Trabajo* list, int len,int id){
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

void mostrarTrabajo(Trabajo job, Servicio servicios[], int lenServicio,Notebook notebook[],int lenNote){
	char service[20];
	char modelo[20];
	cargarDescripcionNotebook(modelo, job.idNotebook,notebook, lenNote);
	cargarDescripcionServicio(service,job.idServicio,servicios,lenServicio);
   printf(" � %d    %d %10s %10s %d/%d/%d\n", job.id, job.idNotebook,modelo,service,job.Fecha.dia,job.Fecha.mes,job.Fecha.anho);
}

int listarTrabajos(Trabajo* list, int length,Servicio servicios[],int lenServicio, Notebook* notebooks,int lenNote){
	printf(" ������������������������������������������͹\n");
	printf(" �      ���    Lista de Trabajos   ۲�      �\n");
	printf(" � Id Id_Note Modelo    Servicio   Fecha    �\n");

	for (int i = 0;i<length;i++){
		if (list[i].id>0){
			mostrarTrabajo(list[i], servicios, lenServicio,notebooks,lenNote);
		}
	}
	return 0;
}
