#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//  we taken the ind1 which is the index of the str1 it will be tracing it from the last ans if
// it is equal to the ind2 which is tracing the str2 then we got match increase the 1

// if not match we have two possiblity wither we can decrease the ind1 or ind2 so we have took the
// max of  both the calls

// dp on strings


// tabulation bottom to up
// shifying og the index so here 0  will be -1 ans n as n-1 and m as m-1
// space optimization
int longestcommonpallinspaceopti(string str1, string str2, int n, int m)
{
    vector<int>prev(m+1,0),curr(m+1,0);
    for (int j = 0; j <= m; j++)
        prev[j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i-1] == str2[j-1])
            {
                curr[j] = 1 + prev[j - 1]; //  match
            }
            else curr[j] = max(prev[j], curr[j - 1]); // notmatch
        }
        prev=curr;
    }
    return prev[m];
}

int main()
{
    // the insertion will be the the lenght of the string and the longest common pallidromic string
    // n - length of longest common pallindromic string  
    string str1 = "acdacavda";
    string str2 =str1;//here is the only trick we want to follow
    reverse(str2.begin(), str2.end());
    // else all part are same as lcs 
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    vector<vector<int>> dpit(n + 1, vector<int>(m + 1, 0));
   
    int lenghtodlongcommoonapallidrome= longestcommonpallinspaceopti(str1, str2, n, m);
     cout<<n-lenghtodlongcommoonapallidrome<<endl;

    return 0;
}