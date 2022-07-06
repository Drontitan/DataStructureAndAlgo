#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// here every time you complere one buy and sell transaction will add the fee in to it 
//  B S then will add fee then again B S 

// recursion    TC:-O(2^n)   SC :- O(N)

int buyandsellstock(int i, int buy,int fee, vector<int> &vec)
{
   
    if (i >= vec.size())
        return 0;

    long profit = 0;
    if (buy)
    {
        profit = max(-vec[i] + buyandsellstock(i + 1, 0,fee ,vec), 0 + buyandsellstock(i + 1, 1,fee, vec)); // profit1
                                                                                                    // in the buy we have checked two conditions either to buy on that day or not buy on that
                                                                                                    // we are buying so there is -  negative sign
    }
    else
    {
        // selling so the added value is +  positive
        profit = max(vec[i]-fee + buyandsellstock(i + 1, 1,fee, vec), 0 + buyandsellstock(i + 1, 0,fee, vec)); // profit2
    }

    return profit;
}

// memoization   TC O(N*2)  SC:-O(N*2) + auxialryspace
int buyandsellstockmemo(int i, int buy,int fee, vector<int> &vec, vector<vector<int>> &dp)
{

    if (i >= vec.size())
        return 0;
    long profit = 0;
    if (dp[i][buy] != -1)
        return dp[i][buy];
    if (buy)
    {
        profit = max(-vec[i] + buyandsellstockmemo(i + 1, 0,fee, vec, dp), 0 + buyandsellstockmemo(i + 1, 1,fee ,vec, dp)); // profit1
                                                                                                                    // in the buy we have checked two conditions either to buy on that day or not buy on that
                                                                                                                    // we are buying so there is -  negative sign
    }
    else
    {
        // selling so the added value is +  positive
        profit = max(vec[i]-fee+ buyandsellstockmemo(i + 1, 1,fee, vec, dp), 0 + buyandsellstockmemo(i + 1, 0,fee, vec, dp)); // profit2
    }
    return dp[i][buy] = profit;
}

// tabulation
int buyandsellstockitertive(int n,int fee, vector<int> vec, vector<vector<int>> &dp)
{

    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            long profit = 0;
            if (j)
            {
                profit = max(-vec[i] + dp[i + 1][0], 0 + dp[i + 1][1]); // profit1
                                                                        // in the buy we have checked two conditions either to buy on that day or not buy on that
                                                                        // we are buying so there is -  negative sign
            }
            else
            {
                // selling so the added value is +  positive
                profit = max(vec[i]-fee + dp[i + 1][1], 0 + dp[i + 1][0]); // profit2
            }
            dp[i][j] = profit;
        }
    }
    return dp[0][1];
}


int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int n = prices.size();
    int fee=2;
    vector<vector<int>> dp(n, vector<int>(2, -1));      // 2 because we can buy or not is taken as two steps
    vector<vector<int>> dpit(n + 2, vector<int>(2, 0)); // 2 because we can buy or not is taken as two steps
    cout << buyandsellstock(0, 1,fee, prices) << endl;
    cout << buyandsellstockmemo(0, 1,fee, prices, dp) << endl;
    cout << buyandsellstockitertive(n,fee, prices, dpit) << endl;

    return 0;
}