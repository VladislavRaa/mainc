#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
//
// Created by Vladislav Raspopin on 02.10.17.
//
Matrix* create_matrix_from_file(FILE* file) {

    int row = 0, col = 0;

    fscanf(file, "%d %d", &row, &col);

    Matrix *matrix = create_matrix(row, col);

    double elem = 0;

    for (int i = 0; i < row; ++i) {
        for (int j = 0;j < col; ++j) {

            fscanf(file, "%lf", &elem);
            set_elem(matrix, i, j, elem);
        }
    }

    fclose(file);

    return matrix;
}

Matrix *create_matrix(int row, int col){

    Matrix *array = malloc(sizeof(Matrix));

    array->matr = (double **)calloc(row, sizeof(double *));

    for (int i = 0; i < row; ++i) {

        array->matr[i] = (double *)calloc(col, sizeof(double));

    }

    array->rows = row;
    array->cols = col;

    return array;
}

void free_matrix(Matrix *matrix){
    {

        for (int i = 0; i < get_rows(matrix); ++i) {

            free(matrix -> matr[i]);

        }

        free(matrix->matr);
        free(matrix);
    }
}

double get_elem(Matrix *matrix, int row, int col){

    return matrix->matr[row][col];

}

void set_elem(Matrix *matrix, int row, int col, double val){

    matrix->matr[row][col] = val;

}

int get_rows(Matrix *matrix){

    return matrix -> rows;
}

int get_cols(Matrix *matrix){

    return matrix->cols;

}