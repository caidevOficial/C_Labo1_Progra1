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

//#include <stdio.h> // windows
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../../inc/LinkedList.h"
#include "../../Parser/parser.h"
#include "registerController.h"

#include "../../KnightOfZodiac/KnightZodiac.h"
#include "../../KnightOfZodiac/Getters/Getters.h"
#include "../../KnightOfZodiac/Setters/Setters.h"
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

int controller_addKnightZodiac(LinkedList *pArrayListKnightZodiac) {
	KnightZodiac *pKnightZodiac;
	pKnightZodiac = KnightZodiac_new();

	int sucess = 0;
	int idForUse;
	int level;
	int cosmosLevel;
	char nameKnightZodiac[128];
	char constellationName[128];
	int armorID;
	char armorType[128];

	if (pArrayListKnightZodiac != NULL) {

		obtainID(&idForUse); // Obtengo el ID al leerlo desde el archivo "lastID.txt" .
		printf("    [Bot_Sanctuary]: El alta se asignara con el ID: %d\n",
				idForUse);

		//------------------- Pido Nombre
		utn_getNombre(nameKnightZodiac, 128,
		"    [Bot_Sanctuary]: Ingrese un nombre: ",
		"    [Bot_Sanctuary]: Nombre incorrecto, reingrese.\n", 5);
		uppercaselInitial(nameKnightZodiac); //--------- Normalizo en minuscula e inicial mayuscula

		//------------------- Pido Constelacion
		utn_getNombre(constellationName, 128,
		"    [Bot_Sanctuary]: Ingrese una Constelacion: ",
		"    [Bot_Sanctuary]: Constelacion incorrecta, reingrese.\n", 5);
		uppercaselInitial(constellationName); //--------- Normalizo en minuscula e inicial mayuscula

		//------------------- Pido Tipo de Armadura
		utn_getNumero(&armorID, "    [Bot_Sanctuary]: Ingrese un tipo de armadura.\n"
		"    ________________________________________\n"
		"    [1][Bronce]  [2][Plata]    [3][Oro]   .\n"
		"    [4][Marina]  [5][Surplice] [6][GodRobe].\n"
		"    [Opcion]: ", "    [Bot_Sanctuary]: Armadura incorrecta, reintentelo.\n", 1, 6, 10);

		//------------------- Pido Nivel de personaje
		utn_getNumero(&level,
		"    [Bot_Sanctuary]: Ingrese Nivel del Caballero [1-100]: ",
		"    [Bot_Sanctuary]: Nivel del Caballero incorrecto, reintente.\n",1, 100, 5);

		//------------------- Pido poder de pelea
		utn_getNumero(&cosmosLevel,
		"    [Bot_Sanctuary]: Ingrese Poder de Cosmos [1K-99999]: ",
		"    [Bot_Sanctuary]: Poder de Cosmos incorrecto, reintente.\n",1000, 99999, 5);

		//------------------- Asigno descripcion de tipo de armadura.
		if (pKnightZodiac != NULL) {
			switch(armorID){
			case 1:
				strcpy(armorType,"Bronce");
				break;
			case 2:
				strcpy(armorType,"Plata");
				break;
			case 3:
				strcpy(armorType,"Oro");
				break;
			case 4:
				strcpy(armorType,"Marina");
				break;
			case 5:
				strcpy(armorType,"Surplice");
				break;
			case 6:
				strcpy(armorType,"GodRobe");
				break;
			}
			KnightZodiac_setAllInfo(pKnightZodiac, &idForUse, nameKnightZodiac,
					constellationName, armorType, level, cosmosLevel);
			ll_add(pArrayListKnightZodiac, pKnightZodiac);
			upgradeID(idForUse); // guarda en el archivo idForUse+1 en "lastID.txt"
			sucess = 1;
		}
	}
	return sucess;
}
