#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// here we have to CountWordEqualto and CountwordStartingWith


struct Node
{
    Node *link[26];
    int CountEndwith = 0;
    int CountPrefix = 0;

    bool ContainKey(char ch)
    {
        return (link[ch - 'a'] != NULL);
    }

    Node *get(char ch)
    {
        return link[ch - 'a'];
    }
    void put(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }
    void IncreaseEnd()
    {
        CountEndwith++;
    }
    void IncreasePrefix()
    {
        CountPrefix++;
    }
    void delteEnd()
    {
        CountEndwith--;
    }
    void deltePrefix()
    {
        CountPrefix--;
    }
    int getEnd(){
        return CountEndwith;
    }
    int getPrefix(){
        return CountPrefix;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->ContainKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->IncreasePrefix();
        }
        node->IncreaseEnd();
    }
    int CountWordEqualto(string word){
         Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->ContainKey(word[i]))
            {
                 node = node->get(word[i]);
            }
            else {
                return 0;
            }
        }
          node->getEnd();
        
    }
    int CountWordStartingWith(string &word){
           Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (node->ContainKey(word[i]))
            {
                 node = node->get(word[i]);
            }
            else {
                return 0;
            }
        }
          node->getPrefix();
    }
    void getErase(string &word){
           Node *node = root;
        for (int i = 0; i < word.size(); i++)
         {
            if (node->ContainKey(word[i]))
            {
                 node = node->get(word[i]);
                 node->deltePrefix();
            }
            else return;
         
        }
        node->delteEnd();
          
    }
};


int main()
{
}