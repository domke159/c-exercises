#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void purgestdin(int status);

int main(void) {
    int num;
    int guesses = 0;
    int guess = 0;
    int stat;
    char c;
    
    srand(time(NULL));
    
    num = (rand() % 100) + 1;
    
    while (guesses++ < 7 && guess != num) {
        guess = -1;
        printf("Guess %d: choose a number between 1 and 100: ", guesses);
        stat = scanf("%d", &guess);
        
        if (guess < 1 || guess > 100) {
            guesses--;
            
            purgestdin(stat);
                
            printf("\nInvalid guess: %d\n", guess);      
        } else if (guess > num) {
            printf("The number is less than: %d\n", guess);
        } else {
            printf("The number is greater than: %d\n", guess);
        }
    }
    
    if (guess == num)
        printf("Well done, you guessed correctly!\n");
    else 
        printf("You need to think harder, you have run out of guesses\n");
        
    printf("You had %d guesses, the number is: %d\n", --guesses, num);
    
    return 0;   
}

/* 
 * It is possible for scanf to leave errors and or characters on stdin.
 * Most systems have an fpurge function to clear an input stream (similar to 
 * fflush to clear an output stream). MINIX 3.1.8 only has fflush not fpurge.
 * The following function has a similar effect to fpurge.
 * To see the need for purging stdin, uncomment the call at line 26 above and
 * enter something other than a when asked to make a guess. clearerr, feof and
 * ferror are part of stdio.h
 */
void purgestdin(int status) {
    char c;
    
    if (feof(stdin) || ferror(stdin))
        clearerr(stdin);
        
    if (status < 1)
        while ((c = getchar()) != EOF && c != '\n')
            ;
}
