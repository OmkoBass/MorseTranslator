#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define COMMANDS 3

//A B C etc...
char *LETTERS[27] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", 
"....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", 
".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

char a = 'a';

void toMorse();
void toEnglish();
void out();
void clearScreen();

void (*which[COMMANDS])() = {toMorse, toEnglish, out};

void toMorse()
{
    int i = 0;
    char *word = malloc(sizeof(char) * 64);

    printf("Enter your word in english: ");

    scanf("%s", word);

    clearScreen();
    printf("Morse: ");
    while(word[i] != '\0')
    {
        printf("%s ", LETTERS[word[i] - a]);
        i++;
    }
    printf("\n\n\n");
}

//TODO
void toEnglish()
{
    
}

void clearScreen()
{
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void out() { exit(0); }

void choose(int n)
{
    if(n >= 0 && n <= COMMANDS)
        (which[n-1])();
    else
        return;
}

int main()
{
    int choice;

    while(1)
    {
        printf("\t---MORSE CODE TRANSLATOR---\n");
        printf("1. English to morse.\n2. Morse to english.\n3.Exit\n");
        scanf("%d", &choice);

        choose(choice);
    }
    
    return 0;
}
