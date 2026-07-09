#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n = 1211;
    int revNum=0;
    int originalNum=n;
    while(n!=0){
        int digit=n%10;
        if(revNum>INT_MAX/10 || revNum<INT_MIN/10) cout<<"Not valid";
        revNum = revNum*10 + digit;
        n=n/10;
    }
    if(revNum == originalNum) cout<<"Palindrome";
    else cout<<"Not a palindrome";
}