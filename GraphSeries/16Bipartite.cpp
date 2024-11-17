#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// color the all nodes by two color  in such a way that the adjacent node should not have the same color  

// linear graph with no cycle is  always bipartite

// any graph with the even cycle length is also the bipartite

// any graph with odd length cycle can never be the bipartite

// what we have done we have took the intitial color to be the 0 then the all adjacent node to oppposite of the 
// color of the previous node 

//TC- O(V +2E);
//Sc -O(V)

bool check(int start, vector<int> vec[], int color[]){
    queue<int> q;
    q.push(start);
    color[start] = 0;


    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        // cout<<node<<" ";
        for (auto ele : vec[node])
        {
            // if the adajacent node is yet not colored
            //  we wil, the give the opposite the color of the node
            if (color[ele] == -1)
            {
                color[ele] = !color[node];
                q.push(ele);
            }
            // if the adjacent have the same color
            // if someone have colored it beore
            else if (color[ele] == color[node])
                return false;
        }
    }

    return true;
}

bool dfs(int start , int col , vector<int>vec[], int color[]){
    color[start]=col;
    for(auto ele : vec[start]){
        if(color[ele]==-1){
           if(dfs(ele,!col,vec,color)==false)return false;
        }
        else if(color[ele]==color[start])return false;
    }
    return true;
}

int main(){

    int n, e;
    cin >> n >> e;
    vector<int> vec[n + 1];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    // for(int i=1; i<=n ;i++){
    //     cout<<i<<" ";
    //     for(auto ele :vec[i] )cout<<ele<<" ";
    //     cout<<endl;
    // }


    bool ans = true;
    int color[n + 1];
    for (int i = 1; i <= n; i++)
        color[i] = -1;

    for (int i = 1; i <= n; i++)
    {   // if the graph has the component the code usually get fails for the larger
        // test cases then use the component code to be safe
        // if (color[i] == -1)
        // {
        //     if (check(i, vec, color) == false)
        //         ans = false;
        // }
        if (color[i] == -1)
        {
            if (dfs(i,0, vec, color) == false)
                ans = false;
        }
    }

    cout << ans << " ";
    return 0;
}