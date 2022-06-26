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
 * Version     : Beta 3.1.0 [Beta v3.1.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
 * ============================================================================
 */

//#include <stdio.h> // windows
#include <stdio_ext.h> // linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../inc/LinkedList.h"
#include "../Parser/parser.h"
#include "../Validate/caidevValidate.h"
#include "Controller.h"
#include "registerController/registerController.h"

#include "../Object/Getters/Getters.h"
#include "../Object/Object.h"
#include "../Object/Setters/Setters.h"
#include "saveMaxID_toText/saveToText_maxID.h"

int controller_loadFromText(char *path, LinkedList *this) {
	FILE *pFile; // para leer los empleados
	FILE *pFile2; //para guardar la proxima ID

	int sucess = 0;

	pFile = fopen(path, "r");
	pFile2 = fopen("lastID.txt", "w");
	if (pFile != NULL) {
		parser_ObjectFromText(pFile, this);
		fclose(pFile);
		sucess = 1;
	}
	if (controller_saveAsTextMaxID(pFile2, "maxID.txt", this)) {
		fclose(pFile2);
	}
	return sucess;
}

int controller_loadFromBinary(char *path, LinkedList *this) {
	FILE *pFile;
	FILE *pFile2;
	int sucess = 0;
	pFile = fopen(path, "rb");
	pFile2 = fopen("lastID.txt", "w");
	if (pFile != NULL) {
		parser_ObjectFromBinary(pFile, this);
		sucess = 1;
	}
	// leo los datos cargados y Guardo el MaxID en archivo de texto
	if (controller_saveAsTextMaxID(pFile2, "lastID.txt", this)) {
		fclose(pFile2);
	}
	fclose(pFile);

	return sucess;
}

int controller_ListObject(LinkedList *this) {
	Object *pObject;
	int sucess = 0;
	int id;
	char name[128];
	char constellationName[128];
	char armorType[128];
	int level;
	float cosmosLevel;

	if (this == NULL) {
		printf("\n    [Bot_Sanctuary]: No hay Caballeros del Zodiaco para listar.\n");
	} else {
		printf("    __________________________________________________________________\n"
				"      ID      Nombre    Constelacion  Armadura   Nivel      Poder\n"
				"    ___________________________________________________________________\n");
		sucess = 1;

		for (int i = 0; i < ll_len(this); i++) {
			pObject = ll_get(this, i);
			Object_getAllInfo(pObject, &id, name, constellationName, armorType, &level,
			        &cosmosLevel);
			printf("    [%4d] [%10s] [%10s] [%7s] [Lv: %3d] [Pow: %4.0f]  \n", id, name,
			        constellationName, armorType, level, cosmosLevel);
		}
	}
	return sucess;
}

int controller_sortObject(LinkedList *this) {
	int sucess = 0;
	if (this != NULL) {
		Object_sortObject(this);
		sucess = 1;
	}
	return sucess;
}

int saveAsTextFormat_Csv(FILE *pFile, LinkedList *this) {
	Object *Object;

	int ID;
	char name[128];
	char constellationName[128];
	char armorType[128];
	int level;
	float cosmosLevel;
	int len_LL;
	int sucess = 0;
	int flagHeader = 1;

	if (pFile != NULL && this != NULL) { //si el archivo y el array no son null..
		len_LL = ll_len(this); // obtengo el tamanho del array.

		for (int i = 0; i < len_LL; i++) {	// recorro el array.
			Object = ll_get(this, i);// copio la estructura del empleado del indice.
			Object_getAllInfo(Object, &ID, name, constellationName, armorType, &level,
			        &cosmosLevel); //obtengo toda la info del caballero.
			if (flagHeader) {
				fprintf(pFile, "%s,%s,%s,%s,%s,%s\n", "ID", "NAME", "COSMOS", "ARMADURA", "LEVEL",
				        "POWER_LV");
				flagHeader = 0;
			}
			fprintf(pFile, "%d,%s,%s,%s,%d,%f\n", ID, name, constellationName, armorType, level,
			        cosmosLevel); //escribo los datos de cada caballero en el archivo.
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

int controller_saveAsBinary(char *path, LinkedList *this) {
	FILE *pFile;
	Object *auxObject;

	int sucess = 0;

	if (this != NULL && path != NULL) {
		pFile = fopen(path, "wb");

		for (int i = 0; i < ll_len(this); i++) {
			auxObject = (Object*) ll_get(this, i);
			fwrite(auxObject, sizeof(Object), 1, pFile);
		}
		fclose(pFile);
		ll_clear(this);
		sucess = 1;
	}
	return sucess;
}

int controller_reallocateObject(LinkedList* this){
	int lastID;
	int firstID;
	int secondID;
	int index1;
	int index2;
	int sucess = 0;
	Object* thisObject;
	obtainID(&lastID);
	lastID--;

	controller_ListObject(this); // muestro la lista
	utn_getNumero(&firstID,"    [Message]: Ingrese un ID para realocar en la lista: ",
	              "    [Message]: ID incorrecto, seleccione de la lista.\n", 1, lastID, 5);
	// Busco su indice.
	index1 = Object_SearchForId(this,	firstID);

	if(index1==-1){
		printf("    [Message] Error, el caballero ingresado no existe en la lista.\n");
	}
	else{
		thisObject = (Object*)ll_pop(this, index1);
		showObject(thisObject); // Lo muestro.

		//****************************** Lo saco de la lista.

		printf("    [Message]: se reubicara el caballero listado arriba.\n"	);
		//****************************** Pido segunda id donde se ubicara.
		utn_getNumero(&secondID, "    [Message]: Se insertara antes de la ID especificada a continuacion: ",
		              "    [Message]: Error, ingrese una ID correcta.\n", 1, lastID, 5);
		// Busco el nuevo indice donde sera ubicaco.
		index2 = Object_SearchForId(this,	secondID);

		if (index2==-1){
			printf("    [Message] Error, el caballero ingresado no existe en la lista.\n");
			ll_push(this, index1, thisObject); // Si falla, lo dejo donde estaba
		}
		else{
			//****************************** Lo pongo en nueva ubicacion.
			ll_push(this, (index2), thisObject);
			controller_ListObject(this); // imprimo nueva lista.
			printf("    [Message]: Reubicacion con exito!\n\n");
			sucess = 1;
		}
	}
	return sucess;
}
