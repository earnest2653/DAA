#include<stdio.h>
int main()
{
	int num,o_num,rem,res=0;
	printf("enter any positive integer:");
	scanf("%d",&num);
	o_num=num;
	while(o_num!=0)
	{
		rem=o_num%10;
		res+=rem*rem*rem;
		o_num=o_num/10;
	}
	if(num==res)
		printf("the given number is amstrong number:");
	else
		printf("the given number is not armstrong number:");
}