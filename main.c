#include <stdio.h>
#include <stdlib.h>
//#include <memory.h>



int main(int argc, char *argv[])
{

    int zero = 0;
    int c;
    int temp_size = 0;
 
    if (argc != 2) {
     
        printf("error arguments\n");
        exit(1);
    }

    FILE *ptrFile = fopen(argv[1], "r+t+"); //r+t+ для открытия .txt

    if (ptrFile == NULL) {
     
        printf("Error opening file\n");
        exit(1);
    }



    while (fscanf(ptrFile, "%d", &c) == 1) {   //%c буква

        temp_size += 1;

        if (c == 0) {

            zero++;
        }
      
    }

    int *temp_massive = (int*) calloc(temp_size, sizeof(int));
    //memset(temp_massive, 0, temp_size);
    rewind(ptrFile);

    for (int i = zero; i < temp_size; i++)
    {

        fscanf(ptrFile, "%d", &temp_massive[i]);
        
        if (temp_massive[i] == 0) 
            i--;
     
    }


    for (int i = zero; i < temp_size; i++) {// сортировка вставками
        for (int j = i; j > zero && temp_massive[j - 1] > temp_massive[j]; j--) {

            int temp = temp_massive[j];
            temp_massive[j] = temp_massive[j-1];
            temp_massive[j-1] = temp;


        }
    }



    rewind(ptrFile);
    
    for (int i = 0; i < temp_size ; i++) {

    fprintf(ptrFile, "%d ", temp_massive[i]);
   
    } 

   // printf("%d ", temp_size);

    fclose(ptrFile);
    free(temp_massive);


    return 0;
}
