#ifndef TP_H_INCLUDED
#define TP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define CantARCH 5
#define AMAYUS(X) ((X)>='a' && (X)<= 'z' ? (X)-('a' - 'A') : (X))
#define AMINUS(X) ((X)>='A' && (X)<= 'Z' ? (X)+('a' - 'A') : (X))

typedef struct{
    unsigned long long dni;
    unsigned long long FechaInscripcion;
    char nombreYapellido [30];
    float promedio;
}Tstruct;


typedef struct{
        const char *NombreArch;
        FILE *apertura;
        Tstruct vec[CantARCH];
}Tarch;


void OrdenamientoGenerico(void *vec, unsigned ce, unsigned tam, int comp(const void*, const void*));
void *buscarMen(void *vec, unsigned ce, unsigned tam, int comp(const void*, const void*));
void intercambio (void *a, void* b, unsigned tam);
int compararFechaInscripcion(const void *a, const void *b);
float cmpProm(const void* a, const void* b);
void MergeGenerico(Tarch *VecNarch,char *NombreSalida,int cant,size_t tamStruct,int comp(const void*, const void*));
void leerArchBin(char *ruta);
void mostrarvector(void* vec, int cant);
void normalizarNombreYApellido(char *cad);
int proxPalabra( char* cad, char **ini,char**fin);
void MostrarYguardar5Mejores(char* ruta,char* rutaSalida,size_t tamStruct, float cmp(const void*, const void*));
void insertarOrdenadamente(void *vec, void *val, int *ce, size_t tamVector, size_t tamDato, float cmp(const void *a, const void *b));
void lotedeprueba (char* ruta);

#endif // TP_H_INCLUDED
