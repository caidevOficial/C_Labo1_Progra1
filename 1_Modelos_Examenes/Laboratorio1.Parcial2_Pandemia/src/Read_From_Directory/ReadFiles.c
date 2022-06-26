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

#include "../Read_From_Directory/ReadFiles.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>


void error(const char *s){
  /* perror() devuelve la cadena S y el error (en cadena de caracteres) que tenga errno */
  perror(s);
}

void processFile(char *archivo){
  /* Al procesar el archivo imprimo tamano en Bytes, KiloBytes, MegaBytes o Gigabytes */
  FILE *fich;
  double ftam;
  char peso[20];

  fich=fopen(archivo, "r");
  if (fich){
      fseek(fich, 0L, SEEK_END);
      ftam=ftell(fich);
      if(ftam<1024){
    	  strcpy(peso,"Bytes");
      }else{
    	  ftam/=1024;
    	  strcpy(peso,"KiloBytes");
    	  if(ftam>1024){
    		  ftam/=1024;
    		  strcpy(peso,"MegaBytes");
    		  if(ftam>1024){
    	    	 ftam/=1024;
    	    	 strcpy(peso,"GigaBytes");
    		  }
    	  }
      }
      fclose(fich);
      /* Si va bien, imprime el Nombre, tamanho y tipo de peso. */
      printf ("    [%-23s] [%06.2f] [%-10s]\n", archivo, ftam,peso);
  }else{
    /* Si falla, solo imprime el nombre. */
    printf ("    [%-23s] (No info.)\n", archivo);
  }
}

int Read_Directory(){
	int success = 0;
	DIR *dir; // Puntero a dir para abrir el directorio actual.
	struct dirent *ent; // Guardo la info de cada archivo que leo.
	dir = opendir("."); // Leo el directorio actual.

	if (dir == NULL){ /* Chequeo que no haya error */
		error("No puedo abrir el directorio");
	}else{
		printf("\n    __________________________________________________\n"
		"    [Message] Archivos actuales en el directorio ROOT:\n"
		"    __________________________________________________\n");
		while ((ent = readdir (dir)) != NULL){
		  /* Simulo comando ls para listar directorio actual y anterior */
		  if((strcmp(ent->d_name, ".")) &&
			 (strcmp(ent->d_name, "..")) &&
			 (strcmp(ent->d_name, "src")) &&
			 (strcmp(ent->d_name,"Debug"))){
			 //Proceso archivos sin contar la carpeta src ni Debug.
			 processFile(ent->d_name); // Obtengo el nombre del archivo y lo proceso.
		  }
	  }
	  printf("    __________________________________________________\n"
	  "\n");
	  closedir (dir);
	  success = 1;
	}

  return success;
}
