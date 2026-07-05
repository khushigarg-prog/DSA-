#include<iostream>
using namespace std;
int main(){
    int A[] = {1,2,3,0,0,0};
    int B[] = {2,5,6};
    int m=3, n=3;
    int idx=m+n-1; //last element of arr
    int i=m-1;
    int j=n-1;
    while(i>=0 && j>=0){
        if(A[i] >= B[j]){
            A[idx]=A[i];
            i--, idx--;
        }
        else{
            A[idx]=B[j];
            j--, idx--;
        }
    }
    // If elements remain in j and i<0
    while(j>=0){
        A[idx]=B[j];
        idx--, j--;
    }
    cout<<"Merged sorted array is : ";
    for(int i=0; i<m+n; i++){
        cout<<A[i]<<" ";
    }
}