#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int  solve(int n,vector<int>&vec){
        vector<int>prev(n+1,0),prev2(n+1,0),curr(n+1,0);
        
        for(int i=n-1;i>=0 ; i--){
            for(int j= 0; j<n;j++){
                  if(i>j)continue;
                   else if(i==j)curr[j]=vec[i];
    else{
        int take1 = vec[i]+min(i + 2 < n ? prev2[j] : 0,prev[j-1]);
        
        int take2= vec[j]+min(prev[j-1],j - 2 >= 0 ? curr[j - 2] : 0);
         
        curr[j]=max(take1,take2);
            }
                
        }
            prev2=prev;
            prev=curr;   
        }
        

       
       int player1 = prev[n - 1];
       int totalScore = 0;
       for(int i = 0; i < n; i++)
           totalScore += vec[i];
       int player2= totalScore - player1;
       
       return player1 ; 
        
    }

int main(){
  vector<int>vec={4,20,2,11};
  int ans = solve(vec.size(),vec);
  cout<<ans<<endl;
  
  return 0;
}