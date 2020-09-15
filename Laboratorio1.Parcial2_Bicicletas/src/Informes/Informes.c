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

#include <ctype.h>
//#include <stdio.h> //windows
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>

#include "Informes.h"
#include "../Bicicleta/Bici.h"
#include "../Bicicleta/Setters/Setters.h"

int getRandom(void){
	int aleatorio;
	aleatorio = rand()% 50 + 71;

	return aleatorio;
}

void* tiempoSeteado(void*bici){
	eBicicleta* bicicleta = NULL;

	if(bici!=NULL){
		bicicleta = (eBicicleta*)bici;
		Object_setTiempo(bicicleta, getRandom());

	}
	return bicicleta;
}

int filterPASEO(void*bici){
	int sucess = 0;

	eBicicleta* bicicleta;
	if(bici!=NULL){

		bicicleta = (eBicicleta*)bici;
		if(strcmp(bicicleta->tipo,"PASEO")==0){
			sucess = 1;
		}
	}

	return sucess;
}

int filterBMX(void*bici){
	int sucess = 0;

	eBicicleta* bicicleta;
	if(bici!=NULL){

		bicicleta = (eBicicleta*)bici;
		if(strcmp(bicicleta->tipo,"BMX")==0){
			sucess = 1;
		}
	}

	return sucess;
}

int filterMTB(void*bici){
	int sucess = 0;

	eBicicleta* bicicleta;
	if(bici!=NULL){

		bicicleta = (eBicicleta*)bici;
		if(strcmp(bicicleta->tipo,"MTB")==0){
			sucess = 1;
		}
	}

	return sucess;
}

int filterPLAYERA(void*bici){
	int sucess = 0;

	eBicicleta* bicicleta;
	if(bici!=NULL){

		bicicleta = (eBicicleta*)bici;
		if(strcmp(bicicleta->tipo,"PLAYERA")==0){
			sucess = 1;
		}
	}

	return sucess;
}
