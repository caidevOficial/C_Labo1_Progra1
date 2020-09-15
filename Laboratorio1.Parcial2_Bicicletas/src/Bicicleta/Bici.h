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

#include "../LinkedList.h"

#ifndef Object_H_INCLUDED
#define Object_H_INCLUDED

typedef struct {
    int id;
	char duenho[128]; // nombre
	char tipo[128]; //
	int tiempo; // tiempo

} eBicicleta;

/**
 * @brief  Search the index of the bicicleta by id.
 * @param  this
 * @param  id
 * @return Return the index if can, else -1.
 */
int Bicicleta_SearchForId(LinkedList *this, int id);

/**
 * @brief  Buids a bicicleta.
 * @return Return the bicicleta.
 */
eBicicleta* Object_new();

/**
 * @brief  crea la bicicleta
 * @param id
 * @param duenho
 * @param tipo
 * @param tiempo
 * @return la bicicleta
 */
eBicicleta* Object_newParam(char *id, char *duenho, char *tipo,	char *tiempo);

/**
 * @brief Delete Object.
 * @param this
 */
void Object_delete(eBicicleta *this);

/**
 * @brief  ordena por tiempo
 * @param tiempo1
 * @param tiempo2
 * @return 1 si pudo, sino 0
 */
int Object_sortTiempo(void *tiempo1, void *tiempo2);

/**
 * @brief ordena por tipo
 * @param tipo1
 * @param tipo2
 * @return 1 si pudo, sino 0
 */
int Object_sortTipo(void *tipo1, void *tipo2);

#endif // Object_H_INCLUDED
