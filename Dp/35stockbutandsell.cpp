#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// dp on stocks 


//****here we can buy or sell only 1 time *******

// here i can buy the stock on 1 day and sell it on another day 
// here i can buy at low cost and sell at cost more than i buy so that i can get the profit

// TC: - O(N), SC:- O(N);

int main(){
    vector<int>prices={7,1,5,3,6,4};
    int n =prices.size();
    int mini= prices[0];
    int maxprofit=0;
    for (int i = 1; i <n; i++)
    {
        int cost = prices[i]-mini;
        maxprofit= max(maxprofit,cost);
        mini = min(mini ,prices[i]);
    }

    cout<<maxprofit<<endl;
    
    return 0;
}