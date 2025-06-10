#include "tp.h"

int main()
{
    lotedeprueba("lotedeprueba.dat");
    Tarch VecNarch[CantARCH]={
        {"estudiantes1.dat"},
        {"estudiantes2.dat"},
        {"estudiantes3.dat"},
        {"estudiantes4.dat"},
        {"estudiantes5.dat"}
        };

    MergeGenerico(VecNarch,"AlumnosTotal.dat",5,sizeof(Tstruct),compararFechaInscripcion);
    leerArchBin("AlumnosTotal.dat");
    printf("\nMEJORES PROMEDIOS \n");
    MostrarYguardar5Mejores("AlumnosTotal.dat","MejoresAlumnos.csv",sizeof(Tstruct),cmpProm);

    return 0;
}
