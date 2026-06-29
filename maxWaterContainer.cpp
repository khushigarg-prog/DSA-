#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int lp=0; 
    int rp=8;
    int maxwater=0; //ans
    while(lp<rp){
        int width = rp-lp;
        int height = min(arr[rp],arr[lp]);
        int currwater = width*height;
        maxwater= max(maxwater,currwater);
        if(arr[lp]<arr[rp]) lp++;
        else rp--;
    }
    cout<<maxwater;
}