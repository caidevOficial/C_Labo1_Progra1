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

#include "../Object.h"

#ifndef LIBRARY_Object_GETTERS_GETTERS_H_
#define LIBRARY_Object_GETTERS_GETTERS_H_


/* Getters: [ID] */
/**
 * @brief  Get the data of the field ID.
 * @param  this
 * @param  id
 * @return Return 1 if can, else 0.
 */
int Object_getID(Object *this, int *id);

/**
 * @brief  Get the data of the field precio.
 * @param  this
 * @param  price
 * @return Return 1 if can, else 0.
 */
int cleanObject_getPrice(cleanObject *this, float *price);

/**
 * @brief  Get the data of the field rubroID,
 * @param  this
 * @param  id
 * @return Return 1 if can, else 0.
 */
int cleanObject_getID(cleanObject *this, int *id);

/* Getters: [Name] */

/**
 * @brief  Get the data of the field Name.
 * @param  this
 * @param  name
 * @return Return 1 if can, else 0.
 */
int Object_getName(Object *this, char *name);

/* Getter: [Constellation] */
/**
 * @brief  Get the data of the field consteliation.
 * @param  this
 * @param  constellation
 * @return Return 1 if can, else 0.
 */
int Object_getConstellation(Object *this, char *constellation);

/* Getter: [Armor] */
/**
 * @brief  Get the data of the field armor.
 * @param  this
 * @param  armor
 * @return Return 1 if can, else 0.
 */
int Object_getArmorType(Object *this, char *armor);

/* Getter: [Cosmos Power] */
/**
 * @brief  Get the data of the field cosmosLevel.
 * @param  this
 * @param  cosmosLevel
 * @return Return 1 if can, else 0.
 */
int Object_getCosmosLevel(Object *this, float *cosmosLevel);

/* Getter: [Level] */
/**
 * @brief  Return the data of the field characterLevel.
 * @param  this
 * @param  level
 * @return Return 1 if can, else 0.
 */
int Object_getLevel(Object *this, int *level);

/* Getter: [All Fields] */
/**
 * @brief  Get all the data from the fields of the Knight.
 * @param  this
 * @param  id
 * @param  name
 * @param  cosmosName
 * @param  armorType
 * @param  level
 * @param  powerLevel
 * @return Return 1 if can, else 0.
 */
int Object_getAllInfo(Object *this, int *id, char *name,
		char *constellationName, char *armorType, int *level,
		float *cosmosLevel);

#endif /* LIBRARY_Object_GETTERS_GETTERS_H_ */
