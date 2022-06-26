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
 * Version     : Beta 1.3.0 [Beta v1.3.0] - FacuFalcone_LinkedList_Bicicletas_[Linux]
 * ============================================================================
 */

#include "../LinkedList.h"

/**
 * @brief	Load data from the path [Text] and upload to LL.
 * @param 	path
 * @param 	this
 * @return	Return 1 if can, else 0.
 */
int controller_loadFromText(char *path, LinkedList *this);

/**
 * @brief	Prints all the knights in the screen.
 * @param 	this
 * @return	Return 1 if can, else 0.
 */
int controller_ListObject(LinkedList *this);

/**
 * @brief	Save the data of the LL in the path [Text Mode]
 * @param 	path
 * @param 	this
 * @return	Return 1 if can, else 0.
 */
int controller_saveAsText(char *path, LinkedList *this);
