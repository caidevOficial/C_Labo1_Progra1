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

//#include <stdio.h>//windows
#include <stdio_ext.h>//linux
#include <stdlib.h>
#include <string.h>
#include "../../Controller/Controller.h"
#include "../../Validate/caidevValidate.h"
#include "../../../inc/LinkedList.h"
#include "../Object.h"

int Object_getID(Object *this, int *id) {
	int sucess = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		sucess = 1;
	}
	return sucess;
}

int cleanObject_getID(cleanObject *this, int *id) {
	int sucess = 0;

	if (this != NULL && id != NULL) {
		*id = this->rubroId;
		sucess = 1;
	}
	return sucess;
}

int cleanObject_getPrice(cleanObject *this, float *price) {
	int sucess = 0;

	if (this != NULL && price != NULL) {
		*price = this->precio;
		sucess = 1;
	}
	return sucess;
}

/* Getter: [Name] */
int Object_getName(Object *this, char *name) {
	int sucess = 0;

	if (this != NULL && name != NULL) {
		strcpy(name, this->name);
		sucess = 1;
	}
	return sucess;
}

/* Getter: [Constellation] */
int Object_getConstellation(Object *this, char *constellation) {
	int sucess = 0;

	if (this != NULL && constellation != NULL) {
		strcpy(constellation, this->constellation);
		sucess = 1;
	}
	return sucess;
}

/* Getter: [Armor Type] */
int Object_getArmorType(Object *this, char *armor) {
	int sucess = 0;

	if (this != NULL && armor != NULL) {
		strcpy(armor, this->armorType);
		sucess = 1;
	}
	return sucess;
}

/* Getter: [Cosmos Power] */
int Object_getCosmosLevel(Object *this, float *cosmosLevel) {
	int sucess = 0;

	if (this != NULL && cosmosLevel != NULL) {
		*cosmosLevel = this->cosmosLevel;
		sucess = 1;
	}
	return sucess;
}

/* Getter: [Level] */
int Object_getLevel(Object *this, int *level) {
	int sucess = 0;

	if (this != NULL && level != NULL) {
		*level = this->characterLevel;
		sucess = 1;
	}
	return sucess;
}

/* Getter: [All Fields] */
int Object_getAllInfo(Object *this, int *id, char *name,
		char *constellationName, char *armorType, int *level,
		float *cosmosLevel) {
	int sucess = -1;

	if (this != NULL) { // si el array no es null, obtengo los datos
		Object_getID(this, id);
		Object_getName(this, name);
		Object_getConstellation(this, constellationName);
		Object_getArmorType(this, armorType);
		Object_getLevel(this, level);
		Object_getCosmosLevel(this, cosmosLevel);
		sucess = 0;
	}
	return sucess;
}
