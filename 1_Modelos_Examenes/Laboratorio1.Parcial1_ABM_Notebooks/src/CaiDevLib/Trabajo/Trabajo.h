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
#include "../Fecha/fecha.h"
#include "../Notebooks/Notebook.h"
#include "../Servicio/Servicio.h"
#include "../Validate/caidevValidate.h"

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct{
	int id; // autoincremental
	int idNotebook;
	int idServicio;
	Fecha Fecha;
}Trabajo;

/**
 * @fn int buscarLibreTrabajo(Trabajo[], int)
 * @brief busca indice libre
 * @param vec
 * @param len
 * @return retorna -1 si no encuentra, sino su indice.
 */
int buscarLibreTrabajo(Trabajo vec[], int len);

/**
 * @fn int cargaTrabajo(Trabajo*, int, int, int, int, Fecha)
 * @brief 	carga un alta de trabajo en el array
 * @param list
 * @param len
 * @param idTrabajo
 * @param idNotebook
 * @param idServicio
 * @param fecha
 * @return	retorna 0 si pudo, sino -1
 */
int cargaTrabajo(Trabajo* list, int len, int idTrabajo, int idNotebook,int idServicio, Fecha fecha);

/**
 * @fn int altaTrabajo(int*, Trabajo*, int, Servicio*, int, Notebook*, int, Tipo*, int, Marca*, int, Cliente[], int)
 * @brief	Da de alta un trabajo.
 * @param idTrabajoLibre
 * @param trabajo
 * @param trabajoTam
 * @param servicios
 * @param serviTam
 * @param notebooks
 * @param tamNotebooks
 * @param tipos
 * @param tamTipos
 * @param marcas
 * @param tamMarca
 * @param clientes
 * @param tamClientes
 * @return
 */
int altaTrabajo(int* idTrabajoLibre, Trabajo* trabajo, int trabajoTam, Servicio* servicios, int serviTam,
		Notebook* notebooks,int tamNotebooks, Tipo* tipos, int tamTipos, Marca* marcas, int tamMarca, Cliente clientes[], int tamClientes);

/**
 * @fn void mostrarTrabajo(Trabajo, Servicio[], int, Notebook[], int)
 * @brief 	Muestra en pantalla un trabajo realizado.
 * @param job
 * @param servicios
 * @param lenServicio
 * @param notebook
 * @param lenNote
 */
void mostrarTrabajo(Trabajo job, Servicio servicios[], int lenServicio,Notebook notebook[],int lenNote);

/**
 * @fn int listarTrabajos(Trabajo*, int, Servicio[], int, Notebook*, int)
 * @brief 	Muestra en pantalla una lista de trabajos realizados.
 * @param list
 * @param length
 * @param servicios
 * @param lenServicio
 * @param notebooks
 * @param lenNote
 */
int listarTrabajos(Trabajo* list, int length,Servicio servicios[],int lenServicio, Notebook* notebooks,int lenNote);

#endif /* TRABAJO_H_ */
