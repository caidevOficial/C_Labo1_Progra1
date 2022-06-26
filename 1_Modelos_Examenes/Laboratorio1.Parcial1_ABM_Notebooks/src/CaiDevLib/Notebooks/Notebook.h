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
#include "../Tipo/Tipo.h"
#include "../Marca/marca.h"

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

typedef struct{
	int id;
	char modelo[20];
	int marca;
	int tipo;
	float precio;
	int idCliente;
}Notebook;

/**
 * @fn int buscarLibreNotebook(Notebook[], int)
 * @brief 	Busca indice libre del array notebooks.
 * @param vec
 * @param len
 * @return
 */
int buscarLibreNotebook(Notebook vec[], int len);

/**
 * @fn int buscarNotebookPorId(Notebook[], int, int)
 * @brief	Busca el indice de la notebook.
 * @param notebook
 * @param tamN
 * @param idNotebook
 * @return	Retorna -1 si no pudo, sino retorna el indice.
 */
int buscarNotebookPorId(Notebook notebook[], int tamN, int idNotebook);

/**
 * @fn int cargaNotebook(Notebook*, int, int, int, int, char[], int, int, int)
 * @brief 	Carga una notebook al vector.
 * @param list
 * @param len
 * @param id
 * @param tipo
 * @param precio
 * @param modelo
 * @param marca
 * @param idCliente
 * @param index
 * @return	Retorna 0 si pudo, sino retorna -1.
 */
int cargaNotebook(Notebook* list, int len, int id, int tipo,int precio,char modelo[],int marca,int idCliente, int index);

/**
 * @fn int altaNotebook(int*, Notebook[], int, Marca[], int, Tipo[], int, Cliente[], int)
 * @brief	Pide los datos para cargar una notebook al vector.
 * @param idX
 * @param notebook
 * @param tamNotebook
 * @param marca
 * @param tamMarca
 * @param tipo
 * @param tamTipo
 * @param clientes
 * @param tamClientes
 * @return  Retorna 1 si pudo, sino retorna -1.
 */
int altaNotebook(int* idX, Notebook notebook[], int tamNotebook,Marca marca[],int tamMarca,Tipo tipo[],int tamTipo, Cliente clientes[], int tamClientes);

/**
 * @fn int cargarDescripcionNotebook(char[], int, Notebook[], int)
 * @brief
 * @param descripcion
 * @param idNotebook
 * @param list
 * @param tamNotebook
 * @return
 */
int cargarDescripcionNotebook(char descripcion[], int idNotebook,Notebook list[], int tamNotebook);

/**
 * @fn int encontrarNotebookPorID(Notebook*, int, int)
 * @brief busca el indice de la notebook.
 * @param list
 * @param len
 * @param id
 * @return retorna el indice si encuentra o sino -1
 */
int encontrarNotebookPorID(Notebook* list, int len,int id);

/**
 * @fn void mostrarNotebook(Notebook, Tipo[], int, Marca[], int, Cliente[], int)
 * @brief 	Imprime en pantalla losd atos de una notebook.
 * @param note
 * @param tipos
 * @param lenTipos
 * @param marcas
 * @param lenMarcas
 * @param clientes
 * @param tamClientes
 */
void mostrarNotebook(Notebook note, Tipo tipos[], int lenTipos, Marca marcas[], int lenMarcas, Cliente clientes[], int tamClientes);

/**
 * @fn int listarNotebook(Notebook*, int, Tipo[], int, Marca[], int, Cliente[], int)
 * @brief 	Imprime en pantalla los datos de todas las notebooks del vector.
 * @param list
 * @param length
 * @param tipos
 * @param lenTipos
 * @param marcas
 * @param lenMarcas
 * @param clientes
 * @param tamClientes
 */
int listarNotebook(Notebook* list, int length, Tipo tipos[], int lenTipos, Marca marcas[], int lenMarcas, Cliente clientes[], int tamClientes);

/**
 * @fn int ordenarNotebooks(Notebook*, int, Tipo[], int, Marca[], int, Cliente[], int)
 * @brief 	Imprime lal ista denotebooks ordenadas por marca y precio.
 * @param list
 * @param len
 * @param tipos
 * @param lenTipos
 * @param marcas
 * @param lenMarcas
 * @param clientes
 * @param tamClientes
 * @return Retorna 1 si pudo, sino 0
 */
int ordenarNotebooks(Notebook* list, int len, Tipo tipos[], int lenTipos, Marca marcas[],int lenMarcas, Cliente clientes[], int tamClientes);

/**
 * @fn int bajaNotebook(Notebook*, int, int, Tipo[], int, Marca[], int, Cliente[], int)
 * @brief 	Pone la ID en 0, dandole de baja.
 * @param list
 * @param len
 * @param id
 * @param tipos
 * @param lenTipos
 * @param marcas
 * @param lenMarcas
 * @param clientes
 * @param tamClientes
 * @return  Retorna 0 si no pudi, sino 1.
 */
int bajaNotebook(Notebook* list, int len, int id, Tipo tipos[],int lenTipos,Marca marcas[],int lenMarcas, Cliente clientes[], int tamClientes);

/**
 * @fn void modificarNotebook(Notebook[], int, Tipo[], int, Marca[], int, Cliente[], int)
 * @brief
 * @param vec
 * @param tam
 * @param tipos
 * @param lenTipos
 * @param marcas
 * @param lenMarcas
 * @param clientes
 * @param tamClientes
 */
void modificarNotebook(Notebook vec[], int tam, Tipo tipos[],int lenTipos, Marca marcas[], int lenMarcas, Cliente clientes[], int tamClientes);

#endif /* NOTEBOOK_H_ */
