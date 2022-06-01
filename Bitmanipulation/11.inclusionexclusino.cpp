#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isvowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        string str[t];
        for (int i = 0; i < t; i++)
        {
            cin >> str[i];
        }
        unordered_map<string, int> hash;
        for (int i = 0; i < t; ++i)
        {
            set<char> distinct_vowel;
            for (char ch : str[i])
            {
                if (isvowel(ch))
                {
                    distinct_vowel.insert(ch);
                }
            }
            string vowel_string;
            for (char ch : distinct_vowel)
            {
                vowel_string.push_back(ch);
            }
        }
    }
    return 0;
}