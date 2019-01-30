#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

//** Caesar.c  A program that encrypts messages using Caesar’s cipher. Your program must
 // accept a single command-line argument: a non-negative integer. If your program is executed without any
 // command-line arguments or with more than one command-line argument, your
  //program should yell at the user and return a value of 1.



int main(int argc, string argv[])
{
    int key = atoi(argv[1]);  //convert the string argument into int
    if (argc != 2)   // check for 2 argument
    {
        printf("Write two arguments ,please\n");
        return 1;
    }
    if (key < 0)   // check for positive integer
    {
        printf("write a positve argument, please\n");
        return 1;
    }

    string word = get_string("a word: \n"); //prompt for the plaintest
    int my_ci_ASCII[strlen(word)];

    for (int i = 0; i < strlen(word); i++)
    {
        int char_ASCII, char_alph, c;

        if (isalpha(word[i]))   // check for alpha
        {
            if (isupper(word[i]))   // check for uppercase
            {
                char_ASCII = (int) word[i];
                char_alph = char_ASCII - 'A';
                c = (char_alph + key) % 26 + 'A';
                my_ci_ASCII[i] = c;
            }
            else
            {
                char_ASCII = (int) word[i];
                char_alph = char_ASCII - 'a';
                c = ((char_alph + key) % 26) + 'a';
                my_ci_ASCII[i] = c;
            }
        }
        else
        {
            my_ci_ASCII[i] = (int)(word[i]);
        }
    }
    printf("ciphertext: ");
    for (int i = 0; i < strlen(word); i++) // covert the array with contains the ASCII number for ciphertest
    {
        printf("%c", my_ci_ASCII[i]);
    }
    printf("\n");
    return 0;
}
