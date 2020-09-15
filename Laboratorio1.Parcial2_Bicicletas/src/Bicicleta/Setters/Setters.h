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

#include "../Bici.h"

#ifndef LIBRARY_Object_SETTERS_SETTERS_H_
#define LIBRARY_Object_SETTERS_SETTERS_H_

/**
 * @brief coloca el tiempo
 * @param this
 * @param tiempo
 * @return 1 si pudo, sino 0
 */
int Object_setTiempo(eBicicleta *this, int tiempo);

/**
 * @brief  coloca el tipo
 * @param this
 * @param tipo
 * @return 1 si pudo, sino 0
 */
int Object_setTipo(eBicicleta *this, char *tipo);

/**
 * @brief  coloca el duenho
 * @param this
 * @param duenho
 * @return 1 si pudo, sino 0
 */
int Object_setDuenho(eBicicleta *this, char *duenho);

/**
 * @brief  coloca el id
 * @param this
 * @param id
 * @return 1 si pudo, sino 0
 */
int Object_setID(eBicicleta *this, int *id);

#endif /* LIBRARY_Object_SETTERS_SETTERS_H_ */
