#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct
{
    char alias[50]; //irrepetibles
    char password[50];
    int partidasJugadas;
    int partidasGanadas;
    int partidasPerdidas;
}Jugador;

typedef struct
{
    char jugador[50]; //para buscar datos del jugador
    int activo;
    int puntaje;
}Partida;

typedef struct
{
    Partida puntaje;
    int idPartida;
    struct NodoPuntaje* siguiente;
}NodoPuntaje;

typedef struct
{
    Jugador player;
    struct NodoPuntaje* partidasJugadas;
    struct nodoArbol* izq;
    struct nodoArbol* der;
}nodoArbol;

typedef struct
{
    char jugador[50]; //para buscar datos del jugador
    int activo;
    int puntaje;
    int idPartida;
}registro_partida;

///inicializar arbol.
nodoArbol* inicArbol();

///insertar en arbol.
nodoArbol* insertarJugadorArbol(nodoArbol* arbol, Jugador nuevo);

///mostrar arbol.
void preorden(nodoArbol* arbol);

/// borra el jugador que ingresa por teclado
nodoArbol* borrar_jugador(nodoArbol* arbol);

///eliminar nodo arbol.
nodoArbol* borrarNodo(nodoArbol* arbol, char nombre[]);
nodoArbol* NodoMasIzquierda(nodoArbol* arbol);
nodoArbol* NodoMasDerecha(nodoArbol* arbol);

///cargar en un archivo el jugador eliminado.
void cargarEnArchivoDeEliminados(Jugador eliminado);

///juego y actualizacion de estadisticas, creacion de puntaje.
nodoArbol* arbol_jugar(nodoArbol* arbol, char alias[]);

/// cada partida que juega cualquier usuario/jugador se carga automaticamente en este archivo "registro_partidas".
void partida_aArchivo(registro_partida p);

///actualiza las estadisticas del jugador despues de terminar el juego.
nodoArbol* actualizar_estadisticas(nodoArbol* arbol, int resultado);

///limpia el archivo "registro_jugadores" asi puede volver a cargar el arbol completo(con la estadisticas del jugador que recientemente jugo actualizadas).
void limpiar_archivo_arbol();

///carga el arbol de jugadores en el archivo "registro_jugadores".
void arbol_toArchivo(nodoArbol* arbol);

///carga de 1 jugador al archivo, la funcion "arbol_toArchivo" llama a esta funcion para cargar todo el arbol en el archivo "registro_jugadores"
void jugador_toArchivo(Jugador nuevo);

///devuele el nodoarbol del jugador que inicio sesion, asi actualiza sus estadisticas luego de jugar.
nodoArbol* retornar_nodo_arbol(nodoArbol* arbol, char alias[]);

///lee el archivo "registro_jugadores" insertando cada jugador leeido en el arbol...(si el archivo contiene datos --> rearma el arbol para poder trabajar con el)
nodoArbol* archivo_toArbol(nodoArbol* arbol);

/// cargar a cada jugador sus partidas correspondientes
nodoArbol* leer_informacion_partida(nodoArbol* arbol);

///necesitamos otro crear nodo para que ahora lo creo con el id correspondiente y no uno random.
NodoPuntaje* crearNodoPuntajeRearmado(Partida aux,int id);

/// cargar a un solo jugador sus partidas correspondientes
nodoArbol* leer_informacion_partida_del_reincorporado(nodoArbol* arbol, char nombre[]);

/// comprueba si un jugador ya fue eliminado
int comprobar_elimnado_anteriormente(char nombre []);

#endif// ARBOL_H_INCLUDED

