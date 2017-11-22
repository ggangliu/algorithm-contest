#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};

//get mirror char
char r(char ch){
	if (isalpha(ch)) return rev[ch-'A'];
	return rev[ch - '0' + 25];
}

int main(int argc, char *argv[]) {
	char s[100];
	while(scanf("%s", s) == 1 && 0 != strcmp("EXIT", s)){
		int len = strlen(s);
		int i, p = 1, m = 1;
		for (i = 0; i < (len+1)/2; i++){
			if (s[i] != s[len-1-i]) p = 0; // not a palindrome
			if (r(s[i]) != s[len-1-i]) m = 0; // not a mirrored string
		}
		
		printf("%s --- is %s.\n\n", s, msg[m*2+p]); //i like this code
	}
	
	return 0;
}

