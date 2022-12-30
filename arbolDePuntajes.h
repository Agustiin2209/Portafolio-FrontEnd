#include <stdbool.h>
#include "registrarJugadores.h"


typedef struct nodoArbol {
	tJugador jugador;
	struct nodoArbol * hijoIzquierdo;
	struct nodoArbol * hijoDerecho;
}tArbol;

tArbol * arbolJugadores;

void crearArbolVacio( tArbol ** );
bool arbolVacio( tArbol * );
void insertarElemento( tArbol **, tJugador );
void leerJugadoresDat();
void abrirArchivoJugadoresRB();
void conseguirJugadores();
void procesarJugadores();
void cerrarArchivoJugadores();
void recorrerEnInordenInvertido(tArbol *);
void mostrarArbolPuntuaciones();

void crearArbolVacio( tArbol ** pArbol ) {	
	*pArbol = NULL;
}

void insertarElemento( tArbol ** pArbol, tJugador pDatos ) {
	if( arbolVacio(*pArbol) ) {
		(*pArbol) = (tArbol *) malloc(sizeof(tArbol));
	
		if( *pArbol == NULL ) {
			printf("No hay espacio disponible!\n");
		} else {
			(*pArbol)->jugador = pDatos;
			(*pArbol)->hijoIzquierdo = NULL;
			(*pArbol)->hijoDerecho = NULL;
		}
		
	}else {
		
		if( pDatos.puntaje > (*pArbol)->jugador.puntaje ) {
			insertarElemento( &(*pArbol)->hijoDerecho, pDatos);
		}else{
			if( pDatos.puntaje < (*pArbol)->jugador.puntaje ) {
				insertarElemento( &(*pArbol)->hijoIzquierdo, pDatos);
			} else {
				printf("puntaje de %s repetido !\n",jugador.nickName);
			}	
		}		
	}
}

bool arbolVacio( tArbol * pArbol ) {
	return pArbol == NULL;
}

void leerJugadoresDat(){
	abrirArchivoJugadoresRB();
	crearArbolVacio(&arbolJugadores);
	procesarJugadores();
	cerrarArchivoJugadores();
	
}

void abrirArchivoJugadoresRB(){
	archivoJugadores = fopen("Jugadores.dat", "rb");
	if(archivoJugadores == NULL ) {
		printf("NO HAY ELEMENTOS PARA LEER!\n");
		
	}
}

void conseguirJugadores(){
	fread(&jugador,sizeof(tJugador),1,archivoJugadores);
}

void procesarJugadores(){
	conseguirJugadores();
	tJugador datos;
	
	while(!feof(archivoJugadores))
	{
		strcpy(datos.nickName,jugador.nickName);	
		datos.puntaje=jugador.puntaje;
		insertarElemento(&arbolJugadores,datos);
		conseguirJugadores();
	}
}

void recorrerEnInordenInvertido( tArbol * pArbol ) {
	if( !(arbolVacio(pArbol)) ) { 
		recorrerEnInordenInvertido(pArbol->hijoDerecho);	
		printf("%s - %d\n", pArbol->jugador.nickName, pArbol->jugador.puntaje);
		recorrerEnInordenInvertido(pArbol->hijoIzquierdo);		
	}
}

void mostrarArbolPuntuaciones(){
	leerJugadoresDat();
	recorrerEnInordenInvertido(arbolJugadores);
}




