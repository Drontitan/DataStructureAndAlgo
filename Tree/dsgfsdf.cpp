#include <bits/stdc++.h>
using namespace std;
int  main()
{
	int t;
	cin>>t;
	while(t--){
        int x,y,z;
	    cin>>x>>y>>z;
	    vector<vector<int>>(8,vector<int>(3));
	    t=x+y+z;
	    if(x<y)
	        ans=abs(y);
	   else
	        ans=abs(y);
	   if(z>ans)
	        ans=abs(z);
	   if(2*ans==t)
	    printf("yes\n");
	   else
	    printf("no\n");
	}
	return 0;
}