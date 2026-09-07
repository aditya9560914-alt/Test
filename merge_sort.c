#include<stdio.h>
int mergesort(int arr[],int start,int end){
    if (start<end){
        int mid=start+(end-start)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int merge(int arr[],int start,int mid,int end){
int temp[100];
 int i=start;
 int j=mid+1;
 int k=0;
 while(i<=mid && j<=end){
    if (arr[i]<=arr[j]){
        temp[k++]=arr[i++];
 }
 else{
    temp[k++]=arr[j++];
 }
}
while(j<=end){
    temp[k++]=arr[j++];
}
for (i=start, k=0; i<=end; i++,k++){
    arr[i]=temp[k];
}

}
int main(){
    int arr[]={12,31,35,8,32,17};
    int n=6;
    mergesort(arr,0,n-1);
    printf("sorted array::");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    } 
}