#include<iostream>
#include<string>
using namespace std;
int main(){
    char chars[] = {'a', 'a', 'b', 'b', 'c' , 'c', 'c'};
    int n = sizeof(chars) / sizeof(chars[0]);;
    int index=0; //for assigning
    int i=0;
    while(i<n){
        char curr_char = chars[i];
        int count = 0; 
        // count the duplicates
        while(i<n && chars[i]==curr_char){
            count++;
            i++;
        }
        // Now assign values
        chars[index] = curr_char;
        index++;
        // then assign count
        if(count>1){
            string count_str = to_string(count);
            for(char &ch : count_str){
                chars[index]=ch;
                index++;
            }
        }
    }
    cout<<index;
}