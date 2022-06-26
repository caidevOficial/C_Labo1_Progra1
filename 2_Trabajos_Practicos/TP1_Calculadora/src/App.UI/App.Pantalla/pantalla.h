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
 * #CalculadorApp
 *
 * About: Versionar
 * El primero (X) se le conoce como versión mayor y nos indica la versión
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como versión menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revisión y nos indica que se hizo una revisi�n del
 * 		c�digo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : 3.4.2 [Release Candidate v3.4]
 * ============================================================================
 */

#ifndef APP_UI_APP_PANTALLA_PANTALLA_H_
#define APP_UI_APP_PANTALLA_PANTALLA_H_

void parteSuperiorMenu();

void menuSuperiorAppVacio();

void menuSuperiorAppA(int num1);

void menuSuperiorAppB(int num1, int num2);

void datosCentrales();

void datosCentralesA(int num1);

void datosCentralesB(int num1,int num2);

void menuInferiorApp2();

int opcionElegidaPorUsuario();

void mensajeResultados();

double resultadoSRM(int* num1, int* num2, char operacion, double* resultadoVar, int marcaFact);

void borrarPantallaYPonerMenuVacio();

void borrarPantallaYPonerMenu(int opcion, int num1, int num2);

int mostrarMensajeErrorResultado(int num1, int num2, int* flag2, int* flagR);

void mostrarSubMenuSalir();

#endif /* APP_UI_APP_PANTALLA_PANTALLA_H_ */
