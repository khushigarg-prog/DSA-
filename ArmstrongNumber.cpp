#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int SumOfCubes=0;
    int Copy=n;
    while(n>0){
        int digit = n%10;
        SumOfCubes+=(digit*digit*digit);
        n=n/10;
    }
    if(SumOfCubes==Copy){
        cout<<"Armstrong Number";
    }
    else{
        cout<<"Not Armstrong";
    }
}