#include<iostream>
using namespace std;
int main(){
    int arr[]= {4,3,2,1};
    int n=4;
    for(int i=1; i<n; i++){
        int curr=i;
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
    cout<<"Sorted elements: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}