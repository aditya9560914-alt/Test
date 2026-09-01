// #include <stdio.h>

// int main() {
//     int arr[] = {3, 4, 5, 6, 7, 0, 1, 2};
//     int n = 8;
//     int target = 5;
//     int mid;
//     int start = 0, end = n - 1;

//     while (start <= end) {

//         mid = start + (end - start) / 2;

//         if (arr[mid] == target) {
//             printf("Target found at position %d", mid+1);
//             return 0;
//         }

//         // Left half is sorted
//         if (arr[start] <= arr[mid]) {

//             if (arr[start] <= target && target < arr[mid]) {
//                 end = mid - 1;
//             }
//             else {
//                 start = mid + 1;
//             }
//         }

//         // Right half is sorted
//         else {

//             if (arr[mid] < target && target <= arr[end]) {
//                 start = mid + 1;
//             }
//             else {
//                 end = mid - 1;
//             }
//         }
//     }

//     printf("Element not found");

//     return 0;
// }


// user input !! 
  #include<stdio.h>
int main(){
    int arr[]={3,4,5,6,7,0,1,2};
    int n=8;
    int i,mid;
    int start=0;
    int end=n-1;
    int target;
    printf("enter the target:");
    scanf("%d",&target);
    while(start <= end){
        mid=start+(end-start)/2;
        if(arr[mid]==target){
            printf("found at position: %d",mid+1);
            return 0;
        }
        if (arr[start]<=target && target<=arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        if(arr[mid]<=target && target<=arr[end]){
            start=mid+1;
        } else{
            end=mid-1;
        }
        }
        return 0;
    }
