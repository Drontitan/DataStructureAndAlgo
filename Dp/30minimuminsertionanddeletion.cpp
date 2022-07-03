#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// minimum possible operation to convert the string 1 to string 2 
// deletion and insertino to make the string 1 equals to the string 2


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
    // the insertion will be the the length of the string and the longest common pallidromic string
    // n + m - 2* length of the longest common pallindromic string
    // total length of both the string -  length of the longest pallindromic string between them 
    string str1 = "acda";
    string str2 ="ana";//here is the only trick we want to follow
    // else all part are same as lcs 
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n, vector<int>(m + 1, -1));
    vector<vector<int>> dpit(n + 1, vector<int>(m + 1, 0));
   
    int lenghtodlongcommoonapallidrome= longestcommonpallinspaceopti(str1, str2, n, m);
     cout<<(n+m)-2*lenghtodlongcommoonapallidrome<<endl;

    return 0;
}