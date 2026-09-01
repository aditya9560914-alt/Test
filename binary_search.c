#include<stdio.h>
int main(){
    int n,i,target;
    int arr[100];
    int start,end,mid;
    printf("enter the size of array:");
    scanf("%d",&n);
    printf("enter the element:");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the element search:");
    scanf("%d",&target);
    start=0;
    end=n-1;
    while(start<=end){
        mid=(start+end)/2;
        if(target==arr[mid]){
            printf("found at position %d",mid+1);
            return 0;
        }
        else if (target>arr[mid]){
            start=mid+1;
        }
        else {
            end=mid-1;
        }

    }
    printf("not found");
    return 0;
}