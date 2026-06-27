#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,2,1,4,4};
    int n = 5;
    int ans=0;
    for(int i=0; i<5; i++){
       ans=ans^arr[i];
    }
    cout<<ans;
}