#include<iostream>
using namespace std;
int main(){
    int arr[3][4] = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    int m = 3; // no. of rows
    int n = 4; // no. of cols
    int target = 34;
    int startRow=0; //starting row
    int endRow=m-1; //ending row
    bool found = false;
    // Apply BS on no. of rows to find appropriate rows
    while(startRow<=endRow){
        int mid = startRow+(endRow-startRow)/2; //Now find that if target exist in this row or not
        if(target >= arr[mid][0] && target <= arr[mid][n-1]){
            //found the row , now apply BS on this row 
            int st=0, end = n-1;
            while(st<=end){
                int midCol = st+(end-st)/2;
                if(target==arr[mid][midCol]){
                    cout<<"Found: "<<arr[mid][midCol];
                    found = true;
                    break;
                }
                else if(target>arr[mid][midCol]){
                    st=midCol+1;
                }
                else{
                    end=midCol-1;
                }
            }
            break;
        }
        else if(target>=arr[mid][n-1]){
            startRow=mid+1;
        }
        else{
            endRow=mid-1;
        }
    }
}