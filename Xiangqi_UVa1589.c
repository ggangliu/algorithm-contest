#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define red_max_num 8

#define Chariot 'R'
#define Horse   'H'
#define General 'G'
#define Cannon  'C'

//General
//Chariot
//Cannon
//Horse
typedef struct {
	int x, y;
} point;

typedef struct {
	int maybe_move_num;
	point cur_pos;
	point can_move_pos[4];
} general_table;

int board[11][10] = {0};

general_table blk_general[] = {{2, {1, 4}, {{1, 5}, {2, 4}}}, \
							   {3, {1, 5}, {{1, 4}, {2, 5}, {1, 6}}}, \
							   {2, {1, 6}, {{1, 5}, {2, 6}}}, \
							   {3, {2, 4}, {{1, 4}, {2, 5}, {3, 4}}}, \
							   {4, {2, 5}, {{1, 5}, {2, 4}, {3, 5}, {2, 6}}}, \
							   {3, {2, 6}, {{1, 6}, {2, 5}, {3, 6}}}, \
							   {2, {3, 4}, {{3, 5}, {2, 4}}}, \
							   {3, {3, 5}, {{3, 4}, {2, 5}, {3, 6}}}, \
							   {2, {3, 6}, {{3, 5}, {2, 6}}}, \
							  };

void debug_show_board(void){
	int i = 0, j = 0;
	for (i = 1; i < 11; i++){
		for (j = 1; j < 10; j++) printf("%c ", (board[i][j] == 0) ? 'O' : board[i][j]);
		printf("\n"); 
	}	
} 

int is_flying_general_checkmate(int x, int y){
	while (++x <= 10 && 0 == board[x][y]);
	return (x <= 10 && General == board[x][y]) ? 1 : 0;
}

int flying_general_enemy_general(int blk_general_x, int blk_general_y){
	return is_flying_general_checkmate(blk_general_x, blk_general_y) ? 1 : 0;
}

int is_chariot_checkmate(int x, int y){
	int x_up = x, x_down = x, y_left = y, y_right = y;
	
	while (--x_up >= 1 && 0 == board[x_up][y]);
	if (x_up >= 1 && Chariot == board[x_up][y]) return 1;
	
	while (++x_down <= 10 && 0 == board[x_down][y]);
	if (x_down <= 10 && Chariot == board[x_down][y]) return 1;
	
	while (--y_left >=  1 && 0 == board[x][y_left]);
	if (y_left >= 1 && Chariot == board[x][y_left]) return 1;
	
	while (++y_right <=  9 && 0 == board[x][y_right]);
	if (y_right <= 9 && Chariot == board[x][y_right]) return 1;
	
	return 0;
}

int is_cannon_checkmate(int x, int y){
	int cannon_flag = 0;
	int x_up = x, x_down = x, y_left = y, y_right = y;
	
	while (--x_up >= 1){
		if (1 == cannon_flag && 0 != board[x_up][y]) return Cannon == board[x_up][y] ? 1 : 0; 
		if (0 == cannon_flag && 0 != board[x_up][y]) cannon_flag = 1;
	}
		
	while (++x_down <= 10){
		if (1 == cannon_flag && 0 != board[x_down][y]) return Cannon == board[x_down][y] ? 1 : 0;
		if (0 == cannon_flag && 0 != board[x_down][y]) cannon_flag = 1;
	}
	
	while (--y_left >=  1){
		if (1 == cannon_flag && 0 != board[x][y_left]) return Cannon == board[x_down][y_left] ? 1 : 0;
		if (0 == cannon_flag && 0 != board[x][y_left]) cannon_flag = 1;
	}
	
	while (++y_right <=  9){
		if (1 == cannon_flag && 0 != board[x][y_right]) return Cannon == board[x_down][y_right] ? 1 : 0;
		if (0 == cannon_flag && 0 != board[x][y_right]) cannon_flag = 1;
	}
	
	return 0;
}

int is_horse_checkmate(int x, int y){
	if ((x-2 >=  1)  && (y+1 <= 9) && Horse == board[x-2][y+1] && 0 == board[x-1][y+1]) return 1;
	if ((x-1 >=  1)  && (y+2 <= 9) && Horse == board[x-1][y+2] && 0 == board[x-1][y+1]) return 1;
	if ((x+1 <= 10)  && (y+2 <= 9) && Horse == board[x+1][y+2] && 0 == board[x+1][y+1]) return 1;
	if ((x+2 <= 10)  && (y+1 <= 9) && Horse == board[x+2][y+1] && 0 == board[x+1][y+1]) return 1;
	if ((x+2 <= 10)  && (y-1 >= 1) && Horse == board[x+2][y-1] && 0 == board[x+1][y-1]) return 1;
	if ((x+1 <= 10)  && (y-2 >= 1) && Horse == board[x+1][y-2] && 0 == board[x+1][y-1]) return 1;
	if ((x-1 >=  1)  && (y-2 >= 1) && Horse == board[x-1][y-2] && 0 == board[x-1][y-1]) return 1;
	if ((x-2 >=  1)  && (y-1 >= 1) && Horse == board[x-2][y-1] && 0 == board[x-1][y-1]) return 1;
	
	return 0;
}
						   
int is_check_mate(int blk_general_x, int blk_general_y){
	//get vailed position
	int i = 0, j = 0, type = 0, len_general_table = sizeof(blk_general)/sizeof(blk_general[0]);
	
	if (flying_general_enemy_general(blk_general_x, blk_general_y)) return 0; // check whether check-mate enemy general
	
	for (i = 0; i < len_general_table; i++)
		if (blk_general_x == blk_general[i].cur_pos.x && blk_general_y == blk_general[i].cur_pos.y) break;
	
	for (j = 0; j < blk_general[i].maybe_move_num; j++){
		type = board[blk_general_x][blk_general_y]; board[blk_general_x][blk_general_y] = 0;
		if (is_flying_general_checkmate(blk_general[i].can_move_pos[j].x, blk_general[i].can_move_pos[j].y)) continue;
		if (is_chariot_checkmate(blk_general[i].can_move_pos[j].x, blk_general[i].can_move_pos[j].y)) continue;
		if (is_cannon_checkmate(blk_general[i].can_move_pos[j].x, blk_general[i].can_move_pos[j].y)) continue;
		if (is_horse_checkmate(blk_general[i].can_move_pos[j].x, blk_general[i].can_move_pos[j].y)) continue;
		board[blk_general_x][blk_general_y] = type;
		return 0;
	}
	
 	return 1;
}

int main(int argc, char* argv[]){
	int blk_general_x = 0, blk_general_y = 0, red_num = 0; // 2 <= red_num <= 7	
	
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	while (scanf("%d %d %d\n", &red_num, &blk_general_x, &blk_general_y)==3 && 0 != red_num){
		memset(board, 0, sizeof(board));
		board[blk_general_x][blk_general_y] = General;	
		//printf("[INFO]%d %d %d\n", red_num, blk_general_x, blk_general_y);
		
		int type = 0, x = 0, y = 0;
		while ((red_num-- > 0) && scanf("%c %d %d\n", &type, &x, &y)) {
			//printf("[info]%c %d %d\n", type, x, y);
			board[x][y] = type;	
		}
		//debug_show_board();
		//check whether is check-mate
		is_check_mate(blk_general_x, blk_general_y) ? printf("YES\n") : printf("NO\n");
	}
	
	return 0;
} 
