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
 * Version     : Beta 3.0.0 [Beta v3.0.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
 * ============================================================================
 */

//#include <stdio.h> // windows
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../../inc/LinkedList.h"
#include "../../Parser/parser.h"
#include "registerController.h"

#include "../../Object/Getters/Getters.h"
#include "../../Object/Object.h"
#include "../../Object/Setters/Setters.h"
#include "../../Validate/caidevValidate.h"
#include "../saveMaxID_toText/saveToText_maxID.h"

int obtainID(int* id){
	int sucess = 0;
	int newID;
	//*id = 1001; //la inicializo con 1001
	FILE* pFile;
	pFile = fopen("lastID.txt","r"); // abro el archivo.
	if(pFile!=NULL){
		fscanf(pFile, "%d\n", &newID);
		//fread(&newID,sizeof(int),1,pFile); //leo la ultima id guardada.
		*id = newID;
		fclose(pFile); // lo cierro si lo pude abrir.
		sucess = 1;
	}
	return sucess;
}

int upgradeID(int id){
	int nextID = ++id; // nextID vale id+1
	// ++id es lo mismo que (id++)
	int sucess = 0;
	FILE* pFile;
	pFile = fopen("lastID.txt","w"); // abre el texto
	if(pFile!=NULL){
		fprintf(pFile,"%d\n",nextID);
		//fwrite(&nextID,sizeof(int),1,pFile); //guarda la id en binario
		fclose(pFile); // lo cierro si lo pude abrir.
		sucess = 1;
	}
	return sucess;
}

/**
 * @brief lee la ultima id del bin y la actualiza con la nueva.
 */
/*
void controllerAlta(){
	int id;
	obtainID(&id); //obtiene la proxima id
	printf("ID: %d",id); // la muestro por si acaso
	upgradeID(id); //actualizo con la nueva id que obtuve
}*/

int controller_addObject(LinkedList *this) {
	Object *anotherObject;
	anotherObject = Object_new();

	int sucess = 0;
	int idForUse;
	int level;
	float cosmosLevel;
	char nameObject[128];
	char constellationName[128];
	char armorType[128];

	if (this != NULL) {

		obtainID(&idForUse); // Obtengo el ID al leerlo desde el archivo "lastID.txt" .
		printf("    [Bot_Sanctuary]: El alta se asignara con el ID: %d\n",
				idForUse);

		//------------------- Pido Nombre
		utn_getNombre(nameObject, 128,
				"    [Bot_Sanctuary]: Ingrese un nombre: ",
				"    [Bot_Sanctuary]: Nombre incorrecto, reingrese.\n", 5);
		uppercaselInitial(nameObject); //--------- Normalizo en minuscula e inicial mayuscula

		//------------------- Pido Constelacion
		utn_getNombre(constellationName, 128,
				"    [Bot_Sanctuary]: Ingrese una Constelacion: ",
				"    [Bot_Sanctuary]: Constelacion incorrecta, reingrese.\n", 5);
		uppercaselInitial(constellationName); //--------- Normalizo en minuscula e inicial mayuscula

		//------------------- Pido Tipo de Armadura
		utn_getNombre(armorType, 128,
				"    [Bot_Sanctuary]: Ingrese un tipo de armadura\n    [Bronce][Plata][Oro][Marina][Oscura][GodRobe]\n    Escriba: ",
				"    [Bot_Sanctuary]: Constelacion incorrecta, reingrese.", 5);
		uppercaselInitial(armorType); //--------- Normalizo en minuscula e inicial mayuscula

		//------------------- Pido Nivel de personaje
		utn_getNumero(&level,
				"    [Bot_Sanctuary]: Ingrese Nivel del Caballero [1-100]: ",
				"    [Bot_Sanctuary]: Nivel del Caballero incorrecto, reintente.\n",
				1, 100, 5);

		//------------------- Pido poder de pelea
		utn_getNumeroFlotante(&cosmosLevel,
				"    [Bot_Sanctuary]: Ingrese Poder de Cosmos [1K-9999]: ",
				"    [Bot_Sanctuary]: Poder de Cosmos incorrecto, reintente.\n",
				1000, 9999, 5);

		if (anotherObject != NULL) {
			Object_setAllInfo(anotherObject, &idForUse, nameObject,
					constellationName, armorType, level, cosmosLevel);
			ll_add(this, anotherObject);
			upgradeID(idForUse); // guarda en el archivo idForUse+1 en "lastID.txt"
			sucess = 1;
		}
	}
	return sucess;
}
