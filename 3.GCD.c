#include<stdio.h>
int main()
{
	int num1,num2,temp,rem;
	printf("enter two integers=");
	scanf("%d,%d",&num1,&num2);
	while (num2!=0)
	{
		rem=num1%num2;
		num1=num2;
		num2=rem;
	}
	printf("GCD=%d\n",num1);
	return 0;
}