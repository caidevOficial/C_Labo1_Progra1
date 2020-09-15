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

#include "marca.h"

void mostrarMarca(Marca marca){
   printf(" บ       [%d]               %6s   บ\n", marca.id, marca.descripcion);
}

int listarMarcas(Marca* list, int length){
	printf(" ฬอออออออออออออออออออออออออออออออออออออน\n");
	printf(" บ     ฑฒÛ     Lista de Marcas   Ûฒฑ   บ\n");
	printf(" บ         Id            Descripcion   บ\n");

	for (int i = 0;i<length;i++){
		if (list[i].id!=0){
			mostrarMarca(list[i]);
		}
	}
	return 0;
}

int cargarDescripcionMarca(char descripcion[], int idMarca,
								Marca list[], int tamMarca){
	int pudo = 0;
	for (int i=0;i<tamMarca;i++){
		if(list[i].id == idMarca){
			strcpy(descripcion, list[i].descripcion);
			pudo = 1;
		}
	}
	return pudo;
}

int buscarMarcaPorId(int id, Marca marca[], int tamMarca){
	int indice = -1;

	for(int i = 0; i < tamMarca; i++){
		if(marca[i].id == id){
			indice = i;
			break;
		}
	}
	return indice;
}
