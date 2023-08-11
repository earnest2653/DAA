#include<stdio.h>
int main()
{
	int n,i;
	printf("enter the size of the array:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
	printf("enter the element of array=");
	scanf("%d",&arr[i]);
	}
	int max = arr[0];
	for(i=1;i<=n;i++){
		if (arr[i]>max){
			max = arr[i];
		}
	}
	printf("largest element in array:%d\n",max);
	return 0;
}