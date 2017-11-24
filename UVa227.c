#include <stdio.h>

#define maxn 5

char puzzle[maxn][maxn] = {{'T', 'R', 'J', 'S', 'G'},
							   {'X', 'D', 'O', 'K', 'I'},	
							   {'M', ' ', 'V', 'L', 'N'},
							   {'W', 'P', 'A', 'B', 'E'},
							   {'U', 'Q', 'H', 'C', 'F'}};
							   
void show_puzzle(){
	int i, j;
	for (i = 0; i < maxn; i++){
		for (j = 0; j < maxn; j++){
			printf("%c ", puzzle[i][j]);
		}
		printf("\n");
	}
}
//puzzle
int main(int argc, char *argv[]) {
	char m = '0';
	int x = 2, y = 1;
	puzzle[x][y] = ' ';
	
	show_puzzle();
	 
	while ((m = getch()) && ('0' != m)){
		//printf("[DEBUG]***%c***\n", m);
		int new_x = 0, new_y = 0, invalid_op_flag = 0;
		switch (m){
			case 'A': //up
				(maxn*x+y-maxn) < 0 ? (invalid_op_flag = 1) : (new_x = (maxn*x+y-maxn)/maxn, new_y = (maxn*x+y-maxn)%maxn);
				break; 
			case 'B': //down 
				(maxn*x+y+maxn) >= maxn*maxn ? (invalid_op_flag = 1) : (new_x = (maxn*x+y+maxn)/maxn, new_y = (maxn*x+y+maxn)%maxn);
				break; 
			case 'L': //left
				((y - 1) >= 0) ? new_x = x, new_y = y - 1 : (invalid_op_flag = 1);
				break;
			case 'R': //right
				(y + 1) <= maxn ? new_x = x, new_y = y + 1 : (invalid_op_flag = 1);
				break;
			default:
				printf("This puzzle has no final configuration.\n");
		}
		
		if (1 == invalid_op_flag){
			printf("This puzzle has no final configuration.\n");
		} else {
			puzzle[new_x][new_y] ^= puzzle[x][y] ^= puzzle[new_x][new_y] ^= puzzle[x][y];
			x = new_x, y = new_y;
		}
		
		show_puzzle();
	}
}
