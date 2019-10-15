#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#pragma warning(disable:4996);
bool findWordInAGrid(char grid[128][128], int m, int n, char word[32]);
void main() {
	char grid[128][128],ch;
	printf("\nEnter the dimensions of the grid m x n :\n");
	int m;
	int n;
	scanf("%d %d", &m, &n);
	printf("\nEnter the grid \n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("\nEnter the [%d][%d] element\n", i, j);
			scanf(" %c", &grid[i][j]);
			ch = getchar();
			
		}
	}
	printf("\nEnter the word to be searched :\n");
	char word[32];
	fgets(word,32,stdin);
	bool response = findWordInAGrid(grid, m, n, word);
	if (response == true)
		printf("\nTrue\n");
	else
		printf("\nFalse\n");
}

bool findWordInAGrid(char grid[128][128], int m, int n, char word[32]) {
	char foundArr[32];
	int xindex = 0;
	int yindex = 0;
	for (int i = 0; i < strlen(word); i++) {
		if (i == 0) {
			int arr[2];
			
			int val = searchInArray(grid, m, n, word[0],arr);
			if (val == 0)
			{
			}
			else {
				foundArr[0] = true;
				xindex = arr[0];
				yindex = arr[1];
				
			}
		}
		else {
			int arr[2];
			int side = checkAtSides(grid[128][128], xindex, yindex, word[i],arr);
			if (side == 1) {
				foundArr[i] = true;
				xindex = arr[0];
				yindex = arr[1];
				continue;
			}
			int upd = checkTopBottom(grid[128][128], xindex, yindex, word[i],arr);
			if (upd == 1) {
				foundArr[i] = true;
				xindex = arr[0];
				yindex = arr[1];
				continue;
			}
			int slant = checkSlant(grid[128][128], xindex, yindex, word[i], arr);
			if (slant == 1) {
				foundArr[i] = true;
				xindex = arr[0];
				yindex = arr[1];
				continue;
			}
		
		}
	 
	}
	int ctr = 0;
	for (int i = 0; i < strlen(word); i++) {
		if (foundArr[i] == true)
			ctr++;
	}
	if (ctr == strlen(word)) {
		return true;
	}
	else {
		return false;
	}
}

int searchInArray(char grid[128][128], int m, int n, char c,int arr[2]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == c) {
				arr[0] = i;
				arr[1] = j;
				return 1;
			}
			
		}
	}
	return 0;
}
int checkAtSides(char grid[128][128], int x, int y, char c,int arr[2]) {
	if (y == 0) {
		if (grid[x][y + 1] == c) {
			arr[0] = x;
			arr[1] = y + 1;
			return 1;
		}
		else {
			return 0;
		}
	 }
	else {
		if (grid[x][y + 1] == c || grid[x][y - 1] == c) {
			if (grid[x][y + 1] == c) {
				arr[0] = x;
				arr[1] = y + 1;
			}
			else {
				arr[0] = x;
				arr[1] = y - 1;

			}
			return 1;
		}
		else {
			return 0;
		}
	}
}

int checkTopBottom(char grid[128][128], int x, int y, char c,int arr[2]) {
	if (x == 0) {
		if (grid[x + 1][y] == c) {
			arr[0] = x + 1;
			arr[1] = y;
			return 1;
		}
		else
			return 0;
	 }
	else {
		if (grid[x + 1][y] == c || grid[x - 1][y] == c) {
			if (grid[x + 1][y] == c) {
				arr[0] = x + 1;
				arr[1] = y;
				return 1;
			}
			else {
				arr[0] = x - 1;
				arr[1] = y;
				return 1;
			}
		}
		else {
			return 0;
		}

	}

}

int checkSlant(char grid[128][128], int x, int y, char c, int arr[2]) {
	if (grid[x + 1][y + 1] == c) {
		arr[0] = x + 1;
		arr[1] = y + 1;
		return 1;
	}
	else if (grid[x - 1][y - 1] == c) {
		arr[0] = x - 1;
		arr[1] = y - 1;
		return 1;
	}
	else if(grid[x+1][y-1]==c){
		arr[0] = x + 1;
		arr[1] = y - 1;
		return 1;

	}
	else if (grid[x-1][y+1]==c) {
		arr[0] = x - 1;
		arr[1] = y + 1;
		return 1;

	}
	else {
		return 0;
	}

}
