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

#include "../../inc/LinkedList.h"
#ifndef KnightZodiac_H_INCLUDED
#define KnightZodiac_H_INCLUDED

typedef struct {
    int id;
	char name[128]; // nombre
	char constellation[128]; // constelacion a la que pertenece
	char armorType[128]; //tipo de armadura (plata, oro, bronce)
	int characterLevel; // nivel del personaje
	int cosmosLevel; //poder de batalla

} KnightZodiac;

/**
 * @brief  Initialize the array in NULL.
 * @param  KnightZodiacs
 * @param  lenKnightZodiacs
 * @return Return 1 if can, else 0.
 */
int initKnightZodiacs(KnightZodiac **KnightZodiacs, int lenKnightZodiacs);

/**
 * @brief  Search the index of the knight by id.
 * @param  pArrayListKnightZodiac
 * @param  id
 * @return Return the index if can, else -1.
 */
int KnightZodiac_SearchForId(LinkedList *pArrayListKnightZodiac, int id);

/**
 * @brief Add a knight to the array.
 * @param index
 * @param KnightZodiacs
 */
void addKnightZodiacToArray(int *pIndex, LinkedList *KnightZodiacs);

/**
 * @brief  Prints a knight.
 * @param  KnightZodiac
 * @return Return 1 if can, else 0.
 */
int showKnightZodiac(KnightZodiac *KnightZodiac);

/**
 * @brief  Buids a knight.
 * @return Return the knight.
 */
KnightZodiac* KnightZodiac_new();

/**
 * @brief  Builds the new knight with all the data.
 * @param  idStr
 * @param  nombreStr
 * @param  horasTrabajadasStr
 * @param  sueldoStr
 * @return Return the knight.
 */
KnightZodiac* KnightZodiac_newParam(char *id, char *name, char *constellation,
		char *armorType, char *level, char *cosmosLevel);

/**
 * @brief Delete KnightZodiac.
 * @param this
 */
void KnightZodiac_delete(KnightZodiac *this);

/**
 * @brief  Sort the knights.
 * @param  pArrayListKnightZodiac
 * @return Return 1 if can, else 0.
 */
int KnightZodiac_sortKnightZodiac(LinkedList *pArrayListKnightZodiac);

/**
 * @brief  Sorts all the knight by id.
 * @param  idOne
 * @param  idTwo
 * @return If the first is higher, return 1, if both are equals 0, else -1.
 */
int KnightZodiac_sortByID(void *idOne, void *idTwo);

/**
 * @brief  Sorts by name.
 * @param  nameOne
 * @param  nameTwo
 * @return If the first is higher, return 1, if both are equals 0, else -1.
 */
int KnightZodiac_sortByName(void *nameOne, void *nameTwo);

/**
 * @brief  Sorts by constellacion.
 * @param  constellationOne
 * @param  constellationTwo
 * @return If the first is higher, return 1, if both are equals 0, else -1.
 */
int KnightZodiac_sortByConstellation(void *constellationOne,
		void *constellationTwo);

/**
 * @brief  Sorts by characterLevel.
 * @param  level1
 * @param  level2
 * @return If the first is higher, return 1, if both are equals 0, else -1.
 */
int KnightZodiac_sortByLevel(void *level1, void *level2);

/**
 * @brief  Sorts by armorType.
 * @param  armorOne
 * @param  armorTwo
 * @return If the first is higher, return 1, if both are equals 0, else -1.
 */
int KnightZodiac_sortByArmorType(void *armorOne, void *armorTwo);

/**
 * @brief  Sorts by cosmosPower.
 * @param  cosmos1
 * @param  cosmos2
 * @return If the first is higher, return 1, if both are equals 0, else -1.
 */
int KnightZodiac_sortByCosmosLevel(void *cosmos1, void *cosmos2);

#endif // KnightZodiac_H_INCLUDED
