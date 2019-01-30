#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

//The heart of this problem is to be familiar with using modulo for wraparound and how to divide elements into a certain number of groupes and take care of the elements order for example if we have 5 elements and we want to divide them into 3 groups , we will do 1 element % 3 = 1 , 2 element % 3 =2 , 3 element % 3 =0 ,and 4 element % 3 = 1..... so group number 1 will contain those elements with modulo 1 and group number 2 will contain those elements with modulo 2 and group number 0 will contain elements with modulo 0 and so forth. so the number of groups will not acceed the three and we will take care of the order as well  

void gettheciph(string keyword, string plainword);
int main(int argc, string argv[])
{
    if (argc <= 1)
    {
        printf("write more than one argument,please \n");
        return 1;
    }
    string keyword[argc];   
    for (int i = 1; i < argc; 
         i++) //check the arguments if they are all char and create an array called keyword its elements is the word provided as arguments
    {
        bool False = 0;
        keyword[i] = argv[i];
        for (int j = 0; j < strlen(keyword[i]); j++)
        {
            if (isalpha(keyword[i][j]) == False)
            {
                printf("write just letters \n");
                return 1;
            }
        }        
    }
    
    string plainword = get_string("write your plainstatment : \n"); //prompt for the plaintest    
    for (int i = 1; i < argc; 
         i++) // loop to iterate over the string arguments  
    {
        keyword[i] = argv[i];
        gettheciph(keyword[i], 
                   plainword); //called the gettheciph function to obtain the ciphertext , called many times if more than one argument provieded 
        printf("  ");
        printf("\n");
       
    }
    return 0;
}

void gettheciph(string keyword, 
                string plainword) //declare a function whose purpose to get the keyword and plainword and print the ciphertext 
{
    int my_ci_ASCII[strlen(plainword)];
    for (int i = 0, j = 0; i < strlen(plainword); i++)
    {
        int char_ASCII, char_alph, c, key;
        
        if (isalpha(plainword[i]))   // check for alpha
        {
            key = tolower(keyword[j % strlen(keyword)]) - 'a'; //convert the keyword to its alpha order , using modulo for wraparound
            j++;
            if (isupper(plainword[i]))   // check for uppercase
            {
                char_ASCII = (int) plainword[i];
                char_alph = char_ASCII - 'A';
                c = (char_alph + key) % 26 + 'A';
                my_ci_ASCII[i] = c;
            }
            else
            {
      
                char_ASCII = (int) plainword[i];
                char_alph = char_ASCII - 'a';
                c = ((char_alph + key) % 26) + 'a';
                my_ci_ASCII[i] = c;
            }
        }
        else
        {
            my_ci_ASCII[i] = (int)(plainword[i]);
        }
    }
    for (int i = 0; i < strlen(plainword); i++) // covert the array which contains the ASCII number for ciphertest
    {
        printf("%c", my_ci_ASCII[i]);
    }
}
