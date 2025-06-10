
#include "conway.h"


int main(int argc, char *argv[])
{
    unsigned char done;
    int k;
    //int anchoVentana, altoVentana;
    int filas, columnas, opcion, opcion2;

/// Planeador
    /*    int matriz[N][M] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };*/

/// Cañon de Planeadores
    /*    int matriz[N][M] =
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
    */

    //Mucha de esta parametrizacion puede venir por linea de comando!!
    int delay               = 150;
    SDL_Window* window      = NULL;
    SDL_Renderer* renderer  = NULL;
    SDL_Event e;

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL No se ha podido inicializar! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }


    bajarArchivo();
    scanf("%d", &opcion);

    printf("\n");
    printf("Ingrese la cantidad de filas: ");
    scanf("%d", &filas);
    printf("\nIngrese la cantidad de columnas: ");
    scanf("%d", &columnas);

    int **matriz = (int**)crearMatriz(filas, columnas, sizeof(int));


    mostrarMenu();

    scanf("%d", &opcion2);

    switch (opcion2)
    {
    case 1:

        if (filas < 10 || columnas < 10)
        {
            printf("La matriz es demasiado chica para el planeador, vuelva a empezar.\n");
            return 0;
        }

        if(opcion==1)
        {
            leerMatrizDesdeArchivo("Planeador.txt",matriz, filas, columnas);
        }
        else
        {
            llenarMatrizConPlaneador(matriz, filas, columnas);
        }

        break;
    case 2:
        if (filas < 12 || columnas < 37)
        {
            printf("La matriz es demasiado chica para el cañon de planeadores, vuelva a empezar.\n");
            return 0;
        }

        if(opcion==1)
        {
            leerMatrizDesdeArchivo("CanionDePlaneadores.txt",matriz, filas, columnas);
        }
        else
        {
            inicializarPlaneador(matriz,filas,columnas);
        }

        break;
    default:
        printf("Opción no válida.\n");
        break;
    }

    window = SDL_CreateWindow("Juego de la vida",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              columnas * tam_celda, ///ancho de la ventana
                              filas * tam_celda, ///altura de la ventana
                              SDL_WINDOW_SHOWN);

    /* SDL_GetWindowSize(window, &anchoVentana, &altoVentana);
     printf("El tamaño actual de la ventana es: %d x %d\n", anchoVentana, altoVentana);
    */




    if (!window)
    {
        SDL_Log("Error en la creacion de la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Creamos el lienzo
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        SDL_Log("No se ha podido crear el lienzo! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    while (!done)  //Se puede parar tambien cuando no se observen cambios!
    {
        while (SDL_PollEvent(&e) != 0)
        {
            // Salida del usuario
            if (e.type == SDL_QUIT)
            {
                done = 1;
            }
        }
        // Se limpia la pantalla
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);
        ;
        ///Para uso de matriz estandar
        /*
                imprimirMatrizSDL(matriz, renderer);
                actualizarMatriz(matriz);
        */
        ///Para uso de matriz dinamica
        imprimirMatrizSDLDin(matriz, filas, columnas, renderer);
        actualizarMatrizDin(matriz, filas, columnas);


        SDL_RenderPresent(renderer);
        k++;
        SDL_UpdateWindowSurface(window);
        SDL_SetWindowTitle(window, "Juego de la vida");
        SDL_Delay(delay);
    }

    destruirMatriz(matriz,filas);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


