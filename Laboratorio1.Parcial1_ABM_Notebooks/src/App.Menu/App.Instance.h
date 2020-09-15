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
 * 							#Biblioteca
 *
 * About: Versionar
 * El primero (X) se le conoce como version mayor y nos indica la version
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como version menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revision y nos indica que se hizo una revision del
 * 		codigo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : 1.1.1 [Release Candidate v1.1]
 *
 * @author	CaiDev - FacuFalcone
 * ============================================================================
 */

#include "../CaiDevLib/Marca/marca.h"
#include "../CaiDevLib/Servicio/Servicio.h"
#include "../CaiDevLib/Tipo/Tipo.h"
#include "../CaiDevLib/Fecha/fecha.h"
#include "../CaiDevLib/Trabajo/Trabajo.h"
#include "../CaiDevLib/Notebooks/Notebook.h"
#include "../CaiDevLib/Validate/caidevValidate.h"

#ifndef APP_INSTANCE_H_
#define APP_INSTANCE_H_

/**
 * @fn int initTodo(Notebook*, int, Trabajo*, int)
 * @brief 	Inicializa trabajos y noteboos con ID 0.
 * @param note
 * @param lenNote
 * @param list
 * @param lenTrab
 * @return	Retorna 0 si puede y -1 si no.
 */
int initTodo(Notebook* note, int lenNote,Trabajo* list, int lenTrab);

/**
 * @fn char menu()
 * @brief 	Menu principal del ABM.
 * @return	Opcion elegida por el usuario.
 */
char menu();

/**
 * @fn int ABM_Notebooks(void)
 * @brief 	Ejecuta todas las funciones del ABM.
 * @return Success
 */
int ABM_Notebooks(void);

#endif /* APP_INSTANCE_H_ */
