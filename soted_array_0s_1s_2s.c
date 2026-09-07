#include<stdio.h>
int main(){
    int arr[]={2,0,2,1,1,0,1,2,0,0};
    int n=10;
    int i,count=0 ,count1=0,count2=0;
    for (i=0;i<n;i++){
        if (arr[i]==0){
            count++;
        }
        else if (arr[i]==1){
            count1++;
        }
        else {
            count2++;
        }

    }
    int k=0;
    for (i=0;i<count;i++){
        arr[k++]=0;
    }
    for (i=0;i<count1;i++){
        arr[k++]=1;
    }
    for (i=0;i<count2;i++){
        arr[k++]=2;
    }
    printf("sorted array ");
    for (i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}