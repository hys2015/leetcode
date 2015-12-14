/**
	https://leetcode.com/problemset/algorithms/
	字符串分类问题，参考的别人的代码
	用到了unordered_map这个容器 
	用到了auto指针
	注意: iterator的first,second都是成员变量，不是函数 
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mymap;
        for(auto& str: strs){
            string cpy = str;
            sort(cpy.begin(), cpy.end());
            mymap[cpy].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it = mymap.begin(); it != mymap.end() ; it++){
            sort(it->second.begin(), (*it).second.end());
            res.push_back(it->second); //it->second instead of it->second()
        }
        return res;
    }
};

