#include <locale.h>
#include "crearColaDinamica.h"
#include "leerJugadores.h"

int  numPregunta=1, opcionUsuario;
int puntaje;
void jugar();
void menuUsuario();


int main(){
	
	menuUsuario();
	
}
void jugar(){

	printf("\nBIENVENIDO %s \n", jugador.nickName);
	crearColaDePreguntas();
	tNodo * auxNodo=ColaPreguntas.principio;
	int vidas = 3;
	while(auxNodo!=NULL)
	{
		if(vidas!=0)
		{
			printf("pregunta n %d  ",numPregunta);
			printf("puntaje %d ", puntaje);
			printf("vidas restantes: %d", vidas);
			printf("\n%s\n",auxNodo->datos.pregunta[0]);
			printf("ingrese la respuesta que considere correcta: \n");
			for(aux=1;aux<5;aux++){
			printf("%d)%s\n",aux,auxNodo->datos.respuestas[aux]);
		}
		scanf("%d:",&opcionUsuario);
		if(opcionUsuario==auxNodo->datos.codRespuestaCorrecta){
			printf("Respuesta Correcta!\n");
			puntaje++;
			jugador.puntaje = puntaje;
		}else{
			printf("Respuesta Incorrecta!\n");
			printf("La respuesta correcta era la opcion (%d):%s\n",
			auxNodo->datos.codRespuestaCorrecta,
			auxNodo->datos.respuestas[auxNodo->datos.codRespuestaCorrecta]);
			vidas--;
		}
			numPregunta++;
			auxNodo=auxNodo->siguiente;
			
			system("pause");
			system("cls");
		}
		
		else
		{
			auxNodo=NULL;
			printf("\nPERDISTE\n");
		}
		
	}
	
}

void menuUsuario(){	
	int opc;
	while(opc!=5){
		printf("\n***INGRESE UNA DE ESTAS OPCIONES***\n");
		printf("1-CREAR USUARIO\n");
		printf("2-JUGAR\n");
		printf("3-VER PUNTAJE DE MAYOR A MENOR\n");
		printf("4-VER TODOS LOS PUNTAJES\n");
		printf("5-SALIR DEL JUEGO\n");
		scanf("%d",&opc);
		switch(opc){
			case 1: 	if(strlen(jugador.nickName) >20){
							printf("NO SE ACEPTAN MAS DE 20 CARACTERES ");
						exit(EXIT_FAILURE);
					}
						else
					{
				
						agregarJugadorDat();
						system("pause");
						system("cls");
						menuUsuario();
					}
			break;
			case 2:	jugar();
					guardarJugador();
					cerrarArchivoJugadores();
					menuUsuario();	
			break;
			case 3:	system("cls");
					mostrarArbolPuntuaciones();
					system("pause");
					system("cls");
					menuUsuario();	
			break;
			case 4 :system("cls");
					leerTodosLosPuntajes();
					menuUsuario();
					
			case 5 : break;
			default:  printf("\nOPCION INGRESADA ICORRECTA\n");
			
		}
	}
}

