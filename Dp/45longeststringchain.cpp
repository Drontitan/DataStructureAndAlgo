#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// string chain means ex : - a, b  ,ba , bda ,bca , bdca

// here {a ba bda} , {a,ba,bda }, {a,b, ,bda,bca}
// so here next element will be addition on 1 char to previod element
//  or the previous element will be the 1 deletion of the next guy
// we have to print he longest length of such strings array

bool checkpossibility(string s, string t)
{
    if (s.size() != t.size() + 1)
        return false;
    int first = 0;
    int second = 0;
    while (first < s.size())
    {
        if (s[first] == t[second])
        {
            first++;
            second++;
        }
        else
        {
            first++;
        }
    }
    if (first == s.size() && second == t.size())
        return true;
    return false;
}
bool comp(string &s ,string &t){
    return   s.size() >t.size();
}

// TC :O(N*N)*length of the string 
// Sc- O(n);
int main()
{
    vector<string> vec = {"a", "b", "ba", "bca", "bda", "bdca"};
    sort(vec.begin(), vec.end(),comp);
    int n = vec.size();
    int maxi = 1;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {

        for (int prev = 0; prev < i; prev++)
        {
            if (checkpossibility(vec[i], vec[prev]) && (1 + dp[prev] > dp[i]))
            {
                dp[i] = 1 + dp[prev];
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
        }
    }


    cout << maxi;
    return 0;
}