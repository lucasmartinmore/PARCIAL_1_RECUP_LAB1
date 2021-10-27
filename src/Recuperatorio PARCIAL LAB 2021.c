/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : Lucas More
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "pedido.h"
#include "informe.h"
//TAMAÑO DE MIS ESTRUCT
#define TAM_LOCALIDAD 10
#define TAM_CLIENTE 100
#define TAM_PEDIDO 1000

int main(void) {

    setbuf(stdout,NULL);
	int seguir=1;

	//DATOS HARDCODEADOS
	eLocalidad localidades[TAM_LOCALIDAD]=
	{
	{1,"PalermoBA",1},
	{2,"Colegiales",1},
	{3,"Caballito",1},
	{4,"Vte Lopez",1},
	{5,"Monserrat",1},
	{6,"San isidro",1},
	{7,"FloresBA",1},
	{8,"PachecoBA",1},
	{9,"Chacarita",1},
	{10,"OtrosBA",1},
	};

	//DATOS HARDCODEADOS
	eCliente clientes[TAM_CLIENTE]=
	{
	{100,"Lasam",11111,"Saenz",795,2,0,0,1},
	{101,"Novuk",22222,"Lopez",183,5,0,0,1},
	{102,"Ñekey",33333,"Casal",248,5,0,0,1},
	{103,"Xefat",44444,"Peñol",924,9,0,0,1},
	{104,"Sorid",55555,"Pilas",359,3,0,0,1},
	{105,"Vucan",66666,"Porte",864,1,0,0,1},
	{106,"Yofur",77777,"Cilas",963,6,0,0,1},
	{107,"Sefoz",88888,"Olmes",123,7,0,0,1},
	{108,"Giseb",99999,"Rubik",995,8,0,0,1},
	};

	//VARIABLES CLIENTES
	//inicializarCliente(clientes, TAM_CLIENTE);
	int buscarPosicionLibreCliente;
	int posicionLibreEncontradaCliente;
	int idCliente=100;

	ePedido pedidos[TAM_PEDIDO];
	//VARIABLES PEDIDOS
	//inicializarPedido(pedidos, TAM_PEDIDO);
	int buscarPosicionLibrePedido;
	int posicionLibreEncontradaPedido;
	int idPedido=1000;
	int contadorMaximoPedidosPendientes;
	int contadorMaximoPedidosProcesados;

	do
	{
		switch(menu())
		{
		case 1:
			buscarPosicionLibreCliente=buscarPosicionVaciaCliente(clientes, TAM_CLIENTE, &posicionLibreEncontradaCliente);
			if(buscarPosicionLibreCliente!=-1)
			{
				if(altaCliente(clientes, localidades, TAM_LOCALIDAD, posicionLibreEncontradaCliente, idCliente)!=-1)
				{
					printf("Carga de Cliente exitosa\n");
					idCliente++;
				}
			}
			else
			{
				printf("No se encuentra espacio libre!\n");
			}
			system("pause");
			break;
		case 2:
			modificarCliente(clientes, TAM_CLIENTE, localidades, TAM_LOCALIDAD);
			system("pause");
			break;
		case 3:
			if(bajaCliente(clientes, TAM_CLIENTE, localidades, TAM_LOCALIDAD)==0)
			{
				printf("Baja de cliente exitosa!\n");
			}
			system("pause");
			break;
		case 4:
			buscarPosicionLibrePedido=buscarPosicionVaciaPedido(pedidos, TAM_PEDIDO, &posicionLibreEncontradaPedido);
			if(buscarPosicionLibrePedido!=-1)
			{
				if(crearPedido(clientes, TAM_CLIENTE, localidades, TAM_LOCALIDAD, pedidos, idPedido, posicionLibreEncontradaPedido)!=-1)
				{
					printf("Carga de Pedido exitosa\n");
					idPedido++;
				}
			}
			else
			{
				printf("No se encuentra espacio libre!\n");
			}
			system("pause");
			break;
		case 5:
			if(procesarResiduos(pedidos, TAM_PEDIDO, clientes, TAM_CLIENTE)!=-1)
			{
				printf("Carga procesada exitosa!\n");
			}
			system("pause");
			break;
		case 6:
			mostrarClientesConPP(clientes, TAM_CLIENTE, localidades, TAM_LOCALIDAD);
			system("pause");
			break;
		case 7:
			if(mostrarPedidosPendienteConCliente(pedidos, TAM_PEDIDO, clientes, TAM_CLIENTE)==-1)
			{
				printf("*****NO SE CARGO NINGUN PEDIDO!*****\n");
			}
			system("pause");
			break;
		case 8:
			if(mostrarPedidosCompletadosConCliente(pedidos, TAM_PEDIDO, clientes, TAM_CLIENTE)==-1)
			{
				printf("*****NO SE PROCESO NINGUN PEDIDO!*****\n");
			}
			system("pause");
			break;
		case 9:
			if(mostrarPedidosPorLocalidad(localidades, TAM_LOCALIDAD, pedidos, TAM_PEDIDO, clientes, TAM_CLIENTE)!=0)
			{
				printf("*****NO SE ENCONTRO NINGUN PP DE LA LOCALIDAD INGRESADA!*****\n");
			}
			system("pause");
			break;
		case 10:
			cantidadPoplipropilenoxCliente(pedidos, TAM_PEDIDO);
			system("pause");
			break;
		case 11:
			contadorMaximoPedidosPendientes=buscarClienteConMasPP(clientes, TAM_CLIENTE);
			mostrarClienteConMasPP(clientes, TAM_CLIENTE, localidades, TAM_LOCALIDAD, contadorMaximoPedidosPendientes);
			system("pause");
			break;
		case 12:
			contadorMaximoPedidosProcesados=buscarClienteConMasPC(clientes, TAM_CLIENTE);
			mostrarClienteConMasPC(clientes, TAM_CLIENTE, localidades, TAM_LOCALIDAD, contadorMaximoPedidosProcesados);
			system("pause");
			break;
		case 13:
			mostrarClienteConMasPPyPC(pedidos, TAM_PEDIDO, clientes, TAM_CLIENTE, localidades, TAM_LOCALIDAD);
			system("pause");
			break;
		}

	}while(seguir==1);

	return EXIT_SUCCESS;
}
