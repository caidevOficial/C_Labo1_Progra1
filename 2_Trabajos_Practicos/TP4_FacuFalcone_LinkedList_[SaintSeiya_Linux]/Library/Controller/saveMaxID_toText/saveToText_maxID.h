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

#ifndef LIBRARY_CONTROLLER_SAVEMAXID_TOTEXT_SAVETOTEXT_MAXID_H_
#define LIBRARY_CONTROLLER_SAVEMAXID_TOTEXT_SAVETOTEXT_MAXID_H_

/**
 * @brief Get the largest id from the LL and save the id + 1 in a .txt file.
 * @param pFile
 * @param path
 * @param pArrayListKnightZodiac
 * @return Return 1 if can, else 0.
 */
int controller_saveAsTextMaxID(FILE *pFile, char *path, LinkedList *pArrayListKnightZodiac);

#endif /* LIBRARY_CONTROLLER_SAVEMAXID_TOTEXT_SAVETOTEXT_MAXID_H_ */
