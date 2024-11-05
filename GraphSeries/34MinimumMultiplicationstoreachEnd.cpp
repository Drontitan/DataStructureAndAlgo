#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// here we are again storing the steps and nod in queue
// but this time we are storing the steps in dis which ever has smallest;
int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here

         // Tc O(100000 * arr.size())
        int mod = 100000;
        vector<int>dis(100000,1e9);
        queue<pair<int,int>>q;
        q.push({0,start}); // steps and start 
        dis[start]=0;
        while(!q.empty()){
            int node =q.front().second;
            int steps =q.front().first;
            q.pop();
            for(int i=0; i<arr.size(); i++){
                int num =(node*arr[i])%mod;
                if(steps+1<dis[num]){
                    dis[num]=steps+1;
                    if(num==end)return steps+1;
                    q.push({dis[num],num});
                }
            }
        }
             return -1;
    }
int main(){
    
    return 0;
}