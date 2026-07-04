#include<iostream>
using namespace std;
int binarySearch(int arr[], int start, int end, int target){
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;;
        }
    }
    return -1;
}
int main(){
    int arr[] = {-1,0,3,4,5,9,12};
    int n = 7;
    int start = 0;
    int end = n-1;
    int target = 4;
    cout<<binarySearch(arr,start,end,target);
}