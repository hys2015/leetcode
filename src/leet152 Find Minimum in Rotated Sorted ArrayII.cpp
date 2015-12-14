/**
	https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
    题目说的挺玄乎，其实就是找数组中的最小值
    旋转不旋转，重复不重复其实没什么区别 
	用二分法直接找即可 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findm(nums, 0, nums.size()-1);
    }
    int findm(vector<int>& nums, int low, int high){
        if( low >= high ){
            return nums[low];
        }
        int mid = low + (high - low)/2;  //不要随便将除法转换为位操作 
        int n1 = findm(nums, low, mid);
        int n2 = findm(nums, mid+1,high);
        return n1 > n2 ? n2: n1;
    }
};
