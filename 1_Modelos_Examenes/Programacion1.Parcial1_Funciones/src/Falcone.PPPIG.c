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
 * Version     : 1.1.1 [Release Candidate v1.1]
 *
 * @author	CaiDev - FacuFalcone
 * ============================================================================
 * ============================================================================
 * Name        : PPPIG.c
 * Author      : FacuFalcone - CaiDev
 * Version     : RC 1.1.1
 * Copyright   : Software Libre
 * Description : Primer parcial de programacion 1
 * ============================================================================
 */


// FUNCIONES DEL PARCIAL DE PROGRAMACION [PRACTICA]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 4

typedef struct{
	int id;
	char procesador[20];
	char marca[20];
	float precio;
}eNotebook;

		/** Funciones **/
		/** Ejercicio 1 **/

float aplicarDescuentoDel_5(float precio){
	float precioConDescuento;
	float valorDescuento;
	valorDescuento = (precio * ((float)5 / 100));
	precioConDescuento = precio - valorDescuento;

	return precioConDescuento;
}

		/** Ejercicio 2 **/
int contarCaracteres(char str[], char caracter){
	int contador = 0;
	int cant = strlen(str);
	for(int i = 0; i<cant; i++){
		if(str[i] == caracter){
			contador++;
		}
	}
	return contador;
}

		/** Ejercicio 3 **/
void sortMarca_Precio(eNotebook notebooks[], int tamNotebook){
	eNotebook auxNotebook;
	for(int i = 0; i < tamNotebook-1; i++){
		for(int j = i + 1; j < tamNotebook; j++){
			// Marca -> Menor a Mayor (Ascendente alfabeticamente)
			if(strcmp(notebooks[i].marca, notebooks[j].marca) > 0){
				auxNotebook = notebooks[i];
				notebooks[i] = notebooks[j];
				notebooks[j] = auxNotebook;
			}
			// Precio -> Menor a Mayor
			else if(strcmp(notebooks[i].marca, notebooks[j].marca) == 0 &&
					notebooks[i].precio > notebooks[j].precio){
				auxNotebook = notebooks[i];
				notebooks[i] = notebooks[j];
				notebooks[j] = auxNotebook;
			}
		}
	}
}


int main(void) {

	float precio = 25000;
	float precioDescuento;
	char letra = 'F';
	char nombre[20];
	int cantCaracteres;
	eNotebook notebooks[TAM] = {//ID   PROCESADOR    MARCA      PRECIO
								{5000, "I5 4300k", 	"Lenovo", 	48000},
								{5001, "I9 9900k", 	"HP", 		95000},
								{5002, "Ryzen 3", 	"HP", 		35000},
								{5003, "Ryzen 5", 	"Asus", 	42000} };

	/***Llamada a funciones:**/

	// Ejercicio 1
	precioDescuento = aplicarDescuentoDel_5(precio);

	// Ejercicio 2
	strcpy(nombre, "Facundo Falcone");
	cantCaracteres = contarCaracteres(nombre, letra);

	// Ejercicio 3
	sortMarca_Precio(notebooks, TAM);

	/***  Respuestas **/
	// Ejercicio 1
	printf("    Ejercicio 1:\n"
			"    El precio de $ %.2f con el descuento del 5 porciento es de $ %.2f\n\n", precio,precioDescuento );
	// Ejercicio 2
	printf("    Ejercicio 2:\n"
			"    En el array: %s hay letras %c: %d\n\n",nombre,letra,cantCaracteres);
	// Ejercicio 3
	printf("    Ejercicio 3:\n"
			"    Criterio: Marca y precio\n "
			"    ID       Procesador        Marca      Precio\n");
	for(int i = 0; i <TAM; i++){
		printf("    %d    %10s    %10s   $ %.2f\n", notebooks[i].id, notebooks[i].procesador, notebooks[i].marca, notebooks[i].precio);
	}
	printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}
