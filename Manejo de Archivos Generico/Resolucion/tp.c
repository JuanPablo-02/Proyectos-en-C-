#include "tp.h"
//////////Funciones de Comparacion//////////////////////////
int compararFechaInscripcion(const void *a, const void *b)
{
    Tarch *estA = (Tarch *)a;
    Tarch *estB = (Tarch *)b;
    return (estA->vec->FechaInscripcion > estB->vec->FechaInscripcion) - (estA->vec->FechaInscripcion < estB->vec->FechaInscripcion);
}

float cmpProm(const void* a, const void* b)
{
    Tstruct* ptA = (Tstruct*)a;
    Tstruct* ptB = (Tstruct*)b;

    return (ptA->promedio - ptB->promedio); // Note the order for descending order
}

//////////Funciones de ordenamiento////////////////////////
void insertarOrdenadamente(void *vec, void *val, int* ce, size_t tamVector, size_t tamDato, float cmp(const void *a, const void *b))
{
    void *ini = vec;
    void *fin = vec + (*ce) * tamDato;

    if (*ce < (tamVector / tamDato)) {
        (*ce)++;
    } else {
        fin -= tamDato;
        if (cmp(fin, val) > 0) {
            return;
        }
    }

    while (fin > ini && cmp(fin - tamDato, val) < 0) {
        memcpy(fin, fin - tamDato, tamDato);
        fin -= tamDato;
    }
    memcpy(fin, val, tamDato);
}

void OrdenamientoGenerico(void *vec, unsigned ce, unsigned tam, int comp(const void*, const void*))
{
    int i, ceaux=ce;
    void *menor;
    for(i=0; i<(ce-1); i++)
    {
        menor = buscarMen(vec, ceaux, tam, comp);
        if(vec!=menor)
        {
            intercambio(vec, menor, tam);
        }
        ceaux--;
        vec+=tam;
    }
}

void *buscarMen(void *vec, unsigned ce, unsigned tam, int comp(const void*, const void*))
{
    void* menor = vec;
    int i;
    vec+=tam;
    for(i=0; i<(ce-1); i++)
    {
        if(comp(menor, vec)>0)
        {
            menor = vec;
        }
        vec+=tam;
    }
    return menor;
}

void intercambio (void *a, void* b, unsigned tam)
{
    char aux;
    int i;
    for(i=0; i<tam; i++)
    {
        aux = *(char*)a;
        *(char*)a = *(char*)b;
        *(char*)b = aux;
        a++;
        b++;
    }
}
////////////Funciones para normalizar/////////////////
int proxPalabra( char* cad, char **ini,char**fin)
{
    int elementos=0;
    while(*cad && !isalpha(*cad))
    {
        cad++;
    }
    *ini = cad;
    while(*cad && isalpha(*cad))
    {
        cad++;
        elementos++;
    }
    *fin = cad;
    return elementos;
}

void normalizarNombreYApellido(char *cad)
{
    char *ini;
    char *fin;
    int band;
    while(proxPalabra(cad, &ini, &fin) > 0)
    {
        cad=ini;
        band=1;
        while(ini<fin)
        {
            if(band==1)
            {
                *cad=AMAYUS(*cad);
                band=0;
                cad++;
            }
            *cad=AMINUS(*cad);
            cad++;
            ini++;
        }
        cad=fin;
    }
    *cad='\0';
}

//////////Funciones de resolucion///////////////////////
void MergeGenerico(Tarch *VecNarch,char *NombreSalida,int cantArch,size_t tamStruct,int comp(const void*, const void*))
{
    Tstruct aux;
    int ArchivosActivos = cantArch;
    FILE *salida = fopen(NombreSalida, "wb");

    if (!salida)
    {
        printf("Error al abrir el archivo de salida.\n");
        return;
    }

    Tarch* inicio= VecNarch;
    ///Abro los archivos segun la cantidad de archivos que le estamos pasando//
    for(size_t i=0; i<cantArch; i++)
    {
        VecNarch->apertura=fopen(VecNarch->NombreArch,"rb");
        if(!VecNarch->apertura)
        {
            printf("Error al abrir el archivo : %s", VecNarch->NombreArch);
        }
        fread(&(VecNarch->vec), tamStruct, 1, VecNarch->apertura);
        VecNarch++;
    }

    VecNarch=inicio;
    ///Ordeno el vector a Tstruct, ligado a la estructura de archivos para saber el orden//
    OrdenamientoGenerico(VecNarch, cantArch, sizeof(Tarch), comp);
    //mostrarvector(VecNarch,cantArch,sizeof(Tarch));

    while(ArchivosActivos>0)
    {
        ///Una vez ordenado, normalizo el elemento del vector que aparece que esta relacionado con el primer registro del archivo y escribo
        normalizarNombreYApellido(VecNarch->vec->nombreYapellido);
        fwrite(&(VecNarch->vec),tamStruct,1,salida);
        ///Luego termino de escribir el resto del archivo hasta que llegue al final
        fread(&aux,tamStruct,1,VecNarch->apertura);
        while(!feof(VecNarch->apertura))
        {
            normalizarNombreYApellido(aux.nombreYapellido);
            fwrite(&aux,tamStruct,1,salida);
            fread(&aux,tamStruct,1,VecNarch->apertura);
        }
        ///Avanzo el vector de archivos y resto activos, que significa que termino un archivo. Activos es igual a la cantidad de archivos que le pasamos por parametro.
        VecNarch++;
        ArchivosActivos--;
    }

    VecNarch=inicio;
    ///Vuelvo el vector de archivos al inicio y cierro los archivos
    for(size_t i=0; i<cantArch; i++)
    {
        fclose(VecNarch->apertura);
        VecNarch++;
    }
    fclose(salida);

}

void MostrarYguardar5Mejores(char* ruta,char* rutaSalida,size_t tamStruct,float cmp(const void*, const void*))
{
    int ce;
    char fechaStr[20];

    FILE *pf,*pt;

    Tstruct vec[5]={0};
    Tstruct aux;
    Tstruct* vecaux= vec;

    pf=fopen(ruta,"rb");
    if(!pf)
        printf("Error al abrir el archivo: %s", ruta);

    pt=fopen(rutaSalida,"wt");
    if(!pt)
        printf("Error al abrir el archivo: %s", ruta);

    ///Abro el archivo resultante del merge, leo e inserto en un vector con la funcion de insertar ordenamente
    fread(&aux,tamStruct,1,pf);
    while(!feof(pf))
    {
        insertarOrdenadamente(vec,&aux,&ce,sizeof(vec),tamStruct,cmp);
        fread(&aux,tamStruct,1,pf);
    }

    mostrarvector(vec,ce);
    ///Muestro y guardo en el archivo de texto el resultado y convierto la fecha en un formato legible
    fprintf(pt, "DNI;Fecha de Inscripción;Nombre y Apellido;Promedio\n");
    for(size_t i=0;i<ce;i++)
    {
        time_t tiempo = (time_t)(vecaux->FechaInscripcion / 1000);
        struct tm *tm_info = localtime(&tiempo);
        strftime(fechaStr, sizeof(fechaStr), "%Y-%m-%d %H:%M:%S", tm_info);
        fprintf(pt, "%I64d;%s;%s;%.2f\n", vecaux->dni, fechaStr, vecaux->nombreYapellido, vecaux->promedio);
        vecaux++;
    }

    fclose(pf);
    fclose(pt);

}
//////////Funciones de Agregado/////////////////////////
void leerArchBin(char *ruta)
{
    Tstruct aux;
    FILE *pf;
    pf= fopen(ruta, "rb");
    if(!pf)
    {
        return;
    }
    fread(&aux, sizeof(Tstruct), 1, pf);
    while(!feof(pf))
    {
        printf("%I64d--%I64d--%s--%.2f\n", aux.dni, aux.FechaInscripcion, aux.nombreYapellido, aux.promedio);
        fread(&aux, sizeof(Tstruct), 1, pf);

    }
    fclose(pf);
}

void mostrarvector(void* vec, int cant)
{
    Tstruct* pt=(Tstruct*)vec;
    int i;
    for(i=0; i<cant; i++)
    {
        //printf("REGISTRO %d\n",(i+1));
        printf("%I64d--%I64d--%s--%.2f\n",pt->FechaInscripcion, pt->dni, pt->nombreYapellido, pt->promedio);
        pt++;
    }
}

void lotedeprueba (char* ruta)
{
    Tstruct vec[]= {{37229000, 1331634235000,"Facu Cesti", 2.0},
        {37229123, 1331635235000, "Nicolas rodRIguez", 4.0},
        {37229456, 1331640095000, "mARIA pIa", 9.99},
        {37229782, 1331714828000, "fRAnco",9.90 }
    };
    FILE *pf;
    pf = fopen(ruta, "wb");
    if(!pf)
    {
        return;
    }
    fwrite(vec, sizeof(vec), 1, pf);
    fclose(pf);
}


