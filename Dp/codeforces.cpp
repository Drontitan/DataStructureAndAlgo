#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
          set<string>st;
        for (int i = 0; i < n-1; i++)
        {
            string substr ="";
            substr += str[i];
            substr+=str[i+1];
            st.insert(substr);
        }
        cout << st.size() << endl;
    }
    return 0;
}