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

#include "Cliente.h"

int initCliente(Cliente* list, int lenCliente){
	int retornoCliente = -1;

	for(int i=0;i<lenCliente;i++){
		list[i].idCliente = 0;
		retornoCliente = 1;
	}
	return retornoCliente;
}

int cargarDescripcionCliente(char descripcion[], int idCliente,
								Cliente list[], int tamCliente){
	int pudo = 0;
	for (int i=0;i<tamCliente;i++){
		if(list[i].idCliente == idCliente){
			strcpy(descripcion, list[i].nombre);
			pudo = 1;
		}
	}
	return pudo;
}

int encontrarClientePorID(Cliente* list, int lenCliente,int idCliente){
	int i;
	int retorno = -1;
	for(i = 0; i < lenCliente; i++){
		if (list[i].idCliente == idCliente && list[i].idCliente>0){
			retorno = i;
			break;
		}
	}
	return retorno;
}

void mostrarCliente(Cliente cliente){
	printf(" บ  [%2d]         %10s         %c                 บ\n", cliente.idCliente, cliente.nombre,cliente.sexo);
}

int listarClientes(Cliente* clientes, int tamClientes){
	printf(" ฬออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
	printf(" บ            ฑฒÛ    Lista de Clientes    Ûฒฑ         บ\n");
	printf(" บ  ID	             Nombre 	  Sexo                บ\n");
	for (int i = 0;i<tamClientes;i++){
		if (clientes[i].idCliente>0){
			mostrarCliente(clientes[i]);
		}
	}
	return 0;
}
