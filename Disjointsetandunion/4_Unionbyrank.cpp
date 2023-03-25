#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// we are merging to different components so we are merging lower rank to higher rank component like 
// example one part fot the tree have rank 5 means there are total 5 node attached to that node 
// and similarly there is one 3 raank node 
// so we will attach this 3 rank node to that 5 rank node 

// cycle detection in undirected graph using dsu 
class Graph{
    int v;
    list<pair<int,int>>lt;

    public:
    Graph(int v){ 
        this->v=v;
    }

    void addedge(int u , int v){
        lt.push_back({u,v});
    }
    void print(){
        for(auto ele:lt)cout<<ele.first<<" "<<ele.second<<endl;
    }
      
      // find
      // here it find the leader of the set 
      int findset(int i , int parent[]){
        if(parent[i]==-1){
            return i;
        }
        return findset(parent[i],parent);  
      }


      //union
      void unionset(int x , int y  , int parent[] , int rank[]){
            int s1=findset(x,parent);
            int s2 =findset(y,parent);
            if(s1!=s2  ){
                if(rank[s1]<rank[s2]){
                    parent[s1]=s2;
                     rank[s2]+=rank[s1];
                }
                else {
                    parent[s2]=s1;
                     rank[s1]+=rank[s2];    
                }
                
            }
      }

    
    bool containscycle(){
    // dsu logic to check the cycle in the graph
     int *parent = new int[v+1];
     int *rank = new int[v];
     for(int i=0; i<v; i++){
        parent[i]=-1;
        rank[i]=1;
     }

     // iterate over the edge list
     for(auto ele: lt){
        int i = ele.first;
        int j = ele.second;
        
        int s1=findset(i,parent);
        int s2=findset(j,parent);

        if(s1!=s2){
            unionset(s1,s2,parent , rank);
        }
        else return true;
     }
      delete [] parent;
     return false;

    }

};


int main(){

      Graph g(4);
      g.addedge(0,1);
      g.addedge(1,2);
      g.addedge(2,3);
      g.addedge(3,0);

    //   g.print();

      cout<<g.containscycle()<<endl;

    
    return 0;
}