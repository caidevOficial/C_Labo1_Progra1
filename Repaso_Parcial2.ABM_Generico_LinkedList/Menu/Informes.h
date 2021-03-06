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

#include <stdlib.h>
#include <stdio.h>
#include "../inc/LinkedList.h"

#ifndef MENU_INFORMES_H_
#define MENU_INFORMES_H_

//***************************************
// funcion para ll_count
//***************************************
/**
 * @brief  Devuelve el nivel del personaje.
 * @param  pElement
 * @return Retorna el nivel del personaje, sino falla da -1.
 */
int counterLevel(void* pElement);

/**
 * @brief
 * @param pElement
 * @return
 */
float powerUpOrDown(void* pElement);

/**
 * @brief
 * @param pElement
 * @return
 */
float discountPrice(void* pElement);

/**
 * @brief Execute all the reports of the main app.
 * @param originalArray
 */
void functionReports(LinkedList* originalArray);

#endif /* MENU_INFORMES_H_ */
