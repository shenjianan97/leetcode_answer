#include <iostream>

using namespace std;

typedef struct trie_node{
    bool is_word;
    struct trie_node *next[26];
}trie_node, *trie_ptr;

class Trie {
public:
    trie_ptr root;
    /** Initialize your data structure here. */
    Trie() {
        root = new trie_node();
        root->is_word = false;
        for(int i=0; i<26; i++){
            root->next[i] = NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int nums = word.length();
        trie_ptr p = root;
        for(int i=0; i< nums; i++){
            if((p->next)[word[i] - 'a'] == NULL){
                (p->next)[word[i] - 'a'] = new trie_node();
            }
            p = (p->next)[word[i] - 'a'];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int nums = word.length();
        trie_ptr p = root;
        for(int i=0; i< nums; i++){
            if((p->next)[word[i] - 'a'] == NULL){
                return false;
            }
            p = (p->next)[word[i] - 'a'];
        }
        return p->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int nums = prefix.length();
        trie_ptr p = root;
        for(int i=0; i< nums; i++){
            if((p->next)[prefix[i] - 'a'] == NULL){
                return false;
            }
            p = (p->next)[prefix[i] - 'a'];
        }
        return true;
    }
};

int main(){
    Trie* obj = new Trie();
    obj->insert("apple");
    bool param_2 = obj->search("apple");
    bool param_3 = obj->startsWith("app");

    cout << param_2 << endl;
    cout << param_3 << endl;

    return 0;
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */