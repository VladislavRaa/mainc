#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "node.h"
#define MSG_LEN 1024

char* cut(char* str)
{
    char* cut_string = (char*)malloc(strlen(str) * sizeof(char));

    if (cut_string == NULL) {
        printf("cut: Could not allocate memory for string storage");
        return NULL;
    }

    for(int i = 0; i < strlen(str); i++) {
        cut_string[i] = str[i+1];
    }

    return cut_string;
}
int catch_error (FILE * file, int error_num)
{
    if (file == NULL)
    {
        char error_buf[MSG_LEN];
        int  error = strerror_r(error_num,error_buf,MSG_LEN);
        switch (error)
        {
            case EINVAL:
                fprintf (stderr, "strerror_r() failed: invalid error code, %d\n", error);
                break;
            case ERANGE:
                fprintf (stderr, "strerror_r() failed: buffer too small: %d\n",error);
            case 0:
                fprintf(stderr, "Error message : %s\n", error_buf);
                break;
            default:
                fprintf (stderr, "strerror_r() failed: unknown error, %s\n", error_buf);
                break;
        }
        return 0;
    }
    return 1;
}


int main(int argc,const char* argv[]) {

    errno = 0;
    FILE *file = fopen(argv[1],"r");

    if (catch_error(file, errno) == 0) {
        exit(1);
    }


    char elem[1024];
    char* s;

    fscanf(file, "%s", elem);
    s = cut(elem);

    TreeElem* root = 0;
    root = new_tree_elem(s, root);
    free(s);

    while (fscanf(file, "%s", elem) == 1 ) {
        s = cut(elem);

        if (elem[0] == '+') {
            if (find_parent_tree(s, root) != 0) {
                free(s);
                continue;
            }
            TreeElem* treeelem = new_tree_elem(s, root);
            free(s);
            continue;
        }
        if (elem[0] == '-') {
            if (find_parent_tree(s, root) == 0)
            {
                free(s);
                continue;
            }
            remove_elem_tree(s, root);
            free(s);
            continue;
        }
        if (elem[0] == '?') {
            if (find_parent_tree(s,root) == 0)
            {
                printf("%s - NO\n", s );
                free(s);
                continue;
            }
            printf("%s - YES\n", s );
            free(s);
            continue;
        }
    }

    fclose(file);
    delete_tree(root);

    return 0;
}