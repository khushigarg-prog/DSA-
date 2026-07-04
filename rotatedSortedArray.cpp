#include<iostream>
using namespace std;
int RotatedSortedArray(int arr[], int start, int end, int target){
    while(start<=end){
        int mid=start+(end-start)/2;
        if(arr[mid]==target) return mid;
        // If array is left sorted
        if(arr[start]<=arr[mid]){
            //Search in left
            if(target>=arr[start] && target<arr[mid]){
                end=mid-1;
            }
            else{
                // Search in left
                start=mid+1;
            }
        }
        //If array is right sorted
        else{
            // search in right
            if(target>arr[mid] && target<=arr[end]){
                start=mid+1;
            }
            else{
                end=mid-1;  //search in left
            }
        }
    }
    return -1;
}
int main(){
    int arr[] = {3,4,5,6,7,0,1,2};
    int target=5;
    int n = sizeof(arr)/sizeof(arr[0]);
    int start=0, end=n-1;
    cout<<RotatedSortedArray(arr,start,end,target);
}