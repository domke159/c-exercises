#include <stdio.h>
#include <stdlib.h>

void clearstdin(void);

/* 
 * Note: the main method is an implementation of binary search to find
 * a number between 1 and 100. If implemented correctly, it is guaranteed to 
 * complete in 7 steps or less - dividing the search space in half at each step
 * (which is why humans are only allowed 7 guesses in exercise 6).
 *
 * Of course, the "computer" will keep guessing forever if you lie about the 
 * number you ask it to find.
 */
int main(void) {
    int num = 0;
    int guesses = 0;
    int stat;
    char ans = 0;
    int floor = 1;
    int ceiling = 100;
    int guess = 50;
    
    printf("Think of a number between 1 and 100\n");
    
    while (guess != num) {
        guesses++;
        printf("Is your number less than (<), greater than (>) or equal to (=) %d? ", guess);
        
        ans = getchar();
        
        while (ans != '<' && ans != '>' && ans != '=') {
            /* make sure nothing else on stdin before ask again */
            clearstdin();
            
            printf("Please answer one of the following:\n");
            printf("   '<' if your number is less than %d\n", guess);
            printf("   '>' if your number is greater than %d\n", guess);
            printf("   '=' if your number is equal to %d\n", guess);
            
            ans = getchar();
        }
    
        if (ans == '=') {
            break;
        } else if (ans == '<') {
            ceiling = guess;
            guess = (guess + floor) / 2;
        } else if (ans == '>') {
            floor = guess;
            guess = (guess + ceiling) / 2;
        }
        
        /* only want one answer at a time */
        clearstdin();
    }
    
    printf("I took %d guesses to find your number: %d\n", guesses, guess);

    return 0;   
}

/* 
 * See ex6-userguess re. purging unwanted characters from stdin.
 */
void clearstdin(void) {
    char c;
    
    if (feof(stdin) || ferror(stdin))
        clearerr(stdin);
        
    while ((c = getchar()) != EOF && c != '\n')
        ;
}

