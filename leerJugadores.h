#include "arbolDePuntajes.h"
void leerTodosLosPuntajes();
void procesarJugadores2();

void leerTodosLosPuntajes(){
	abrirArchivoJugadoresRB();
	procesarJugadores2();
	cerrarArchivoJugadores();
	system("pause");
	system("cls");
	
}

void procesarJugadores2(){
	
	conseguirJugadores();
	printf("\n****LOS JUGADORES SON***\n");
	printf("JUGADOR\t\t|| PUNTAJE\n");
	while(!feof(archivoJugadores))
	{
		printf("%s   \t|| %d\n", jugador.nickName, jugador.puntaje);
		conseguirJugadores();
	}
}