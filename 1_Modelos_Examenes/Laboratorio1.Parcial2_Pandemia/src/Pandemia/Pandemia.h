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

#include "../LinkedList.h"

#ifndef Entity_H_INCLUDED
#define Entity_H_INCLUDED

typedef struct {
    int id;
	char pais[128]; //
	int recuperados; //
	int infectados;
	int muertos;//

} ePais;

/**
 * @brief  Assign space on the memory for the entity.
 * @return Return the entity.
 */
ePais* Entity_new();

/**
 * @brief  builds the entity with its fields values.
 * @param id the id of the entity.
 * @param pais the name of the entity.
 * @param infectados the value of the infected people of the entity.
 * @param recuperados the value of the recovered people of the entity.
 * @param muertos the value of the dead people of the entity.
 * @return the entity builded.
 */
ePais* Entity_newParam(char *id, char *pais, char *infectados,char *recuperados, char* muertos);

/**
 * @brief  sort the array by infected field.
 * @param infected1 first entity to evaluate.
 * @param infected2 second entity to evaluate.
 * @return return 0 if both are equals, 1 if the first is higher and -1 if is lower.
 */
int Entity_sortInfectados(void *infected1, void *infected2);

#endif // Entity_H_INCLUDED
