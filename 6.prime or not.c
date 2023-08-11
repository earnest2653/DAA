#include<stdio.h>
int isprime(int num){
	if (num<2)
	return 0;
	int sqrtnum = (int) sqrt(num);
	for(int i=2;i<=sqrtnum;++i)
	{
		if(num%i==0)
		return 0;
	}
	return 1;
}
int main(){
	int num;
	printf("enter a number:");
	scanf("%d",&num);
	if(isprime(num)){
		printf("%d is a prime number",num);}
	else{
		printf("%d is not a prime number", num);}
}