/**
 	https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 	�����б�����ƽ�������
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //�ݹ�ⷨ 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST( nums, 0, nums.size() - 1);
    }
    TreeNode* buildBST( vector<int>& nums, int left, int right){
        if(nums.size() < 1 || left > right){
            return NULL;
        }
        int mid = (left + right + 1 )/2; //����û��+1������runcode���ݷ���֮���+1 
        TreeNode* node = new TreeNode(nums[mid]);
        node -> left = buildBST( nums, left, mid - 1);
        node -> right = buildBST(nums, mid + 1, right);
        return node;
    }
};

//���нⷨ
 
