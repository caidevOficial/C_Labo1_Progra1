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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../../../inc/LinkedList.h"

#ifndef LIBRARY_CONTROLLER_MODIFYCONTROLLER_MODIFYCONTROLLER_H_
#define LIBRARY_CONTROLLER_MODIFYCONTROLLER_MODIFYCONTROLLER_H_

/**
 * @brief 	Edita los datos del Caballero del Zodiaco.
 * @param pArrayListKnightZodiac
 * @return	Retorna 1 si pudo, sino 0.
 */
int controller_editKnightZodiac(LinkedList *pArrayListKnightZodiac);

#endif /* LIBRARY_CONTROLLER_MODIFYCONTROLLER_MODIFYCONTROLLER_H_ */
