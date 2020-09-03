#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    float rate;
    float pound;
    int lower, upper, step;
    
    if (argc < 2) {
        printf("Usage: a.out <rate>\n");
        return -1;
    }
    
    rate = atof(argv[1]);
    
    if (rate < 0) {
        printf("Negative rate not allowed: %f\n", rate);
        return -1;
    }
    
    lower = 1;
    upper = 100;
    step = 10;
    
    pound = lower;
    
    printf("UK pounds  Euros\n");
    
    printf("%9.2f %6.2f\n", pound, pound * rate);
    
    pound = step;
    while (pound <= upper) {
        printf("%9.2f %6.2f\n", pound, pound * rate);
        pound += step;
    }
        
    return 0;
}
