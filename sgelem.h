//
// Created by Vladislav Raspopin on 01.10.17.
//

#ifndef UNTITLED_SGELEM_H
#define UNTITLED_SGELEM_H

double get_elem(double *matr, int row, int col) { //возвращает значение элемента матрицы по его индексам
    double *ptr = (matr + row);
    return ptr[col] ;


}


void set_elem(void * matr, int row, int col, double elem) { //устанавливает значение элемента матрицы по его индексам

    double *ptr = (double*) (matr + row);
    ptr[col] = elem;

    /*for(int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            printf("%4.2f  ",ptr[col]);
        }
    printf("/n");
    }*/
}

#endif //UNTITLED_SGELEM_H
