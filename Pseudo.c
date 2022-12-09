//Semestral Principio de Programacion 2022
//Rohacerlfo Campos 8-905-2179, Adriana Achurra 8-990-123;


//Declaracion de Constantes Globales				Puede cambiar el tamaño de las mesas y computadoras.
#define MESAS 3						//Lo hicimos escalable a futuro cambiando las constantes a variables para una funcion de cambiar tamaño
#define COMPUTADORAS 4
#define PERSONAS 20

//Declaracion de Funciones
entero ImprimirBanner();
entero ImprimirLaboratorio(entero mesas, entero computadoras, entero laboratorio[mesas][computadoras]);                       //Funcion para imprimir Las mesas y computadoras
entero ValidarNumero(entero n);                                                                                         //Funcion para validar numero de entrada
entero VerificarCedula();                                                                                            //Funcion para verficar acceso con cedula
entero Reservar(entero personas, entero mesas, entero computadoras, entero laboratorio[mesas][computadoras], entero registro[personas][(mesas*computadoras)+1]);  //Funcion para reservar computadora
entero Cancelar(entero mesas, entero computadoras, entero laboratorio[mesas][computadoras]);                                  //Funcion para cancelar reserva de computadora
entero ImprimirRegistro(entero personas, entero mesas, entero computadoras, entero registro[personas][(mesas*computadoras)+1]);  //Funcion para imprimir el registro de reservas
entero ImprimirListado();                                                                                            //Funcion para imprimir listado de personas con acceso a reservass


//Listado de Acceso
caracter todasLasCedulas[PERSONAS][15]=
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
	
caracter todosLosNombres[PERSONAS][15]=
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

caracter todosLosApellidos[PERSONAS][15]=
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

Algoritmo SemestralPrincipiosDeProgramacion
{
	//Declaracion de Variables
	entero rodolfo, adriana, seleccion, mesa, computadora, laboratorio[MESAS][COMPUTADORAS], registro[PERSONAS][(MESAS*COMPUTADORAS)+1];
	
	//Valorando ArregloS
	para (rodolfo=0; rodolfo<MESAS; rodolfo++)
	{
		para (adriana=0; adriana<COMPUTADORAS; adriana++)
		{
			laboratorio[rodolfo][adriana] = 0;
		}
	}
	
	para (rodolfo=0; rodolfo<PERSONAS; rodolfo++)
	{
		para (adriana=0; adriana<(MESAS*COMPUTADORAS)+1; adriana++)
		{
			registro[rodolfo][adriana] = 0;
		}
	}
	
	//Ciclo Principal
	hacer
	{
		sistema("limpiar");
		imprimir("\n");
		ImprimirBanner();
		imprimir(" BIENVENIDO AL LABORATORIO DE COMPUTO!\n\n");
		imprimir(" Seleccione una de las siguientes opciones para continuar:\n\n");
		imprimir("  1. Ver los puestos de las computadoras ocupadas y disponibles.\n");
		imprimir("  2. Reservar una computadora.\n");
		imprimir("  3. Salir del laboratorio.\n");
		imprimir("  4. Registro del uso del laboratorio.\n");
		imprimir("  5. Ver el listado de los estudiantes autorizado para usar el laboratorio.\n");
		imprimir("  6. Salir del sistema.\n\n");
		imprimir(" Seleccion: ");
		leer(seleccion);
		segun(seleccion)
		{
			  1:
				sistema("limpiar");
				ImprimirLaboratorio(MESAS, COMPUTADORAS, laboratorio);
				imprimir("Presione cualquier tecla para regresar\n");
				sistema("PAUSA");
				;
			  2:
				Reservar(PERSONAS, MESAS, COMPUTADORAS, laboratorio, registro);
				sistema("PAUSA");
				;
			  3:
				Cancelar(MESAS, COMPUTADORAS, laboratorio);
				sistema("PAUSA");
				;
			  4:
				ImprimirRegistro(PERSONAS, MESAS, COMPUTADORAS, registro);
				sistema("PAUSA");
				;
			  5:
				ImprimirListado();
					sistema("PAUSA");
				;
			  6:
				ImprimirFin();
				;
			de otro modo:
				imprimir("\n\033[31m >> inserte un numero valido <<\033[0m\n");
				sistema("PAUSA");
		}
	}mientras (seleccion!=6);
	retornar 0;
}

entero ImprimirBanner()
{
	imprimir(" \033[90m'\033[33m##\033[90m::::::::::'\033[33m###\033[90m::::'\033[33m########\033[90m:::'\033[33m#######\033[90m::'\033[33m########\033[90m:::::'\033[33m###\033[90m::::'\033[33m########\033[90m::'\033[33m#######\033[90m::'\033[33m########\033[90m::'\033[33m####\033[90m::'\033[33m#######\033[90m::\n");
	imprimir(" \033[90m \033[33m##\033[90m:::::::::'\033[33m##\033[90m \033[33m##\033[90m::: \033[33m##\033[90m.... \033[33m##\033[90m:'\033[33m##\033[90m.... \033[33m##\033[90m: \033[33m##\033[90m.... \033[33m##\033[90m:::'\033[33m##\033[90m \033[33m##\033[90m:::... \033[33m##\033[90m..::'\033[33m##\033[90m.... \033[33m##\033[90m: \033[33m##\033[90m.... \033[33m##\033[90m:. \033[33m##\033[90m::'\033[33m##\033[90m.... \033[33m##\033[90m:\n");
	imprimir(" \033[90m \033[33m##\033[90m::::::::'\033[33m##\033[90m:. \033[33m##\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m::'\033[33m##\033[90m:. \033[33m##\033[90m::::: \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m:: \033[33m##\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m:\n");
	imprimir(" \033[90m \033[33m##\033[90m:::::::'\033[33m##\033[90m:::. \033[33m##\033[90m: \033[33m########\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m########\033[90m::'\033[33m##\033[90m:::. \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m########\033[90m::: \033[33m##\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m:\n");
	imprimir(" \033[90m \033[33m##\033[90m::::::: \033[33m#########\033[90m: \033[33m##\033[90m.... \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m.. \033[33m##\033[90m::: \033[33m#########\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m.. \033[33m##\033[90m:::: \033[33m##\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m:\n");
	imprimir(" \033[90m \033[33m##\033[90m::::::: \033[33m##\033[90m.... \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m::. \033[33m##\033[90m:: \033[33m##\033[90m.... \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m##\033[90m::. \033[33m##\033[90m::: \033[33m##\033[90m:: \033[33m##\033[90m:::: \033[33m##\033[90m:\n");
	imprimir(" \033[90m \033[33m########\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m: \033[33m########\033[90m::. \033[33m#######\033[90m:: \033[33m##\033[90m:::. \033[33m##\033[90m: \033[33m##\033[90m:::: \033[33m##\033[90m:::: \033[33m##\033[90m::::. \033[33m#######\033[90m:: \033[33m##\033[90m:::. \033[33m##\033[90m:'\033[33m####\033[90m:. \033[33m#######\033[90m::\n");
	imprimir(" \033[90m........::..:::::..::........::::.......:::..:::::..::..:::::..:::::..::::::.......:::..:::::..::....:::.......:::\033[0m\n\n");
}

entero ImprimirLaboratorio(entero mesas, entero computadoras, entero laboratorio[mesas][computadoras])  //Funcion para imprimir Las mesas y computadoras
{
	//Declaracion de Variables
	entero m, c;
	
	//Bloque de Instrucciones
	imprimir("\n\033[33m                    TABLA DE PUESTOS DE COMPUTADORAS DISPINIBLES.\033[0m\n\n");
	
	para (m=0; m<mesas; m++)
	{
		imprimir("\033[33m Mesa %d\033[0m:  \n ", m+1);
		para (c=0; c<computadoras; c++)
		{
			imprimir("_____________________");
		}
		imprimir("_\n");
		imprimir("| ");
		para (c=0; c<computadoras; c++)
		{
			imprimir("____________________ ");
		}
		imprimir("|\n||");
		para (c=0; c<computadoras; c++)
		{
			imprimir("  ___________   __  |");
		}
		imprimir("|\n||");
		para (c=0; c<computadoras; c++)
		{
			imprimir(" |           | |==| |");
		}
		imprimir("|\n||");
		para (c=0; c<computadoras; c++)
		{
			imprimir(" |     %d     | |--| |", c+1);
		}
		imprimir("|\n||");
		para (c=0; c<computadoras; c++)
		{
			imprimir(" |___________| |  | |");
		}
		imprimir("|\n||");
		para (c=0; c<computadoras; c++)
		{
			imprimir("      | |      |--| |");
		}
		imprimir("|\n||");
		para (c=0; c<computadoras; c++)
		{
			imprimir("  ===========  |__| |");
		}
		imprimir("|\n||");
		para (c=0; c<computadoras; c++)
		{
			si(laboratorio[m][c]==0)
			{	
				imprimir("  \033[32m Disponible \033[0m      |");
			}
			de otro modo si(laboratorio[m][c]>0)
			{
				imprimir(" \033[31m No Disponible \033[0m    |");
			}
		}
		imprimir("|\n||");
		para (c=0; c<computadoras; c++)
		{
			imprimir("____________________|");
		}
		imprimir("|\n|_");
		para (c=0; c<computadoras; c++)
		{
			imprimir("_____________________");
		}
		imprimir("|\n\n");
	}
}

entero ValidarNumero(entero n)  //Funcion para validar numero de entrada
{
	//Declaracion de Variable
	entero i;
	
	//Bloque de Instrucciones
	hacer
	{	
		leer(i);
		si (i<1 || i>n)
		{
			imprimir("\n\033[31m >>No hay tal numero! Elige un numero entre el 1 al %d!<<\033[0m\n", n);
			imprimir("Ingrese nuevamente el numero: ");
		}
	} mientras (i<1 || i>n);
	retornar i;
}

entero VerificarCedula()  //Funcion para verficar acceso con cedula
{
	//Declaracion de Variables
	entero i, buscar, persona;
	caracter cedula[15];
	
	//Bloque de instrucciones
	imprimir("Ingrese su numero de cedula: ");
	leer(cedula);
	para(i=0; i<PERSONAS; i++)
    {
    	buscar = strcmp(cedula, todasLasCedulas[i]);
        si(buscar == 0)
    	{
    		persona=i;
            ;
        }
    }
    si(buscar == 0)
    {
    	sistema("limpiar");
        imprimir("\n                      %s %s tiene Acceso Confirmado!\n\n", todosLosNombres[persona], todosLosApellidos[persona]);
        retornar persona;
    }
    de otro modo
    {
        imprimir("no tiene Acceso\n");
        retornar -1;
	}
}

entero Reservar(entero personas, entero mesas, entero computadoras, entero laboratorio[mesas][computadoras], entero registro[personas][(mesas*computadoras)+1])  //Funcion para reservar computadora
{
	//Declaracion de variables
	entero persona, mesa, computadora, seleccion=0;
	
	//Bloque de Instrucciones
	sistema("limpiar");
	hacer
	{
		persona=VerificarCedula();
		si(persona>=0)
		{
			ImprimirLaboratorio(mesas, computadoras, laboratorio);
			imprimir("Para realizar una reserva, seleccione una mesa y una computadora.\n");
			imprimir("Ingrese el numero de mesa: ");
			mesa=ValidarNumero(mesas);
			imprimir("Ingrese el numero de computadora: ");
			computadora=ValidarNumero(computadoras);
			si (laboratorio[mesa-1][computadora-1] == 0)
			{
				sistema("limpiar");
				laboratorio[mesa-1][computadora-1] = 1;
				sistema("limpiar");
				imprimir("  __^__                                      __^__\n");
				imprimir(" ( ___ )------------------------------------( ___ )\n");
				imprimir("  | / |                                      | \\ |\n");
				imprimir("  | /  \033[32mLA RESERVA FUE EXITOSA!!!\033[0m      | \\ |\n");
				imprimir("  |   |                                      |   |\n");
				imprimir("  | / |       Su lugar reservado es:         | \\ |\n");
				imprimir("  | / |       mesa ", mesa, " y computadora", computadora, "         | \\ |\n");
				imprimir("  |___|                                      |___|\n");
				imprimir(" (_____)------------------------------------(_____)\n"); 
				computadora=((mesa-1)*computadoras)+computadora;
				registro[persona][computadora]= registro[persona][computadora]+1;
				registro [persona][0]= registro [persona][0] + 1;
				retornar registro;
			}
			de otro modo
			{
				imprimir("\n\033[31m >>El lugar esta ocupado! ¡Elige otro!<<\033[0m\n");	
			}
		}
		de otro modo
		{
			hacer
			{
				sistema("limpiar");
				imprimir("Usted no esta dentro de la lista de personas para realizar una reserva\n");
				imprimir("Desea volver a enteroentarlo?\n");
				imprimir("Digite 1 para si, 0 para salir: ");
				leer(seleccion);
				si (seleccion<0 || seleccion>1)
				{
					imprimir("\n\033[31m >>No hay tal numero! Elige un numero entre el 0 y 1!<<\033[0m\n");
					sistema("PAUSA");
					
				}
			} mientras (seleccion<0 || seleccion>1);
			sistema("limpiar");
		}
	}mientras(seleccion==1);
	imprimir("Presione cualquier tecla para regresar\n");
}
	
entero Cancelar(entero mesas, entero computadoras, entero laboratorio[mesas][computadoras])  //Funcion para cancelar reserva de computadora
{
	//Declaracion de variables
	entero mesa, computadora, persona, seleccion;
	
	//Bloque de Instrucciones
	sistema("limpiar");
	hacer
	{
		persona=VerificarCedula();
		si(persona>=0)
		{
			ImprimirLaboratorio(mesas, computadoras, laboratorio);
			imprimir("Para culminar una reserva, seleccione una mesa y una computadora.\n");
			imprimir("Ingrese el numero de mesa: ");
			mesa=ValidarNumero(mesas);
			imprimir("Ingrese el numero de computadora: ");
			computadora=ValidarNumero(computadoras);
			si (laboratorio[mesa-1][computadora-1] == 1)
			{
				laboratorio[mesa-1][computadora-1] = 0;
				sistema("limpiar");
				imprimir("  __^__                                      __^__\n");
				imprimir(" ( ___ )------------------------------------( ___ )\n");
				imprimir("  | / |                                      | \\ |\n");
				imprimir("  | / |            \033[32mLA RESERVA SE\033[0m             | \\ |\n");
				imprimir("  | / |         \033[32mCANCELO CON EXITO!!!\033[0m         | \\ |\n");
				imprimir("  |   |                                      |   |\n");
				imprimir("  | / |     Se culmino su reservacion de:    | \\ |\n");
				imprimir("  | / |        mesa" , mesa "y computadora" computafora "       | \\ |\n");
				imprimir("  |___|                                      |___|\n");
				imprimir(" (_____)------------------------------------(_____)\n"); 
			}
			de otro modo
			{
				imprimir("\n\033[31m >>El lugar no esta reservado! Elige otro!<<\033[0m\n");	
			}
		}
		de otro modo
		{
			hacer
			{
				sistema("limpiar");
				imprimir("Usted no esta dentro de la lista de personas para realizar una reserva\n");
				imprimir("Desea volver a enteroentarlo?\n");
				imprimir("Digite 1 para si, 0 para salir: ");
				leer(seleccion);
				si (seleccion<0 || seleccion>1)
				{
					imprimir("\n\033[31m >>No hay tal numero! Elige un numero entre el 0 y 1!<<\033[0m\n");
					sistema("PAUSA");
					
				}
			} mientras (seleccion<0 || seleccion>1);
			sistema("limpiar");
		}
	}mientras(seleccion==1);
	imprimir("Presione cualquier tecla para regresar\n");
}

entero ImprimirRegistro(entero personas, entero mesas, entero computadoras, entero registro[personas][(mesas*computadoras)+1])  //Funcion para imprimir el registro de reservas
{
	//Declacion de Variables
	entero i, j, k, m, c, mesa, computadora, registro2D[mesas][computadoras]; //Nos toco revalorizar en otro arreglo 2D para hacer la imprecion, para no usar arreglos 3D
	
	//Bloque de Instrucciones
	sistema("limpiar");
	imprimir("\n Estas fueron las personas que reservaron computadoras:\n\n");
	imprimir("  __________________________________________ \n");
	imprimir(" | ________________________________________ |\n");

	para(i=0; i<PERSONAS; i++)
	{
		si(registro[i][0]>0)
		{
			si(i+1<10)
			{
				imprimir(" ||\033[32m#0%d %s %s \033[0m", i+1, todosLosNombres[i], todosLosApellidos[i]);
				para(j=0; j<34-(strlen(todosLosNombres[i])+strlen(todosLosApellidos[i])); j++)
				{
					imprimir(" ");
				}
			}
			de otro modo si(i+1>=10 && i+1<100)
			{
				imprimir(" ||\033[32m#%d %s %s \033[0m", i+1, todosLosNombres[i], todosLosApellidos[i]);
				para(j=0; j<34-(strlen(todosLosNombres[i])+strlen(todosLosApellidos[i])); j++)
				{
					imprimir(" ");
				}
			}
			de otro modo
			{
				imprimir(" ||\033[32m#%d %s %s \033[0m", i+1, todosLosNombres[i], todosLosApellidos[i]);
				para(j=0; j<33-(strlen(todosLosNombres[i])+strlen(todosLosApellidos[i])); j++)
				{
					imprimir(" ");
				}
			}
			
			imprimir("||\n");
			imprimir(" ||========================================||\n");
			imprimir(" || Reservo estas computadoras:            ||\n");
			k=1;
			para(m=0;m<mesas;m++)
    		{
        		para(c=0;c<computadoras;c++)
        		{
            		registro2D[m][c] = registro[i][k];
            		k++;
        		}
    		}
    		para(m=0;m<mesas;m++)
    		{
        		para(c=0;c<computadoras;c++)
        		{
        			si(registro2D[m][c]>0)
        			{
        				si(m+1<10)
        				{
        					imprimir(" ||    Mesa", m+1 "Computadora : " c+1 , registro2D[m][c] "veces.   ||\n");
						}
						de otro modo
						{
							imprimir(" ||    Mesa", m+1 "Computadora : " c+1 , registro2D[m][c] "veces.   ||\n");
						}
        				
					}
        		}
    		}
    		si(registro[i][0]<10)
    		{
    			imprimir(" ||    con un total de: " , registro[i][0]         "reservas.||\n");
			}
			de otro modo
			{
    			imprimir(" ||    con un total de: ", registro[i][0]         "reservas.||\n");
    		}
    		imprimir(" ||________________________________________||\n");
		}
	}
	imprimir(" |__________________________________________|\n\n");
	imprimir("Presione cualquier tecla para regresar\n");		
}

entero ImprimirListado()  //Funcion para imprimir listado de personas con acceso a reservas
{
	//Declaracion de Variables
	entero i, j, k;
	
	//Bloque de Instrucciones
	sistema("limpiar");
	imprimir("Este es el listado de las personas autorizadas.\n");
	imprimir("  __________________________________________ \n");
	imprimir(" | ________________________________________ |\n");
	imprimir(" ||\033[32m #n  Nombres    Apellidos  Cedulas      \033[0m||\n");
	imprimir(" ||========================================||\n");
	para(i=0;i<PERSONAS; i++)
	{
		imprimir(" || ");
		si(i+1>=10)
		{
			imprimir("\033[33m%d\033[0m  ", i+1);
		}
		de otro modo
		{
			imprimir("\033[33m0%d\033[0m  ", i+1);
		}
		para(j=0; j<strlen(todosLosNombres[i]); j++)
		{
			imprimir("\033[33m%c\033[0m", todosLosNombres[i][j]);
		}
		para(k=0; k<11-strlen(todosLosNombres[i]); k++)
		{
			imprimir(" ");
		}
		para(j=0; j<strlen(todosLosApellidos[i]); j++)
		{
			imprimir("\033[33m%c\033[0m", todosLosApellidos[i][j]);
		}
		para(k=0; k<11-strlen(todosLosApellidos[i]); k++)
		{
			imprimir(" ");
		}
		para(j=0; j<strlen(todasLasCedulas[i]); j++)
		{
			imprimir("\033[33m%c\033[0m", todasLasCedulas[i][j]);
		}
		para(k=0; k<12-strlen(todasLasCedulas[i]); k++)
		{
			imprimir(" ");
		}
		imprimir(" ||\n");
	}
	imprimir(" ||________________________________________||\n");
	imprimir(" |__________________________________________|\n\n");
	imprimir("Presione cualquier tecla para regresar\n");
}

entero ImprimirFin()
{
	sistema("limpiar");
		imprimir("\n");
		imprimir("  \033[35m########### ########### #############    ############ ################\033[0m       \n");
		imprimir("  \033[35m########### ########### #############    ############ ####################\033[0m    \n");
		imprimir("  \033[35m########### ########### #############    ############ ######################\033[0m  \n");
		imprimir("                \033[35m########                     ########                ##########\033[0m \n");
		imprimir("                \033[35m########                 \033[32m #  \033[35m########                   ########\033[0m\n");
		imprimir("  \033[32m######        \033[35m########              \033[32m ######\033[35m########\033[32m####                \033[35m#######\033[0m\n");
		imprimir(" \033[32m########       \033[35m########         \033[32m ###   # ###\033[35m########\033[32m##########          \033[35m#######\033[0m\n");
		imprimir("   \033[32m########    #\033[35m########   \033[32m ##############   \033[35m########\033[32m############       \033[35m########\033[0m\n");
		imprimir("  \033[32m##############\033[35m########\033[32m#################    \033[35m########  \033[32m############    \033[35m#########\033[0m\n");
		imprimir("   \033[32m#############\033[35m########\033[32m################     \033[35m######## #########################\033[0m \n");
		imprimir(" \033[32m###############\033[35m########\033[32m############         \033[35m######## #######################\033[0m   \n");
		imprimir(" \033[32m#            ##\033[35m\033[35m########\033[32m#######              \033[35m######## ####################\033[0m      \n");
		imprimir("                \033[35m########\033[32m###########          \033[35m########    \033[32m#############\033[0m          \n");
		imprimir("                \033[35m######## \033[32m###########         \033[35m########     \033[32m #########\033[0m            \n");
		imprimir("                \033[35m########  \033[32m###########        \033[35m########        \033[32m#### \033[0m              \n");
		imprimir("                 \033[35m########  \033[32m######           \033[35m#########                           \n");
		imprimir("                 \033[35m##########               ##########\033[0m                            \n");
		imprimir("                \033[35m#  ###############################  # \033[0m                          \n");
		imprimir("                \033[35m###  ###########################  ###\033[0m                           \n");
		imprimir("                \033[35m######  #####################  ###### \033[0m                          \n");
		imprimir("                \033[35m########                     ########\033[0m                           \n");
		imprimir("\n");
		imprimir("\033[33m  #####  ######     #     #####  ###    #     #####     ######  ####### ######  \n");
		 imprimir(" #     # #     #   # #   #     #  #    # #   #     #    #     # #     # #     # \n");
		 imprimir(" #       #     #  #   #  #        #   #   #  #          #     # #     # #     # \n");
		 imprimir(" #  #### ######  #     # #        #  #     #  #####     ######  #     # ######  \n");
		 imprimir(" #     # #   #   ####### #        #  #######       #    #       #     # #   #   \n");
		 imprimir(" #     # #    #  #     # #     #  #  #     # #     #    #       #     # #    #  \n");
		 imprimir("  #####  #     # #     #  #####  ### #     #  #####     #       ####### #     # \n");
		 imprimir("                                                                                \n");
		 imprimir("          #     # ####### ### #       ### #######    #    ######                \n");
		 imprimir("          #     #    #     #  #        #       #    # #   #     #               \n");
		 imprimir("          #     #    #     #  #        #      #    #   #  #     #               \n");
		 imprimir("          #     #    #     #  #        #     #    #     # ######                \n");
		 imprimir("          #     #    #     #  #        #    #     ####### #   #                 \n");
		 imprimir("          #     #    #     #  #        #   #      #     # #    #                \n");
		 imprimir("           #####     #    ### ####### ### ####### #     # #     #               \033[0m\n");
}

