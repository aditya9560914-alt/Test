#include<stdio.h>
int main(){
    int n,i,key;
    int arr[100];
    int found=0;
    printf("enter the size of array:");
    scanf("%d",&n);
    printf("enter the elements of array:");
    for (i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     printf("enter the key ");
    scanf("%d",&key);
    for (i=0;i<n;i++){
        if(arr[i]==key){
            printf("found at position  %d",i+1);
            found=1;
            break;

        }
    }
    if(!found){
        printf("not found ");
    }
    return 0;
}