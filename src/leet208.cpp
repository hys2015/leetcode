#include<iostream>
#include<cstring>


using namespace std;

class TrieNode {
public:
    char c;
    TrieNode* next[26];
    bool isWord;
    
        // Initialize your data structure here.
    TrieNode():isWord(false){
        memset(next,0,sizeof(TrieNode*) * 26);
    }
    TrieNode(char _c):c(_c),isWord(false){
        memset(next,0,sizeof(TrieNode*) * 26);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for(int i = 0;i < word.size(); ++i){
            int idx = word[i] - 'a';
            if(!p -> next[idx]){
            	p -> next[idx] = new TrieNode(word[i]);
			}
            p = p->next[idx];
        }
        p->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); ++i){
            int idx = word[i]-'a';
            if(p -> next[idx]){
                p = p->next[idx];
            }else{
            	return false;
			}
        }
        return p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i = 0; i < prefix.size(); ++i){
            int idx = prefix[i] - 'a';
            if(!p->next[idx]) return false;
            p = p->next[idx];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(){
	Trie trie;
	trie.insert("abcd");
	trie.insert("cdef");
	trie.insert("aase");
	bool t = trie.startsWith("abc"); 
	cout<<t<<endl; //true
	t = trie.search("abcd");
	cout<<t<<endl; 
}
