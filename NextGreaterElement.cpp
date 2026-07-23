#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    vector<int> arr = {6,8,0,1,3};
    // next greater element
    stack<int> s;
    vector<int> ans(arr.size(),0);
    for(int i=arr.size()-1; i>=0; i--){
        // agr elements chote h or hume chaye next greater tih unhe pop krdo
        while(s.size()>0 && s.top() <= arr[i]){
            s.pop(); // chote elements ko pop krdo
        }

        // agr hmare stack m kuch nhi h toh ans -1 hoga
        // jse last element k next greater kuch nhi h toh hum stack m kya hi store krenge 
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(arr[i]);
    }
    // print ans
    for(int val: ans){
        cout<<val<<" ";
    }
    cout<<endl;
}