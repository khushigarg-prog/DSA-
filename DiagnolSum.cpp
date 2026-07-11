#include<iostream>
using namespace std;
int main(){
    int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int n = 3;
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i][i]; // when i=j
        if(i != n-i-1){
            sum+=arr[i][n-i-1];
        }
    }
    cout<<sum;
}