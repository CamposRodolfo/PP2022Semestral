//Semestral Principio de Programacion 2022;
//Rodolfo Campos 8-905-2179, Adriana Achurra 8-990-123;
//A:\Desktop\Semestral\PP2022Semestral\v1

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

//Constantes Globales          Puede cambiar el tamaño de las mesas y computadoras
#define MESAS 6
#define COMPUTADORAS 8
#define PERSONAS 20

//Declaracion de Funciones
int ImprimirLaboratorio(int mesas, int computadoras, int laboratorio[mesas][computadoras]);
int ValidarNumero(int n);
int Reservar(int mesas, int computadoras, int laboratorio[mesas][computadoras]);

//Listado de Acceso
char todasLasCedulas[PERSONAS][15]=
{
	"8-756-2131",
	"8-905-2179",
	"8-990-123",
	"8-996-1219",
	"20-5-7353",
	"8-1002-1756",
	"8-1095-516",
	"2-752-1519",
	"8-1012-1297",
	"8-1010-1697",
	"8-1004-172",
	"8-973-1067",
	"3-752-865",
	"8-996-518",
	"8-1006-298",
	"8-996-1793",
	"8-1001-2089",
	"8-1006-1899",
	"3-753-1582",
	"8-1001-1046"
};
	
char todosLosNombres[PERSONAS][15]=
{
	"Kexy",
	"Rodolfo",
	"Adriana",
	"Victor",
	"Sebastian",
	"Alexander",
	"Went",
	"Arantxa",
	"Paola",
	"Stefany",
	"Jeremiah",
	"Pedro",
	"Rodrigo",
	"Eynar",
	"Angel",
	"Mariangel",
	"Allan",
	"Denisse",
	"Jessica",
	"Moises"
};

char todosLosApellidos[PERSONAS][15]=
{
	"Rodriguez",
	"Campos",
	"Achurra",
	"Arrocha",
	"Olivera",
	"Camargo",
	"Chung",
	"Coronado",
	"Quiñones",
	"Gonzalez",
	"Kurmaty",
	"Lucero",
	"Molinar",
	"Morales",
	"Medina",
	"Santos",
	"Vega",
	"Zepeda",
	"Wong",
	"Delgado"
};

int main()
{
	//Declaracion de Variables
	int rodolfo, adriana, seleccion, mesa, computadora, laboratorio[MESAS][COMPUTADORAS], registro[PERSONAS][MESAS*COMPUTADORAS];
	
	//Valorando ArregloS
	for (rodolfo=0; rodolfo<MESAS; rodolfo++)
	{
		for (adriana=0; adriana<COMPUTADORAS; adriana++)
		{
			laboratorio[rodolfo][adriana] = 0;
		}
	}
	
	for (rodolfo=0; rodolfo<PERSONAS; rodolfo++)
	{
		for (adriana=0; adriana<MESAS*COMPUTADORAS; adriana++)
		{
			registro[rodolfo][adriana] = 0;
		}
	}
	
	//Ciclo Principal
	do
	{
		system("cls");
		printf("1. Ver los puestos de las computadoras ocupadas y disponibles.\n");
		printf("2. Reservar una computadora.\n");
		printf("3. Salir del laboratorio.\n");
		printf("4. Registro del uso del laboratorio.\n");
		printf("5. Ver el listado de los estudiantes autorizado para usar el laboratorio.\n");
		printf("6. Salir del sistema.\n\n");
		printf("Seleccion: ");
		scanf("%d", &seleccion);
		switch(seleccion)
		{
			case 1:
				system("cls");
				ImprimirLaboratorio(MESAS, COMPUTADORAS, laboratorio);
				printf("Presione cualquier tecla para regresar\n");
				system("PAUSE");
				break;
			case 2:
				Reservar(MESAS, COMPUTADORAS, laboratorio, registro);
				system("PAUSE");
				break;
			case 3:
				Cancelar(MESAS, COMPUTADORAS, laboratorio);
				system("PAUSE");
				break;
			case 4:
				printf("Presione cualquier tecla para regresar\n");
				system("PAUSE");
				break;
			case 5:
				ImprimirListado();
				system("PAUSE");
				break;
			case 6:
				printf("\n\033[33m>> fin. <<\033[0m");
				break;
			default:
				printf("\n\033[33m>> inserte un numero valido <<\033[0m\n");
				system("PAUSE");
		}
	}while (seleccion!=6);
	return 0;
}

int ImprimirLaboratorio(int mesas, int computadoras, int laboratorio[mesas][computadoras])  //Funcion para imprimir Las mesas y computadoras
{
	//Declaracion de Variables
	int m, c;
	
	//Bloque de Instrucciones
	printf("Tabla de puestos de computadoras disponibles.\n\n");
	
	for (m=0; m<mesas; m++)
	{
		printf(" Mesa %d:  \n ", m+1);
		for (c=0; c<computadoras; c++)
		{
			printf("_____________________");
		}
		printf("_\n");
		printf("| ");
		for (c=0; c<computadoras; c++)
		{
			printf("____________________ ");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf("  ___________   __  |");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf(" |           | |==| |");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf(" |     %d     | |--| |", c+1);
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf(" |___________| |  | |");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf("      | |      |--| |");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf("  ===========  |__| |");
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			if(laboratorio[m][c]==0)
			{	
				printf("  \033[32m Disponible \033[0m      |");
			}
			else if(laboratorio[m][c]>0)
			{
				printf(" \033[31m No Disponible \033[0m    |");
			}
		}
		printf("|\n||");
		for (c=0; c<computadoras; c++)
		{
			printf("____________________|");
		}
		printf("|\n|_");
		for (c=0; c<computadoras; c++)
		{
			printf("_____________________");
		}
		printf("|\n\n");
	}
}

int ValidarNumero(int n)  //Funcion para validar numero de entrada
{
	//Declaracion de Variable
	int i;
	
	//Bloque de Instrucciones
	do
	{	
		scanf("%d", &i);
		if (i<1 || i>n)
		{
			printf("No hay tal numero! Elige un numero entre el 1 al %d!\n", n);
		}
	} while (i<1 || i>n);
}

int VerificarCedula()  //Funcion para verficar acceso con cedula
{
	//Declaracion de Variables
	int i, buscar;
	char cedula[15];
	
	//Bloque de instrucciones
	printf("Ingrese su numero de cedula: ");
	scanf("%s", &cedula);
	for(i=0; i<PERSONAS; i++)
    {
    	buscar = strcmp(cedula, todasLasCedulas[i])+1;
        if(buscar == 1)
    	{
    		system("cls");
            printf("%s %s tiene Acceso Confirmado!\n\n", todosLosNombres[i], todosLosApellidos[i]);
            return i;
            //registro[i]++;
            break;
        }
        else
        {
        	printf("no tiene Acceso");
        	return 0;
		}
    }
}

int Reservar(int mesas, int computadoras, int laboratorio[mesas][computadoras], int registro[mesas][mesas*computadoras])  //Funcion para reservar computadora
{
	//Declaracion de variables
	int persona, mesa, computadora, seleccion;
	
	//Bloque de Instrucciones
	system("cls");
	do
	{
		persona=VerificarCedula();
		if(persona>1)
		{
			ImprimirLaboratorio(mesas, computadoras, laboratorio);
			printf("Para realizar una reserva, seleccione una mesa y una computadora.\n");
			printf("Ingrese el numero de mesa: ");
			mesa=ValidarNumero(mesas);
			printf("Ingrese el numero de computadora: ");
			computadora=ValidarNumero(computadoras);
			if (laboratorio[mesa-1][computadora-1] == 0)
			{
				registro [persona][((mesa-1)*computadora)+computadora]= 1;
				laboratorio[mesa-1][computadora-1] = mesa;
				printf("\n\nLa reserva fue exitosa!!\n");
				printf("Su lugar reservado es: mesa %d y computadora %d! \n\n", mesa, computadora);
			}
			else
			{
				printf("El lugar esta ocupado! ¡Elige otro!\n");	
			}
		}
		else
		{
			do
			{
				system("cls");
				printf("Usted no esta dentro de la lista de personas para realizar una reserva\n");
				printf("Desea volver a intentarlo?\n");
				printf("Digite 1 para si, 0 para salir: ");
				scanf("%d", &seleccion);
				if (seleccion<0 || seleccion>1)
				{
					printf("No hay tal numero! Elige un numero entre el 0 y 1!\n");
					system("PAUSE");
					
				}
			} while (seleccion<0 || seleccion>1);
			system("cls");
		}
	}while(seleccion==1);
	printf("Presione cualquier tecla para regresar\n");	
}
	
int Cancelar(int mesas, int computadoras, int laboratorio[mesas][computadoras])  //Funcion para cancelar reserva de computadora
{
	//Declaracion de variables
	int mesa, computadora, seleccion;
	
	//Bloque de Instrucciones
	system("cls");
	do
	{
		if(VerificarCedula()==1)
		{
			ImprimirLaboratorio(mesas, computadoras, laboratorio);
			printf("Para culminar una reserva, seleccione una mesa y una computadora.\n");
			printf("Ingrese el numero de mesa: ");
			mesa=ValidarNumero(mesas);
			printf("Ingrese el numero de computadora: ");
			computadora=ValidarNumero(computadoras);
			if (laboratorio[mesa-1][computadora-1] == mesa)
			{
				laboratorio[mesa-1][computadora-1] = 0;
				printf("\n\nLa reserva fue cancelada con exito!\n");
				printf("e culmino su reservacion de: mesa %d y computadora %d!\n\n", mesa, computadora);
			}
			else
			{
				printf("El lugar no esta reservado! Elige otro!\n");	
			}
		}
		else
		{
			do
			{
				system("cls");
				printf("Usted no esta dentro de la lista de personas para realizar una reserva\n");
				printf("Desea volver a intentarlo?\n");
				printf("Digite 1 para si, 0 para salir: ");
				scanf("%d", &seleccion);
				if (seleccion<0 || seleccion>1)
				{
					printf("No hay tal numero! Elige un numero entre el 0 y 1!\n");
					system("PAUSE");
					
				}
			} while (seleccion<0 || seleccion>1);
			system("cls");
		}
	}while(seleccion==1);
	printf("Presione cualquier tecla para regresar\n");
}

int ImprimirRegistro()
{
	
}

int ImprimirListado()  //Funcion para imprimir listado de personas con acceso a reservas
{
	//Declaracion de Variables
	int i, j, k;
	
	//Bloque de Instrucciones
	system("cls");
	printf("Nombres    Apellidos  Cedulas\n");
	for(i=0;i<=PERSONAS; i++)
	{
		for(j=0; j<strlen(todosLosNombres[i]); j++)
		{
			printf("%c", todosLosNombres[i][j]);
		}
		for(k=0; k<11-strlen(todosLosNombres[i]); k++)
		{
			printf(" ");
		}
		for(j=0; j<strlen(todosLosApellidos[i]); j++)
		{
			printf("%c", todosLosApellidos[i][j]);
		}
		for(k=0; k<11-strlen(todosLosApellidos[i]); k++)
		{
			printf(" ");
		}
		for(j=0; j<strlen(todasLasCedulas[i]); j++)
		{
			printf("%c", todasLasCedulas[i][j]);
		}
		printf("\n");
	}
	printf("Presione cualquier tecla para regresar\n");
}

