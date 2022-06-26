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
 * Version     : 3.1.1 [Release Candidate v3.4]
 *
 * @author	CaiDev - FacuFalcone
 * ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "caidevValidate.h"

//		INPUT - VALIDACIONES

/**
* @brief	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
* 			un máximo de ' longitud - 1' caracteres .
* @param	cadena Puntero al espacio de memoria donde se copiara la cadena obtenida
* @param	longitud Define el tamaño de cadena
* @return	Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
*/
int myGets(char * cadena, int longitud){
int retorno = -1;
	if (cadena != NULL && longitud >0 && fgets (cadena,longitud,stdin)==cadena){
		fflush (stdin); // LINUX-> __fpurge o WIN-> fflush o MAC-> fpurge
		if (cadena[ strlen (cadena)-1] == '\n' ){
			cadena[ strlen (cadena)-1] = '\0' ;
		}
		retorno = 0;
	}
	return retorno;
}

/**
* @brief	Verifica si la cadena ingresada es numerica.
* @param	cadena Cadena de caracteres a ser analizada.
* @return	Retorna 1 ( vardadero ) si la cadena es numerica y 0 ( falso ) si no lo es.
*/
static int esNumerica(char* cadena){
int i=0;
int retorno = 1;
	//if (cadena != NULL && strlen(cadena) > 0){
	if (cadena[0] == '-'){
		i = 1;
	}
	while (cadena[i] != '\0' ){
		if (cadena[i] < '0' || cadena[i] > '9' ){
			retorno = 0;
			break ;
		}
		i++;
	}
	return retorno;
}


/**
* @brief devuelve 0 si obtiene un entero desde la terminal.
* @param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
* @return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
*
*/
static int getInt(int* pResultado){

int retorno=-1;
char buffer[64];

	if (pResultado != NULL){
		// Le pregunto si es un numero
		if (myGets(buffer, sizeof (buffer))==0 && esNumerica(buffer)){
		*pResultado = atoi(buffer);
		retorno = 0;
		}
	}
return retorno;
}

/**
 * @fn int utn_getNumero(int*, char*, char*, int, int, int)
 * @brief	devuelve 0 si obtiene un entero desde la terminal.
 * @param	pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion.
 * @param	mensaje mensaje a mostrar antes de obtener algun dato.
 * @param	mensajeError mensaje mostrado en caso de que el dato sea invalido.
 * @param	minimo numero minimo del rango a validar.
 * @param	maximo numero maximo del rango a validar.
 * @param	reintentos cantidad de veces que pedira ingresar dato.
 * @return	Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no.
 */
int utn_getNumero( int* pResultado, char* mensaje, char* mensajeError,
					int minimo, int maximo, int reintentos){
int bufferInt;
int retorno = -1;

	if (pResultado != NULL && mensaje != NULL
		&& mensajeError != NULL && minimo <=maximo
		&& reintentos >=0){
	do{

		printf("%s" ,mensaje);

		if ((getInt(&bufferInt)==0) && bufferInt >= minimo && bufferInt <= maximo){
		*pResultado = bufferInt;
		retorno = 0;
		break ;
		}
		reintentos--;
		printf("%s" ,mensajeError);
	}while (reintentos>0);

	}
return retorno;
}

// Flotantes

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
int esFlotante(char* cadena){
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(myGets(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}


int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}

void strMayuscula(char cadena[])
{
    int i=0;
    while(cadena[i]!='\0')
    {
        cadena[i] = toupper(cadena[i]);
        i++;
    }
}
void strMinuscula(char cadena[])
{
    int i=0;
    while(cadena[i]!='\0')
    {
        cadena[i] = tolower(cadena[i]);
        i++;
    }
}

