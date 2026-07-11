#include<iostream>
#include<vector>
using namespace std;
int main(){
    int arr[4][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    int m = 4, n=4;
    int srow=0, erow=m-1;
    int scol=0, ecol=n-1;
    vector<int> ans;
    while(srow<=erow && scol<=ecol){
        // top 
        for(int j=scol;j<=ecol; j++){
            ans.push_back(arr[srow][j]);
        }
        // right
        for(int i=srow+1; i<=erow; i++){
            ans.push_back(arr[i][ecol]);
        }
        // bottom
        for(int j=ecol-1; j>=scol; j--){
            if(srow==erow) break;
            ans.push_back(arr[erow][j]);
        }
        //left
        for(int i=erow-1; i>=srow+1; i--){
            if(scol==ecol) break;
            ans.push_back(arr[i][scol]);
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }
    for(int x : ans) {
        cout << x << " ";
    }
}