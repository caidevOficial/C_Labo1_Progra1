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
 * Version     : Beta 3.0.0 [Beta v3.0.0] - FacuFalcone_LinkedList_SaintSeiya_[Linux]
 * ============================================================================
 */

//#include <stdio.h> //windows
#include <stdio_ext.h> //linux
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../../../inc/LinkedList.h"
#include "../../KnightOfZodiac/KnightZodiac.h"
#include "../../KnightOfZodiac/Getters/Getters.h"
#include "../../Parser/parser.h"
#include "../../Validate/caidevValidate.h"

int KnightZodiac_getHigherID(KnightZodiac *this, int *id) {
    int sucess = -1;

    if(this != NULL){ // si el array no es null, obtengo los datos
		KnightZodiac_getID(this, id);
        sucess = 0;
    }
    return sucess;
}

int saveAsText_maxID(FILE *pFile, LinkedList *pArrayListKnightZodiac,
		int *maxID) {
	KnightZodiac *KnightZodiac;

    int ID;
    int len_LL;
    int sucess = 0;
    int biggerID;
    int flag = 0;

	if (pFile != NULL && pArrayListKnightZodiac != NULL) {//si el archivo y el array no son null..
		len_LL = ll_len(pArrayListKnightZodiac);// obtengo el tamanho del array.

        for(int i=0; i<len_LL; i++){	// recorro el array.
			KnightZodiac = ll_get(pArrayListKnightZodiac, i);// copio la estructura del empleado del indice.
			KnightZodiac_getHigherID(KnightZodiac, &ID);//obtengo toda la info del empleado.
            if(flag==0 || ID>biggerID){
            	biggerID = ID;
            	flag=1;
            }
            sucess = 1;
        }
    }
    *maxID = biggerID;
    return sucess;
}

int controller_saveAsTextMaxID(FILE *pFile, char *path,
		LinkedList *pArrayListKnightZodiac) {
    int sucess = 0;
    int maxID;

	if (pFile != NULL
			&& saveAsText_maxID(pFile, pArrayListKnightZodiac, &maxID)) { //si el archivo no es null y pude escribir, retorno 1
        sucess = 1;
        fprintf(pFile,"%d\n",maxID+1);	//escribo los datos de cada empleado en el archivo.
    }
    return sucess;
}
