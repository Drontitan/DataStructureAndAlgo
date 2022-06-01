#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void escapingthecharacter(string p, string str)
{

    if (str.empty())
    {
        reverse(p.begin(), p.end());
        cout << p;
        return;
    }
    char ch = str.at(str.size() - 1);
    if (ch == 'a')
    {
        str.pop_back();
        escapingthecharacter(p, str);
    }
    else
    {
        p.push_back(ch);
        str.pop_back();
        escapingthecharacter(p, str);
    }
}
int main()
{
    string str;
    cin >> str;
    cout << str.length() << endl;
    escapingthecharacter("", str);
    return 0;
}