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
 * Type: Recuperatorio segundo parcial - Laboratorio 1.
 * Version     : Beta 1.1.2 [Beta v1.1.2] - FacuFalcone_ABM_Pandemia_[Linux]
 * ============================================================================
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../LinkedList.h"

#ifndef MAINAPP_MAINAPP_H_
#define MAINAPP_MAINAPP_H_

/**
 * @brief Pointer to function, with many actions.
 * @param messageError1 error if the file is open.
 * @param messageError2 error if the file is null
 * @param messageSuccess message if can open the archive
 * @param flag flag state to evaluate
 * @param flagValue value to evaluate the flag
 * @param NewflagValue value to upgrade the flag value
 * @param path path of the file
 * @param array array to copy all the entities
 * @param pFunction function to open the file
 */
void pFunctionLoadBinCsv(char* messageError1,char* messageError2,char* messageSuccess,int* flag,int flagValue,
		int NewflagValue,char*path,LinkedList* array,int(*pFunction)(char*,LinkedList*));

/**
 * @brief 	Executes all the functions of the ABM.
 */
int FACUFALCONE_ABM_PANDEMY();

#endif /* MAINAPP_MAINAPP_H_ */
