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
//#include <windows.h>

#include "../App.Animaciones/logIn.h"
#include "../App.Animaciones/logOut.h"
#include "../CaiDevLib/Cliente/Cliente.h"
#include "../CaiDevLib/Fecha/fecha.h"
#include "../CaiDevLib/Informes/Informes.Funciones.h"
#include "../CaiDevLib/Informes/Informes.Menu.h"
#include "../CaiDevLib/Marca/marca.h"
#include "../CaiDevLib/Notebooks/Notebook.h"
#include "../CaiDevLib/Servicio/Servicio.h"
#include "../CaiDevLib/Tipo/Tipo.h"
#include "../CaiDevLib/Trabajo/Trabajo.h"
#include "../CaiDevLib/Validate/caidevValidate.h"

#define CLIENTES 14
#define NOTEBOOKS 14
#define MARCA 4
#define TIPO 4
#define SERVICIO 4
#define TRABAJO 14

char menu(){
	char retorno;
	printf("    �������������������������������������ͻ\n");
	printf("    �    ���     Menu Principal    ۲�    �\n");
	printf("    �������������������������������������͹\n"
		   "    �   Escoja una opcion para operar:    �\n"
	"    �   [A] Alta Notebook.                �\n"
	"    �   [B] Modificar Notebook.           �\n"
	"    �   [C] Baja Notebook.                �\n"
	"    �   [D] Listar Notebooks.             �\n"
	"    �   [E] Listar Marcas.                �\n"
	"    �   [F] Listar Tipos.                 �\n"
	"    �   [G] Listar Servicios.             �\n"
	"    �   [H] Alta Trabajo.                 �\n"
	"    �   [I] Listar trabajos.              �\n"
	"    �   [J] Informes.                     �\n"
	"    �   [K] Salir.                        �\n"
	"    �������������������������������������͹\n"
	"    �       Opcion: ");
	//fflush(stdin);		//Windows
	__fpurge(stdin); // Linux
	getString(&retorno,sizeof(retorno));
	retorno = tolower(retorno);
	return retorno;
}

int ABM_Notebooks(void) {
																			// 	ID 	MODELO 		MARCA 	TIPO 	PRECIO	CLIENTE
	Notebook notebooks[NOTEBOOKS] = {
																				{1,		"Hermes",			1000,		5003,		19000	,		1},
																				{2,		"Neptune",		1002,		5002,		60000	,		12},
																				{3,		"Cronos",			1003,		5000,		60000	,		2},
																				{4,		"Zeus",				1001,		5000,		56000	,		4},
																				{5,		"Odin",				1001,		5000,		60000	,		5},
																				{6,		"Poseidon",		1003,		5000,		60000	,		1},
																				{7,		"Ares",				1000,		5001,		45000	,		6},
																				{8,		"Afrodita",		1003,		5002,		46000	,		7},
																				{9,		"Persefone",		1001,		5002,		25000	,		9},
																				{10,		"Hades",			1002,		5000,		58000	,		3},
	};
	Marca marca[MARCA] = {
													{1000,	"Compaq"},
													{1001,	"Asus"	},
													{1002,	"Acer"	},
													{1003,	"HP"	}
	};
	Tipo tipo[TIPO] = {
										{5000,	"Gamer"		},
										{5001,	"Disenho"	},
										{5002,	"Ultrabook"	},
										{5003,	"Normalita"	}
	};
	Servicio servicios[SERVICIO] = {
																{20000,	"Bateria",					250},
																{20001,	"Antivirus",				300},
																{20002,	"Actualizacion",	400},
																{20003,	"Fuente",					600}
	};
	Cliente clientes[CLIENTES] = {
															{1,	"Vegita",		'm'},
															{2,	"Gogeta",		'm'},
															{3,	"Vegito",		'm'},
															{4,	"Frieza",		'm'},
															{5,	"Broly",		'm'},
															{6,	"Beerus",		'G'},
															{7,	"Whiss",		'A'},
															{8,	"Bulma",		'f'},
															{9,	"Kakarot",	'm'},
															{10,"Pan",				'f'},
															{11,"Trunks",		'm'},
															{12,"ZenoSama",'G'}
	};
	Trabajo trabajo[TRABAJO]= {
														 //ID  IDNot   IDserv  	  Fecha
														  {1,	 		6,			20001, 	{19,02,2020}},
														  {2,	 		6,			20002,	 {25,02,2020}},
														  {3,	 		3,			20003, 	{14,05,2020}},
														  {4,	 		10,		20000, 	{19,05,2020}},
														  {5,	 		4,			20001, 	{20,02,2020}},
														  {6,	 		5,			20002, 	{21,02,2020}},
														  {7,	 		2,			20001, 	{21,02,2020}},
														  {8,	 		8,			20002, 	{21,02,2020}},
														  {9,	 		7,			20003, 	{21,02,2020}},
														  {10,	 	9,			20003, 	{21,02,2020}}
	};

	int idUltimoTrabajoCargado = 10;
	int idTrabajoLibre = 11;
	int ultimaIdNotebookCargada = 10;
	int idNotebookLibre = 11;
	int idNotebookBaja;
	char respuesta = 's';

	//opening();
	//system("cls"); 		// Windows
	system("clear"); // Linux
	/** Descomentar para inicializar **/
	//initNotebook(notebooks,NOTEBOOKS);
	//initTrabajo(trabajo,TRABAJO);
	do{
		switch(menu()){
		case 'a': // [A] Alta Notebook.
			if(altaNotebook(&idNotebookLibre, notebooks, NOTEBOOKS,marca,MARCA,tipo,TIPO,clientes,CLIENTES)==0){
				ultimaIdNotebookCargada++;
			}
			break;
		case 'b': // [B] Modificar Notebook.
			modificarNotebook(notebooks, NOTEBOOKS, tipo,TIPO, marca, MARCA,clientes,CLIENTES);
			break;
		case 'c': // [C] Baja Notebook.
			//system("cls"); 		// Windows
			system("clear"); // Linux
			printf("*** Baja Notebook ***\n\n");
			listarNotebook(notebooks,NOTEBOOKS,tipo,TIPO,marca,MARCA,clientes,CLIENTES);
			utn_getNumero(&idNotebookBaja,"\ningrese la id para remover: ","\nERROR, reingrese: ",1,ultimaIdNotebookCargada,10);
			bajaNotebook(notebooks, NOTEBOOKS, idNotebookBaja, tipo,TIPO,marca,MARCA,clientes,CLIENTES);
			break;
		case 'd': // [D] Listar Notebooks.
			ordenarNotebooks(notebooks, NOTEBOOKS, tipo, TIPO, marca,MARCA,clientes,CLIENTES);
			break;
		case 'e': // [E] Listar Marcas.
			//system("cls"); 		// Windows
			system("clear"); // Linux
			listarMarcas(marca,MARCA);
			break;
		case 'f': // [F] Listar Tipos.
			//system("cls"); 		// Windows
			system("clear"); // Linux
			listarTipos(tipo, TIPO);
			break;
		case 'g': // [G] Listar Servicios.
			//system("cls"); 		// Windows
			system("clear"); // Linux
			listarServicios(servicios,SERVICIO);
			break;
		case 'h': /*** [H] Alta Trabajo. */
			//system("cls"); 		// Windows
			system("clear"); // Linux
			if (ultimaIdNotebookCargada == 0){
				printf("    � Aun no cargo ninguna notebook, \n"
						"    �     Empiece por ahi.\n");
			}else{
				if (altaTrabajo(&idTrabajoLibre,trabajo,TRABAJO,servicios,SERVICIO,
						notebooks,NOTEBOOKS, tipo, TIPO, marca, MARCA,clientes,CLIENTES)){
					idUltimoTrabajoCargado = idTrabajoLibre-1;
				}
			}
			break;
		case 'i': // [I] Listar trabajos.
			//system("cls"); 		// Windows
			system("clear"); // Linux
			if (idUltimoTrabajoCargado==0){
				printf("    � Aun no hay ningun trabajo cargado!\n");
			}else{
				listarTrabajos(trabajo, TRABAJO,servicios,SERVICIO,notebooks,NOTEBOOKS);
			}
			break;
		case 'j': /** [J] INFORMES. **/
			informes(trabajo,TRABAJO,notebooks,NOTEBOOKS , tipo, TIPO, marca, MARCA,servicios,SERVICIO,clientes,CLIENTES);
			break;
		case 'k': // [K] Salir.
			respuesta = caseSalir();
			break;
		default:
			printf("    �  Opcion Incorrecta, Use [A - K]\n");
			break;
		}
		system("pause");
		//system("cls"); 		// Windows
		system("clear"); // Linux
	}while(respuesta == 's');
	return EXIT_SUCCESS;
}
