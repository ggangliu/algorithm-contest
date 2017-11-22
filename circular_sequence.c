#include <stdio.h>
#include <string.h>
#include <math.h>
#define maxn 105

// circular string S's expression p whether less than q or not
int less(const char* s, int p, int q){
	int i = 0, n = strlen(s);
	for (i = 0; i < n; i++)
		if (s[(i+p)%n] != s[(i+q)%n]) return s[(i+p)%n] < s[(i+q)%n];
	
	return 0; //equal
}

int main(int argc, char *argv[]) {
	char s[maxn] = {0};
	
	printf("int (max=%d min=%d) %d %d ... %d %d |%d| %d %d ... %d %d\n", (1<<31)-1, (1<<31), (1<<31), ((1<<30) + ((1<<30) - 1)), (1<<1), (1<<0),\ 
	                                                                     (1<<32), \
																		 (1<<31)+((1<<31)-1), (1<<32)-2, (1<<32)-(1<<31), (1<<32)-(1<<32));
	printf("unsigned int (max=%u min=%u)\n", (1<<32)-1, 0);
	return 0;
	
	while (scanf("%s", s) == 1 && 0 != strcmp("exit", s)){
		int i = 0, ans = 0, n = strlen(s);
		for (i = 1; i < n; i++)
			if (less(s, i, ans)) ans = i;
		
		for (i = 0; i < n; i++)
			putchar(s[(i+ans)%n]);
		
		putchar('\n');
	}
	
	return 0;
}
