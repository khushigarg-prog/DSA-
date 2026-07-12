#include<iostream>
#include<vector>
using namespace std;
bool sorted(int arr[], int n){
    if(n==0 || n==1) return true;
    return arr[n-1]>=arr[n-2] && sorted(arr,n-1);
}
int main(){
    int arr[]={1,2,3,4};
    int n = 4;
    cout<<sorted(arr,n);
}