//jus print all the sequence that lead to the endword
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<vector<string>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord}); // here we are storing as a list of string 
        vector<string>useonlevel;
        useonlevel.push_back(beginWord);
        vector<vector<string>>ans;
        int level=0;
        while(!q.empty()){
            
            vector<string>vec=q.front();
            q.pop();
            // erase all the word that has been 
            // used in the preious level to transform
            if(vec.size()>level){
                level++;
                for(auto ele :useonlevel )st.erase(ele);
                useonlevel.clear();
            }

            string word = vec.back();
            // storing the ans;
            if(word==endWord){
                // first sequence where we reach the end 
                if(ans.size()==0){
                    ans.push_back(vec);
                }
                // as we have one sequence size so we will use to compare for new ones
                else if (ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0; i<word.size();i++){
                int original = word[i];
                for(char ch= 'a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        q.push(vec);
                        // make as visited on the level;
                        useonlevel.push_back(word);
                        vec.pop_back(); // see as on level Ex:-  bat , pat
                        // then bat , cat // so it can change on current level as we are pushing 
                        // in to queue , we dont need to worry here we can change 
                    }
                }
                word[i]=original;
            }
        }
        return ans;
        
    }

int main(){
    
    return 0;
}