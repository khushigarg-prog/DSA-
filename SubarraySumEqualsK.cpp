#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    int arr[] = {1,1,1};
    int k = 2;
    int n = 3;
    unordered_map<int,int> mp; // stores cumsum and it's count
    int result=0; // which gives the ans
    int cumSum=0;
    mp.insert({0,1}); //0 cumsum starting m hoga jo ki 1 baar h
    for(int i=0; i<n; i++){
        cumSum+=arr[i];
        if(mp.find(cumSum-k) != mp.end()){
            result+=mp[cumSum-k];
        }
        mp[cumSum]++;
    }
    cout<<result;
}