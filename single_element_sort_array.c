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




#include <stdio.h>

int main() {
    int arr[] = {1,1,2,3,3,4,4,8,8};
    int n = 9;

    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // First element
        if (mid == 0 && arr[mid] != arr[mid + 1]) {
            printf("Found single element: %d", arr[mid]);
            return 0;
        }

        // Last element
        if (mid == n - 1 && arr[mid] != arr[mid - 1]) {
            printf("Found single element: %d", arr[mid]);
            return 0;
        }

        // Middle element
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
            printf("Found single element: %d", arr[mid]);
            return 0;
        }

        if (mid % 2 == 0) {
            if (arr[mid] == arr[mid + 1]) {
                start = mid + 2;
            } else {
                end = mid - 1;
            }
        } 
        else {
            if (arr[mid] == arr[mid - 1]) {
                 start = mid + 1;
            } else {
                end = mid - 1; 
            }
        }
    }

    return 0;
}