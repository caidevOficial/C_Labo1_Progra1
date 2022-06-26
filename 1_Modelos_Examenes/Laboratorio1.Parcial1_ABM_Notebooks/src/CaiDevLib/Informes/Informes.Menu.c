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

#include "../Cliente/Cliente.h"
#include "../Marca/marca.h"
#include "../Notebooks/Notebook.h"
#include "../Servicio/Servicio.h"
#include "../Tipo/Tipo.h"
#include "../Validate/caidevValidate.h"

#include "Informes.Funciones.h"

#define BRAND 4 // mismo tamanho que cantidad de marcas para Harcodear.
// Vector para guardar las marcas y la cantidad de notebooks que hay
// de esa misma marca - [Marca mas elegida].
BestBrand mostChosen[BRAND];

char menuInforme(){
	char opcionMenu;
	printf(" �������������������������������������ͻ\n"
			" �    ���     Menu  Informes    ۲�    �\n"
			" �������������������������������������͹\n"
			" � Que desea informar? \n"
			" � [A] P1 - Listar notebook de tipo.\n"
			" � [B] P2 - Listar notebook de marca.\n"
			" � [C] P3 - Listar las mas baratas.\n"
			" � [D] P4 - Listar Notebook por Marca.\n"
			" � [E] P5 - Cantidad Not. Marca Sector.\n"
			" � [F] P6 - Marcas mas elegidas.\n"
			" � [G] P7 - Mostrar trabajos de notebook.\n"
			" � [H] P8 - Servicios por pc.\n"
			" � [I] P9 - Pedir servicio y ver notebooks.\n"
			" � [J] P10 - Pedir Fecha y ver Servicios.\n"
			" � [L] SALIR.\n"
			" �  Opcion: ");
	fflush(stdin);
	getString(&opcionMenu,sizeof(opcionMenu));
	opcionMenu = tolower(opcionMenu);

	return opcionMenu;
}

int informes(Trabajo trabajos[],int tamTrabajo,Notebook vec[], int tam, Tipo tipos[],int tamTipos,
		Marca marcas[], int tamMarca, Servicio servicios[], int tamServi,Cliente clientes[], int tamClientes){
	int retorno = 0;
	char seguir = 's';
	system("cls");
	do{
		switch(menuInforme()){

		case 'a':
			printf(" � [A] P1 - Listar notebook de tipo..\n");
			informarNotebooksPorTipo(vec,tam,tipos,tamTipos,marcas,tamMarca,clientes,tamClientes);
			break;
		case 'b':
			printf(" � [B] P2 - Listar notebook de marca.\n");
			informarNotebooksPorMarcas(vec,tam,tipos,tamTipos,marcas,tamMarca,clientes,tamClientes);
			break;
		case 'c':
			printf(" � [C] P3 - Listar las mas baratas.\n");
			informarMenorPrecioNotebook(vec,tam,tipos,tamTipos,marcas,tamMarca,clientes,tamClientes);
			break;
		case 'd':
			printf(" � [D] P4 - Listar Notebook por Marca.\n");
			informarNotebooksXMarcas(vec,tam,tipos,tamTipos,marcas,tamMarca,clientes,tamClientes);
			break;
		case 'e':
			printf(" � [E] P5 - Cantidad Not. Marca Sector.\n");
			cantidadNotebooksMarcaTipo(vec,tam,tipos,tamTipos,marcas,tamMarca);
			break;
		case 'f':
			printf(" � [F] P6 - Marcas mas elegidas.\n");
			initMostChosenBrand(mostChosen,BRAND);
			informarMarcaMasElegida(vec,tam,tipos,tamTipos,marcas,tamMarca, mostChosen);
			break;
		case 'g':
			printf(" � [G] P7 - Mostrar trabajos de notebook.\n");
			informarTrabajosDeNotebook (trabajos, tamTrabajo, vec, tam,
						tipos, tamTipos, marcas, tamMarca, servicios, tamServi,clientes,tamClientes);
			break;
		case 'h':
			printf(" � [H] P8 - Servicios por pc.\n");
			sumaImporteServicios(vec, tam, tipos, tamTipos, marcas,
					tamMarca, trabajos, tamTrabajo, servicios, tamServi,clientes,tamClientes);
			break;
		case 'i':
			printf(" � [I] P9 - Pedir servicio y ver notebooks.\n");
			pedirServicioMostrarNotebook(trabajos, tamTrabajo, vec,tam,tipos,tamTipos,marcas,tamMarca,servicios,tamServi,clientes,tamClientes);
			break;
		case 'j':
			printf(" � [J] P10 - Pedir Fecha y ver Servicios.\n");
			serviciosPorFecha(trabajos, tamTrabajo, servicios, tamServi);
			break;
		case 'l':
			seguir = 'n';
			break;
		default:
			printf(" � [ERROR] Opcion incorrecta. [ERROR]\n");
			break;
		}
		system("pause");
		system("cls");
	}while(seguir=='s');
	return retorno;
}
