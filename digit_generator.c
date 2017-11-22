#include <stdio.h>
#include <string.h>

#define maxn 100005
#define DEBUG_TEST 1

int ans[maxn];

//test whether exist the same generator or not
int test_exist_the_same_generator(){
	int n, i;
	memset(ans, 0, sizeof(ans));
	while (scanf("%d", &n) == 1 && 0 != n){
		for (i = 1; i < n; i++){
			int x = i, y = i;
			while(x > 0) {y += x % 10; x /= 10;}
			(0 == ans[y]) ? ans[y] = i : printf("ans[%d], old=%d, now=%d\n", y, ans[y], i);
		}	
	}	
} 

//get generator
int main(int argc, char *argv[]) {
	#ifndef DEBUG_TEST
	test_is_or_not_the_same_generator();
	#endif
	
	int T, n, m;
	memset(ans, 0, sizeof(ans));
	for (m = 1; m < maxn; m++){
		int x = m, y = m;
		while (x > 0) {y += x % 10; x /= 10;}
		if (0 == ans[y] || m < ans[y]) ans[y] = m;
	}
	
	while(scanf("%d", &n) == 1 && 0 != n) printf("%d\n\n", ans[n]);
	
	return 0;
} 
