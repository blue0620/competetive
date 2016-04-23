#include <stdio.h>

int main()
{
	int *s,*e;
	int n;
	scanf("%d",n);
	s = (int *)malloc( sizeof( double ) * n );
	e = (int *)malloc( sizeof( double ) * n );
	
	for(int i=0;i<n;i++){
		scanf("%d-%d\n",&s[i],&e[i]);
	}
	
}