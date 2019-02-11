#include <stdio.h>
#include <complex.h>
#include <math.h>

//Estructura prrona, alv, compa. :v
typedef struct {
        double x;
        double y;
}cin;

int mandelbrotSet(double, float, int);

int main() {
        //Declarar constante que se utilizarán.
        const int ite = 100; //Número de Iteraciones.
        const int T = 128;   //Tuplas de la Matriz. :v
        const int A = 128;   //Atributos de la Matriz. :v
        const float lLX = -1.5; //Límite mínimo de X.
        const float uLX = 1.5;  //Límite máximo de X.
        const float lLY = -1.0; //Límite Mínimo de Y.
        const float uLY = 1.0;  //Límite Máximo de Y.

        double dX = ((uLX - lLX) / A);
        double dY = ((uLY - lLY) / T);
        double fx, fy;

        cin c;

        int n = ite;

        int array[T][A];

        for(int i = 0; i < T; i++) {
                for(int j = 0; j < A; j++) {
                        c.x = (lLX - (j * dX));
                        c.y = (uLY - (i * dY));
                        array[i][j] = mandelbrotSet();
                }
        }

        printf("Matriz: \n");
        for(int i = 0; i < T; i++) {
                for(int j = 0; j < A; j++) {
                        printf("%d ", array[i][j]);
                }
                printf("\n");
        }
}

int mandelbrotSet(double fnZ, float cnum, int nn) {
        fnZ += pow(fnZ, 2) + cnum;

        if(fnZ > 2)
                return 0;
        else if(nn == 0)
                return 1;
        else
                return mandelbrotSet(fnZ, cnum, nn-1);
}
