#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private: 
    vector<int> sta;
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        s
    }
};
int main(){
	Solution sol;
	//0.00001,2147483647
	//
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	TreeNode* res = sol.sortedArrayToBST(nums);
	return 0;	
}
