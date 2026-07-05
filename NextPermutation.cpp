#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr = {1,2,3,6,5,4};
    int n = 6;
    //To find the pivot => pivot could not be the last element ..Start from last
    int pivot = -1;
    for(int i=n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            pivot=i;
            break;
        }
    }
    if(pivot==-1){
        reverse(arr.begin(), arr.end());
    }
    // Swap pivot with the rightmost greater element
    for(int i=n-1; i>pivot; i--){
        if(arr[pivot]<arr[i]){
            swap(arr[pivot], arr[i]);
            break;
        }
    }
    // Reverse pivot+1 upto n-1
    int i= pivot+1;
    int j=n-1;
    while(i<=j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    cout<<"Next lexography: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}