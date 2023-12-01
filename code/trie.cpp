#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fr first
#define sc second

const int SIZE = 26;

struct node 
{
    node *child[SIZE];
    bool isEndOfWord;
};

void ins(node *root, string key)
{
    node *now = root;
    int i;
    for (i=0; i<key.length(); i++)
    {
        int index = key[i]-'a';
        if (!now->child[index])
        {
            now->child[index] = new node();
        }
        now = now->child[index];
    }
    now->isEndOfWord = 1;
}

bool search(node *root, string key)
{
    node *now = root;
    int i;
    for (i=0; i<key.length(); i++)
    {
        int index = key[i]-'a';
        if (!now->child[index])
        {
            return 0;
        }
        now = now->child[index];
    }
    return now->isEndOfWord;
}

int main()
{

}