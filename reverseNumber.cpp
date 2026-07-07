#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int revNum=0;
    while(n!=0){
        int digit = n%10;
        // Check for potential overflow before multiplying by 10
        if(revNum > INT_MAX / 10 || revNum < INT_MIN / 10){
                return 0; 
        }
        revNum = revNum * 10 + digit;
        n = n / 10;
    }
    cout<<revNum;
}