#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define MAX 20

typedef char tString[100];
typedef tString tVectorPreguntas[1];
typedef tString tVectorRespuestas[5];
typedef int tVector[MAX];
tVector vectorNumeros;


typedef struct{
	int codPregunta;
	tVectorPreguntas pregunta;
	tVectorRespuestas respuestas;
	int codRespuestaCorrecta;
}tDatos;

typedef struct nodo{
	tDatos datos;
	struct nodo * siguiente;
}tNodo;

typedef struct {
	tNodo * principio;
	tNodo * final;
}tCola;

tCola ColaPreguntas;

typedef struct {
	int codPregunta;
	tVectorPreguntas pregunta;
	tVectorRespuestas respuestas;
	int codRespuestaCorrecta;
}tRegistro;

tRegistro registro;
FILE * archivo;
int i, aux=0;
int limite_inferior = 1;
int limite_superior = 28;

void inicializarCola();
void agregarElementos(tCola *, tDatos);
void visualizarElementos(tCola);
void conseguirPreguntas();
bool colaVacia(tCola);
void crearVectorNumeros();
void ordenarVector();
void crearColaDePreguntas();

void abrirArchivo();
void conseguirDatos();
void cerrarArchivo();


bool colaVacia(tCola pCola){
	return(pCola.principio== NULL && pCola.final== NULL);
}

void inicializarCola(tCola * pCola){
	(*pCola).principio=NULL;
	pCola->final=NULL;
	
}

void agregarElementos(tCola * pCola, tDatos pDatos){
	tNodo * nuevoNodo;
	nuevoNodo=(tNodo*)malloc(sizeof(tNodo));
	
	nuevoNodo->datos=pDatos;
	nuevoNodo->siguiente=NULL;
	
	if(colaVacia(*pCola)){
		(*pCola).principio=nuevoNodo;
		pCola->final=nuevoNodo;
	}
	else{
		
		(*pCola).final->siguiente=nuevoNodo;
		(*pCola).final=nuevoNodo;
	}
}

void conseguirPreguntas(){
	abrirArchivo();
	tDatos auxDatos;
 		while(!feof(archivo)) { 
 		
			if(vectorNumeros[aux]==registro.codPregunta){
				auxDatos.codPregunta=registro.codPregunta;
			   	strcpy(auxDatos.pregunta[0],registro.pregunta[0]);
						for (i=1;i<5;i++){
							strcpy(auxDatos.respuestas[i],registro.respuestas[i]);
						}
					auxDatos.codRespuestaCorrecta=registro.codRespuestaCorrecta;
					agregarElementos(&ColaPreguntas,auxDatos);
					aux++;
					conseguirDatos();
					}
					else{
						if(vectorNumeros[aux]==vectorNumeros[aux-1]){
							aux++;
						}
						else{
							conseguirDatos();
						}
					}

		}
}

void abrirArchivo(){
	archivo=fopen("Preguntas.dat","rb");
	conseguirDatos();
}

void conseguirDatos(){
	fread(&registro,sizeof(tRegistro),1,archivo);
}

void cerrarArchivo(){
	fclose(archivo);
}

void crearVectorNumeros(){
	int j=0,aux,i=0;
	srand(time(NULL));
	for( i=0; i<MAX; i++) {
		vectorNumeros[i]=( limite_inferior + rand() % ( limite_superior + 1 - limite_inferior ));
	}
	
}

void ordenarVector(){
	int aux,j;
	bool flag = false;
	
	i = 0;
	while( (flag == false) && ( i<MAX ) ) {
		flag = true;
		for( j=0; j<MAX-1; j++ ) {
			
			if( vectorNumeros[j] > vectorNumeros[j+1] ) {
				aux =  vectorNumeros[j];
				vectorNumeros[j] =  vectorNumeros[j+1];
				vectorNumeros[j+1] = aux;
				flag = false;
			}		
		}					
		i = i+1;
	}
}

void crearColaDePreguntas(){
	inicializarCola(&ColaPreguntas);
	crearVectorNumeros();
	ordenarVector();
	conseguirPreguntas();
	cerrarArchivo();
}

void visualizarElementos(tCola pCola){
	if(colaVacia(pCola)){
		printf("No existen elementos");
	}
	else{
		tNodo * auxNodo=pCola.principio;
		printf("elementos en la cola: ");
		while(auxNodo!=NULL){
			printf("\n codPregunta %d \n",auxNodo->datos.codPregunta);
			printf("%s\n",auxNodo->datos.pregunta[0]);
			for(i=1;i<5;i++){
				printf("%d)%s\n",i,auxNodo->datos.respuestas[i]);
			}
			printf("respuesta correcta %d [%s]",auxNodo->datos.codRespuestaCorrecta,
			auxNodo->datos.respuestas[auxNodo->datos.codRespuestaCorrecta]);
			auxNodo=auxNodo->siguiente;
		}
	}
}


