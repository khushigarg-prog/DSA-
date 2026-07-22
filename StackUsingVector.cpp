#include<iostream>
#include<vector>
using namespace std;
class Stack{
    vector<int> v;
    public:
    void push(int val){
        v.push_back(val);
    }

    void pop(){
        v.pop_back();
    }

    int top(){
        return v[v.size()-1];
    }
    // to check if stack is empty..agr size 0 h toh true return krdo
    bool empty(){
        return v.size()==0;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}