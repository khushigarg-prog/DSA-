#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    int rows=3, cols=3;
    int maxRowSum = INT_MIN;
    for(int i=0; i<rows; i++){
        int rowSum = 0;
        for(int j=0; j<cols; j++){
            rowSum += arr[i][j];
        }
        maxRowSum = max(maxRowSum,rowSum);
    }
    cout<<maxRowSum;
}