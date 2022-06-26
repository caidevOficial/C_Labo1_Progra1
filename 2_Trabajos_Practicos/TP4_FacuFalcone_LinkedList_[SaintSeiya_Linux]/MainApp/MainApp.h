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

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

#ifndef MAINAPP_MAINAPP_H_
#define MAINAPP_MAINAPP_H_

/**
 * @brief	Simulate the systemPause in linux.
 */
void enterToContinue(void);

/**
 * @brief Pointer to function, with many actions.
 * @param messageError1
 * @param messageError2
 * @param messageSucess
 * @param flag
 * @param flagValue
 * @param NewflagValue
 * @param path
 * @param array
 * @param pFunction
 */
void pFunctionLoadBinCsv(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue,
		int NewflagValue,char*path,LinkedList* array,int(*pFunction)(char*,LinkedList*));

/**
 * @brief 	Pointer to function, when many actions.
 * @param messageError1
 * @param messageError2
 * @param messageSucess
 * @param flag
 * @param flagValue
 * @param array
 * @param pFunction
 */
void pFunction(char* messageError1,char* messageError2,char* messageSucess,int* flag,int flagValue
		,LinkedList* array,int(*pFunction)(LinkedList*));

/**
 * @brief 	Execute all the functions of the ABM.
 */
void tp4_FacuFalcone_LinkedList();

#endif /* MAINAPP_MAINAPP_H_ */
