#include<iostream>
#include<cmath>
#include<vector>
#include<string>

using namespace std;

class Solution {
private:
    vector<vector<string> > res;
    void anagrams(vector<string>& strs, int idx){
    	string tstr = strs[idx];
    	vector<string> t;
    	t.push_back(tstr);
    	for(int i = idx+1; i < strs.size() ; ++i){
    		if(eqs(tstr, nums[i])){
    				
    		}else{
    			
    		}
    	}
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return anagrams(strs, 0);
    }
};
int main(){
	Solution sol;
	vector<string> s;
	s.push_back("eat");
	s.push_back("eta");
	s.push_back("etd");
	s.push_back("dte");
	vector<vector<string> > res = sol.groupAnagrams(s);
	cout << res.size() << endl;
	return 0;	
}
