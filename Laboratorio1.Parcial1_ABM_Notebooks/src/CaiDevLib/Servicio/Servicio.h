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

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{
	int id; // Empieza en 20000
	char descripcion[25];
	int precio;
}Servicio;

/**
 * @fn int buscarLibreServicio(Servicio[], int)
 * @brief 	Busca un indice de servicio libre.
 * @param vec
 * @param len
 * @return	Retorna el indice del servicio o sino -1.
 */
int buscarLibreServicio(Servicio vec[], int len);

/**
 * @fn int buscarServicioPorId(int, Servicio[], int)
 * @brief	Busca el indice del servicio segun si ID.
 * @param id
 * @param listaS
 * @param tamS
 * @return  Retorna el indice del servicio o -1.
 */
int buscarServicioPorId(int id, Servicio listaS[], int tamS);

/**
 * @fn void mostrarServicio(Servicio)
 * @brief  Muestra caracteristicas de un servicio.
 * @param serv
 */
void mostrarServicio(Servicio servicio);

/**
 * @fn int listarServicios(Servicio*, int)
 * @brief 	Muestra una lista de servicios.
 * @param list
 * @param length
 */
int listarServicios(Servicio* list, int length);

/**
 * @fn int cargarDescripcionServicio(char[], int, Servicio[], int)
 * @brief	Carga la descripcion del servicio.
 * @param descripcion
 * @param idServicio
 * @param list
 * @param tamServicio
 * @return	Retorna 1 si pudo, sino 0.
 */
int cargarDescripcionServicio(char descripcion[], int idServicio,Servicio list[], int tamServicio);

#endif /* SERVICIO_H_ */
