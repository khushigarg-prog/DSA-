 /* #include<iostream>
using namespace std;
bool isFreqSame(int freq[26], int windFreq[26]){
    for(int i=0; i<26; i++){
        if(freq[i] != windFreq[i]) return false;
    }
    return true;
}
bool ExistPermutation(string s1, string s2){
    // freq of s1 
    int freq[26] = {0}; // to count freq of characters of s1
    for(int i=0; i<s1.size(); i++){
        int idx_s1 = s1[i]-'a'; // a-a = 0 , b-a = 98-97=1
        freq[idx_s1]++;
    }

    // s1 size will be window size in s2..if s1 is 2 it means length of window will be 2 to search in s2
    int windSize = s1.size(); //2 
    for(int i=0;i<s2.size()-windSize; i++){
        int windIdx=0, idx_s2=i;
        int windFreq[26]={0}; 
        while(windIdx<windSize && idx_s2<s2.size()){
            int windFreqIdx = s2[idx_s2]-'a';
            windFreq[windFreqIdx]++;
            windIdx++;
            idx_s2++;
        }
        if(isFreqSame(freq,windFreq)){
            return true;
        }
    }
    return false;
}
int main(){
    string  s1 = "ab";
    string  s2 = "eidbaooo";
    cout<<ExistPermutation(s1,s2);
} */

#include<iostream>
using namespace std;
bool isFreqSame(int freq[26], int windFreq[26]){
    for(int i=0; i<26; i++){
        if(freq[i] != windFreq[i]) return false;
    }
    return true;
}
bool ExistPermutation(string s1, string s2){
    // count freq of characters of s1
    int freq[26] = {0};
    for(int i=0; i<s1.size(); i++){
        int idx_freq= s1[i]-'a';
        freq[idx_freq]++;
    }

    int windSize = s1.size();
    for(int i=0; i<s2.size()-windSize; i++){
        int windIdx=0, idx_s2=i;
        int windFreq[26] = {0};
        while(windIdx<windSize && idx_s2<s2.size()){
            int windFreqIdx= s2[idx_s2]-'a';
            windFreq[windFreqIdx]++;
            windIdx++;
            idx_s2++;
        }
        if(isFreqSame(freq,windFreq)) return true;
    }
    return false;
}
int main(){
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout<<ExistPermutation(s1,s2);
}