#include<stdio.h>
int linear_search(int arr[],int n,int key){
    for (int i=0;i<n;i++){
        if (arr[i]==key){
            return i;
        }
    }    
            return -1;
        
    
}
int main(){
    int arr[]={8,3,12,7,6};
    int n=5;
    int key;
    printf("enter your key");
    scanf("%d",&key);
    int result =linear_search(arr,n,key);
    if (result!=-1){
        printf("element found %d",result);
    }
    else{
        printf("not found ");
    }
}



