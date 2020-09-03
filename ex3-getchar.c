#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char c;
    int i = 0;
    
    while ((c = getchar()) != EOF && i++ < 10) {
        if (c == '\n' || c == ' ') {
            i--;
            continue;
        }
            
        putchar(c);
        putchar('\n');
    }
        
    return 0;
}
