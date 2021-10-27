/*
 * localidad.c
 *
 *  Created on: 22 oct. 2021
 *      Author: ACantarini
 */
#include "localidad.h"

void mostrarLocalidades(eLocalidad localidades[], int tam)
{
	if(localidades!=NULL && tam>0)
	{
		system("cls");
		printf("*****LISTADO LOCALIDADES*****\n");
		printf("------------------------------------------\n");
		printf("ID   LOCALIDADES\n");
		printf("------------------------------------------\n");
		for(int i=0; i<tam; i++)
		{
			printf("%2d   %7s\n",localidades[i].idLocalidad,localidades[i].nombre);
			printf("------------------------------------------\n");
		}
	}
}
