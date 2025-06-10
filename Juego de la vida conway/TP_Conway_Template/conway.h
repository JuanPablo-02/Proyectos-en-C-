#ifndef CONWAY_H_INCLUDED
#define CONWAY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __MINGW32__
    #define SDL_MAIN_HANDLED
    #include <SDL_main.h>
#endif

#include <SDL.h>

#define N 20  // Número de filas
#define M 40 // Número de columnas
#define tam_celda 25
/// Matriz estandar
void imprimirMatrizSDL(int matriz[N][M], SDL_Renderer* renderer);
void actualizarMatriz(int matriz[N][M]);


/// Matriz dinamica
void** crearMatriz(int filas, int columnas, size_t tamElem);
void destruirMatriz(int** matriz, int filas);
void imprimirMatrizSDLDin(int** matriz, int filas, int columnas, SDL_Renderer* renderer);
void actualizarMatrizDin(int** matriz, int filas, int columnas);
void llenarMatrizConPlaneador(int** matriz, int filas, int columnas);
void inicializarPlaneador(int **matriz, int fil, int col);
void leerMatrizDesdeArchivo(const char* nombreArchivo,int** matriz, int filas, int columnas);

///Funciones x
void mostrarMenu();
void bajarArchivo();
#endif // CONWAY_H_INCLUDED
