#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>

int mandelbrotSet(complex double, complex double, int);

int main() {
        //Declarar constante que se utilizarán.
        const int ite = 1000; //Número de Iteraciones.
        const int T = 1000;   //Tuplas de la Matriz. :v
        const int A = 1000;   //Atributos de la Matriz. :v
        const float lLX = -1.5; //Límite mínimo de X.
        const float uLX = 0.5;  //Límite máximo de X.
        const float lLY = -1.0; //Límite Mínimo de Y.
        const float uLY = 1.0;  //Límite Máximo de Y.

        double dX = ((uLX - lLX) / A);
        double dY = ((uLY - lLY) / T);

        complex double c, z;

        int n = ite;

        int array[T][A];

        for(int i = 0; i < T; i++) {
                for(int j = 0; j < A; j++) {
                        c = (lLX + (j * dX)) + ((uLY - (i * dY)) * I);
                        z = c;
                        array[i][j] = mandelbrotSet(z, c, n);
                }
        }

        FILE *fptr;
        fptr = fopen("yogiornogiovanatengounsuegno.pgm", "w");

        //Condicional para archivo corrupto.
        if(fptr == NULL) {
                printf("Archivo no existente. :'v \n");
        }

        fprintf(fptr, "%s \n", "P2");
        fprintf(fptr, "%d %d \n", T, A);
        fprintf(fptr, "%d \n", 1);
        for(int i = 0; i < T; i++) {
                for(int j = 0; j < A; j++) {
                        fprintf(fptr, "%d ", array[i][j]);
                }
                fprintf(fptr, "\n");
        }
        fclose(fptr);
}

int mandelbrotSet(complex double fz, complex cnum, int knn) {
        fz = cpow(fz, 2) + cnum;
        if(knn > 0)
                return mandelbrotSet(fz, cnum, knn-1);
        else if(cabs(fz) > 2)
                return 0;
        else
                return 1;
}
