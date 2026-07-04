#include<iostream>
using namespace std;
bool isValid(int arr[], int n, int m, int maxAllowedPages){
    int student=1, pages=0;
    for(int i=0; i<n; i++){
        if(arr[i]>maxAllowedPages){
            return false;
        }
        if(arr[i]+pages<=maxAllowedPages){

            pages=pages+arr[i];
        }
        else{
            student++;
            pages=arr[i];
        }
    }
    if(student>m){
           return false;
    }
    else{
        return true;
    }
}
int allocateBooks(int arr[], int n, int m){
    if(m>n){
        return -1;
    }
    int sum=0; //to find max range
    for(int i=0; i<n; i++){
        sum=sum+arr[i];
    }
    int ans=-1;
    int start=0; //min possible pages allocated to a student
    int end=sum; //max possible pages allocated to a student
    while(start<=end){
        int mid=start+(end-start)/2;
        if(isValid(arr,n,m,mid)){
            ans=mid; //maxAllowedpages
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {2,1,3,4};
    int n=4; // no. of students
    int m=2; //no. of students
    cout<<allocateBooks(arr,n,m);
}