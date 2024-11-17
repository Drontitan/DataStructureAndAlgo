// wordlist   {hot dot dog lot log cog}
// begin word  =hit // endword  cog;

//here we have to find the minimum step to convert the begin word to end word 
// and this all should be present in the worldlist and we can perfrom transaction only 1 at a time 

// brute force we can convert the h -> a to z 
   // similar for i -> a to z and t ->a to z 
   // whenever we the find the word in wordlist we will count that step as 1 and so on

   // here we will use queue as for our brute force approach 

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>>q;
        set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        q.push({beginWord,1});
        
        while(!q.empty()){
            auto node = q.front();
            string word = node.first;
            int step = node.second;
            if(word==endWord)return step;
            q.pop();
            for(int i=0; i<word.size();i++){
                char original = word[i];
                
                for(char j ='a' ;j<='z';j++){
                    word[i]=j;
                    
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        // to avoid revisting same word in future 
// avoiding cycles
                        q.push({word,step+1});
                    }
                }
                word[i]=original;
            }
            
        }
        
        return 0;
    }

int main(){
    
    return 0;
}