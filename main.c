#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sgelem.h"


double evklid_norm(double *matr, int row, int col ){

    int sum = 0;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {

            sum += fabs(get_elem(matr, i, j) * get_elem(matr, i, j));

            //printf("%4.2f  ", get_elem(matr, i, j));

        }
    printf("\n");
    }        return sqrt(sum);
}



int main(int argc, char *argv[]) {

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




        for(int i = 0; i < rows_n; ++i)
        {
            for(int j = 0; j < cols_n; ++j)
            {
                fscanf(ptrFile, "%lf", &elem) ;

                set_elem(matrix, i, j, elem);

                printf("[%d,%d:]  %4.2f  ",i, j, matrix[i][j]);

            }
                printf("\n");
        }




        for(int i = 0; i < rows_n; ++i)
        {
            for(int j = 0; j < cols_n; ++j)
            {

                printf("[%d,%d:]  %4.2f  ",i, j, get_elem(matrix, i, j));

            }
            printf("\n");
        }

        printf("%f\n", evklid_norm(matrix, rows_n, cols_n ));

        for (int i = 0; i < cols_n; i++) {
            free(matrix[i]);
        }
        free(matrix);

    }



    return 0;

}