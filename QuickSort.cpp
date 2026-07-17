#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr, int st, int end){
    int idx=st-1;
    int pivot = arr[end];
    for(int j=st; j<=end-1; j++){
        if(arr[j]<=pivot){
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    // Now assign correct pos to pivot
    idx++;
    //arr[end]=pivot
    swap(arr[end], arr[idx]);
    return idx;
}
void quickSort(vector<int> &arr, int st, int end){
    // st = end islye ni kyuki single array sorted hi hota h
    if(st<end){
        int pivIdx = partition(arr,st,end);
        quickSort(arr,st,pivIdx-1); // left half
        quickSort(arr,pivIdx+1,end); // left half
    }
}
int main(){
    vector<int> arr = {12,31,35,8,32,17};
    quickSort(arr,0,arr.size()-1);
    for(int val: arr){
        cout<<val<<" ";
    }
    cout<<endl;
}