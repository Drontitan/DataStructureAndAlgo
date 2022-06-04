#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// recursoin solution 
int solve(int day,int last, vector<vector<int>>&points){

    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    int maxi=0;
     for(int task=0;task<3;task++){
            if(task!=last){
               int point= points[day][task]+solve(day-1,task,points);
               maxi=max(maxi,point);
            }
        }
        return maxi;
}

// memoization solution
int solvememo(int day,int last, vector<vector<int>>&points,vector<vector<int>>&dp){

    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    int maxi=0;
    if(dp[day][last]!=-1)return dp[day][last];
     for(int task=0;task<3;task++){
            if(task!=last){
               int point= points[day][task]+solvememo(day-1,task,points,dp);
               maxi=max(maxi,point);
            }
        }
        return dp[day][last]=maxi;
}

// tabulation 
int solveiterative(int n, vector<vector<int>>&points,vector<vector<int>>&dp){
   
   dp[0][0]=max(points[0][1],points[0][2]);
   dp[0][1]=max(points[0][1],points[0][2]);
   dp[0][2]=max(points[0][1],points[0][1]);
   dp[0][3]=max(points[0][1],max(points[0][1],points[0][2]));
   
    for(int day=1;day<n;day++){
    for(int last=0;last<4;last++){
        dp[day][last]=0;
     for(int task=0;task<3;task++){
            if(task!=last){
               int point= points[day][task]+dp[day-1][task];
               dp[day][last]=max(dp[day][last],point);
            }
        }
    }
}
        return dp[n-1][3];
        
}


int ninjatraning(vector<vector<int>>&points,int n,vector<vector<int>>&dp){
//    return solve(n-1,3,points);
//    return solvememo(n-1,3,points,dp);
   return solveiterative(n,points,dp);
}
int main(){
     vector<vector<int>>points={{18,11,19},{4,13,7},{1,8,13}};
     int n=3;
     vector<vector<int>>dp(n,vector<int>(4,-1));
     cout<<ninjatraning(points,n,dp);
    return 0;
}