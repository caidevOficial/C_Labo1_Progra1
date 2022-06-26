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
 * About: Versionar
 * El primero (X) se le conoce como version mayor y nos indica la version
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como version menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revision y nos indica que se hizo una revision del
 * 		codigo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : RC 6.13.2020 [Release Candidate v6.13] - FacuFalcone_LinkedList
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
 * @brief	simula el systemPause en linux.
 */
void enterToContinue(void);

/**
 * @brief 	Puntero a funcion, donde se cargan parametros, mensajes de error y exito y actualiza un puntero.
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
 * @brief 	Puntero a funcion, donde se cargan parametros, mensajes de error y exito.
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
 * @brief 	Ejecuta dentro todas las funciones del ABM.
 */
void tp3_LinkedList();

#endif /* MAINAPP_MAINAPP_H_ */
