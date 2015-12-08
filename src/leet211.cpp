#include<iostream>
#include<cstring>
#include<string>

using namespace std;

class DictNode{
public:
    char c;
    DictNode* next[26];
    bool isWord;
    DictNode(char _c):c(_c),isWord(false){
        memset(next,0,sizeof(DictNode*) * 26);        
    }
    DictNode():isWord(false){
        memset(next,0,sizeof(DictNode*) * 26);
    }
};


class WordDictionary {
public:
    //constructor
    WordDictionary(){
        root = new DictNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        DictNode* p = root;
        for(int i = 0 ; i < word.size() ; ++i ){
        	char c = word[i];
            int idx = c - 'a';
            if(!p->next[idx]){
                p->next[idx] = new DictNode(c);
            }
            p = p -> next[idx];
        }
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchHelper(root,word.c_str());
    }
private:
    DictNode* root;
    
   	bool searchHelper(DictNode* now,const char* s){
        DictNode* p =now;
        for(int i = 0; i < strlen(s); ++i){
            if(p && s[i] == '.'){
                //DictNode* x = p;    //这个地方的问题
                for(int j = 0;j < 26 ; ++j){
                    //p = x->next[j];
                    //if(searchHelper(p,s+i+1)) return true;
                
                    DictNode* x = p->next[j];
                    if(searchHelper(x,s+i+1)) return true;
                }
            }else if(p && s[i] != '.'){
                int idx = s[i] - 'a';
                p = p -> next[idx];
            }else{
                break;
            }
        }
        return p && p->isWord;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(){
	WordDictionary wordDictionary;
	wordDictionary.addWord("a");
	bool t = wordDictionary.search("a.");
	cout<< t << endl;
}
