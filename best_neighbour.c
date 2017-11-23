#include <stdio.h>

#define DEBUG 1
#define maxn 50005

typedef struct {
	int a;
	int c;
} AMONG;

int pos[maxn] = {0};
AMONG ac[maxn] = {0}; 
int n = 0;

//place b to among a and c
int pos_b_to_ac(int b, int a, int c){
	// a, a-1, b
	int ch = (a > c) ? c : a;
	pos[ch-1] ^= pos[ch] ^= pos[ch-1] ^= pos[ch];
	pos[ch]   ^= pos[b]  ^= pos[ch]   ^= pos[b];
	
	return 2;
}

//check whether is best friends or not
int is_best_friends(int b, int a, int c){
	int i = 1, pb = 0, match = 0;
	
	//printf("%d %d %d\n", b, a, c);
	for (i = 1; i <= n; i++) if (pos[i] == b) {pb = i; break;}
	//printf("%d %d %d\n\n", pos[(pb-1)<1?n:pb-1], b, pos[(pb+1)>n?1:(pb+1)]);
	match = ((pos[(pb-1)<1?n:pb-1] == a && pos[(pb+1)>n?1:(pb+1)] == c) || (pos[(pb-1)<1?n:pb-1] == c && pos[(pb+1)>n?1:(pb+1)] == a)) ? 1 : 0;
	return match;
}

int main(int argc, char *argv[]) {
	int N = 0;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	 
	if (scanf("%d", &N) != 1 || N <= 0 || N >= 10) {
		printf("[Error] N=%d is not a valid input, process exist!\n");
		return -1;
	}
	
	while (N-- >0){
		if (scanf("%d", &n) == 1 && n >= 3 && n <= 50000){
			int a = 0, b = 1, c = 0, eval = 0, i = 1;
			
			for (i = 1; i <= n; i++) pos[i] = i; //initial pos
			memset(ac, 0, sizeof(ac));
			
			while (b <= n){
				scanf("%d %d", &ac[b].a, &ac[b].c);
				if (!is_best_friends(b, ac[b].a, ac[b].c)) eval = eval + pos_b_to_ac(b, ac[b].a, ac[b].c);
				b++;
			}
			
			#ifdef DEBUG
			printf("%d\n", eval);
			for (i = 1; i <= n; i++) {printf("%d ", pos[i]);} printf("\n");
			#endif
			
			b = 1;
			while (b <= n) {
				if (!is_best_friends(b, ac[b].a, ac[b].c)) { eval = -1; break;}
				b++;
			}
			
			printf("%d\n", eval);
		}
	}
}
