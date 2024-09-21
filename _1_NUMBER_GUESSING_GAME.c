//NUMBER GUESSING GAME PROJECT
/*
WHATS INCLUDED:
1.3 DIFFICULTY LEVELS ACCORDING TO USER'S CHOICE
2.NUMBER OF GUESSES USER TOOK TO GUESS THE NUMBER
3.QUITTING OF THE GAME BY PRESSING A SINGLE BUTTON
*/
#include<stdio.h>
#include<stdlib.h>  //to use rand(),srand()
#include<time.h>    //to use time()
//Function to play the game ie to take number input from user and then matching it with the number generated
void game(int n)
{
    int guesses = 0;    //calculates the number of guesses
    int guessed_number; //to take a number input from user to match it with the number generated
    //the loop runs until the user guesses the correct number and exits when the user presses 0
    do
    {
        printf("Enter the number: \n");
        scanf("%d", &guessed_number);
        if (guessed_number==0)
        {   //exits the program if user presses 0
            printf("Exited the game...\n");
            printf("GUESSES : %d", guesses);
            return 0;
        }
        else if(guessed_number<n)
        {   //if user guesses a low number
            guesses++;
            printf("WRONG!\tHIGHER NUMBER PLEASE\n");
        }
        else if(guessed_number>n)
        {   //if user guesses a high number
            guesses++;
            printf("WRONG!\tLOWER NUMBER PLEASE\n");
        }
        else
        {   //if user guesses the correct number
            guesses++;
            printf("CONGRATULATIONS!!! YOU GUESSED IT RIGHT\n");
            printf("GUESSES YOU TOOK: %d", guesses);
            break;
        }
    }while(guessed_number != n);    //loop runs until the user guesses something
}
int main()
{
    printf("\033[36;1m");  //ansi codes for cyan color and bold
    printf("\t\t\t\tWELCOME TO THE NUMBER GUESSING GAME CREATED BY DIPAYAN\n");
    int difficulty;     //for difficulty level of the game
    printf("1-easy:you have to guess a number from 1 to 100\n"
           "2-medium: you have to guess a number from 1 to 1000\n"
           "3-hard: you have to guess a number from 1 to 10000\n");
    printf("Choose the difficulty level (1-easy, 2-medium, 3-hard): \n");
    scanf("%d",&difficulty);
    srand(time(0)); //ensures different sequences of random numbers each time the program runs
    int random_number;  //to generate a random number
    switch(difficulty)  //cases for specific difficulty levels
    {
        case 1:
            printf("\tGOOD CHOICE!\tLET\'S START THE GAME\tTO END THE GAME PRESS 0\n");
            random_number = rand() % 100 + 1;   //generates a random number between 1 and 100
            game(random_number);
            break;
        case 2:
            printf("\tVERY GOOD CHOICE!\tLET\'S START THE GAME\tTO END THE GAME PRESS 0\n");
            random_number = rand() % 1000 + 1;  //generates a random number between 1 and 1000
            game(random_number);
            break;
        case 3:
            printf("\tEXCELLENT CHOICE!\tLET\'S START THE GAME\tTO END THE GAME PRESS 0\n");
            random_number = rand() % 10000 + 1; //generates a random number between 1 and 10000
            game(random_number);
            break;
        default:
            printf("Invalid difficulty level. Please try again.\n");
            return 0;
    }
}