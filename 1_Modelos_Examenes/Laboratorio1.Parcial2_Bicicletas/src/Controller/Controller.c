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

//#include <stdio.h> // windows
#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../LinkedList.h"
#include "../Bicicleta/Bici.h"
#include "../Bicicleta/Getters/Getters.h"
#include "../Parser/parser.h"

int controller_loadFromText(char *path, LinkedList *this) {
	FILE *pFile; // para leer los empleados
	//FILE *pFile2; //para guardar la proxima ID

	int sucess = 0;
	pFile = fopen(path, "r");
	//pFile2 = fopen("lastID.txt", "w");
	if (pFile != NULL) {
		if(parser_ObjectFromText(pFile, this)){
			fclose(pFile);
			sucess = 1;
		}
		else{
			printf("    [Message]: ERROR NULL DE PARSER");
		}

	}else{
		printf("    [Message]: ERROR NULL DE CONTROLLER");
	}

	return sucess;
}

int controller_ListObject(LinkedList *this) {
	eBicicleta *pObject;
	int sucess = 0;
	int id;
	char tipo[128];
	char duenho[128];
	int tiempo;

	if (this == NULL) {
		printf("\n    [Message]: No hay bicis para listar.\n");
	} else {
		printf("    __________________________________________________________________\n"
				"      ID      Duenho      Tipo    Tiempo   \n"
				"    ___________________________________________________________________\n");
		sucess = 1;

		for (int i = 0; i < ll_len(this); i++) {
			pObject = ll_get(this, i);
			Object_getDuenho(pObject, duenho);
			Object_getID(pObject, &id);
			Object_getTiempo(pObject, &tiempo);
			Object_getTipo(pObject, tipo);
			printf("    [%03d] [%-10s] [%-7s] [%03d]\n", id, duenho, tipo, tiempo);
		}
	}
	return sucess;
}

int saveAsTextFormat_Csv(FILE *pFile, LinkedList *this) {
	eBicicleta *Object;

	int ID;
	char tipo[20];
	char duenho[20];
	int tiempo;
	int len_LL;
	int sucess = 0;
	int flagHeader = 1;

	if (pFile != NULL && this != NULL) { //si el archivo y el array no son null..
		len_LL = ll_len(this); // obtengo el tamanho del array.

		for (int i = 0; i < len_LL; i++) {	// recorro el array.
			Object = ll_get(this, i);// copio la estructura del empleado del indice.
			Object_getID(Object, &ID);
			Object_getDuenho(Object, duenho);
			Object_getTipo(Object, tipo);
			Object_getTiempo(Object, &tiempo);

			if (flagHeader) {
				fprintf(pFile, "%s,%s,%s,%s\n", "ID", "duenho", "tipo", "tiempo");
				flagHeader = 0;
			}
			fprintf(pFile, "%d,%s,%s,%d\n", ID, duenho,tipo, tiempo); //escribo los datos de cada caballero en el archivo.
			sucess = 1;
		}
	}
	return sucess;
}

int controller_saveAsText(char *path, LinkedList *this) {
	int sucess = 0;
	FILE *pFile = fopen(path, "w"); // abro el archivo

	if (pFile != NULL && saveAsTextFormat_Csv(pFile, this)) { //si el archivo no es null y pude escribir, retorno 1
		sucess = 1;
	}
	fclose(pFile); // cierro el archivo.
	ll_clear(this); //vacio el array
	return sucess;
}
