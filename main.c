#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>
#include "matrix.h"
#include <string.h>
#define MSG_LEN 1024

double evklid_norm(Matrix *matr, int row, int col)
{
    int sum = 0;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {

            sum += pow(get_elem(matr, i, j), 2);

        }
    }

    return sqrt(sum);
}

int main(int argc, char* argv[]) {

    errno = 0;

    errno_t error_num = errno;
    char error_buf[MSG_LEN];

    if (argc == 1) {
       // error =
        //printf("not files\n");
        //exit(1);
    }

    while (--argc > 0) {

        errno = 0;

        FILE *input_file = fopen(argv[argc], "r");

        if(input_file) {



       // if (input_file == NULL) {
            // errno_t error = strerror_r(error_num, error_buf, MSG_LEN);
            //printf("Error opening file\n");
            //exit(1);
        //}

        Matrix *array = create_matrix_from_file(input_file);

        printf("%10.4f\n", evklid_norm(array,get_rows(array),get_cols(array)));

        free_matrix(array);

        }

        else {
            errno_t error = strerror_r (error_num, error_buf, MSG_LEN);

            switch (error) {
                case EINVAL:
                    fprintf (stderr, "strerror_r() failed: invalid error code, %d\n", error);
                    break;
                case ERANGE:
                    fprintf (stderr, "strerror_r() failed: buffer too small: %d\n", MSG_LEN);
                case 0:
                    fprintf(stderr, "Error message : %s\n", error_buf);
                    break;
                default:
                    fprintf (stderr, "strerror_r() failed: unknown error, %d\n", error);
                    break;
            }
        }


    }

    return 0;
}