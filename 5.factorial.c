#include<stdio.h>
int main()
{
	int i,num,fact=1;
	printf("enter any integer=");
	scanf("%d",&num);
	if(num<0)
	{
		printf("invalid input");
	}
	else
	{
		for(i=1;i<=num;i++){
			fact=fact*i;
		}
	}
	printf("factorial of %d=%d\n",num,fact);
}