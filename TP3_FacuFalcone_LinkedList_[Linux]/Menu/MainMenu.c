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
 * About: Versionar
 * El primero (X) se le conoce como version mayor y nos indica la version
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como version menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revision y nos indica que se hizo una revision del
 * 		codigo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : RC 6.13.2020 [Release Candidate v6.13] - FacuFalcone_LinkedList
 * ============================================================================
 */

#include <stdio_ext.h> // linux
//#include <stdio.h> // windows
#include <stdlib.h>
#include <string.h>
#include "../Library/Validate/caidevValidate.h"

int menu() {
	int option;
	printf("    \n"
			"    [Bot_Apu]: Buen dias visitantes, mi nombre es Apus y te guiare \n"
			"     en estes programas, escoje entre las opciones de abajos..\n"
			"     Oh! a quien enganio? Le juro por los numerosos brazos de Vishnu\n"
			"     que no me gustas este empleos pero tengo deudas por pagar.\n");
	 printf("     Y con que las voy a pagar? Con pastel de platanos? o lo siento,\n");
	 printf("     no he dormido bien en dias y se nos esta acabando el dineros y...\n"
	        "     Pastel de platano! En que rayos estabas pensandos?.\n");
	 printf("     No te quedes mirandos, esto no es una bibliotecas! \n"
			"     Deberias haberme quedados en el Minisupers (U_U)\n"
			"    _______________________________________________________________\n"
			"    [Menu]\n"
			"    [1] Cargar datos de empleados desde data.csv (modo texto).\n"
			"    [2] Cargar datos de empleados desde data.bin (modo binario).\n"
			"    [3] Altas de empleados.\n"
			"    [4] Modificar datos de empleados.\n"
			"    [5] Baja de empleados.\n"
			"    [6] Listar empleados.\n"
			"    [7] Ordenar empleados.\n"
			"    [8] Guardar datos de empleados en data.csv (modo texto).\n"
			"    [9] Guardar datos de empleados en data.bin (modo binario).\n"
			"    [10] Salir.\n");
	utn_getNumero(&option, "    [Bot_Apu]: Elijes una opcion [1-10]:  ",
			"    [Bot_Apu]: Opcion incorrectas.\n",
			1, 10, 5);

	return option;
}
