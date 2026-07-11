#include<iostream>
using namespace std;
int main(){
    int arr[5][5] = {{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};
    int m=5, n=5;
    int row = 0; // staring row
    int col = n-1; //starting col
    int target=5;
    bool found = false;
    while(col>=0 && row<m){
        // mid value is already [row][col] which we are taking
        if(target==arr[row][col]){
            cout<<"Found";
            found=true;
            break;
        }
        else if(target>arr[row][col]){
            row++;
        }
        else{
            col--;
        }
    }
    if(!found) {
        cout << "Not Found\n";
    }
}