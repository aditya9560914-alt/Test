#include<stdio.h>
int main(){
   int i,j,min,n,temp;
   int arr[100];
   printf("enter the size of array: ");
   scanf("%d",&n);
   printf("enter the elements:");
   for (i=0;i<n;i++){
    scanf("%d",&arr[i]);
   }
   printf("array:");
   for(i=0;i<n;i++){
    printf("%d ",arr[i]);
   }
   for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
     temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
}
    printf("sorted array:");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}