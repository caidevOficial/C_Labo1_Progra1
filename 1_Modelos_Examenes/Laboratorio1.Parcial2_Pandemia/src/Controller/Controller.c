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
 * Type: Recuperatorio segundo parcial - Laboratorio 1.
 * Version     : Beta 1.1.2 [Beta v1.1.2] - FacuFalcone_ABM_Pandemia_[Linux]
 * ============================================================================
 */

//#include <stdio.h> // windows
#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../LinkedList.h"
#include "../Pandemia/Pandemia.h"
#include "../Pandemia/Getters/Getters.h"
#include "../Parser/parser.h"

int controller_loadFromText(char *path, LinkedList *this) {
	FILE *pFile; // para leer los objetos

	int sucess = 0;
	pFile = fopen(path, "r");
	if (pFile != NULL) {
		if(parser_ObjectFromText(pFile, this)){
			fclose(pFile);
			sucess = 1;
		}
		else{
			printf("    ERROR: No se pudo parsear Texto.");
		}

	}else{
		printf("    ERROR: El archivo es NULL");
	}

	return sucess;
}

int controller_ListObject(LinkedList *this) {
	ePais *pObject;
	int sucess = 0;
	int id;
	char pais[128];
	int infectados;
	int muertos;
	int recuperados;

	if (this == NULL) {
		printf("\n    No se puede listar objetos ya que la lista es NULL.\n");
	} else {
		printf("    __________________________________________________________________\n"
				"      ID      Pais     Recuperad Infectad   Muertos \n"
				"    ___________________________________________________________________\n");
		sucess = 1;

		for (int i = 0; i < ll_len(this); i++) {
			pObject = ll_get(this, i);
			Entity_getID(pObject, &id);
			Entity_getInfected(pObject, &infectados);
			Entity_getDeads(pObject, &muertos);
			Entity_getRecovered(pObject, &recuperados);
			Entity_getCountry(pObject, pais);
			printf("    [%3d] [%-10s] [%07d] [%07d] [%07d]  \n", id, pais, recuperados, infectados, muertos);
		}
	}
	return sucess;
}

int saveAsTextFormat_Csv(FILE *pFile, LinkedList *this) {
	ePais *pObject;

	int id;
	char pais[128];
	int infectados;
	int muertos;
	int recuperados;
	int len_LL;
	int sucess = 0;
	int flagHeader = 1;

	if (pFile != NULL && this != NULL) { //si el archivo y el array no son null..
		len_LL = ll_len(this); // obtengo el tamanho del array.

		for (int i = 0; i < len_LL; i++) {	// recorro el array.
			pObject = ll_get(this, i);
			Entity_getID(pObject, &id);
			Entity_getInfected(pObject, &infectados);
			Entity_getDeads(pObject, &muertos);
			Entity_getRecovered(pObject, &recuperados);
			Entity_getCountry(pObject, pais);

			if (flagHeader) {
				fprintf(pFile, "%s,%s,%s,%s,%s\n", "id", "nombre", "recuperados", "infectados", "muertos");
				flagHeader = 0;
			}
			fprintf(pFile, "%d,%s,%d,%d,%d\n", id, pais,recuperados, infectados, muertos); //escribo los datos de cada caballero en el archivo.
			sucess = 1;
		}
	}
	else{
		printf("    ERROR: El archivo o el array son NULL.\n");
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
