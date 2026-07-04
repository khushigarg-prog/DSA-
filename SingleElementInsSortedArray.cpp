#include<iostream>
using namespace std;
int singleElement(int arr[], int start, int end, int n){
    if(n==1) return arr[0]; // if size is 1 then ans is that single element only
    
    while(start<=end){
        int mid=start+(end-start)/2;
        if(mid==0 && arr[0]!=arr[1]) return arr[0];
        if(mid==n-1 && arr[n-1]!=arr[n-2]) return arr[n-1];
        // If mid is that single number
        if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
            return arr[mid];
        }
        //Check that how many elements are there before and after mid i.e even or odd
        if(mid%2==0){
            //Even elements
            if(arr[mid]==arr[mid-1]){
                //which means odd will left which means -> duplicates + unique so search in left
                end=mid-1;
            }
            else{
                // search in right
                start=mid+1;
            }
        }
        else{
            // odd elements
            if(arr[mid]==arr[mid-1]){
                // even will left which means duplicates exist, so move to right
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of an array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int start=0;
    int end=n-1;
    cout<<singleElement(arr,start,end,n);
}