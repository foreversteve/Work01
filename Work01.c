#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int fibEven(int v1, int v2, int sum){
	if (v1 > 4000000){
		return sum;
	}
	if (v1 % 2 == 0) return fibEven(v2,v1+v2,sum+v1);
	return fibEven(v2,v1+v2,sum);
}

int solve(int **board, int s){
	for (int k = 0; k < s; k++){
		for (int j = 0; j < s; j++){
			if (j == 0 || k == 0){
				board[k][j] = 1;
			}
			else{
				board[k][j] = board[k-1][j]+board[k][j-1];
			}
		}
	}
	return board[s-1][s-1];
}
int main(){
	// Problem 2
	printf("The answer to Problem 2 is %d\n",fibEven(1,2,0));
	//Problem 15
	int **board = calloc(sizeof(int*),50);
	for (int i = 0; i < 50; i++){
		board[i] = calloc(sizeof(int),50);
	}
	
	printf("The answer to Problem 15 is %d modulo INT_MAX()\n",solve(board,21));

	/*
	for (int k = 0; k < 21; k++){
		for (int j = 0; j < 21; j++){
			printf("%d",board[j][k]);
		}
		printf("\n");
	}
	*/

	for (int i = 0; i < 50; i++){
		free(board[i]);
	}
	free(board);
	return 0;
}
