#include <stdio.h>

int main(int argc, char **argv) {
    int i = -1;
    char* mode = "w";
    FILE *f = NULL;
    int stat = -1;
    int snum = 0;
    
    if (argc < 2) {
        printf("Usage: ./a.out <filename>\n");
        return stat;
    }
         
    snum = scanf("%d", &i);
    
    if (i < 1 || snum < 1) {
        printf("Not writing unrecognised value or number less than 1\n");
        return stat;
    }
        
    printf("Attempting to write %d to file %s ... \n", i, argv[1]);

    if ((f = fopen(argv[1], mode)) != NULL) {
        stat = 0;
        
        if (fprintf(f, "%d\n", i) < 1 || fclose(f) != 0)
            stat = -1;
    }
        
        
    if (stat == -1)
        perror("I/O error");
     
    return stat;   
}