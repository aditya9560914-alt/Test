#include<stdio.h>
int main(){
    int i,n,curr,prev;
    int arr[100];
    printf("enter the size of array");
    scanf("%d",&n);
    printf("enter the elements of array:");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (i=1;i<n;i++){
        curr=arr[i];
        prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
    printf("sorted array:");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}