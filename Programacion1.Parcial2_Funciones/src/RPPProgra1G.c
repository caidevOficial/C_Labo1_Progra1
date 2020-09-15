/*
 ============================================================================
 Name        : RPPProgra1G.c
 Author      : FacuFalcone - CaiDev
 Version     :
 Copyright   : Software Libre
 Description : Hello World in C, Ansi-style
 ============================================================================
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
void actualizarRecuperados(ePais pais[], int recuperadosDelDia){
	pais->recuperados = pais->recuperados + recuperadosDelDia;
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
	char ordenar[10] = {"facu"};
	char cadenaInvertida[10];
	int recuperadosDelDia = 1000;
					 //ID  Nombre     Inf   Rec  Muer
	ePais pais[1] = {{1,"Argentina",50000,25000,900}};

	actualizarRecuperados(pais, recuperadosDelDia);
	printf("1 - Recuperados totales a hoy: %d\n",pais[0].recuperados);

	strcpy(cadenaInvertida,invertirCadena(ordenar));
	printf("2 - Cadena %s invertida queda %s\n","facu",cadenaInvertida);

	ordenarCaracteres(ordenar);
	printf("3 - cadena %s ordenada queda: %s\n","facu",ordenar);
	return EXIT_SUCCESS;
}
