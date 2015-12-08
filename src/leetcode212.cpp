#include<cstring>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class TreiNode{
    public:
        char c;
        TreiNode* next[26]; 
        bool isWord;
        TreiNode():isWord(false){
            memset(next,0,sizeof(TreiNode*) * 26);
        }
        TreiNode(char _c):c(_c),isWord(false){
            memset(next,0,sizeof(TreiNode*) * 26);
        }
};

class TreiTree{
    public:
        TreiNode* root;
        TreiTree():root(new TreiNode()){
            
        }
        void addWord(string& word){
            TreiNode* p = root;
            for(int i = 0 ; i < word.size() ; ++i){
                int idx = word[i]-'a';
                if(p->next[idx]){
                    p->next[idx] = new TreiNode(word[i]);
                }                
                p = p->next[idx];
            }
            p->isWord = true;
        }
};

class Solution {
private:
    void findWords(TreiNode* p,vector<vector<char> >& board,int i,int j,int m,int n ,vector<string>& result,string& str){
        if(i<0||i>=m||j<0||j>=n){
            return;
        }
        if(board[i][j] == '*'){
            return;
        }
        char ch = board[i][j];
        str+=ch;
        board[i][j] = '*';
        int idx = ch-'a';
        if(!p->next[idx]){
            str = string("");
            return;
        }else if(p->isWord){
            result.push_back(str);
        }
        if(i-1 >= 0){
            findWords(p,board,i-1,j,m,n,result,str);
        }
        if(i+1 < m){
            findWords(p,board,i+1,j,m,n,result,str);
        }
        if(j-1 >= 0){
            findWords(p,board,i,j-1,m,n,result,str);
        }
        if(j+1 < n){
            findWords(p,board,i,j+1,m,n,result,str);
        }
    }
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> result;
        
        TreiTree trei;
        for(int i = 0 ; i < words.size() ; ++i){
            trei.addWord(words[i]);
        }
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0 ; i < rows ; ++i){
            for(int j = 0 ; j < cols ; ++j){
            	string str;
                findWords(trei.root,board,i,j,rows,cols,result,str);
            }
        }
        return result;        
    }
};

int main(){
	
}
