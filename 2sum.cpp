#include<iostream>
#include<map>
using namespace std;
int main(){
    int arr[] = {2,7,11,15};
    int n = 4;
    int target=9;
    map<int,int> mp; //it will store the number and the corresponding index
    for(int i=0; i<n; i++){
        int remaining = target-arr[i];
        // Phir hum dekhenge ki remaining khi dekha h kya map m
        // agr dekha h toh index return krdenge remaining ka or ab ka
        if(mp.find(remaining) != mp.end()){
            cout<<mp[remaining]<<" "<<i;
        }
        // or agr nhi dekha toh map m arr[i] or i ko store krdenge
        mp[arr[i]]=i;
    }
}