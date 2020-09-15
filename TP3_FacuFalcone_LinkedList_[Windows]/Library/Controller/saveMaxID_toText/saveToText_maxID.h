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
 * About: Versionar
 * El primero (X) se le conoce como version mayor y nos indica la version
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como version menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revision y nos indica que se hizo una revision del
 * 		codigo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : RC 6.13.2020 [Release Candidate v6.13] - FacuFalcone_LinkedList
 * ============================================================================
 */

#ifndef LIBRARY_CONTROLLER_SAVEMAXID_TOTEXT_SAVETOTEXT_MAXID_H_
#define LIBRARY_CONTROLLER_SAVEMAXID_TOTEXT_SAVETOTEXT_MAXID_H_

/**
 * @brief 	Obtiene la id mas grande del LL y guarda el id+1 en un archivo.txt
 * @param pFile
 * @param path
 * @param pArrayListEmployee
 * @return Retorna 1 si pudo, sino 0.
 */
int controller_saveAsTextMaxID(FILE* pFile,char* path, LinkedList* pArrayListEmployee);

#endif /* LIBRARY_CONTROLLER_SAVEMAXID_TOTEXT_SAVETOTEXT_MAXID_H_ */
