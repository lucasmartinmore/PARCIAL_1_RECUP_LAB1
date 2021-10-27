/*
 * cliente.c
 *
 *  Created on: 22 oct. 2021
 *      Author: ACantarini
 */
#include "cliente.h"

int menu()
{
    system("cls");
	int opcion;
	opcion=validarEntero("1)ALTA CLIENTE\n2)MODIFICAR CLIENTE\n3)BAJA CLIENTE\n4)CREAR PEDIDO\n5)PROCESAR RESIDUO\n6)IMPRIMIR CLIENTE CON PP\n7)IMPRIMIR PEDIDOS PEND\n8)IMPRIMIR PEDIDOS PROC\n9)IMP PP POR LOCALIDAD\n10)CANT PROMEDIO PP\n11)CLIENTE CON MAS P.P\n12)CLIENTE CON MAS P.PROC\n13)CLIENTE CON MAS PEDIDOS\n\n\nIngrese opcion: \n", "Opcion invalidad, reingrese opcion: \n", 1, 13);
	return opcion;
}

void inicializarCliente(eCliente clientes[], int tamCliente)
{
    if(clientes!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			clientes[i].isEmpty=0;
			clientes[i].acumuladorPC=0;
			clientes[i].acumuladorPP=0;
		}
	}
}

int buscarPosicionVaciaCliente(eCliente clientes[], int tamCliente, int* posicion)
{
    int error;
	error=-1;
	*posicion=-1;
	if(clientes!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==0)
			{
				*posicion=i;
				error=0;
				break;
			}
		}
	}
	return error;
}

int altaCliente(eCliente clientes[], eLocalidad localidades[], int tamLocalidad, int posicion, int id)
{
	system("cls");
	printf("*****MENU ALTA*****\n");
    int error;
    error=1;
	if(clientes!=NULL && posicion!=-1)
	{
		validarCadena("Ingrese nombre de la empresa: \n","Nombre invalido, reingrese nuevamente: \n", 50,clientes[posicion].nombreEmpresa);
		validarCadena("Ingrese nombre de la direccion de la empresa: \n","Direccion invalida, reingrese nuevamente: \n", 50,clientes[posicion].calle);
		clientes[posicion].numeroCalle=validarEntero("Ingrese numero de la direccion empresa: \n","Direccion numerica invalida, reingrese nuevamente: \n", 1, 9999);
		mostrarLocalidades(localidades, tamLocalidad);
		clientes[posicion].idLocalidad=validarEntero("Ingrese id de la localidad correspondiente: \n", "Id invalido, reingrese nuevamente: \n", 1, 10);
		clientes[posicion].cuit=validarEntero("Ingrese CUIT de la empresa: \n","CUIT invalido, reingrese nuevamente: \n", 1, 99999);
		clientes[posicion].idCliente=id;
		clientes[posicion].isEmpty=1;
		error=0;
    }
	return error;
}


int buscarCliente(eCliente clientes[], int tamCliente, int id)
{
	int posicion=-1;
	if(clientes!=NULL && tamCliente>0 && id>99)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].idCliente==id && clientes[i].isEmpty==1)
			{
				posicion=i;
				break;
			}
		}
	}
	return posicion;
}

void mostrarCliente(eCliente cliente, eLocalidad localidades[], int tamLocalidad)
{
	for(int i=0; i<tamLocalidad; i++)
	{
		if(cliente.idLocalidad==localidades[i].idLocalidad)
		{
			printf("ID   NOMBRE   CUIT   DIRECCION   LOCALIDAD\n");
			printf("------------------------------------------\n");
			printf("%3d %8s %6d %7s %4d %10s\n",cliente.idCliente,cliente.nombreEmpresa,
			cliente.cuit,cliente.calle,cliente.numeroCalle,localidades[i].nombre);
			printf("------------------------------------------\n");
			break;
		}
	}
}

int mostrarClientes(eCliente clientes[], int tamCliente, eLocalidad localidades[], int tamLocalidades)
{
	int error=-1;
	if(clientes!=NULL && tamCliente>0 && localidades!=NULL && tamLocalidades>0)
	{
		system("cls");
		printf("-----------LISTADO DE CLIENTES------------\n\n");
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				mostrarCliente(clientes[i], localidades, tamLocalidades);
				error=0;
			}
		}
	}
	return error;
}

int bajaCliente(eCliente clientes[], int tamCliente, eLocalidad localidades[], int tamLocalidades)
{
	system("cls");
	printf("*****MENU BAJA*****\n");
	int id;
	int posicion;
	int confirmar;
	int error;
	error=-1;

	if(clientes!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				mostrarCliente(clientes[i], localidades, tamLocalidades);
			}
			else
			{
				printf("****NO SE REGISTRARON CLIENTES!*****\n");
				break;
			}
		}
	}

	id=validarEntero("\nIngrese numero de id: \n", "Error, reingrese id: \n", 100, 999);
	posicion=buscarCliente(clientes, tamCliente, id);

	if(posicion!=-1)
	{
		confirmar=validarEntero("\nDesea confirmar eliminacion del cliente (1)SI 2)NO: \n", "Opcion invalida, reingrese: \n", 1, 2);
		if(confirmar==1)
		{
			clientes[posicion].isEmpty=0;
			clientes[posicion].idCliente=' ';
			error=0;
		}
		else
		{
			printf("BAJA CANCELADA\n");
		}

	}
	else
	{
		printf("ID NO ENCONTRADO\n");
	}
	return error;

}

int subMenuModificarCliente()
{
	system("cls");
	int opcion;
	printf("*****MENU MODIFICAR*****\n");
	opcion=validarEntero("1)Direccion\n2)Localidad\n\nIngrese opcion a modificar: \n", "Opcion invalidad, reingrese opcion: \n", 1, 2);
	return opcion;
}

void modificarCliente(eCliente clientes[], int tamCliente, eLocalidad localidades[], int tamLocalidades)
{
	system("cls");
	printf("*****MENU MODIFICAR*****\n");
	int id;
	int posicion;
	char auxNombreDireccion[50];

	if(clientes!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				mostrarCliente(clientes[i], localidades, tamLocalidades);
			}
			else
			{
				printf("****NO SE REGISTRARON CLIENTES!*****\n");
				break;
			}
		}

		id=validarEntero("\nIngrese numero de id: \n", "Error, reingrese id: \n", 100, 999);
		posicion=buscarCliente(clientes, tamCliente, id);

		if(posicion!=-1)
		{
			switch(subMenuModificarCliente())
			{
			case 1:
				validarCadena("Ingrese nuevo nombre de la direccion de la empresa: \n","Direccion invalida, reingrese nuevamente: \n", 50,auxNombreDireccion);
				strcpy(clientes[posicion].calle,auxNombreDireccion);
				clientes[posicion].numeroCalle=validarEntero("Ingrese nuevo numero de la direccion empresa: \n","Direccion numerica invalida, reingrese nuevamente: \n", 1, 9999);
				printf("DIRECCION MODIFICADA EXITOSAMENTE!\n");
				break;
			case 2:
				mostrarLocalidades(localidades, tamLocalidades);
				clientes[posicion].idLocalidad=validarEntero("Ingrese id de la nueva localidad correspondiente: \n", "Id invalido, reingrese nuevamente: \n", 1, 10);
				printf("LOCALIDAD MODIFICADA EXITOSAMENTE!\n");
				break;
			}
		}
		else
		{
			printf("ID NO ENCONTRADO\n");
		}
	}
}



