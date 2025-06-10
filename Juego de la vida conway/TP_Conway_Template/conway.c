#include "conway.h"

void imprimirMatrizSDL(int matriz[N][M], SDL_Renderer* renderer)
{
    SDL_Rect celda;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matriz[i][j] == 1)
            {
                // color blanco
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                celda.x = j * tam_celda;
                celda.y = i * tam_celda;
                celda.w = tam_celda;
                celda.h = tam_celda;

                SDL_RenderFillRect(renderer, &celda);
            }
        }
    }
}

void actualizarMatriz(int matriz[N][M])
{
    int matAux[N][M];
    int vecinosVivos, j, i, limFil, limCol, fila, columna;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            vecinosVivos = 0;
            for (limFil = -1; limFil <= 1; limFil++)
            {
                for (limCol = -1; limCol <= 1; limCol++)
                {
                    if (!(limFil == 0 && limCol == 0))
                    {
                        fila = i + limFil;
                        columna = j + limCol;

                        if (fila >= 0 && fila < N && columna >= 0 && columna < M)
                        {
                            if (matriz[fila][columna] == 1)
                            {
                                vecinosVivos++;
                            }
                        }
                    }
                }
            }

            if (matriz[i][j] == 1) //caso en el que se encuentre viva, sigue o no
            {
                if (vecinosVivos < 2 || vecinosVivos > 3)
                {
                    matAux[i][j] = 0;
                }
                else
                {
                    matAux[i][j] = 1;
                }
            }
            else //caso en el que se encuentre sin vida, nace o no
            {
                if (vecinosVivos == 3)
                {
                    matAux[i][j] = 1;
                }
                else
                {
                    matAux[i][j] = 0;
                }
            }
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            matriz[i][j] = matAux[i][j];
        }
    }
}

void** crearMatriz(int filas, int columnas, size_t tamElem)
{
    void** matriz=malloc(sizeof(void*) * filas);

    if(!matriz)
        return NULL;

    void** ult= matriz + filas - 1;

    for(void** i= matriz; i<=ult; i++)
    {
        *i=malloc(tamElem*columnas);

        if(*i==NULL)
        {
            for(void** j= matriz; j<i; j++)
            {
                free(*j);
            }
            free(matriz);
            return NULL;
        }
    }

    return matriz;
}

void destruirMatriz(int** matriz, int filas)
{

    int** ult= matriz + filas - 1;

    for(int** i= matriz; i<=ult; i++)
    {
        free(*i);
    }
    free(matriz);
}

void llenarMatrizConPlaneador(int** matriz, int filas, int columnas)
{

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = 0;
        }
    }

    matriz[2][2] = 1;
    matriz[3][3] = 1;
    matriz[4][1] = 1;
    matriz[4][2] = 1;
    matriz[4][3] = 1;
}

void imprimirMatrizSDLDin(int** matriz, int filas, int columnas, SDL_Renderer* renderer)
{
    SDL_Rect celda;

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (matriz[i][j] == 1)
            {
                // Color blanco
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                celda.x = j * tam_celda;
                celda.y = i * tam_celda;
                celda.w = tam_celda;
                celda.h = tam_celda;

                SDL_RenderFillRect(renderer, &celda);
            }
        }
    }
}
void actualizarMatrizDin(int** matriz, int filas, int columnas)
{
    int matAux[filas][columnas];
    int vecinosVivos, i, j, limFil, limCol, fila, columna;

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            vecinosVivos = 0;

            for (limFil = -1; limFil <= 1; limFil++)
            {
                for (limCol = -1; limCol <= 1; limCol++)
                {
                    if (!(limFil == 0 && limCol == 0))
                    {
                        fila = i + limFil;
                        columna = j + limCol;

                        if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas)
                        {
                            if (matriz[fila][columna] == 1)
                            {
                                vecinosVivos++;
                            }
                        }
                    }
                }
            }

            if (matriz[i][j] == 1) //caso en el que se encuentre viva, sigue o no
            {
                if (vecinosVivos < 2 || vecinosVivos > 3)
                {
                    matAux[i][j] = 0;
                }
                else
                {
                    matAux[i][j] = 1;
                }
            }
            else //caso en el que se encuentre sin vida, nace o no
            {
                if (vecinosVivos == 3)
                {
                    matAux[i][j] = 1;
                }
                else
                {
                    matAux[i][j] = 0;
                }
            }
        }
    }

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            matriz[i][j] = matAux[i][j];
        }
    }

}

void mostrarMenu()
{
    printf("\n");
    printf("Seleccione una figura para inicializar\n");
    printf("1. Planeadores\n");
    printf("2. Canion de Planeadores \n");
    printf("Ingrese su eleccion: ");
}


void inicializarPlaneador(int **matriz, int fil, int col)
{
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matriz[i][j] = 0;
        }
    }

    // Definir el cañón de planeadores
    int canion[20][40] =
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Copiar el cañón de planeadores a la matriz
    for (int i = 0; i < fil; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matriz[i][j] = canion[i][j];
        }
    }
}

void bajarArchivo()
{
    printf("Eliga si quiere bajar el juego de un archivo \n");
    printf("1. Archivo \n");
    printf("2. Flujo normal\n");
    printf("Ingrese su eleccion: ");

}


void leerMatrizDesdeArchivo(const char* nombreArchivo,int** matriz, int filas, int columnas)
{

    FILE* archivo = fopen(nombreArchivo, "rt");
    if (!archivo)
    {
        printf("No se pudo abrir el archivo.\n");
    }

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            fscanf(archivo, "%d,", &matriz[i][j]);
        }
    }

    fclose(archivo);

}



/*int actuazlizar2(int matriz[N][M], int fila, int columna)
{
    int vecinosVivos = 0;

    // Iterar por las celdas vecinas (incluidas las diagonales)
    for (int limFil = -1; limFil <= 1; limFil++)
    {
        for (int limCol = -1; limCol <= 1; limCol++)
        {
            int vecinoFila = fila + limFil;
            int vecinoColumna = columna + limCol;

            // Ignorar la célula misma y verificar límites
            if (!(limFil == 0 && limCol == 0) &&
                    vecinoFila >= 0 && vecinoFila < N &&
                    vecinoColumna >= 0 && vecinoColumna < M)
            {
                if (matriz[vecinoFila][vecinoColumna] == 1)
                {
                    vecinosVivos++;
                }
            }
        }
    }

    return vecinosVivos;
}*/
