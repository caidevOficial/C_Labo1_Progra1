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
 * Version     : Beta 3.3.0 [Beta v3.3.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
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
	"    [Bot_Sanctuary]: Bienvenido al santuario! \n"
	"     Guiate con las opciones listadas debajo para operar.\n"
	"    Arde tu cosmos! \n"
	"    _______________________________________________________________\n"
	"    [Menu]\n"
	//"    [1] Cargar datos de empleados desde data.csv (modo texto).\n"
	//"    [2] Cargar datos de empleados desde data.bin (modo binario).\n"
	"    [1] Altas de Caballeros del Zodiaco.\n"
	"    [2] Modificar datos de Caballeros del Zodiaco.\n"
	"    [3] Baja de Caballeros del Zodiaco.\n"
	"    [4] Listar Caballeros del Zodiaco.\n"
	"    [5] Ordenar Caballeros del Zodiaco.\n"
	"    [6] Informes de Caballeros del Zodiaco.\n"
	"    [7] Duplicar lista.\n"
	//"    [8] Guardar datos de empleados en data.csv (modo texto).\n"
	//"    [9] Guardar datos de empleados en data.bin (modo binario).\n"
	"    [10] Salir.\n");
	utn_getNumero(&option, "    [Bot_Sanctuary]: Escoje una opcion [1-10]:  ",
	"    [Bot_Sanctuary]: Opcion incorrecta.\n", 1, 10, 5);

	return option;
}
