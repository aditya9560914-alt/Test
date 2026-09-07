// #include<stdio.h>
// int main(){
//     int arr[]={10,20,30,40};
//     int n=4,m=2;
//     int start=40,end=100;
//     int mid,ans=-1;
//     int painters=2;
//     while(start<=end){
//         mid=start+(end-start)/2;
//         int painter=1;
//         int time=0;
//         for (int i=0;i<n;i++){
//             if (time+arr[i]<=mid){
//                 time=time+arr[i];
//             }
//             else{
//                 painter++;
//                 time=arr[i];
//             }
//         }
//         if (painter<=painters){
//             ans=mid;
//             end=mid-1;
//         }
//         else{
//             start=mid+1;
//         }
//     }
//     printf("the minimum time= %d",ans);
// return 0;
// }



//  with function:::===>>!!

#include<stdio.h>

int ispossible(int arr[],int n,int painters,int maxtime){
int painter=1;
int time=0;
for ( int i=0;i<n;i++){
if(time+arr[i]<=maxtime){
    time=time+arr[i];
}else{
    painter++;
    time=arr[i];
}
}
return painter<=painters;
}
int main(){
    int arr[]={10,20,30,40};
    int n=4;
    int painters=2;
    int start=40;
    int end=100;
    int ans=-1;
 while(start<=end){
    int mid=start+(end-start)/2;
    if (ispossible(arr,n,painters,mid)){
        ans=mid;
        end=mid-1;
    }
    else{
        start=mid+1;
    }
 }
 printf("tne minimum time %d",ans);
}