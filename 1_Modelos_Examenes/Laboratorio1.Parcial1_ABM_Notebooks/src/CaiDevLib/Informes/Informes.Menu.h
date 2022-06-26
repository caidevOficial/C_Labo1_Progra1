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

#ifndef CAIDEVLIB_INFORMES_INFORMES_MENU_H_
#define CAIDEVLIB_INFORMES_INFORMES_MENU_H_

char menuInforme();

/**
 * @fn int informes(Trabajo[], int, Notebook[], int, Tipo[], int, Marca[], int, Servicio[], int, Cliente[], int)
 * @brief 	Imprime el menu de informes y las respectivas opciones.
 * @param trabajos
 * @param tamTrabajo
 * @param vec
 * @param tam
 * @param tipos
 * @param tamTipos
 * @param marcas
 * @param tamMarca
 * @param servicios
 * @param tamServi
 * @param clientes
 * @param tamClientes
 */
int informes(Trabajo trabajos[],int tamTrabajo,Notebook vec[], int tam,Tipo tipos[],int tamTipos,
		Marca marcas[], int tamMarca, Servicio servicios[], int tamServi, Cliente clientes[], int tamClientes);


#endif /* CAIDEVLIB_INFORMES_INFORMES_MENU_H_ */
