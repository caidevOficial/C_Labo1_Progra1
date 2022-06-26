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

/**
 * @brief  Genera un numero aleatorio entre 70 y 120.
 * @return Retorna el numero aleatorio generado [71-120].
 */
int getRandom(void);

/**
 * @brief Setea un tiempo random al campo tiempo del elemento bici.
 * @param bici Es el elemento con el cual buscara el campo para setearle el tiempo.
 */
void* tiempoSeteado(void*bici);

/**
 * @brief  compara el tipo del elemento con el campo asignado.
 * @param  bici Es el elemento con el cual buscara el campo ''tipo'' para filtrar.
 * @return Retorna 1 si el campo del elemento coincide con ''PASEO'', sino retorna 0.
 */
int filterPASEO(void*bici);

/**
 * @brief  compara el tipo del elemento con el campo asignado.
 * @param  bici Es el elemento con el cual buscara el campo ''tipo'' para filtrar.
 * @return Retorna 1 si el campo del elemento coincide con ''BMX'', sino retorna 0.
 */
int filterBMX(void*bici);

/**
 * @brief  compara el tipo del elemento con el campo asignado.
 * @param  bici Es el elemento con el cual buscara el campo ''tipo'' para filtrar.
 * @return Retorna 1 si el campo del elemento coincide con ''MTB'', sino retorna 0.
 */
int filterMTB(void*bici);

/**
 * @brief  compara el tipo del elemento con el campo asignado.
 * @param  bici Es el elemento con el cual buscara el campo ''tipo'' para filtrar.
 * @return Retorna 1 si el campo del elemento coincide con ''PLAYERA'', sino retorna 0.
 */
int filterPLAYERA(void*bici);
