#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Time complexity
// O(len of the word)



// insert search and startwith in trie
struct Node
{
    Node *links[26];
    bool flag;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    } 
    bool setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
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
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // move to the reference trie;
            node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool Startwith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};


int main()
{

    return 0;
}