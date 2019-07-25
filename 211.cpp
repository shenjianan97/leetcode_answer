#include <iostream>

using namespace std;

typedef struct trie_node{
    bool is_word;
    struct trie_node *next[26];
}trie_node, *trie_ptr;

class WordDictionary {
public:
    trie_ptr root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new trie_node();
        root->is_word = false;
        for(int i=0; i<26; i++){
            root->next[i] = NULL;
        }
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
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

    bool search_inner(trie_ptr p, string word){
        int nums = word.length();
        cout << "nums" << nums << endl;
        for(int i=0; i< nums; i++){
            if(word[i] == '.'){
                // 找到所有不为null的p->next
                for(int n=0; n<26; n++){
                    if(p->next[n] != NULL){
                        if(search_inner(p->next[n], word.substr(i+1, nums-i-1)) == true){
                            return true;
                        }
                    }
                }
                return false;
            }else if((p->next)[word[i] - 'a'] == NULL){
                return false;
            }
            p = (p->next)[word[i] - 'a'];
        }
        return p->is_word;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search_inner(root, word);
    }
};

int main(){
    WordDictionary* obj = new WordDictionary();
    obj->addWord("a");
    bool param_2 = obj->search(".");
    cout << param_2 << endl;

    return 0;
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */