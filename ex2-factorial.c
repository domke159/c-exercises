#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int rfactorial(int n);

int main(int argc, char **argv) {
    int n;
    int fac;
    int rfac;
    
    if (argc < 2) {
        printf("Usage: a.out <n>\n");
        return -1;
    }
    
    n = atoi(argv[1]);
    fac = factorial(n);
    rfac = rfactorial(n);
    
    if (fac > 0) {
        printf("factorial(%d):  %d\n", n, fac); 
        printf("rfactorial(%d): %d\n", n, fac); 
        return 0;
    } else {
        printf("cannot calculate factorial of %d\n", n);
        return -1;
    }
}

int factorial(int n) {
    int i;
    int f = 1;
    
    if (n < 0)
        return -1;
        
    for (i = 0; i < n; i++)
        f = f * (i + 1);
       
    return f;
}

int rfactorial(int n) {
    int f;
    
    if (n < 0) 
        return -1;
    
    if (n == 0)
        return 1;
    
    return n * rfactorial(n - 1);
}

