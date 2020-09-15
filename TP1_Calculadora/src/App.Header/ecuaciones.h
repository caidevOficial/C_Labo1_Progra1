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
 * El primero (X) se le conoce como versi�n mayor y nos indica la versi�n
 * 		principal del software. Ejemplo: 1.0.0, 3.0.0
 * El segundo (Y) se le conoce como versi�n menor y nos indica nuevas funcionalidades.
 * 		Ejemplo: 1.2.0, 3.3.0
 * El tercero (Z) se le conoce como revisi�n y nos indica que se hizo una revisi�n del
 * 		c�digo por algun fallo. Ejemplo: 1.2.2, 3.3.4
 *
 * Version     : 3.4.2 [Release Candidate v3.4]
 * ============================================================================
 */

#ifndef ECUACIONES_H_INCLUDED
#define ECUACIONES_H_INCLUDED

// ECUACIONES

/**
 * @brief	Suma los numeros ingresados por el usuario.
 * @param	'number1' es el primer numero ingresado por el usuario.
 * @param	'number2' es el segundo numero ingresado por el usuario.
 * @return	Denota el resultado "resultado" de la suma de ambos numeros.
 */
int suma(int number1, int number2);

/**
 * @brief	Resta los numeros ingresados por el usuario.
 * @param	'number1' es el primer numero ingresado por el usuario.
 * @param	'number2' es el segundo numero ingresado por el usuario.
 * @return	Denota el resultado "resultado" de la resta de ambos numeros.
 */
int resta(int number1, int number2);

/**
 * @brief	Multiplica los numeros ingresados por el usuario.
 * @param	'number1' es el primer numero ingresado por el usuario.
 * @param	'number2' es el segundo numero ingresado por el usuario.
 * @return	Denota el resultado "resultado" de la multiplicacion de ambos numeros.
 */
double multiplicacion(int number1, int number2);

/**
 * @brief	Divide los numeros ingresados por el usuario, si number2 es CERO, da un mensaje de error.
 * @param	'number1' es el primer numero ingresado por el usuario.
 * @param	'number2' es el segundo numero ingresado por el usuario.
 * @return	Denota el resultado "resultado" de la division de ambos numeros.
 */
float division(int number1, int number2);

/**
 * @brief	Factoriza el numero ingresado por el usuario (Solo numeros enteros).
 * @param	'numIngresado' es el numero ingresado por el usuario.
 * @return	Denota el resultado "fact" del factorial de "numIngresado".
 */
double factorial(int numIngresado);

/**
 * @brief	Pide un numero ENTERO al usuario y lo retorna.
 * @param	'numero1' es el numero que le pide al usuario.
 * @return	El numero pedido.
 */
int ingresoNumero();


// UI CALCULADORA

/**
 * @brief	Dibuja la parte superior con el nombre de la app.
 */
int parteSuperiorMenu();

/**
 * @brief	Dibuja los datos centrales de la app, con lo que puede hacer el usuario.
 */
int datosCentrales();

/**
 * @brief	Dibuja los datos centrales de la app, con lo que puede hacer el usuario.
 * @param	'num1' Es el primer operando ingresado.
 */
int datosCentralesA(int num1);

/**
 * @brief	Dibuja los datos centrales de la app, con lo que puede hacer el usuario.
 * @param	'num1' Es el primer operando ingresado.
 * @param	'num2' Es el segundo operando ingresado.
 */
int datosCentralesB(int num1,int num2);

/**
 * @brief	Dibuja parte de la UI mostrando las primeras 3 opciones al usuario con los operandos incognitos.
 */
int menuSuperiorAppVacio();

/**
 * @brief	Dibuja parte de la UI mostrando las primeras 3 opciones al usuario con operando A Visible.
 * @param	num1 es el primer operando.
 */
int menuSuperiorAppA(int num1);

/**
 * @brief	Dibuja parte de la UI mostrando las primeras 3 opciones al usuario con operandos A y B Visibles.
 * @param	num1 es el primer operando.
 * @param	num2 es el segundo operando
 */
int menuSuperiorAppB(int num1, int num2);

/**
 * @brief	Dibuja parte de la UI mostrando las ultimas dos opciones al usuario.
 */
int menuInferiorApp2();

/**
 * @brief	Muestra mensaje para que el usuario elija una opcion del menu.
 * @return	La opcion elegida.
 */
int opcionElegidaPorUsuario();

/**
 * @brief	Muestra mensaje anunciando que el sistema se esta apagando (Imitacion pantalla azul de la muerte).
 */
int interfazShutdown();

/**
 * @fn int opening()
 * @brief	Hace una pequenha animacion al iniciar la app.
 */
int opening();

/**
 * @brief	Muestra mensajes de carga de datos cada 1 segundo a modo de animacion.
 */
int animacionCargaResultados();

/**
 * @brief	Muestra mensajes de porcentaje de carga cada 1 segundo a modo de animacion.
 */
int animacionShutdown();

/**
 * @fn int resetFlags(int* flag1)
 * @brief	Vuelve flag1 a valor 0.
 * @param flag1
 */
int resetFlags(int* flag1);


// OPERACIONES SWITCH

/**
 * @brief	Ejecuta operaciones al elegir la opcion 1 del menu para ingreso del primer operando.
 * @param	numero1Auxiliar puntero para el operando 1.
 * @param	numero2Auxiliar puntero para el operando 2.
 * @param	flagNum1 puntero para el flag del operando 1.
 * @return	Opcion elegida por el usuario.
 */
int caseIngresoPrimerNumero(int* numero1Auxiliar, int* numero2Auxiliar, int* pFlagNum1);

/**
 * @brief	Ejecuta operaciones al elegir la opcion 1 del menu para ingreso del primer operando.
 * @param	numero1Auxiliar puntero para el operando 1.
 * @param	numero2Auxiliar puntero para el operando 2.
 * @param	flagNum1 puntero para el flag del operando 1.
 * @param	flagNum2 puntero para el flag del operando 2.
 * @return	Opcion elegida por el usuario.
 */
int caseIngresoSegundoNumero(int* numero1Auxiliar, int* numero2Auxiliar, int* pFlag1, int* pFlag2);

/**
 * @fn int mostrarMensajeErrorResultado(int, int, int*, int*)
 * @brief Muestra un mensaje de error si al menos uno de los dos operandos no estan ingresados.
 * @param num1 es para el primer operando.
 * @param num2 es para el segundo operando.
 * @param flag2 puntero para el flag del primer operando.
 * @param flagR puntero que se activa al mostrar resultados.
 * @return opcion elegida por el usuario.
 */
int mostrarMensajeErrorResultado(int num1, int num2, int* flag2, int* flagR);

/**
 * @brief	Muestra animacion de shutdown y reinicia todas los flags a 0.
 */
char caseSalir();

/**
 *  @brief	Muestra un menu para apagar la app o volver a cargar numeros.
 */
int mostrarSubMenuSalir();

/**
 * @fn 	int borrarPantallaYPonerMenuVacio().
 * @brief	Borra la pantalla y pone el menu de datos con incognitas X e Y.
 */
int borrarPantallaYPonerMenuVacio();

/**
 * @brief	borra la pantalla y muestra el menu con uno, dos o ningun operando cargado.
 * @param	'opcion' es la opcion para ver operandos cargados (0: ninguno, 1: el primero, 2: ambos).
 */
int borrarPantallaYPonerMenu(int opcion, int num1, int num2);

/**
 * @fn int resultadoSRM(int*, int*, char, double*, int)
 * @brief
 * @param num1 puntero hacia variable donde estara el primer operando.
 * @param num2 puntero hacia variable donde estara el segundo operando.
 * @param operacion caracter alfanumerico que indica la operacion a realizar (+,-,*,/,!).
 * @param resultadoVar puntero hacia la variable que almacena resultados de operaciones.
 * @param marcaFact en caso de haber un factorial en las operaciones, indica con cual de los dos operar.
 */
double resultadoSRM(int* num1, int* num2, char operacion, double* resultadoVar, int marcaFact);

/**
 * @brief	Realiza todas las operaciones de una calculadora basica.
 * @return	0.
 */
int CalculadorApp();


#endif // ECUACIONES_H_INCLUDED
