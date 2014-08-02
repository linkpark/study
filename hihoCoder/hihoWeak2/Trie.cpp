#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct TrieNode{
    int value;
    struct TrieNode* next[26];
};

class Trie{
public:
    Trie(){
        root = new struct TrieNode();
        root->value = 0;
        for(int i = 0 ; i < 26 ; i++)
            root->next[i] = NULL;
    }

    int initNode(struct TrieNode *pTrieNode){
        if(NULL == pTrieNode)
            return -1;

        pTrieNode->value = 0 ;
        for(int i = 0 ; i < 26; i++)
            pTrieNode->next[i] = NULL;
        
        return 0;
    }

    ~Trie(){
    }

    int insertOneNode(string& word){
        struct TrieNode *p;
        p = root;
        for(unsigned long i = 0 ; i < word.length(); i++){
            if(p->next[word[i] - 'a'] == NULL){
                p->next[word[i] - 'a'] = new struct TrieNode();
                initNode(p->next[word[i] - 'a']);
            }
            
            p = p->next[word[i] - 'a'];
            p->value++;
        }
        return 0; 
    }
    
    int queryWord(string& word){
        struct TrieNode *p;
        p = root;

        for(unsigned long i = 0 ; i < word.length(); i++){
            if(p == NULL){
                return 0;
            }

            if( NULL == p->next[word[i] - 'a'] )
                return 0;
            p = p->next[word[i] - 'a'];
        }
        
        return p->value;
    }

    
private:
    struct TrieNode* root;
};

int main(){
    int n,m;
    Trie trie;
    cin >> n;
    
    while (n >0){
        string word;
        cin >> word;    
        trie.insertOneNode(word);
        n--;
    }

    cin >>m;
    while (m>0){
        string wordQuery;
        cin >> wordQuery;
        cout << trie.queryWord(wordQuery) << endl;        
        m--;
    }
}

