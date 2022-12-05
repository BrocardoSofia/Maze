#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

///registrar jugador, ingresa alias y password.
Jugador registrar_jugador(nodoArbol* arbol, Jugador player);

///validacion del usuario que se quiere registrar, busca en el arbol si existe el alias que se quiere registrar, si existe retorna[1] | si no existe retorna[0].
int validar_nombre(nodoArbol* arbol, char alias[]);
int buscar_nombre_arbol(nodoArbol* arbol, char alias[]);

///muestra un jugador solo
void mostrar_jugador(Jugador player);

#endif // JUGADOR_H_INCLUDED


