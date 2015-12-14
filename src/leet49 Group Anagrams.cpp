/**
	https://leetcode.com/problemset/algorithms/
	�ַ����������⣬�ο��ı��˵Ĵ���
	�õ���unordered_map������� 
	�õ���autoָ��
	ע��: iterator��first,second���ǳ�Ա���������Ǻ��� 
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

