
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

void scoretracker(int gold,int player,int *player1Score , int *player2Score, char type, int *player1Bombs, int *player2Bombs);

int main()
{
    char displayGrid[6][6];
    uint8_t values[6][6];
    int row, col, size = 6;
    int gold = 0;
    int player1Score = 0, player2Score = 0, player1Bombs = 0, player2Bombs = 0;
    

    

    int locationX, locationY;

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

    srand((int)time(0));//ALE

    int currentPlayer;
    int randomStart = rand() % 2;//ALE 
    if (randomStart % 2 == 0)
        currentPlayer = 1;
    else
        currentPlayer = 2;
    printf("Player %d starts first!\n", currentPlayer);

    for (row = 0; row < size; row++) {
        for (col = 0; col < size; col++) {
            values[row][col] = rand() % 256;
            displayGrid[row][col] = '$';
        }
    } //Ale


    printf("\Grid:\n");//RalfsStart
    for (row = 0; row < size; row++) {
        printf("%d\t", row);
        for (col = 0; col < size; col++) {
            printf("[%d][%d] %c ", row, col, displayGrid[row][col]);
        }
        printf("\n"); 
    }
    printf("\t1\t2\t3\t4\t5\t6\n");//ralfsEnd


    for (int loop = 0; loop < 36; loop++) {


        printf("Player %d is your turn \n", currentPlayer); // MULTIPLAYER ALE
        
        do {//RalfsStart

            printf("choose a location [x]: ");
            scanf_s("%d", &locationX);
            printf("choose a location [y]: ");
            scanf_s("%d", &locationY);
        
            if (displayGrid[locationX][locationY] != '$') {
                printf("This location has already been searched, try again!\n");
            }

        } while (displayGrid[locationX][locationY] != '$');

        printf("You just choose [%d][%d] the real number is: %d\n", locationX, locationY, values[locationX][locationY]);
        

        if (values[locationX][locationY] & 1) {

            displayGrid[locationX][locationY] = 'B';
            printf("You found a bomb !\n");

        }

        else if (values[locationX][locationY] & 2) {
            displayGrid[locationX][locationY] = 'G';

            values[locationX][locationY] = (values[locationX][locationY] >> 4);
            
            gold = values[locationX][locationY];
            printf("\nyou found %i gold", gold);
            
            

           
        }

        else
        {
            displayGrid[locationX][locationY] = 'E';

        }

        scoretracker(gold, currentPlayer, &player1Score, &player2Score, displayGrid[locationX][locationY], &player1Bombs, &player2Bombs);
        printf("\ncurrent score:\nplayer1: %i \n Player2: %i \n player 1 bomb(s): %i, player 2 bomb(s): %i \n", player1Score, player2Score, player1Bombs, player2Bombs);

        printf("\Grid:\n");
        for (row = 0; row < size; row++) {
            printf("%d\t", row);
            for (col = 0; col < size; col++) {
                printf("[%d][%d] %c ", row, col, displayGrid[row][col]);
            }
            printf("\n");
        }
        printf("\t1\t2\t3\t4\t5\t6\n");//RalfsEnd

        currentPlayer = 3 - currentPlayer; // change player ALE

    }
        
    return 0;
}

void scoretracker(int gold, int player, int* player1Score, int* player2Score, char type, int* player1Bombs, int* player2Bombs) //ralfs
{
    if (type == 'G') {
        if (player == 1) {
            *player1Score = *player1Score + gold;
        }
        else {
            *player2Score = *player2Score + gold;
        }
    }
    if (type == 'B') {
        if (player == 1) {
            *player1Score = *player1Score - 1;
            (*player1Bombs)++;
        }
        else {
            *player2Score = *player2Score - 1;
            (*player2Bombs)++;
        }
    }

}//ralfsEnd