#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// atmax k transaction  k time buy and sell in the row as we discussed previously 

int buyandsellstock(int i, int buy,int cap, vector<int> &vec)
{

    if (i == vec.size() || cap==0)
        return 0;

    long profit = 0;
    if (buy)
    {
        profit = max(-vec[i] + buyandsellstock(i + 1, 0,cap, vec), 0 + buyandsellstock(i + 1, 1,cap, vec)); // profit1
                                                                                                    // in the buy we have checked two conditions either to buy on that day or not buy on that
                                                                                                    // we are buying so there is -  negative sign
    }
    else
    {
        // selling so the added value is +  positive
        profit = max(vec[i] + buyandsellstock(i + 1, 1,cap-1, vec), 0 + buyandsellstock(i + 1, 0,cap, vec)); // profit2
    }

    return profit;
}

// memoization   TC O(N*2*3)  SC:-O(N*2*3) + auxialryspace
int buyandsellstockmemo(int i, int buy,int cap, vector<int> &vec, vector<vector<vector<int>>> &dp)
{

    if (i == vec.size() || cap==0)
        return 0;
    long profit = 0;
    if (dp[i][buy][cap] != -1)
        return dp[i][buy][cap];
    if (buy)
    {
        profit = max(-vec[i] + buyandsellstockmemo(i + 1, 0,cap, vec, dp), 0 + buyandsellstockmemo(i + 1, 1,cap, vec, dp)); // profit1
                                                                                                                    // in the buy we have checked two conditions either to buy on that day or not buy on that
                                                                                                                    // we are buying so there is -  negative sign
    }
    else
    {
        // selling so the added value is +  positive
        profit = max(vec[i] + buyandsellstockmemo(i + 1, 1,cap-1, vec, dp), 0 + buyandsellstockmemo(i + 1, 0,cap, vec, dp)); // profit2
    }
    return  dp[i][buy][cap] = profit;
}

// tabulation
int buyandsellstockitertive(int n, int k,vector<int> vec, vector<vector<vector<int>>> &dp)
{

    for(int i=0 ;i<=n;i++){
        for(int buy =0 ;buy<=1;buy++){
            dp[i][buy][0]=0;
        }
    }
    for(int buy =0 ;buy<=1;buy++){
        for(int cap =0 ;cap<=k;cap++){
            dp[n][buy][cap]=0;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            for(int cap=1;cap<=k;cap++){

            
            long profit = 0;
            if (j)
            {
                profit = max(-vec[i] + dp[i + 1][0][cap], 0 + dp[i + 1][1][cap]); // profit1
                                                                        // in the buy we have checked two conditions either to buy on that day or not buy on that
                                                                        // we are buying so there is -  negative sign
            }
            else
            {
                // selling so the added value is +  positive
                profit = max(vec[i] + dp[i + 1][1][cap-1], 0 + dp[i + 1][0][cap]); // profit2
            }
            dp[i][j][cap] = profit;
            }
        }
    }
    return dp[0][1][k];
}

// space optimizatoin
int buyandsellstockspaceopti(int n,int k, vector<int> vec)
{

    vector<vector<int>>after(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
    // it 2*3 matrix jus used 2d matrix here 
   for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            for(int cap=1;cap<=k;cap++){

            
            long profit = 0;
            if (j)
            {
                profit = max(-vec[i] + after[0][cap], 0 + after[1][cap]); // profit1
                                                                        // in the buy we have checked two conditions either to buy on that day or not buy on that
                                                                        // we are buying so there is -  negative sign
            }
            else
            {
                // selling so the added value is +  positive
                profit = max(vec[i] + after[1][cap-1], 0 + after[0][cap]); // profit2
            }
            curr[j][cap] = profit;
            }
        }
        after=curr;
    }
    return after[1][k];
}
int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4,9};
    int n = prices.size();
    int k=3;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1,-1)));      // 2 because we can buy or not is taken as two steps
    vector<vector<vector<int>>> dpit(n + 1, vector<vector<int>>(2,vector<int>(k+1,0))); // 2 because we can buy or not is taken as two steps
    cout << buyandsellstock(0, 1,k, prices) << endl;
    cout << buyandsellstockmemo(0, 1, k, prices, dp) << endl;
    cout << buyandsellstockitertive(n,k, prices, dpit) << endl;
    cout << buyandsellstockspaceopti(n,k, prices) << endl;
    return 0;
}