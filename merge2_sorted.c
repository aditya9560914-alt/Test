#include<stdio.h>
int main(){
    int arr1[]={1,2,3,0,0,0};
    int m=3,n=3;
    int arr2[]={2,5,6};
    int i=m-1,j=n-1;
    int idx =m+n-1;
    while (i>=0 && j>=0){
        if (arr1[i]>arr2[j]){
            arr1[idx]=arr1[i];
            i--;
            idx--;
        }{
            arr1[idx]=arr2[j];
            j--;
            idx--;
        }
        while (j >= 0) {
        arr1[idx] = arr2[j];
        j--;
        idx--;
    }
    printf("Sorted array: ");

    for (i = 0; i < m + n; i++) {
        printf("%d ", arr1[i]);
    }
    }
}