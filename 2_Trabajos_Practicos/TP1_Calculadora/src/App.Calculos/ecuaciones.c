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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/**
 *  isDigit() te dice si es un digito
 *  isAlpha() te dice si es una letra
 *  isSpace() te dice si es un espacio en blanco
 *  itoa() integer to ascii
 *  atoi() ascii to integer
 *  atof() ascii to float
 *  guardarlo en array y recorrerlo caracter por caracter
 *
 */

// ECUACIONES

int suma(int number1, int number2){
	int resultado;
	resultado = (number1) + (number2);
	return resultado;
}

int resta(int number1, int number2){
	int resultado;
	resultado = (number1) - (number2);
	return resultado;
}

double multiplicacion(int number1, int number2){
	double resultado;
	resultado = (number1) * (number2);
	return resultado;
}

float division(int number1, int number2){
	float resultadoDiv;
	if (number1 != 0){
		resultadoDiv = ((float)(number1)) / (number2);
	}
	else{
		resultadoDiv = 0;
	}

	return resultadoDiv;
}

double factorial(int numIngresado){
	double fact;
	//int contador;
	if(((numIngresado)==1) || ((numIngresado)==0) || ((numIngresado)>40)){
		fact = 1;
	}
	else{
		fact = (numIngresado)*factorial((numIngresado)-1);
	}

	return fact;
}

int resetFlags(int* flag1){
	*flag1 = 0;

	return 0;
}

int esPositivo(int numeroPorParametro){
    return numeroPorParametro>0;
}

float promediarNumeros(int acumulador,int contador){
    return (float)acumulador/contador;
}
