// 26 - 02 - 2026
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
int main()
{

	
	char grid[6][6];
	int row, col,size = 6;
	
	int locationX, locationY;

	char password[] = "Alex07";
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
	

	for (row = 0; row < size; row++) {
		printf("%d\t", row, grid[0][row]);
		for (col = 0; col < size; col++) {
			
			printf("[%d][%d] $",row,col,grid[row][col]);
			if (col == size - 1) {
				printf("\n");
			}
		}
	}
	printf("\t1\t 2\t 3\t 4\t 5\t 6\n");

	printf("choose a location [x] ");
	scanf_s(&locationX);

	printf("choose a location [y]");
	scanf_s(&locationY);

	printf("test");

	printf("test2");

	return(0);
}