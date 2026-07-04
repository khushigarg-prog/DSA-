#include<iostream>
using namespace std;
int peakElement(int arr[], int start, int end){
    while(start<=end){
        int mid = start+(end-start)/2;
        //if mid if peak
        if(arr[mid]>arr[mid-1] && arr[mid]> arr[mid+1]) return mid;
        // Check that if array part is left increasing or right decreasing
        if(arr[mid]>arr[mid-1]){
            // it is left increasing so check in right
            start=mid+1;
        }
        else{
            //it is right decreasing then check in left
            end=mid-1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {0,3,8,9,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start=1; //as arr[0] could not be peak element
    int end=n-2; //as last element i.e n-1 could not be peak element
    cout<<peakElement(arr,start,end);
}