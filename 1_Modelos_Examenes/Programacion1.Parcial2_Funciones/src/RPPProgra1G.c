/*
 * Copyright (C) 2020 caidev
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int id;
	char nombre[20];
	int infectados;
	int recuperados;
	int muertos;
}ePais;

/* Ejercicio 1 */
void actualizarRecuperados(ePais pais, int recuperadosDelDia){
	pais.recuperados = pais.recuperados + recuperadosDelDia;
}

/* Ejercicio 2 */
char* invertirCadena(char str[]){
	char aux;
	int largo;
	int j;

	if(str != NULL){
		largo = strlen(str);
		j = largo;
		for(int i = 0 ; i<(largo/2); i++){
			j--;
			aux = str[i];
			str[i] = str[j];
			str[j] = aux;
		}
	}
	return str;
}

/* Ejercicio 3 */
void ordenarCaracteres(char str[]){
	int tamCadena = strlen(str);
	char auxChar;
	for(int i = 0; i < tamCadena-1; i++){
			for(int j = i + 1; j < tamCadena; j++){
				//(Ascendente alfabeticamente)
				if(str[i] > str[j]){
					auxChar = str[i];
					str[i] = str[j];
					str[j] = auxChar;
				}
			}
		}
}

int main(void) {
	char ordenar[10] = {"algoritmo"};
	char cadenaInvertida[10];
	int recuperadosDelDia = 1000;
					 //ID  Nombre     Inf   Rec  Muer
	ePais pais = {1,"Argentina",50000,25000,900};

	actualizarRecuperados(pais, recuperadosDelDia);
	printf("1 - Recuperados totales a hoy: %d\n",pais.recuperados);

	strcpy(cadenaInvertida,invertirCadena(ordenar));
	printf("2 - Cadena %s invertida queda %s\n","algoritmo",cadenaInvertida);

	ordenarCaracteres(ordenar);
	printf("3 - cadena %s ordenada queda: %s\n","algoritmo",ordenar);
	return EXIT_SUCCESS;
}
