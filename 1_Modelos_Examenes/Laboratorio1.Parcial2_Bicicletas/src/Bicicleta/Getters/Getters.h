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

#ifndef LIBRARY_Object_GETTERS_GETTERS_H_
#define LIBRARY_Object_GETTERS_GETTERS_H_

/**
 * @brief  Get the data of the field tipo.
 * @param  this
 * @param  tipo
 * @return Return 1 if can, else 0.
 */
int Object_getTipo(eBicicleta *this, char *tipo);

/**
 * @brief  Get the data of the field tiempo.
 * @param  this
 * @param  tiempo
 * @return Return 1 if can, else 0.
 */
int Object_getTiempo(eBicicleta *this, int *tiempo);

/**
 * @brief  Get the data of the field duenho.
 * @param  this
 * @param  duenho
 * @return Return 1 if can, else 0.
 */
int Object_getDuenho(eBicicleta *this, char *duenho);

/**
 * @brief  Get the data of the field id.
 * @param  this
 * @param  id
 * @return Return 1 if can, else 0.
 */
int Object_getID(eBicicleta *this, int *id);

#endif /* LIBRARY_Object_GETTERS_GETTERS_H_ */
