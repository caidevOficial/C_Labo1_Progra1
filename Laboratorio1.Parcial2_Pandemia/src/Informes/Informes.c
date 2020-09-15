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
 * Type: Recuperatorio segundo parcial - Laboratorio 1.
 * Version     : Beta 1.1.2 [Beta v1.1.2] - FacuFalcone_ABM_Pandemia_[Linux]
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "../Pandemia/Getters/Getters.h"
#include "../Pandemia/Setters/Setters.h"
#include "../Pandemia/Pandemia.h"
#include "../LinkedList.h"

int getRandomDeadPeople(void){
	int aleatorio;
	//1k-50k
	aleatorio = (rand()% 49000) + 1000;

	return aleatorio;
}

int getRandomInfectedPeople(void){
	int aleatorio;
	//40k-2kk
	aleatorio = (rand()% 1960000) + 40000;

	return aleatorio;
}

int getRandomRecoveredPeople(void){
	int aleatorio;
	//50k-1kk
	aleatorio = (rand()% 95000) + 50000;

	return aleatorio;
}

void* setDeads(void*muertos){
	ePais* tomuer = NULL;

	if(muertos!=NULL){
		tomuer = (ePais*)muertos;
		Entity_setDeads(tomuer, getRandomDeadPeople());

	}
	return tomuer;
}

void* setInfecteds(void*infected){
	ePais* infectado = NULL;

	if(infected!=NULL){
		infectado = (ePais*)infected;
		Entity_setInfecteds(infectado, getRandomInfectedPeople());

	}
	return infectado;
}

void* setRecovered(void*recu){
	ePais* recovered = NULL;

	if(recu!=NULL){
		recovered = (ePais*)recu;
		Entity_setRecovered(recovered, getRandomRecoveredPeople());
	}
	return recovered;
}

int filterSuccessCountry(void*cantidad){
	int success = 0;
	int muertos;

	ePais* exitoso;
	if(cantidad!=NULL){
		exitoso = (ePais*)cantidad;
		Entity_getDeads(exitoso, &muertos);
		if(muertos<5000){
			success = 1;
		}
	}

	return success;
}

int filterBakedCountry(void*cantidad){
	int success = 0;
	int recuperados;
	int infectados;

	ePais* horno;
	if(cantidad!=NULL){
		horno = (ePais*)cantidad;
		Entity_getInfected(horno, &infectados);
		Entity_getRecovered(horno, &recuperados);
		if(infectados >= (recuperados*3)){
			success = 1;
		}
	}

	return success;
}

LinkedList* punishedCountries(LinkedList* this){
	LinkedList* mappedList = NULL;
	ePais* pElement = NULL;
	int cantidadMuertos;
	int cantidadMayor;
	int flag = 0;
	char nombrePais[128];

	if(this==NULL){
		printf("    [Message] ERROR: La lista esta vacia (NULL).\n");
	}
	else{
		mappedList = ll_newLinkedList();
		for(int i = 0;i<ll_len(this);i++){
			pElement = ll_get(this, i);
			Entity_getDeads(pElement, &cantidadMuertos);
			if(!flag || cantidadMuertos > cantidadMayor){
				cantidadMayor = cantidadMuertos;
				Entity_getCountry(pElement, nombrePais);
				flag = 1;
			}
		}

		printf("    ____________________________________________________\n");
		printf("    [Message] El numero de muertos mayor es %d\n",cantidadMayor);
		printf("    [Message] El pais mas afectado es %s\n",nombrePais);
		printf("    [Message] Como se puede observar debajo.\n");
		pElement = NULL;
		for(int i = 0;i<ll_len(this);i++){
			pElement = ll_get(this, i);
			Entity_getDeads(pElement, &cantidadMuertos);
			if(cantidadMuertos==cantidadMayor){
				ll_add(mappedList, pElement);
			}
		}
	}

	return mappedList;
}
