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
 *
 * Version     : Beta 1.3.0 [Beta v1.3.0] - FacuFalcone_LinkedList_Bicicletas_[Linux]
 * ============================================================================
 */

#include <stdio_ext.h> // linux
//#include <stdio.h> // windows
#include <stdlib.h>
#include <string.h>
#include "../Validate/caidevValidate.h"

int menu() {
	int option;
	printf("    \n"
					"    [Message]: Bienvenido \n"
			"    _______________________________________________________________\n"
			"    [Menu]\n"
			"    [1] Cargar archivo.\n"
			"    [2] Listar bicicletas.\n"
			"    [3] Asignar tiempos [Random].\n"
			"    [4] Filtrar por tipos de bicicletas.\n"
			"    [5] Mostrar posiciones [Ordenar].\n"
			"    [6] Guardar posiciones.\n"
			"    [7] Salir.\n");
	utn_getNumero(&option, "    [Message]: Escoje una opcion [1-8]:  ",
			"    [Message]: Opcion incorrecta.\n", 1, 8, 5);

	return option;
}
