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

#include "../../inc/LinkedList.h"

/**
 * @brief 	Parse the data the Knights of the Zodiac data from the sanctuary.csv file (text mode).
 * @param 	pFile
 * @param 	pArrayListKnightZodiac
 * @return	Return 1 if can, else 0.
 */
int parser_KnightZodiacFromText(FILE *pFile, LinkedList *pArrayListKnightZodiac);

/**
 * @brief 	Parse the data the Knights of the Zodiac data from the sanctuary.bin file (binary mode).
 * @param 	pFile
 * @param 	pArrayListKnightZodiac
 * @return	Return 1 if can, else 0.
 */
int parser_KnightZodiacFromBinary(FILE *pFile, LinkedList *pArrayListKnightZodiac);
