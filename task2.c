#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sgelem.h"


double evklid_norm(void *matrix, int rows_n, int cols_n){

    int sum = 0;

    for (int i = 0; i < rows_n; ++i) {
        for (int j = 0; j < cols_n; ++j) {

            sum += fabs(get_elem(matrix, rows_n, cols_n) * get_elem(matrix, rows_n, cols_n));

            printf("%4.2f  ", get_elem(matrix, rows_n, cols_n));

        }
    printf("\n");
    }        return sqrt(sum);
}



int main(int argc, char *argv[])
{

    int rows_n, cols_n;

    if (argc == 1) {

        printf("not files\n");
        exit(1);
    }


    while (--argc > 0) {

        FILE *ptrFile = fopen(argv[argc], "r+");

        if (ptrFile == NULL) {

            printf("Error opening file\n");
            exit(1);
        }


        fscanf(ptrFile, "%d %d", &rows_n, &cols_n);


        double **matrix = malloc(sizeof(double *) * rows_n);

        for (int i = 0; i < rows_n; i++) {
            matrix[i] = malloc(sizeof(double) * cols_n);
        }

        double elem = 0;


        while (fscanf(ptrFile, "%lf", &elem) == 1) {

            set_elem(*matrix, rows_n, cols_n, elem);

        }



    }

    /*for (int i = 0; i < rows_n; i++) {
        for (int j = 0; j < cols_n; j++) {
            printf("%4.2f  ", get_elem(*matrix, rows_n, cols_n));
        }
        printf("/n");
    }*/

    return 0;

}