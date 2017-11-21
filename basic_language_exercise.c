#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define INF 1000000
#define LOCAL
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//Calculate cylinder area
int Area_for_cylinder(){
	int a, b;
	const double pi = acos(-1.0);
	double r, h, s1, s2, s;
	
	//scanf("%d%d\n", &a, &b);
	//printf("%.8f\n", a+2*sqrt(b)/(5-0.1));
	//printf("%.20f\n", pi);
	scanf("%lf%lf", &r, &h);
	
	s1 = pi*r*r;
	s2 = 2*pi*r*h;
	s  = 2.0*s1 + s2;
	printf("Area = %.3f\n", s);
	return 0;
}

//Reverse the three-digit number 
int reverse_the_three_digit_number(const int num){
	scanf("%d", &num);
	int result = num%10*100 + num/10%10*10 + num/100;
	printf("%03d\n", result);
	return 0;
}

//Switch two number 
int switch_two_number(void){
	int a, b;
	scanf("%d%d", &a, &b);
	/*
	a = a + b;
	b = a - b;
	a = a - b;
	*/
	a ^= b ^= a ^= b;
	 
	printf("%d %d\n", a, b);
	return 0; 
}

//Get average value 
int get_average_value(void){
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%.3f\n", (float)(a+b+c)/3);
	return 0;	
}

//Check the max and min of int 
int get_max_min(void){
	unsigned int a = -1;
	int max_int = a/2;
	int min_int = max_int + 1;
	 
	printf("%d, %d\n", min_int, max_int);
	
	printf("cos(0) = %.3f\n", cos(0));
	printf("sin(0) = %.3f\n", sin(0));
	
	return 0;
}

//Get count of the number change to 1
int get_count_of_to_one(void){
	long long count = 0, a = 0;
	scanf("%lld", &a);
	while(a > 1){
		if (a % 2 == 1) a = 3*a + 1;
		else a = a / 2;
		count++;
	}
	printf("%d\n", count);
	
	return 0;
}
 
//Get approximation
int get_approximation(void){
	double sum = 0, term = 0;
	int i = 0;
	do {
		term = 1.0 / (i*2 + 1);
		if (i % 2 == 0) sum += term;
		else sum -= term;
		i++;	
	} while (term >= 1e-9);
	
	printf("%.9f\n", sum);
	return 0;
}

//mod timer
int check_mod_with_timer(void){
	const int MOD = 1000000;
	int i, j, n, S = 0;
	
	scanf("%d", &n);
	if (n > 26) n = 26;
	
	for (i = 1; i < n; i++){
		int factorial = 1;
		for (j = 1; j < i; j++) factorial = (factorial * j % MOD);
		S = (S + factorial) % MOD;
	}
	
	printf("%d\n", S);
	printf("Time used = %.2f\n", (double)clock()/CLOCKS_PER_SEC);
	return 0;
}

//Get min max and average
int get_min_max_and_average(void){
	int x = 0, n = 0, min = INF, max = -INF, s = 0;
	while(scanf("%d", &x) == 1){
		s += x;
		if (x < min) min = x;
		if (x > max) max = x;
		n++;
	}
	printf("%d %d %.3f\n", min, max, (double)s/n);
	printf("test redirect to standard i/o\n");
	return 0;
}

//using file api implement the above program
int get_min_max_and_average_by_file(void){
	FILE *fin, *fout;
	fin  = fopen("input.data", "rb");
	fout = fopen("output.data", "wb");
	
	int x = 0, n = 0, min = INF, max = -INF, s = 0;
	while(fscanf(fin, "%d", &x) == 1){
		s += x;
		if (x < min) min = x;
		if (x > max) max = x;
		n++;
	}
	fprintf(fout, "%d %d %.3f\n", min, max, (double)s/n);
	fprintf(fout, "test redirect to standard i/o\n");
	
	fclose(fin);
	fclose(fout);
	
	/* if we want to replace file operation as standard I/O, so just need to replace fin = stdin, fout = stdout
	   and do not to call fopen() and fclose() 
	*/
	
	return 0;
} 

int daffodil(void){
	int i = 0;
	for (i = 0; i < 1000; i++){
		if (i == (pow(i/100,3) + pow(i/10%10,3) + pow(i%10,3))) printf("%d\n", i);
	}
	
}

//inverted triangle
int inverted_triangle(void){
	int i, j, n = 0;
	while((scanf("%d", &n) == 1) && (n <= 20 && n > 0)){
		int len = 2*(n-1) + 1;
		for(i = n-1; i >= 0; i--) {   //2n+1
			for(j = 0; j < (n-1-i); j++) printf(" ");
			for(j = 0; j < (2*i+1); j++) printf("#");
			printf("\n");
		}
	}
	
}

int main(int argc, char *argv[]) {
	#ifndef LOCAL
	//Redirect to standard i/o
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	inverted_triangle();
	//daffodil();
	//get_min_max_and_average_by_file();
	//get_min_max_and_average();
	//check_mod_with_timer();	
	//get_approximation(); 
	//get_count_of_to_one();
	//get_max_min(); 
	//get_average_value();
	//switch_two_number(); 
	//printf("%%d");	
	return 0;
}
