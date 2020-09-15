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
 * Version     : 1.1.1 [Release Candidate v1.1]
 *
 * @author	CaiDev - FacuFalcone
 * ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "caidevEstructuras.h"
#include "caidevValidate.h"
//#include "caidevDataWareHouse.h"
#include "Empleado.h"
#include "Sector.h"


char menuInforme(){
	char opcionMenu;
	printf("\n INFORME EMPLEADOS ");
	printf("\nQue desea informar? ");
	printf("\n [A] Listar Empleado por anho."
			"\n [B] Listar Empleadas."
			"\n [C] Total sueldos."
			"\n [D] Informe D"
			"\n [E] Informe E"
			"\n [F] Informe Mayor Sueldo por sector"
			"\n [G] Informe Empleado Mas Costoso"
			"\n [H] Aumentar Sueldos"
			"\n [I] Informar Sector Mas Costoso."
			"\n [J] Informar sueldo por sector."
			"\n [K] Informe K"
			"\n [L] SALIR");
	fflush(stdin);
	scanf("%c",&opcionMenu);
	opcionMenu = tolower(opcionMenu);

	return opcionMenu;
}

int informes(eEmpleado vec[], char opcion, int tam, eSector sectores[], int tamSec){
	int retorno = 0;
	char seguir = 's';

	do{
		switch(opcion){
		case 'a':
			printf(" \n[A] Listar Empleado por anho");
			listarEmpleadosPorAnio(vec,tam,sectores,tamSec);
			break;
		case 'b':
			printf(" \n[B] Listar Empleadas");
			listarEmpleadasMujeres(vec, tam, sectores, tamSec);
			break;
		case 'c':
			printf(" \n[C] Total sueldos");
			informarTotalSueldos(vec,tam);
			break;
		case 'd':
			printf(" \n[D] Informe D");
			break;
		case 'e':
			printf(" \n[E] Informe E");
			break;
		case 'f':
			printf(" \n[F] Informe Mayor Sueldo por sector");
			informarMayorSueldoSector(vec, tam, sectores, tamSec);
			break; //
		case 'g':
			printf(" \n[G] Informe Empleado Mas Costoso.");
			informarEmpleadoCostosoSector(vec, tam, sectores,tamSec);
			break;
		case 'h':
			printf(" \n[H] Aumentar Sueldos.");
			aumentarSueldosSector(vec,tam,sectores,tamSec);
			break;
		case 'i':
			printf(" \n[I] Informar Sector Mas Costoso.");
			informarSectorCostoso(vec,tam,sectores,tamSec);
			break;
		case 'j':
			printf(" \n[J] Informar sueldo por sector.");
			informarTotalSueldoPorSector(vec,tam,sectores,tamSec);
			break;
		case 'k':
			printf(" \n[K] Cantidad Empleados por sectores.");
			cantidadEmpleadosPorSector(vec,tam,sectores,tamSec);
			break;
		case 'l':
			printf(" \n[K] Empleados Mas Joven/es.");
			informeEmpleadoMasJoven(vec,tam,sectores,tamSec);
			break;
		case 'm':
			seguir = 'n';
			break;
		default:
			break;
		}
		system("pause");
	}while(seguir=='s');
	return retorno;
}

void informarTotalSueldos(eEmpleado vec[], int tam){
	float totalSueldo = 0;
	system("cls");
	printf("** total sueldos **\n\n");
	for (int i=0; i<tam;i++){
		if (vec[i].isEmpty == 0){
			totalSueldo = totalSueldo + vec[i].sueldo;
		}
	}
	printf("El total de sueldos es $ %.2f", totalSueldo);
}

void informarEmpleadosDeSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int idSector;
    int hayEmpleadosEnSector = 0;
    char nombreSector[20] ;

    system("cls");
    printf("** Listado de empleados por sector **\n\n");
    listarSectores(sectores, tamsec);
    printf("\n Ingrese id del sector:");
    scanf("%d", &idSector);
    cargarDescripcionSector(nombreSector, idSector, sectores, tamsec);
    printf("\nEmpleados Sector %s \n\n ", nombreSector);
    printf("   Id       Nombre        Sexo        Edad     Sueldo     Fecha Ingreso    Sector\n");

    for (int i=0; i< tam; i++){
        if (vec[i].isEmpty == 0 && vec[i].idSector == idSector){
            mostrarEmpleado(vec[i],sectores, tamsec);
            hayEmpleadosEnSector = 1;
        }
    }

    if ( hayEmpleadosEnSector == 0){
        printf("\nNo hay empleados en el sector \n");
    }
}

void informarEmpleadosPorSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec){
	int flag;

	system("cls");
	printf("\n###################### Listado de empleados por Sector ######################## \n");

	for (int s = 0;s<tamSec;s++){
		//cargarDescripcionSector(nombreSector, s, sectores,tamSec);
		flag = 0;
		printf("\n ###### Empleados Sector: %10s",sectores[s].descripcion);
		printf("\n   Id       Nombre        Sexo        Edad     Sueldo     FechaIngreso    Sector     NomSector");
		for (int e = 0;e<tam;e++){
			if (vec[e].isEmpty==0 && vec[e].idSector == sectores[s].id){
				mostrarEmpleado(vec[e], sectores,tamSec);
				flag = 1;
			}
		}
		if (flag==0){
			printf("\nNo hay empleados en el sector");
		}
		printf("\n\n");
	}
}

void informarMayorSueldoSector(eEmpleado vec[], int tam, eSector sectores[], int tamSec){
	float mayorSueldo = 0;
	int sector;
	char nombreSector[20];
	int contador = 0;
	system("cls");
	printf("\n###################### Listado de empleados por Sector ######################## \n");
	listarSectores(sectores,tamSec);
	printf("ingrese sector");
	scanf("%2d",&sector);

	cargarDescripcionSector(nombreSector, sector, sectores,tamSec);

	for (int e = 0; e<tamSec;e++){
		if (vec[e].isEmpty==0 && vec[e].idSector == sector){
			if (mayorSueldo < vec[e].sueldo || contador == 0){
				mayorSueldo = vec[e].sueldo;
				contador++;
			}
		}
	}
	printf("\n ###### Mayor Sueldo Sector %10s es $ %.2f",nombreSector,mayorSueldo);
}

/* Practicar un informe
 * 1 - informar el o los empleados que mas ganan de un sector
 * (todos sus datos).
 * 2 - aumentar sueldo sector. (se pide el sector y se aumenta por porcentaje segun el input 10,20,30 etc).
 * 2.5 Informe total sueldos por sector (todos con su total de sueldo).
 * 3 - informar sector costoso (dennota el nombre del sector donde mas se paga sueldos [la suma del sueldo de empleados]).
 * 4 - cantidad de empleados por sector.
 * 5 - informa empleado joven de un sector.
 * */


// Ejercicio 1
void informarEmpleadoCostosoSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int idSector;
    float mayorSueldo =0;
    char nombreSector[20] ;
    int hayEmpleados=0;

    system("cls");
    printf("**  Empleados que más cobran de un sector  **\n\n");
    listarSectores(sectores, tamsec);
    printf("\n Ingrese id del sector:");
    scanf("%d", &idSector);
    cargarDescripcionSector(nombreSector, idSector, sectores, tamsec);

    for (int i=0; i< tam; i++){
        if (vec[i].isEmpty == 0 && vec[i].idSector == idSector){
            if ( vec[i].sueldo > mayorSueldo || hayEmpleados == 0){
                mayorSueldo = vec[i].sueldo;
               hayEmpleados =1;
            }
        }
    }
    if (hayEmpleados){
        printf("\nEl mayor sueldo del sector %s es $%.2f y lo cobran: \n\n ", nombreSector, mayorSueldo);
        printf("     ID    Nombre    Sexo    Edad    Sueldo    FechaIngreso    Sector");
        for (int i=0; i< tam; i++){
            if ( vec[i].isEmpty == 0 && vec[i].idSector == idSector && vec[i].sueldo == mayorSueldo){
                mostrarEmpleado(vec[i], sectores, tamsec);
            }
        }
    }
    else{
        printf("No hay empleados en el sector %s\n\n", nombreSector);
    }

}

//Ejercicio 2
void aumentarSueldosSector(eEmpleado vec[],int tam,eSector sectores[], int tamsec){
	int idSector;
	float sueldoAumentado;
	float porcentaje;
	char nombreSector[20] ;
	int hayEmpleados=0;

	system("cls");
	printf("**  Aumentar Sueldos de un Sector  **\n\n");
	listarSectores(sectores, tamsec);
	printf("\n Ingrese id del sector:");
	scanf("%d", &idSector);
	printf("\n Ingrese porcentaje de aumento:");
	scanf("%f", &porcentaje);
	cargarDescripcionSector(nombreSector, idSector, sectores, tamsec);
	 for (int i=0; i< tam; i++){
		if (vec[i].isEmpty == 0 && vec[i].idSector == idSector){
			sueldoAumentado = vec[i].sueldo*(porcentaje/100);
			vec[i].sueldo += sueldoAumentado;
			hayEmpleados=1;
		}
	}
	if (hayEmpleados){
		printf("     Nuevos Sueldos");
		printf("     ID    Nombre    Sexo    Edad    Sueldo    FechaIngreso    Sector");
		for (int i=0; i< tam; i++){
			if ( vec[i].isEmpty == 0 && vec[i].idSector == idSector){
				mostrarEmpleado(vec[i], sectores, tamsec);
			}
		}
	}
	else{
		printf("No hay empleados a los que actualizar sueldos\n\n");
	}
}

//2.5 Informe total sueldos por sector (todos con su total de sueldo).
float obtenerTotalSueldosSector(int idSector, eEmpleado vec[], int tam){
	float sumaSueldos = 0;

	 for (int i=0; i< tam; i++){
		if (vec[i].isEmpty == 0 && vec[i].idSector == idSector){
			sumaSueldos += vec[i].sueldo;

		}
	}
	return sumaSueldos;
}

//3 - informar sector costoso (dennota el nombre del sector donde mas se paga sueldos [la suma del sueldo de empleados]).
void informarSectorCostoso(eEmpleado vec[],int tam, eSector sectores[], int tamsec){
	float sumaSueldoSector[tamsec];
	float mayorTotal;
	int flag = 0;

	system("cls");
	printf("Sector mas costoso\n\n");

	for (int s = 0;s<tamsec;s++){
		sumaSueldoSector[s] = obtenerTotalSueldosSector(sectores[s].id,vec,tam);
	}

	for(int i = 0;;i++){
		if (sumaSueldoSector[i] > mayorTotal || flag ==0){
			mayorTotal = sumaSueldoSector[i];
			flag=1;
		}
	}
	printf("El mayor gasto en sueldo es $%.2f y se realiza en el sector",mayorTotal);
	for(int i = 0;;i++){
		if (sumaSueldoSector[i] == mayorTotal){
			printf("%s\n",sectores[i].descripcion);
		}
	}
}

void informarTotalSueldoPorSector(eEmpleado vec[],int tam, eSector sectores[], int tamsec){
	int idSector;
	char nombreSector[20];
	float totalSueldo=0;

	system("cls");
	listarSectores(sectores,tamsec);
	printf("Ingrese sector: \n");
	scanf("%d",&idSector);
	totalSueldo = obtenerTotalSueldosSector(idSector,vec,tam);
	cargarDescripcionSector(nombreSector,idSector,sectores,tamsec);
	printf("El total de sueldo en %s es de $%.2f",nombreSector,totalSueldo);
}

void cantidadEmpleadosPorSector(eEmpleado vec[],int tam, eSector sectores[], int tamsec){
	//int flag;
	int cantidadEmpleados = 0;

	system("cls");
	printf("\n###################### Listado de empleados por Sector ######################## \n");

	for (int s = 0;s<tamsec;s++){
		//flag = 0;
		printf("\n ###### Empleados Sector: %10s",sectores[s].descripcion);
		for (int e = 0;e<tam;e++){
			if (vec[e].isEmpty==0 && vec[e].idSector == sectores[s].id){
				cantidadEmpleados++;
			}
		}

		printf("\n ###### Empleados Sector: %10s %d",sectores[s].descripcion,cantidadEmpleados);
		printf("\n\n");
	}
}

void informarEmpleadosXSector(eEmpleado vec[], int tam, eSector sectores[], int tamsec){
    int flag;
    system("cls");
    printf("*Listado de Empleados de todos los sectores*\n\n");

    for(int s=0; s < tamsec; s++){
        flag = 0;
        printf("Sector: %s\n", sectores[s].descripcion);
        printf("    Id        Nombre    Sexo   Edad   Sueldo   Fecha Ingreso   Sector\n\n");

        for(int e=0; e < tam; e++){
            if(vec[e].isEmpty == 0 && vec[e].idSector == sectores[s].id){
                mostrarEmpleado(vec[e], sectores, tamsec);
                flag = 1;
            }
        }
        if (flag ==0){
            printf("**Sin Empleados**\n");
        }
        printf("\n---------------------------------------------------------------------\n");
    }
    system("pause");
}

void informeEmpleadoMasJoven(eEmpleado vec[],int tam, eSector sectores[], int tamsec){
	int masJoven;
	int sector;
	char nombreSector[20];
	int contador = 0;
	system("cls");
	printf("\n###################### Informa Mas Joven de Sector ######################## \n");
	listarSectores(sectores,tamsec);
	printf("ingrese sector");
	scanf("%d",&sector);

	cargarDescripcionSector(nombreSector, sector, sectores,tamsec);

	for (int e = 0; e<tamsec;e++){
		if (vec[e].isEmpty==0 && vec[e].idSector == sector){
			if (masJoven > vec[e].edad || contador == 0){
				masJoven = vec[e].edad;
				contador++;
			}
		}
	}
	printf("\n ###### Mas Joven del Sector %10s es $ %d y pertenece a: \n",nombreSector,masJoven);
	for (int i = 0;i<tam;i++){
		if (vec[i].isEmpty==0 && vec[i].idSector == sector && vec[i].edad == masJoven){
			mostrarEmpleado(vec[i],sectores,tamsec);
		}
	}
}
