/*
 * pedido.c
 *
 *  Created on: 24 oct. 2021
 *      Author: ACantarini
 */
#include "pedido.h"

void inicializarPedido(ePedido pedidos[], int tamPedido)
{
	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			pedidos[i].isEmpty=0;
		}
	}
}

int buscarPosicionVaciaPedido(ePedido pedidos[], int tamPedido, int* posicion)
{
	int error;
	error=-1;
	*posicion=-1;
	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			if(pedidos[i].isEmpty==0)
			{
				*posicion=i;
				error=0;
				break;
			}
		}
	}
	return error;
}

int buscarPedido(ePedido pedidos[], int tamPedido, int id)
{
	int posicion=-1;
	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			if(pedidos[i].idPedido==id && pedidos[i].isEmpty==1)
			{
				posicion=i;
				break;
			}
		}
	}
	return posicion;
}

int crearPedido(eCliente clientes[], int tamCliente,eLocalidad localidades[], int tamLocalidad,ePedido pedidos[],int id, int posicion)
{
	int error;
	int idIngresado;
	int posicionEncontrada;
	int cantidadKilos;

	error=-1;
	if(clientes!=NULL && pedidos!=NULL && localidades!=NULL && tamCliente>0 && tamLocalidad>0)
	{
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				mostrarCliente(clientes[i], localidades, tamLocalidad);
			}
			else
			{
				printf("****NO SE REGISTRARON CLIENTES!*****\n");
				break;
			}
		}

		idIngresado=validarEntero("\nIngrese numero de id: \n", "Error, reingrese id: \n", 100, 999);
		posicionEncontrada=buscarCliente(clientes, tamCliente, idIngresado);

		if(posicionEncontrada!=-1)
		{
			cantidadKilos=validarEntero("Ingrese cantidad de kilos totales a recolectar: \n","Error, reingrese nuevamente: \n", 1, 9999);
			pedidos[posicion].KilosTotalRecoleccion=cantidadKilos;
			pedidos[posicion].idCliente=idIngresado;
			strcpy(pedidos[posicion].estado, "Pendiente");
			pedidos[posicion].idPedido=id;
			pedidos[posicion].isEmpty=1;
			clientes[posicionEncontrada].acumuladorPP++;
			error=0;
		}
		else
		{
			printf("ID NO ENCONTRADO\n");
		}
	}
	return error;
}

void mostrarPedido(ePedido pedido)
{
	if(strcmp(pedido.estado,"Pendiente")==0)
	{
		system("cls");
		printf("------------------------------------\n");
		printf("ID PED    KILOS    ESTADO    ID CLIE\n");
		printf("------------------------------------\n");
		printf("%4d      %3d      %5s    %3d\n",pedido.idPedido,pedido.KilosTotalRecoleccion,
		pedido.estado,pedido.idCliente);
	}
}

void mostrarPedidos(ePedido pedidos[], int tamPedido)
{
	if(pedidos!=NULL && tamPedido>0)
	{
		for(int i=0; i<tamPedido; i++)
		{
			if(pedidos[i].isEmpty==1 && strcmp(pedidos[i].estado,"Pendiente")==0)
			{
				mostrarPedido(pedidos[i]);
			}
		}
	}
}

int subMenuTipo()
{
	int opcion;
	opcion=validarEntero("1)HDPE\n2)LDPE\n3)PP\n4)OTROS\n\nIngrese tipo de plastico: \n", "Opcion invalidad, reingrese opcion: \n", 1, 4);
	return opcion;
}

void pedidoCompletado(eCliente clientes[], int tamCliente,ePedido pedidos[], int tamPedido,int kilosIngresados, int posicionEncontrada)
{
    strcpy(pedidos[posicionEncontrada].estado,"Completado");

    for(int j=0; j<tamCliente; j++)
    {
        if(pedidos[posicionEncontrada].idCliente==clientes[j].idCliente)
	    {
	        clientes[j].acumuladorPP--;
	     	clientes[j].acumuladorPC++;
		    break;
	    }
    }
}

int procesarResiduos(ePedido pedidos[], int tamPedidos,eCliente clientes[],int tamCliente)
{
	int error;
	int posicionEncontrada;
	int idIngresado;
	int kilosIngresados;
    int opcion;
	error=-1;

	if(pedidos!=NULL && tamPedidos>0)
	{
		for(int i=0; i<tamPedidos; i++)
		{
			if(pedidos[i].isEmpty && strcmp(pedidos[i].estado, "Pendiente")==0)
			{
				mostrarPedido(pedidos[i]);
			}
		}

		idIngresado=validarEntero("\nIngrese numero del id pedido: \n", "Error, reingrese id: \n", 1000, 2000);
		posicionEncontrada=buscarPedido(pedidos, tamPedidos, idIngresado);

		if(posicionEncontrada!=-1)
		{
			kilosIngresados=validarEntero("Ingrese cantidad de kilos a procesar: \n", "Error, reingrese cantidad: \n", 1, 9999);
			if(kilosIngresados==pedidos[posicionEncontrada].KilosTotalRecoleccion)
			{
				opcion=subMenuTipo();
				switch(opcion)
				{
				case 1:
					pedidoCompletado(clientes, tamCliente, pedidos, tamPedidos, kilosIngresados, posicionEncontrada);
				    pedidos[posicionEncontrada].kilosHDPE=kilosIngresados;
				    pedidos[posicionEncontrada].idTipoPlastico=1;
					error=0;
					break;
				case 2:
					pedidoCompletado(clientes, tamCliente, pedidos, tamPedidos, kilosIngresados, posicionEncontrada);
				    pedidos[posicionEncontrada].kilosLDPE=kilosIngresados;
				    pedidos[posicionEncontrada].idTipoPlastico=2;
				    error=0;
					break;
				case 3:
					pedidoCompletado(clientes, tamCliente, pedidos, tamPedidos, kilosIngresados, posicionEncontrada);
				    pedidos[posicionEncontrada].kilosPP=kilosIngresados;
				    pedidos[posicionEncontrada].idTipoPlastico=3;
					error=0;
					break;
				}
			}
			else
			{
				printf("CANTIDAD DE KILOS MAYOR O DISTINTO DE LO REGISTRADO\n");
			}
		}
		else
		{
			printf("ID NO ENCONTRADO\n");
		}
	}
	return error;
}

void mostrarClienteConPP(eCliente cliente, eLocalidad localidades[], int tamLocalidad)
{
	for(int i=0; i<tamLocalidad; i++)
	{
		if(cliente.idLocalidad==localidades[i].idLocalidad)
		{
			printf("%3d %8s %6d %7s %4d %10s  %2d\n",cliente.idCliente,cliente.nombreEmpresa,
			cliente.cuit,cliente.calle,cliente.numeroCalle,localidades[i].nombre,cliente.acumuladorPP);
			printf("------------------------------------------\n");
			break;
		}
	}
}

void mostrarClientesConPP(eCliente clientes[], int tamCliente, eLocalidad localidades[], int tamLocalidad)
{
	if(clientes!=NULL && localidades!=NULL && tamCliente>0 && tamLocalidad>0)
	{
		system("cls");
		printf("-----LISTADO DE CLIENTES CON PEDIDOS PENDIENTES-----\n\n");
		printf("ID   NOMBRE   CUIT   DIRECCION   LOCALIDAD  PED PEND\n");
		printf("----------------------------------------------------\n");
		for(int i=0; i<tamCliente; i++)
		{
			if(clientes[i].isEmpty==1)
			{
				mostrarClienteConPP(clientes[i], localidades, tamLocalidad);
			}
			else
			{
				printf("****NO SE REGISTRARON CLIENTES!*****\n");
				break;
			}
		}
	}
}

int mostrarPedidosPendienteConCliente(ePedido pedidos[],int tamPedidos, eCliente clientes[], int tamClientes)
{
	int error;
	error=-1;
	if(pedidos!=NULL && clientes!=NULL && tamClientes>0 && tamPedidos>0)
	{
		printf("******PEDIDOS PENDIENTE INFORMACION******\n");
		printf("-----------------------------------------\n");
		printf("ID PED    ESTADO   CANT   CUIT    DIRECCION\n");
		printf("-----------------------------------------\n");
		for(int i=0; i<tamPedidos; i++)
		{
			if(pedidos[i].isEmpty==1 && strcmp(pedidos[i].estado, "Pendiente")==0)
			{
				for(int j=0; j<tamClientes; j++)
				{
					if(pedidos[i].idCliente==clientes[j].idCliente)
					{
						printf("%2d    %7s  %2d   %4d %8s %4d\n",pedidos[i].idPedido,pedidos[i].estado,
						pedidos[i].KilosTotalRecoleccion,clientes[j].cuit,clientes[j].calle,clientes[j].numeroCalle);
						printf("-----------------------------------------\n");
						error=0;
					}
				}
			}
		}
	}
	return error;
}

int mostrarPedidosCompletadosConCliente(ePedido pedidos[], int tamPedidos, eCliente clientes[], int tamClientes)
{
	int error;
	error=-1;
	if(pedidos!=NULL && clientes!=NULL && tamClientes>0 && tamPedidos>0)
	{
		printf("******PEDIDOS COMPLETOS INFORMACION******\n");
		printf("-----------------------------------------\n");
		printf("ID PED    ESTADO   CANT   CUIT    DIRECCION\n");
		printf("-----------------------------------------\n");
		for(int i=0; i<tamPedidos; i++)
		{
			if(pedidos[i].isEmpty==1 && strcmp(pedidos[i].estado, "Completado")==0)
			{
				for(int j=0; j<tamClientes; j++)
				{
					if(pedidos[i].idCliente==clientes[j].idCliente)
					{
						printf("%2d    %7s  %2d   %4d %8s %4d\n",pedidos[i].idPedido,pedidos[i].estado,
						pedidos[i].KilosTotalRecoleccion,clientes[j].cuit,clientes[j].calle,clientes[j].numeroCalle);
						printf("-----------------------------------------\n");
						error=0;
					}
				}
			}
		}
	}
	return error;
}
