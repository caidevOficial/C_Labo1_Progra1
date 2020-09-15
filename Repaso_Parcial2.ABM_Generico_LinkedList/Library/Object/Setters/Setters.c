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

/* Setters: [ID] */
int Object_setID(Object *this, int *id) {
	int sucess = 0;

	if (this != NULL) {
		if (id >= 0) {
			this->id = *id;
			sucess = 1;
		}
	}
	return sucess;
}

/* Setters: [Name] */
int Object_setName(Object *this, char *name) {
	int sucess = 0;

	if (this != NULL && name != NULL) {
		strncpy(this->name, name, 10);
		sucess = 1;
	}
	return sucess;
}

/* Setters: [Constellation] */
int Object_setConstellation(Object *this, char *constellationName) {
	int sucess = 0;

	if (this != NULL && constellationName != NULL) {
		strncpy(this->constellation, constellationName, 10);
		sucess = 1;
	}
	return sucess;
}

/* Setters: [Armor Type] */
int Object_setArmorType(Object *this, char *armor) {
	int sucess = 0;

	if (this != NULL && armor != NULL) {
		strncpy(this->armorType, armor, 10);
		sucess = 1;
	}
	return sucess;
}

/* Setters: [Level] */
int Object_setLevel(Object *this, int level) {
	int sucess = 0;

	if (this != NULL) {
		if (level >= 0) {
			this->characterLevel = level;
			sucess = 1;
		}
	}
	return sucess;
}

/* Setters: [Cosmos Power] */
int Object_setCosmosLevel(Object *this, float cosmosLevel) {
	int sucess = 0;

	if (this != NULL) {
		if (cosmosLevel >= 0) {
			this->cosmosLevel = cosmosLevel;
			sucess = 1;
		}
	}
	return sucess;
}

/* Setter: [All Fields]*/
int Object_setAllInfo(Object *this, int *id, char *name,
		char *constellationName, char *armorType, int level, float CosmosLevel) {
	int sucess = -1;

	if (this != NULL) { // si el array no es null, obtengo los datos
		Object_setID(this, id);
		Object_setName(this, name);
		Object_setConstellation(this, constellationName);
		Object_setArmorType(this, armorType);
		Object_setLevel(this, level);
		Object_setCosmosLevel(this, CosmosLevel);
		sucess = 0;
	}
	return sucess;
}

