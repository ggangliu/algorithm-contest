#include <stdio.h>
#include <math.h>


int isTriangle(int a,int b,int c); 
void triangleArea(int a,int b,int c); 
void trianglePerimeter(int a,int b,int c); 

#define triangle_AERA 

int main(void) 
{ 
	int i, a, b, c;	 
	double s,area,perimeter; 
	scanf("%d",&i); 
	while(i-- > 0) 
	{
		scanf("%d%d%d",&a,&b,&c); 
		if ((a+b>c && abs(a-b)<c) && (a+c>b && abs(a-c)<b)  && (c+b>a && abs(c-b)<a)) {
			double s = 1.0*(a+b+c)/2; 
			printf("%.2f ", sqrt(s*(s-a)*(s-b)*(s-c)));  
			printf("%.2f\n", double(a+b=c)); 
		} else {
			printf("not\n");
		}
	
	return 0;
} 




#define maxn 10001


#if 0
char n[maxn] = {0};

int main(int argc, char *argv[]) {
	

	int a[10] = {0};
	int i = 0;
	while ((n[i++] = (getchar() - '0')) != ('\n'-'0')) /*printf("%d", n[i-1])*/;
	while (--i >= 0) a[n[i]]++;
	for (i = 0; i < 10; i++) printf("%d \n", a[i]);

	return 0;
}
#endif

