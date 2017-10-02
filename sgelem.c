//
// Created by Vladislav Raspopin on 01.10.17.
//
double get_elem(double *matr, int row, int col) { //возвращает значение элемента матрицы по его индексам

    double **ptr = (double**)(matr);

    return ptr[row][col] ;


}


void set_elem(void * matr, int row, int col, double elem) { //устанавливает значение элемента матрицы по его индексам

    double **ptr = (double**)(matr);

    ptr[row][col] = elem;

}

