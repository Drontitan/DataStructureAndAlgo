#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int Count_Digit(int num)
{
  int ans = 0;
  while (num)
  {
    num = num / 10;
    ans++;
  }

  return ans;
}
string formreverse(string ans,map<int,char>mp ,string nonspecial , int n  ){
  int j=0;
    for (int i = 0; i <n ; i++)
  {
    if (mp.find(i) != mp.end())
      ans+= mp[i];
    else if(j<nonspecial.size()){
      ans+=nonspecial[j];
      j++;
    }
  }
  while(j<nonspecial.size()){
    ans+=nonspecial[j];
    j++;
  }

  return ans;
}
int main()
{

  // for the 1st question
  // when it is in the form of vector of string
  vector<string> vec = {"122", "234", "3244", "312", "344444", "23", "444"};
  int count = 0;
  for (auto ele : vec)
  {
    if (ele.size() % 2 == 0)
      count++;
  }
  cout << count << endl;

  // when it is in the form of vector of integer
  vector<int> num = {122, 234, 3244, 312, 344444, 23, 444, 1000};
  count = 0;
  for (auto ele : num)
  {
    if (Count_Digit(ele) % 2 == 0)
      count++;
  }
  cout << count << endl;

  // for the 2nd question
  string str = "a.b$c";;
  map<int, char> mp;
  string nonspecial;
  string ans = "";
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] >= 'a' && str[i] <= 'z')nonspecial+=str[i];
    else
      mp[i] = str[i];
  }
  for (auto ele : mp)
    cout << ele.first<<" "<<ele.second<<" ";
   cout <<endl;
  // using direct string reverse function
  int j=0;
  reverse(nonspecial.begin(), nonspecial.end());
  cout<<formreverse("",mp,nonspecial,str.size())<<endl;

  //  without using the reverse function
  reverse(nonspecial.begin(), nonspecial.end());
  string nonreverse="";
  for (int i = nonspecial.size() - 1; i >= 0; i--)
  {
     nonreverse+=nonspecial[i];
  }
  cout<<formreverse("",mp,nonreverse,str.size())<<endl;

  return 0;
}