#include<stdio.h>
void selection (int arr[],int n){
	for (int i=0;i<n-1;i++){
		int minind = i;
		for(int j = i+1;j<n;j++){
			if(arr[j]<arr[minind]){
				minind = j;
			}
		}
		int temp = arr[i];
		arr[i]=arr[minind];
		arr[minind]=temp;
	}
}
int main()
{
	int n,i;
	printf("enter the number of elements=");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
	printf("enter the element=");
	scanf("%d",&arr[i]);}
	selection (arr,n);
	printf("sorted array");
	for(i=0;i<n;i++){
		printf(" %d ",arr[i]);
	}
	printf("\n");
	return 0;
	
}