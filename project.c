// 26 - 02 - 2026
//Alessandro
//Project
//19_03_2026
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

int main()
{
    char displayGrid[6][6];
    uint8_t values[6][6];
    int row, col, size = 6;
    int gold = 0;

    int locationX, locationY;

    char password[] = "Alex07"; //ale
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

    srand((int)time(0));


    for (row = 0; row < size; row++) {
        for (col = 0; col < size; col++) {
            values[row][col] = rand() % 256;
            displayGrid[row][col] = '$';
        }
    } //ale


    printf("\Grid:\n");//Ralf
    for (row = 0; row < size; row++) {
        printf("%d\t", row);
        for (col = 0; col < size; col++) {
            printf("[%d][%d] %c ", row, col, displayGrid[row][col]);
        }
        printf("\n"); 
    }
    printf("\t1\t2\t3\t4\t5\t6\n");


    for (int loop = 0; loop < 18; loop++) {
        printf("choose a location [x]: ");
        scanf_s("%d", &locationX);
        printf("choose a location [y]: ");
        scanf_s("%d", &locationY);

        printf("You just choose [%d][%d] the real number is: %d\n", locationX, locationY, values[locationX][locationY]);
        //Ralf

        if (values[locationX][locationY] & 1) {//ralfs

            displayGrid[locationX][locationY] = 'B';

        }

        else if (values[locationX][locationY] & 2) {
            displayGrid[locationX][locationY] = 'G';
            values[locationX][locationY] = (values[locationX][locationY] >> 4);
            gold = values[locationX][locationY];
        }

        else
        {
            displayGrid[locationX][locationY] = 'E';

        }

        printf("\Grid:\n");//Ralf
        for (row = 0; row < size; row++) {
            printf("%d\t", row);
            for (col = 0; col < size; col++) {
                printf("[%d][%d] %c ", row, col, displayGrid[row][col]);
            }
            printf("\n");
        }
        printf("\t1\t2\t3\t4\t5\t6\n");
        printf("\nyou found %i gold", gold);//ralfs
    }
    return 0;
}