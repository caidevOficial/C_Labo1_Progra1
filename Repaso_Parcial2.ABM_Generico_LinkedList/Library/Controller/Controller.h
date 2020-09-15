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

#include "../../inc/LinkedList.h"

/**
 * @brief	Load data from the path [Text] and upload to LL.
 * @param 	path
 * @param 	this
 * @return	Return 1 if can, else 0.
 */
int controller_loadFromText(char *path, LinkedList *this);

/**
 * @brief	Load data from the path [Binary] and upload to LL.
 * @param 	path
 * @param 	this
 * @return  Return 1 if can, else 0.
 */
int controller_loadFromBinary(char *path, LinkedList *this);

/**
 * @brief	Prints all the knights in the screen.
 * @param 	this
 * @return	Return 1 if can, else 0.
 */
int controller_ListObject(LinkedList *this);

/**
 * @brief 	Sort all the knights by name, id, constellation, armor Type and cosmos.
 * @param 	this
 * @return 	Return 1 if can, else 0.
 */
int controller_sortObject(LinkedList *this);

/**
 * @brief	Save the data of the LL in the path [Text Mode]
 * @param 	path
 * @param 	this
 * @return	Return 1 if can, else 0.
 */
int controller_saveAsText(char *path, LinkedList *this);

/**
 * @brief 	Save the data of the LL in the path [Binary Mode].
 * @param 	path
 * @param 	this
 * @return	Return 1 if can, else 0.
 */
int controller_saveAsBinary(char *path, LinkedList *this);

/**
 * @brief  Reallocate the an objet of the array.
 * @param  this
 * @return Return 1 if can, else 0.
 */
int controller_reallocateObject(LinkedList* this);
