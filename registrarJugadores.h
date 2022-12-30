#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char tStriing [20];

typedef struct {
	tStriing nickName;
	int puntaje;
}tJugador;

tJugador jugador;

FILE * archivoJugadores;

void abrirArchivoJugadoresAB();
void ingresarJugador();
void guardarJugador();
void ingresarDatos();  
void agregarJugadoresDat();
void cerrarArchivoJugadores();

void agregarJugadorDat()
{
	abrirArchivoJugadoresAB();
	ingresarJugador();
	
	
}
void abrirArchivoJugadoresAB()
{
	archivoJugadores = fopen("Jugadores.dat", "ab");
	
}

void ingresarJugador()
{
	printf("\n INGRESE SU NICKNAME\n");
		ingresarDatos();
}
void ingresarDatos()
{
		printf("\nIngrese su Nick name: ");
		fflush(stdin);
		scanf("%[^\n]s", &jugador.nickName);	
}
void guardarJugador()
{
	fwrite(&jugador, sizeof(tJugador), 1, archivoJugadores);
}

void cerrarArchivoJugadores()
{
	fclose(archivoJugadores);
}
