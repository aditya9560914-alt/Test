#include<stdio.h>
int main(){
    int arr[]={0,3,9,10,20,5,2,1};
    int n=9;
    int i,mid;
    int start=0,end=n-1;
    while(start< end){
        mid=start+(end-start)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            printf("peek element fond %d",mid+1);
        }
        if (arr[mid-1]<arr[mid]){
            start=mid+1;
        } else{
            end=mid-1;
        }
        if (arr[mid+1] <arr[mid]){
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
}