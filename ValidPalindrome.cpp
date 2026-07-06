#include<iostream>
using namespace std;
bool alphaNumeric(char ch){
    if((ch>='0' && ch<='9') ||(tolower(ch)>='a' &&  tolower(ch)>='a')){
        return true;
    }
    return false;
}
bool ValidPalindrome(string s){
    int start=0; 
    int end=s.size()-1;
    while(start<=end){
        if(!alphaNumeric(s[start])){
            start++;
            continue;
        }
        if(!alphaNumeric(s[end])){
            end--;
            continue;
        }
        if(tolower(s[start])==tolower(s[end])){
            start++, end--;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    //string s = "Ac3?e3c&a";
    string s = "khushi";
    cout<<ValidPalindrome(s);
}