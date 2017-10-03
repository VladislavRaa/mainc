#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "matrix.h"

#define MSG_LEN 1024

double evklid_norm(Matrix *matr, int row, int col) {

    int sum = 0;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {

            sum += pow(get_elem(matr, i, j), 2);

        }
    }

    return sqrt(sum);
}

void catch_error(int error, char *error_buf) {

    switch (error) {
        case EINVAL:

            fprintf (stderr, "strerror_r() failed: Invalid argument, %d\n", error);

            break;

        case ERANGE:

            fprintf (stderr, "strerror_r() failed: buffer too small: %d\n", MSG_LEN);

            break;

        case ENOENT:

            fprintf (stderr, "strerror_r() failed: No such file or directory: %d\n", MSG_LEN);

            break;

        case 0:

            fprintf(stderr, "Error message : %s\n", error_buf);
            break;

        default:

            fprintf (stderr, "strerror_r() failed: unknown error, %d\n", error);
            break;
    }

    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {

    errno = 0;

    errno_t error_num = errno;

    char error_buf[MSG_LEN];

    if (argc == 1) {

        error_num = EINVAL;
        errno_t error = strerror_r (error_num, error_buf, MSG_LEN);
        catch_error(error, error_buf);

    }

    while (--argc > 0) {
        
        FILE *input_file = fopen(argv[argc], "r");

        if(input_file) {


            Matrix *array = create_matrix_from_file(input_file);

            printf("%10.4f\n", evklid_norm(array,get_rows(array),get_cols(array)));

            free_matrix(array);

        }

        else {

            error_num = ENOENT;

            errno_t error = strerror_r (error_num, error_buf, MSG_LEN);

            catch_error(error, error_buf);

        }


    }

    return EXIT_SUCCESS;
}