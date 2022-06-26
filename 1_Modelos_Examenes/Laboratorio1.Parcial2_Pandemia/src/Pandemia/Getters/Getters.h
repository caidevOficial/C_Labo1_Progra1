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

#include "../Pandemia.h"

#ifndef LIBRARY_Entity_GETTERS_GETTERS_H_
#define LIBRARY_Entity_GETTERS_GETTERS_H_

/**
 * @brief  get the value of the field muertos.
 * @param  this entity to get the data.
 * @param  muertos variable to save the number getted.
 * @return return 1 if can, else 0.
 */
int Entity_getDeads(ePais *this, int *muertos);

/**
 * @brief  get the value of the field recuperados.
 * @param  this entity to get the data.
 * @param  recu variable to save the number getted.
 * @return return 1 if can, else 0.
 */
int Entity_getRecovered(ePais *this, int *recu);

/**
 * @brief get the value of the field infectados.
 * @param this entity to get the data.
 * @param infec variable to save the number getted.
 * @return return 1 if can, else 0.
 */
int Entity_getInfected(ePais *this, int *infec);

/**
 * @brief get the value of the field pais.
 * @param this entity to get the data.
 * @param pais variable to save the string getted.
 * @return return 1 if can, else 0.
 */
int Entity_getCountry(ePais *this, char *pais);

/**
 * @brief get the value of the field id.
 * @param this entity to get the data.
 * @param id variable to save the number getted.
 * @return return 1 if can, else 0.
 */
int Entity_getID(ePais *this, int *id);

#endif /* LIBRARY_Entity_GETTERS_GETTERS_H_ */
