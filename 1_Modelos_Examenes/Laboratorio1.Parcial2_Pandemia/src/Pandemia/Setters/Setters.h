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

#ifndef LIBRARY_Entity_SETTERS_SETTERS_H_
#define LIBRARY_Entity_SETTERS_SETTERS_H_

/**
 * @brief  set the value infect to the entity.
 * @param  this entity to upgrade its field infectados.
 * @param  infect number to assign to the entity.
 * @return return 1 if can, else 0.
 */
int Entity_setInfecteds(ePais *this, int infect);

/**
 * @brief  set the value infect to the entity.
 * @param  this entity to upgrade its field recuperados.
 * @param  recu number to assign to the entity.
 * @return return 1 if can, else 0.
 */
int Entity_setRecovered(ePais *this, int recu);

/**
 * @brief  set the value infect to the entity.
 * @param  this entity to upgrade its field muertos.
 * @param  muertos number to assign to the entity.
 * @return return 1 if can, else 0.
 */
int Entity_setDeads(ePais *this, int muertos);

/**
 * @brief  set the value infect to the entity.
 * @param  this entity to upgrade its field pais.
 * @param  pais string to assign to the entity.
 * @return return 1 if can, else 0.
 */
int Entity_setCountry(ePais *this, char *pais);

/**
 * @brief  set the value infect to the entity.
 * @param  this entity to upgrade its field id.
 * @param  id number to assign to the entity.
 * @return return 1 if can, else 0.
 */
int Entity_setID(ePais *this, int *id);

#endif /* LIBRARY_Entity_SETTERS_SETTERS_H_ */
