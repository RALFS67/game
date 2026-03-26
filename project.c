
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>


void scoretracker(int gold, int player, int* player1Score, int* player2Score, char type, int* player1Bombs, int* player2Bombs);
void game(char *playerName1 , char *playerName2,int* player1TotalWins , int* player2TotalWins);

int main()
{
    srand((int)time(0));//ALE

    char playAgain;

    char player1Name[20]; // USERNAME
    char player2Name[20]; // USERNAME

    int player1TotalWins = 0, player2TotalWins = 0;

    char password[] = "67"; //ale
    char input[10];


    for (int i = 0; i < 3; i++) {
        printf("Enter the password: ");
        fgets(input, sizeof(input), stdin);

        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        if (strcmp(password, input) == 0) {
            printf("Correct password! The game starts now.\n");



            break;
        }
        else {
            if (i == 2) {
                printf("Wrong password. No attempts left. Exit.\n");
                return 0;
            }
            else {
                printf("Wrong password... do you have Alzheimer's or something?\n");
            }
        }
    }


    printf("Enter name for Player 1: "); // USERNAME
    fgets(player1Name, sizeof(player1Name), stdin); // USERNAME
    if (player1Name[strlen(player1Name) - 1] == '\n') { // USERNAME
        player1Name[strlen(player1Name) - 1] = '\0'; // USERNAME
    }

    printf("Enter name for Player 2: "); // USERNAME
    fgets(player2Name, sizeof(player2Name), stdin); // USERNAME
    if (player2Name[strlen(player2Name) - 1] == '\n') { // USERNAME
        player2Name[strlen(player2Name) - 1] = '\0'; // USERNAME
    }



   game(player1Name,player2Name,&player1TotalWins,&player2TotalWins);

   for (int i = 0; i < 2; i++) {
       printf("Would you like to play again [y/n]: ");
       scanf_s(" %c", &playAgain);

       if (playAgain == 'y' || playAgain == 'Y') {
           printf("Total wins: %s: %i \t %s: %i\n", player1Name, player1TotalWins, player2Name, player2TotalWins);

           game(player1Name, player2Name, &player1TotalWins, &player2TotalWins);

           i = 0;

       }
       else if (playAgain == 'n' || playAgain == 'N') {
           printf("See you next time :)");
           break;
       }
   }

    return 0;
}

void game(char* playerName1, char* playerName2, int* player1TotalWins, int* player2TotalWins) {
    char displayGrid[6][6];
    uint8_t values[6][6];
    int row, col, size = 6, loop;
    int gold = 0;
    int player1Score = 0, player2Score = 0, player1Bombs = 0, player2Bombs = 0;

    int locationX, locationY;

    

    int currentPlayer;
    int randomStart = rand() % 2;//ALE 
    if (randomStart % 2 == 0)
        currentPlayer = 1;
    else
        currentPlayer = 2;

    if (currentPlayer == 1) // USERNAME
        printf("%s starts first!\n", playerName1); // USERNAME
    else
        printf("%s starts first!\n", playerName2); // USERNAME

    for (row = 0; row < size; row++) {
        for (col = 0; col < size; col++) {
            values[row][col] = rand() % 256;
            displayGrid[row][col] = '?';
        }
    }

    printf("---------------------------------------------------------------------------------\n");
    printf("|\t\t\t\tKEY\t\t\t\t\t\t|\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("|$ = gold\t ! = bomb \t # = empty space \t ? = unknown space\t|\n");
    printf("---------------------------------------------------------------------------------\n\n");


    for (row = 0; row < size; row++) {
        if (row == 3) {
            printf("\tY\t%d|", row);
        }
        else {
            printf("\t\t%d|", row);
        }

        for (col = 0; col < size; col++) {
            printf(" \t%c ", displayGrid[row][col]);
        }
        printf("\n");
    }
    printf("\t\t\t------------------------------------------\n");
    printf("\t\t\t0 \t1 \t2 \t3 \t4 \t5\n");
    printf("\t\t\t------------------------------------------\n");
    printf("\t\t\t  \t  \t    X \t \t \n");


        for (loop = 0; loop < 36; loop++) {


            if (currentPlayer == 1) // USERNAME
                printf("%s is your turn \n", playerName1); // USERNAME
            else
                printf("%s is your turn \n", playerName2); // USERNAME

            do {

                printf("choose a location [y]: ");
                scanf_s("%d", &locationY);
                printf("choose a location [x]: ");
                scanf_s("%d", &locationX);

                if (displayGrid[locationY][locationX] != '?') {
                    printf("This location has already been searched, try again!\n");
                }

                

            } while (displayGrid[locationY][locationX] != '?' );

            // printf("You just choose [%d][%d] the real number is: %d\n", locationX, locationY, values[locationX][locationY]);


            if (values[locationY][locationX] & 1) {

                displayGrid[locationY][locationX] = '!';
                printf("You found a bomb !\n");

            }

            else if (values[locationY][locationX] & 2) {
                displayGrid[locationY][locationX] = '$';

                values[locationY][locationX] = (values[locationY][locationX] >> 4);

                gold = values[locationY][locationX];
                if (gold == 0) {

                    if (currentPlayer == 1) {
                        printf("%s found an empty tressure chest :(", playerName1);
                    }
             
                    else {
                        printf("%s found an empty tressure chest :(", playerName2);
                    }
                }
                else {
                    if (currentPlayer == 1) {
                        printf("\n%s found %i gold", playerName1,gold);
                    }

                    else {
                        printf("\n%s found %i gold", playerName2, gold);
                    }
                }
            }

            else
            {
                displayGrid[locationY][locationX] = 'X';

            }

            scoretracker(gold, currentPlayer, &player1Score, &player2Score, displayGrid[locationY][locationX], &player1Bombs, &player2Bombs);



            printf("\nGrid:\n");

            printf("\ncurrent score: %s: %i \t %s: %i \t%s bomb(s): %i \t %s bomb(s): %i \n",
                playerName1, player1Score,
                playerName2, player2Score,
                playerName1, player1Bombs,
                playerName2, player2Bombs); // USERNAME



            for (row = 0; row < size; row++) {
                if (row == 3) {
                    printf("\tY\t%d|", row);
                }
                else {
                    printf("\t\t%d|", row);
                }

                for (col = 0; col < size; col++) {
                    printf(" \t%c ", displayGrid[row][col]);
                }
                printf("\n");
            }
            printf("\t\t\t------------------------------------------\n");
            printf("\t\t\t0 \t1 \t2 \t3 \t4 \t5\n");
            printf("\t\t\t------------------------------------------\n");
            printf("\t\t\t  \t  \t    X \t \t \n");

            currentPlayer = 3 - currentPlayer;//Alessandro

            if (player1Score >= 50) {
                printf("\n%s has won the game !!!\n", playerName1);
                (*player1TotalWins)++;
            }
            else if (player2Score >= 50) {
                printf("\n%s has won the game !!!\n", playerName2);
                (*player2TotalWins)++;
            }
            else if (loop == 35) {
                if (player1Score > player2Score) {
                    printf("\n%s has won the game !!!\n", playerName1);
                    (*player1TotalWins)++;
                }
                else if (player1Score < player2Score) {
                    printf("\n%s has won the game !!!\n", playerName2);
                    (*player2TotalWins)++;
                }
                else {
                    printf("\nThere has been a draw\n");



                }

            }
        }


    
}

void scoretracker(int gold, int player, int* player1Score, int* player2Score, char type, int* player1Bombs, int* player2Bombs)
{
    if (type == '$') {
        if (player == 1) {
            *player1Score = *player1Score + gold;
        }
        else {
            *player2Score = *player2Score + gold;
        }
    }
    if (type == '!') {
        if (player == 1) {
            *player1Score = *player1Score - 1;
            (*player1Bombs)++;
        }
        else {
            *player2Score = *player2Score - 1;
            (*player2Bombs)++;
        }
    }
}