// 26 - 02 - 2026
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
int main()
{

	
	char grid[6][6];
	int row, col,size = 6;
	
	int locationX, locationY;

	
	

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
	scanf(&locationX);

	printf("choose a location [y]");
	scanf(&locationY);

	printf("test");

	printf("test2");

	return(0);
}