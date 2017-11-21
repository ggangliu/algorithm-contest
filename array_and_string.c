#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_n 1000

int a[max_n] = {0};
 
/*turn the light on*/ 
int light_on_issue(void){
	int i, j, n = 0, k = 0;
	
	while((scanf("%d %d", &n, &k) == 2) && k <= 1000 && n <= 1000){
		int flag = 1;
		//memset(a, 1, sizeof(a)); //first one man open all light
		for(i = 1; i <= k; i++){
			for(j = 1; j <=n; j++) if(j%i == 0) a[j] = !a[j]; 
		}
		
		//display the result
		for(j = 1; j <=n; j++) if (a[j]) {
			flag = 0;
			printf("%d ", j);	
		}
		if (flag) printf("\nAll lights were turned off.\n");
	}
	
	printf("k=%d or n=%d > 1000, so process exit\n", k, n);
	return 0;
}

//snake matrix
int snake[8][8] = {0};
int snakelikes_shaped_metrix(void){
	int x, y, n, tot = 0;
	
	scanf("%d", &n);
	memset(snake, 0, sizeof(snake));
	tot = snake[x=0][y=n-1] = 1;
	
	while (tot < n*n){
		while (x+1 <  n && !snake[x+1][y]) snake[++x][y] = ++tot;
		while (y-1 >= 0 && !snake[x][y-1]) snake[x][--y] = ++tot;
		while (x-1 >= 0 && !snake[x-1][y]) snake[--x][y] = ++tot;
		while (y+1 <  n && !snake[x][y+1]) snake[x][++y] = ++tot;
	}
	
	for (x = 0; x < n; x++){
		for (y = 0; y < n; y++) printf("%3d", snake[x][y]);
		printf("\n");
	}
	return 0;
}

//fgetc(stdin) == getchar()
//fgets(buf, max, fin) gets()


int main(int argc, char *argv[]) {
	char b[5];
	gets(b);
	
	//snakelikes_shaped_metrix();
	//light_on_issue();
	return 0;
}
