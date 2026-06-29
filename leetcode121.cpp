#include<iostream>
using namespace std;
int main(){
    int prices[] = {7,6,4,3,1};
    int maxprofit=0;
    int bestbuy=prices[0];
    for(int i=1; i<5; i++){
        if(bestbuy < prices[i]){
            maxprofit = max(maxprofit,prices[i]-bestbuy);
        }
        bestbuy=min(bestbuy,prices[i]);
    }
    cout<<maxprofit;
}