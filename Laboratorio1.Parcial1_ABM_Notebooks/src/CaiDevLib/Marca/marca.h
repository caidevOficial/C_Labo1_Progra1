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

#ifndef MARCA_H_
#define MARCA_H_

typedef struct{
	int id; // empieza en 1000
	char descripcion[20];
}Marca;

/**
 * @fn void mostrarMarca(Marca)
 * @brief	Muestra la id y descripcion de la marca.
 * @param marca
 */
void mostrarMarca(Marca marca);

/**
 * @fn int listarMarcas(Marca*, int)
 * @brief 	Muestra la lista de marcas con sus id
 * @param list
 * @param length
 */
int listarMarcas(Marca* list, int length);

/**
 * @fn int cargarDescripcionMarca(char[], int, Marca[], int)
 * @brief 	Carga la descripcion de la marca.
 * @param descripcion
 * @param idMarca
 * @param list
 * @param tamMarca
 * @return	Retorna 1 si pudo, sino 0.
 */
int cargarDescripcionMarca(char descripcion[], int idMarca,	Marca list[], int tamMarca);

/**
 * @fn int buscarMarcaPorId(int, Marca[], int)
 * @brief 	Busca el indice de la marca.
 * @param id
 * @param marca
 * @param tamMarca
 * @return	retorna -1 si no pudo, sino retorna el indice.
 */
int buscarMarcaPorId(int id, Marca marca[], int tamMarca);

#endif /* MARCA_H_ */
