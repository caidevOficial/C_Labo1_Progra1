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

#include "Informes.Funciones.h"
#include "../Notebooks/Notebook.h"
#include "../Servicio/Servicio.h"
#include "../Marca/marca.h"
#include "../Tipo/Tipo.h"
#include "../Validate/caidevValidate.h"

/** INFORMES **/

		/** INFORME 1**/
// INFORMA TOTAL DE NOTEBOOKS POR tipo
void informarNotebooksPorTipo(Notebook vec[], int tam,Tipo tipos[], int tamTipos, Marca marcas[], int tamMarca, Cliente clientes[], int tamClientes){
	int idTipo;
	int hayNotebooksDeTipo = 0;
	char tipo[20] ;

	system("cls");
	printf(" บ Listado de notebooks por Tipo **\n\n");
	listarTipos(tipos,tamTipos);
	utn_getNumero(&idTipo," บ Ingrese ID del tipo: "," บ Error: Escoja entre [5000 - 5003]: ",5000,5003,2);
	cargarDescripcionTipo(tipo,idTipo,tipos,tamTipos);
	printf(" บ Notebooks Tipo %s \n\n ", tipo);
	printf(" บ Id       Modelo        Marca        tipo     Precio   Cliente\n");

	for (int i=0; i< tam; i++){
		if (vec[i].id > 0 && vec[i].tipo == idTipo){
			mostrarNotebook(vec[i],tipos,tamTipos,marcas,tamMarca,clientes,tamClientes);
			hayNotebooksDeTipo = 1;
		}
	}
	if ( hayNotebooksDeTipo == 0){
		printf(" บ No hay notebooks del tipo %10s \n",tipo);
	}
}

		/** INFORME 2 **/
void informarNotebooksPorMarcas(Notebook vec[], int tam,Tipo tipos[], int tamTipos, Marca marcas[], int tamMarca, Cliente clientes[], int tamClientes){
    int idMarca;
    int hayNotebooksDeLaMarca = 0;
    char nombreMarca[20] ;

    system("cls");
    printf(" บ Listado de notebooks por Marca **\n\n");
    listarMarcas(marcas,tamMarca);
    utn_getNumero(&idMarca," บ Ingrese ID de la Marca: ","\nError: Escoja entre [1000 - 1003]\n",1000,1003,2);
    cargarDescripcionMarca(nombreMarca,idMarca,marcas,tamMarca);
    system("cls");
    printf(" บ Notebooks Marca %10s\n", nombreMarca);
    printf(" บ Id       Modelo      Marca          tipo     Precio      Cliente\n");

    for (int i=0; i< tam; i++){
        if (vec[i].id > 0 && vec[i].marca == idMarca){
        	mostrarNotebook(vec[i],tipos,tamTipos,marcas,tamMarca,clientes,tamClientes);
        	hayNotebooksDeLaMarca = 1;
        }
    }
    if ( hayNotebooksDeLaMarca == 0){
        printf(" บ No hay notebooks de la marca %10s\n",nombreMarca);
    }
}


		/** INFORME 3 **/
// Informa el valor, marca y modelo de la notebook mas barata
void informarMenorPrecioNotebook(Notebook vec[], int tam,Tipo tipos[],int tamTipo, Marca marcas[], int tamMarca, Cliente clientes[], int tamClientes){
	float menorPrecio = 0;
	int contador = 0;
	int idNotebook;
	char modelo[20];
	system("cls");
	for (int e = 0;e<tam;e++){
		if (vec[e].id>0){
			if (menorPrecio>vec[e].precio || contador == 0){
				menorPrecio=vec[e].precio;
				contador++;
			}
		}
	}
	if (contador >0){
		printf(" ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
		printf(" บ    ฑฒÛ     Lista de Notebooks baratas    Ûฒฑ                       บ\n");
		printf(" บ  ID	     Modelo 	Marca      Tipo       Precio        Cliente   บ\n");

		for (int e = 0; e<tam;e++){
			if (vec[e].id > 0 && menorPrecio == vec[e].precio){
				idNotebook = vec[e].id;
				cargarDescripcionNotebook(modelo,idNotebook,vec,tam);
				mostrarNotebook(vec[e],tipos,tamTipo,marcas,tamMarca,clientes,tamClientes);
			}
		}
	}
	printf("\n");
}

		/** INFORME 4 **/
void informarNotebooksXMarcas(Notebook notebooks[], int tamNotebooks, Tipo tipos[], int tamTipo, Marca marcas[], int tamMarca, Cliente clientes[], int tamClientes){
    int hayNotebooks=0;
    system("cls");
    printf(" ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
	printf(" บ            ฑฒÛ    Lista de Notebooks   Ûฒฑ                       บ\n");
	printf(" บ  ID	     Modelo 	Marca          Tipo     Precio    Cliente   บ\n");

    for (int m = 0; m<tamMarca; m++){
        printf(" ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
        for(int n=0; n<tamNotebooks; n++){
            if(notebooks[n].id > 0 && notebooks[n].marca == marcas[m].id){
                mostrarNotebook(notebooks[n], tipos, tamTipo, marcas, tamMarca,clientes,tamClientes);
                hayNotebooks =1;
            }
        }
        if (hayNotebooks == 0){
        	printf(" บ  ID	     Modelo 	Marca          Tipo     Precio  บ\n");
        	printf(" บ  Marca %10s - No tiene Notebooks cargadas           บ\n",marcas[m].descripcion);

        }
    }
    printf(" ฬออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
}

		/** INFORME 5 **/
void cantidadNotebooksMarcaTipo(Notebook vec[],int tamNotebooks, Tipo tipos[], int tamTipos, Marca marcas[],int tamMarcas){

	int cantidadNotebooks = 0;
	int tipoNotebook;
	int marcaNotebook;
	char descripcionMarca[20];
	char descripcionTipo[20];

	system("cls");
	printf(" บ Cantidad de notebooks segun criterio  \n");
	listarTipos(tipos,tamTipos);
	utn_getNumero(&tipoNotebook," บ Elegi un tipo: "," บ Error, Elegi entre [5000-5003]",5000,5003,2);
	cargarDescripcionTipo(descripcionTipo,tipoNotebook,tipos,tamTipos);
	system("cls");
	listarMarcas(marcas,tamMarcas);
	utn_getNumero(&marcaNotebook," บ Elegi una marca: "," บ Error, Elegi entre [1000-1003]",1000,1003,2);
	cargarDescripcionMarca(descripcionMarca,marcaNotebook,marcas,tamMarcas);
	system("cls");
	for (int e = 0;e<tamNotebooks;e++){
		if (vec[e].id > 0 && vec[e].marca == marcaNotebook && vec[e].tipo == tipoNotebook){
			cantidadNotebooks++;
		}
	}
	printf(" บ Notebooks %10s tipo %10s: %d Unit. บ",descripcionMarca,descripcionTipo,cantidadNotebooks);
	printf("\n ฬอออออออออออออออออออออออออออออออออออออออออออออออน");
	printf("\n");
}

		/** INFORME 6 **/
// Para inicializar antes de guardar elementos
// donde guardare las marcas con la cantidad de notebooks que haya.
int initMostChosenBrand(BestBrand bestBrand[], int lenBbrand){
	int everythingOk = -1;

	if(bestBrand != NULL){
		for(int i = 0; i < lenBbrand; i++){
			bestBrand[i].idBrand = 0;
		}
		everythingOk = 0;
	}
	return everythingOk;
}

void informarMarcaMasElegida(Notebook notebooks[], int tamNotebooks, Tipo tipos[], int tamTipos,
								Marca marcas[], int tamMarcas, BestBrand mostChosen[]){
	int flagCounter;
	int thisBrand = 0;
	BestBrand auxBestBrand;
	int flag = 0;
	int indiceMarca;

	system("cls");
	printf(" ฬอออออออออออออออออออออออออออออออออออออน\n");
	printf(" บ  Informe Marcas Mas Elegidas\n");
	//recorro marcas
	for(int m = 0; m < tamMarcas; m++) {
		// el contador se reinicia en cada iteracion de vector marca
		flagCounter = 0;
		// dentro de una marca se recorre todas las notebooks
		for(int n = 0; n < tamNotebooks; n++){
			// si encuentro una notebook con la id de la marca, el contador lo aumento en 1
			if(notebooks[n].id > 0 && notebooks[n].marca == marcas[m].id){
				flagCounter++;
			}
		}
		mostChosen[thisBrand].idBrand = marcas[m].id;
		mostChosen[thisBrand].qtyChosen = flagCounter;
		thisBrand++;
	}

	for(int m = 0; m < tamMarcas; m++){
		if(flag == 0){
			auxBestBrand = mostChosen[m];
			flag = 1;
		}
		else if(mostChosen[m].qtyChosen > auxBestBrand.qtyChosen && mostChosen[m].idBrand > 0){
			auxBestBrand = mostChosen[m];
		}
	}

	printf(" บ  Marca mas elegida: \n");
	printf(" บ         ID             Descripcion\n");
	for(int m = 0; m < tamMarcas; m++){
		if(auxBestBrand.qtyChosen == mostChosen[m].qtyChosen && mostChosen[m].idBrand > 0){
			// se muestra la marca
			indiceMarca = buscarMarcaPorId(mostChosen[m].idBrand, marcas, tamMarcas);
			mostrarMarca(marcas[indiceMarca]);
		}
	}
	printf(" ฬอออออออออออออออออออออออออออออออออออออน\n");
}

		/** INFORME 7 **/
void informarTrabajosDeNotebook (Trabajo trabajos[], int tamTrabajo, Notebook notebooks[], int tamNote,
			Tipo tipos[], int tamTipo, Marca marcas[], int tamMarca, Servicio servicios[], int tamServ, Cliente clientes[], int tamClientes){
	int flag=0;
	int idNote;
	char modelo[20];

	system("cls");
	printf(" บ  Lista de Trabajos de una notebook\n");

	listarNotebook(notebooks,tamNote,tipos, tamTipo, marcas, tamMarca,clientes,tamClientes);
	utn_getNumero(&idNote," บ  Ingrese la ID de la notebook: "," บ  Error, escoja entre las listadas.\n",1,20,2);
	cargarDescripcionNotebook(modelo, idNote, notebooks, tamNote);

	system("cls");
	printf("\n\n บ  Notebook: %s\n", modelo);

	printf(" บ IDtr IDnot  MODELO     SERVICIO FECHA\n");
	for (int i=0; i< tamTrabajo; i++){
		if (trabajos[i].id >0 && trabajos[i].idNotebook == idNote){
			mostrarTrabajo(trabajos[i],servicios, tamServ,notebooks, tamNote);
			flag = 1;
		}
	}
	if ( flag == 0){
		printf(" บ  No hay trabajos en esa notebook.\n");
	}
}

		/** INFORME 8 **/
void sumaImporteServicios(Notebook notebooks[], int tamNotebook, Tipo tipos[], int tamTipos, Marca marcas[],
		int tamMarca, Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicio, Cliente clientes[], int tamClientes){
	int NotebookID;
	int notebookIndex;
	int ServiceID;
	int serviceIndex;
	float ServiceTotal = 0;

	system("cls");
	printf(" บ  Service Notebooks ##\n");

	listarNotebook(notebooks, tamNotebook, tipos, tamTipos, marcas, tamMarca,clientes,tamClientes);
	utn_getNumero(&NotebookID, " บ Ingrese ID de notebook : ", " บ Error, Seleccione de la lista.\n", 1, 20,2);
	notebookIndex = encontrarNotebookPorID(notebooks, tamNotebook,NotebookID);
	printf(" ฬอออออออออออออออออออออออออออออออออออออน\n");
	if(notebookIndex < 0){
		printf("La notebook no existe en sistema.\n\n");
	}
	else{
		printf(" บ  ID      Modelo       Marca       Tipo     Precio       Cliente\n");
		mostrarNotebook(notebooks[notebookIndex], tipos, tamTipos, marcas, tamMarca,clientes,tamClientes);
		for(int t = 0; t < tamTrabajos; t++){
			if(notebooks[notebookIndex].id == trabajos[t].idNotebook && trabajos[t].id > 0){
				ServiceID = trabajos[t].idServicio;
				serviceIndex = buscarServicioPorId(ServiceID, servicios, tamServicio);
				ServiceTotal += servicios[serviceIndex].precio;
			}
		}

		if(ServiceTotal == 0){
			printf(" บ La notebook no tiene trabajos hechos.\n");
		}
		else{
			printf(" บ Costo de servicios notebook: %.2f\n", ServiceTotal);
		}
	}
}


		/**  INFORME 9 **/
void pedirServicioMostrarNotebook(Trabajo trabajos[], int tamTrabajo, Notebook notebooks[],int tamNotebook,
		Tipo tipos[],int tamTipos,Marca marcas[],int tamMarcas,Servicio servicios[],int tamService, Cliente clientes[], int tamClientes){
	int serviceID;

	listarServicios(servicios,tamService);
	utn_getNumero(&serviceID, " บ  Indique ID del Servicio: ", " บ ID incorrecta, Reintente.\n", 20000, 20003, 5);
	system("cls");
	printf(" บ IDtr IDnot  MODELO     SERVICE  FECHA\n");

	for (int i = 0; i < tamTrabajo; i++){
		if(trabajos[i].id > 0 && trabajos[i].idServicio == serviceID){
			for(int j = 0; j < tamNotebook; j++){
				if(notebooks[j].id == trabajos[i].idNotebook){
					mostrarTrabajo(trabajos[i],servicios,tamService,notebooks,tamNotebook);
				}
			}
		}
	}
}

		/** INFORME 10 **/
void serviciosPorFecha(Trabajo trabajos[], int tamTrabajo, Servicio servicios[], int tamServicio){
	Fecha auxFecha;
	int serviceIndex;
	int hayServicios = 0;

	utn_getNumero(&auxFecha.dia, " บ Ingrese el dia [1-31]: "," บ Dia incorrecto, reingrese.\n",1,31,2);
	utn_getNumero(&auxFecha.mes, " บ Ingrese el mes [1-12]: "," บ Mes incorrecto, reingrese.\n",1,12,2);
	utn_getNumero(&auxFecha.anho, " บ Ingrese el anho [2019++]: "," บ Anho incorrecto, reingrese.\n",2019,2030,2);

	system("cls");
	printf("  บ Servicios hechos:\n");
	printf("  บ   ID             Descripcion         Precio\n");
	for(int t = 0; t < tamTrabajo; t++){
		if(trabajos[t].id > 0 && trabajos[t].Fecha.dia == auxFecha.dia && trabajos[t].Fecha.mes == auxFecha.mes
				&& trabajos[t].Fecha.anho == auxFecha.anho){
			serviceIndex = buscarServicioPorId(trabajos[t].idServicio, servicios, tamServicio);
			mostrarServicio(servicios[serviceIndex]);
			hayServicios = 1;
		}
	}
	if(hayServicios == 0){
		printf(" บ  Fecha sin servicios.\n");
	}
}
