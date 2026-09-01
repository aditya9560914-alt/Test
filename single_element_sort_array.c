// #include<stdio.h>
// int main(){
//     int arr[]={1,1,2,3,3,4,4,8,8};
//     int mid;
//     int n=9;
//     int start=0,end=n-1;
//     while(start<=end){
//         mid=start+(end-start)/2;
//         if(arr[mid-1]!=arr[mid] && arr[mid+1]!=arr[mid]){
//             printf("found single elementd %d",arr[mid]);
//             return 0;
//         }
//         if (mid%2==0){
//         if (arr[mid]==arr[mid-1]){
//             end=mid-1;
//         }else{
//             start=mid+1;
//         }
//         } 
//         else{
//         if (arr[mid]==arr[mid+1]){
//             start=mid+1;
//         }else{
//             end=mid-1;
//         }
//     }
// }
// return 0;
// }




#include<stdio.h>
int main(){
    int arr[]={1,1,2,3,3,4,4,8,8};
    int mid;
    int n=9;
    int start=0,end=n-1;
    while(start<=end){
        mid=start+(end-start)/2;
        if(arr[mid-1]!=arr[mid] && arr[mid+1]!=arr[mid]){
            printf("found single elementd %d",arr[mid]);
            return 0;
        }
        if (mid%2==0){
        if (arr[mid-1]==arr[mid]){
            end=mid-1;
        }else{
            start=mid+1;
        }
        } 
        else{
        if (arr[mid+1]==arr[mid]){
            start=mid+1;
        }else{
            end=mid-1;
        }
    }
}
return 0;
}
