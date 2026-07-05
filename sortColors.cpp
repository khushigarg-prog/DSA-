#include<iostream>
using namespace std;
int main(){
    int nums[] = {2,0,2,1,1,0};
    int n = 6;
    int i=0; // denotes for 0
    int j=0;  // denotes for 1
    int k=n-1; // denotes for k
    while(j<=k){
        if(nums[j]==1){
            j++;
        }
        else if(nums[j]==2){
            swap(nums[j],nums[k]);
            k--;
        }
        else{ // nums[j]==0
            swap(nums[j],nums[i]);
            i++;
            j++;
        }
    }
    cout<<"Sorted elements: ";
    for(int i=0; i<n; i++){
        cout<<nums[i]<<" ";
    }
}