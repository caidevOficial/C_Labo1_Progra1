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

#include "../Cliente/Cliente.h"
#include "../Marca/marca.h"
#include "../Notebooks/Notebook.h"
#include "../Servicio/Servicio.h"
#include "../Tipo/Tipo.h"
#include "../Trabajo/Trabajo.h"

#ifndef CAIDEVLIB_INFORMES_INFORMES_FUNCIONES_H_
#define CAIDEVLIB_INFORMES_INFORMES_FUNCIONES_H_

typedef struct{

	int idBrand;
	int qtyChosen;

}BestBrand;

/**
 * @fn void informarNotebooksPorTipo(Notebook[], int, Tipo[], int, Marca[], int, Cliente[], int)
 * @brief 	Lista todas las notebooks segun el tipo elegido.
 * @param vec
 * @param tam
 * @param tipos
 * @param tamTipos
 * @param marcas
 * @param tamMarca
 * @param clientes
 * @param tamClientes
 */
void informarNotebooksPorTipo(Notebook vec[], int tam,Tipo tipos[], int tamTipos, Marca marcas[], int tamMarca, Cliente clientes[], int tamClientes);

/**
 * @fn void informarNotebooksPorMarcas(Notebook[], int, Tipo[], int, Marca[], int, Cliente[], int)
 * @brief 	Lista todas las notebooks segun la marca elegida.
 * @param vec
 * @param tam
 * @param tipos
 * @param tamTipos
 * @param marcas
 * @param tamMarca
 * @param clientes
 * @param tamClientes
 */
void informarNotebooksPorMarcas(Notebook vec[], int tam,Tipo tipos[], int tamTipos, Marca marcas[], int tamMarca, Cliente clientes[], int tamClientes);

/**
 * @fn void informarMenorPrecioNotebook(Notebook[], int, Tipo[], int, Marca[], int, Cliente[], int)
 * @brief	Informa la notebook mas costosa de la marca elegida.
 * @param vec
 * @param tam
 * @param tipos
 * @param tamTipo
 * @param marcas
 * @param tamMarca
 * @param clientes
 * @param tamClientes
 */
void informarMenorPrecioNotebook(Notebook vec[], int tam,Tipo tipos[],int tamTipo, Marca marcas[], int tamMarca, Cliente clientes[], int tamClientes);

/**
 * @fn void cantidadNotebooksMarcaTipo(Notebook[], int, Tipo[], int, Marca[], int)
 * @brief 	Informa la cantidad de notebooks de la marca y tipo elegidos.
 * @param vec
 * @param tamNote
 * @param tipos
 * @param tamTipos
 * @param marcas
 * @param tamMarcas
 */
void cantidadNotebooksMarcaTipo(Notebook vec[],int tamNote, Tipo tipos[], int tamTipos, Marca marcas[],int tamMarcas);

/**
 * @fn void informarNotebooksXMarcas(Notebook[], int, Tipo[], int, Marca[], int, Cliente[], int)
 * @brief	Imprime la lista de notebooks separadas por marca.
 * @param notebooks
 * @param tamN
 * @param tipos
 * @param tamTipo
 * @param marcas
 * @param tamMarca
 * @param clientes
 * @param tamClientes
 */
void informarNotebooksXMarcas(Notebook notebooks[], int tamN, Tipo tipos[], int tamTipo, Marca marcas[], int tamMarca, Cliente clientes[], int tamClientes);

/**
 * @fn void informarMarcaMasElegida(Notebook[], int, Tipo[], int, Marca[], int, BestBrand[])
 * @brief 	Informa la o las marcas con mayor cantidad de unidades.
 * @param notebooks
 * @param tamN
 * @param tipos
 * @param tamTipos
 * @param marcas
 * @param tamM
 * @param mostChosen
 */
void informarMarcaMasElegida(Notebook notebooks[], int tamN, Tipo tipos[], int tamTipos,Marca marcas[], int tamM, BestBrand mostChosen[]);

/**
 * @fn int initMostChosenBrand(BestBrand[], int)
 * @brief 	Inicializa la id del Vector donde se almacena la marca y un entero que indica su cantidad.
 * @param bestBrand
 * @param lenBbrand
 * @return	Retorna 0 si pudo, sino -1.
 */
int initMostChosenBrand(BestBrand bestBrand[], int lenBbrand);

/**
 * @fn void informarTrabajosDeNotebook(Trabajo[], int, Notebook[], int, Tipo[], int, Marca[], int, Servicio[], int, Cliente[], int)
 * @brief 	Informa todos los trabajos de una notebook seleccionada.
 * @param trabajos
 * @param tamTr
 * @param notebooks
 * @param tamNote
 * @param tipos
 * @param tamTipo
 * @param marcas
 * @param tamMarca
 * @param servicios
 * @param tamServ
 * @param clientes
 * @param tamClientes
 */
void informarTrabajosDeNotebook (Trabajo trabajos[], int tamTr, Notebook notebooks[], int tamNote,Tipo tipos[], int tamTipo, Marca marcas[], int tamMarca, Servicio servicios[], int tamServ, Cliente clientes[], int tamClientes);

/**
 * @fn void sumaImporteServicios(Notebook[], int, Tipo[], int, Marca[], int, Trabajo[], int, Servicio[], int, Cliente[], int)
 * @brief	Imprime en pantalla la suma de todos los servicios realizados a la notebook.
 * @param notebooks
 * @param tamNotebook
 * @param tipos
 * @param tamTipos
 * @param marcas
 * @param tamMarca
 * @param trabajos
 * @param tamTrabajos
 * @param servicios
 * @param tamServicio
 * @param clientes
 * @param tamClientes
 */
void sumaImporteServicios(Notebook notebooks[], int tamNotebook, Tipo tipos[], int tamTipos, Marca marcas[],int tamMarca, Trabajo trabajos[], int tamTrabajos, Servicio servicios[], int tamServicio, Cliente clientes[], int tamClientes);

/**
 * @fn void pedirServicioMostrarNotebook(Trabajo[], int, Notebook[], int, Tipo[], int, Marca[], int, Servicio[], int, Cliente[], int)
 * @brief	Imprime las notebooks que tienen realizado el servicio seleccionado.
 * @param trabajos
 * @param tamTrabajo
 * @param notebooks
 * @param tamNotebook
 * @param tipos
 * @param tamTipos
 * @param marcas
 * @param tamMarcas
 * @param servicios
 * @param tamService
 * @param clientes
 * @param tamClientes
 */
void pedirServicioMostrarNotebook(Trabajo trabajos[], int tamTrabajo, Notebook notebooks[],int tamNotebook,
		Tipo tipos[],int tamTipos,Marca marcas[],int tamMarcas,Servicio servicios[],int tamService, Cliente clientes[], int tamClientes);

/**
 * @fn void serviciosPorFecha(Trabajo[], int, Servicio[], int)
 * @brief 	Imprime en pantalla todos los servicios realizados en tal fecha.
 * @param trabajos
 * @param tamTrabajo
 * @param servicios
 * @param tamServicio
 */
void serviciosPorFecha(Trabajo trabajos[], int tamTrabajo, Servicio servicios[], int tamServicio);

#endif /* CAIDEVLIB_INFORMES_INFORMES_FUNCIONES_H_ */
