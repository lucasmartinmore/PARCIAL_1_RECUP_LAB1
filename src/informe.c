/*
 * informe.c
 *
 *  Created on: 26 oct. 2021
 *      Author: ACantarini
 */
#include "informe.h"

int mostrarPedidosPorLocalidad(eLocalidad localidades[], int tamLocalidad, ePedido pedidos[], int tamPedido, eCliente clientes[], int tamCliente)
{
	int error;
	int localidadIngresada;
	error=-1;
	if(pedidos!=NULL && clientes!=NULL && tamCliente>0 && tamPedido>0)
	{
		mostrarLocalidades(localidades, tamLocalidad);
		localidadIngresada=validarEntero("Ingrese id de la localidad correspondiente: \n", "Id invalido, reingrese nuevamente: \n", 1, 10);
		printf("*****PEDIDOS PENDIENTE POR LOCALIDAD*****\n");
		for(int i=0; i<tamCliente; i++)
		{
			for(int j=0; j<tamPedido; j++)
			{
				if(clientes[i].idLocalidad==localidadIngresada && pedidos[j].idCliente==clientes[i].idCliente)
				{
					//mostrarClienteConPP(clientes[i], localidades, tamLocalidad);
					mostrarPedido(pedidos[j]);
					error=0;
				}
			}
		}
	}
	return error;
}

int buscarClienteConMasPP(eCliente clientes[], int tamCliente)
{
	int flagMax=0;
	int cantidadMasAlta;

	if(clientes!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				if(flagMax==0 || clientes[i].acumuladorPP>cantidadMasAlta)
				{
					cantidadMasAlta=clientes[i].acumuladorPP;
					flagMax=1;
				}
			}
		}
	}
	return cantidadMasAlta;
}

void mostrarClienteConMasPP(eCliente clientes[], int tamCliente,eLocalidad localidades[], int tamLocalidad, int cantidadMasCliente)
{
	if(clientes!=NULL && tamCliente>0 && cantidadMasCliente>0)
	{
		printf("********CLIENTE/S CON MAS PED.PEND********\n");
		printf("------------------------------------------\n");
		printf("ID   NOMBRE   CUIT   DIRECCION   LOCALIDAD  PED PEND\n");
		printf("------------------------------------------\n");

		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].acumuladorPP==cantidadMasCliente)
			{
				mostrarClienteConPP(clientes[i], localidades, tamLocalidad);
			}
		}
	}
}

int buscarClienteConMasPC(eCliente clientes[], int tamCliente)
{
	int flagMax=0;
	int cantidadMasAlta;

	if(clientes!=NULL && tamCliente>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				if(flagMax==0 || clientes[i].acumuladorPC>cantidadMasAlta)
				{
					cantidadMasAlta=clientes[i].acumuladorPC;
					flagMax=1;
				}
			}
		}
	}
	return cantidadMasAlta;
}

void mostrarClienteConMasPC(eCliente clientes[], int tamCliente,eLocalidad localidades[], int tamLocalidad, int cantidadMasCliente)
{
	if(clientes!=NULL && tamCliente>0 && cantidadMasCliente>0)
	{
		printf("********CLIENTE/S CON MAS PED.COMP********\n");
		printf("------------------------------------------\n");
		printf("ID   NOMBRE   CUIT   DIRECCION   LOCALIDAD  PED COMP\n");
		printf("------------------------------------------\n");

		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].acumuladorPC==cantidadMasCliente)
			{
				mostrarClienteConPC(clientes[i], localidades, tamLocalidad);
			}
		}
	}
}

void mostrarClienteConPC(eCliente cliente, eLocalidad localidades[], int tamLocalidad)
{
	for(int i=0; i<tamLocalidad; i++)
	{
		if(cliente.idLocalidad==localidades[i].idLocalidad)
		{
			printf("%3d %8s %6d %7s %4d %10s  %2d\n",cliente.idCliente,cliente.nombreEmpresa,
			cliente.cuit,cliente.calle,cliente.numeroCalle,localidades[i].nombre,cliente.acumuladorPC);
			printf("------------------------------------------\n");
			break;
		}
	}
}

void cantidadPoplipropilenoxCliente(ePedido pedidos[], int tamPedido)
{
	int acumulador;
	int contador;
	float promedio;
	acumulador=0;
	contador=0;

	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			if(pedidos[i].isEmpty==1 && strcmp(pedidos[i].estado,"Completado")==0)
			{
				if(pedidos[i].idTipoPlastico)
				{
					acumulador=pedidos[i].kilosPP+acumulador;
					contador++;
				}
			}
		}
		if(contador!=0)
		{
			promedio=(float)acumulador/contador;
			printf("*****EL PRECIO PROMEDIO DE POLIPROPILENO ES %.2f KILOS*****\n",promedio);
		}
		else
		{
			printf("*****NO SE REGISTRO NINGUN RECICLADO DE POLIPROPILENO*****\n");
		}
	}
}

void mostrarClienteConMasPPyPC(ePedido pedidos[], int tamPedido, eCliente clientes[], int tamCliente, eLocalidad localidades[], int tamLocalidades)
{
	int clienteMasPC;
	int clienteMasPP;

	if(pedidos!=NULL && clientes!=NULL && localidades!=NULL && tamCliente>0 && tamPedido>0 && tamLocalidades>0)
	{
		clienteMasPC=buscarClienteConMasPC(clientes, tamCliente);
		clienteMasPP=buscarClienteConMasPP(clientes, tamCliente);
	}

	for(int i=0; i<tamCliente; i++)
	{
		if(clientes[i].acumuladorPC==clienteMasPC || clientes[i].acumuladorPP==clienteMasPP)
		{
			mostrarCliente(clientes[i], localidades, tamLocalidades);
		}
	}
}








