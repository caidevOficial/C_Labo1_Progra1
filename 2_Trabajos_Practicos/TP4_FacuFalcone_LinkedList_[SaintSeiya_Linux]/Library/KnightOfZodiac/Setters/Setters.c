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

//#include <stdio.h>//windows
#include <stdio_ext.h>//linux
#include <stdlib.h>
#include <string.h>
#include "../../Controller/Controller.h"
#include "../../Validate/caidevValidate.h"
#include "../../../inc/LinkedList.h"
#include "../KnightZodiac.h"

/* Setters: [ID] */
int KnightZodiac_setID(KnightZodiac *this, int *id) {
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
int KnightZodiac_setName(KnightZodiac *this, char *name) {
	int sucess = 0;

	if (this != NULL && name != NULL) {
		strncpy(this->name, name, 10);
		sucess = 1;
	}
	return sucess;
}

/* Setters: [Constellation] */
int KnightZodiac_setConstellation(KnightZodiac *this, char *constellationName) {
	int sucess = 0;

	if (this != NULL && constellationName != NULL) {
		strncpy(this->constellation, constellationName, 10);
		sucess = 1;
	}
	return sucess;
}

/* Setters: [Armor Type] */
int KnightZodiac_setArmorType(KnightZodiac *this, char *armor) {
	int sucess = 0;

	if (this != NULL && armor != NULL) {
		strncpy(this->armorType, armor, 10);
		sucess = 1;
	}
	return sucess;
}

/* Setters: [Level] */
int KnightZodiac_setLevel(KnightZodiac *this, int level) {
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
int KnightZodiac_setCosmosLevel(KnightZodiac *this, int cosmosLevel) {
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
int KnightZodiac_setAllInfo(KnightZodiac *this, int *id, char *name,
		char *constellationName, char *armorType, int level, int CosmosLevel) {
	int sucess = 0;

	if (this != NULL) { // si el array no es null, obtengo los datos
		KnightZodiac_setID(this, id);
		KnightZodiac_setName(this, name);
		KnightZodiac_setConstellation(this, constellationName);
		KnightZodiac_setArmorType(this, armorType);
		KnightZodiac_setLevel(this, level);
		KnightZodiac_setCosmosLevel(this, CosmosLevel);
		sucess = 1;
	}
	return sucess;
}
