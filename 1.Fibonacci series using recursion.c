#include<stdio.h>
int fibonacci (int n) {
	if (n<=0)
	return n;
	return fibonacci (n-1)+fibonacci (n-2);
}
void print_fibonacci_series(int n){
	printf("fibonacci series (int n) :\n");
	for (int i=0;i<n;i++){
		printf ("%d",fibonacci(i));
	}
	printf("\n");
}
int main(){
	int numterms;
	printf("enter the number of terms :");
	scanf("%d",&numterms);
	print_fibonacci_series(numterms);
	return 0;
}