#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 2, 1};
    int n = 5;
    int freq=0, ans=0;
    for(int i=0; i<n; i++){
        if(freq==0){
            ans=arr[i];
        }
        if(ans==arr[i]){
            freq++;
        }
        else{
            freq--;
        }
    }
    cout<<ans;
}
