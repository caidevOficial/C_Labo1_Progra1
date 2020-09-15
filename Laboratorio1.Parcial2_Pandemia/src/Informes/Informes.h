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

#ifndef INFORMES_INFORMES_H_
#define INFORMES_INFORMES_H_

/**
 * @brief set a random number between 1k to 50k to the field muertos.
 * @param muertos Entity to assign the value.
 */
void* setDeads(void*muertos);

/**
 * @brief set a random number between 40k to 2kk to the field infectados.
 * @param infected Entity to assign the value.
 */
void* setInfecteds(void*infected);

/**
 * @brief set a random number between 50k to 1kk to the field recuperados.
 * @param recu Entity to assign the value.
 */
void* setRecovered(void*recu);

/**
 * @brief checks if the number of deads if lower than 5k
 * @param cantidad Entity to check the value.
 * @return 1 if is lower than 5k, else 0.
 */
int filterSuccessCountry(void*cantidad);

/**
 * @brief checks if the quantity of infected is the triple or more than recovered.
 * @param cantidad entity to check the values.
 * @return Return 1 if is the triple or more, else return 0.
 */
int filterBakedCountry(void*cantidad);

/**
 * @brief  scan the entire list to find the highest numer of deads, then check the countries with the same number.
 * @param this Entity to check.
 * @return the list with the country or countries with the highest number of deads.
 */
LinkedList* punishedCountries(LinkedList* this);

#endif /* INFORMES_INFORMES_H_ */
