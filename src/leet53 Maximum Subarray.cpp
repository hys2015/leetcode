/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

*/


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = nums[0] ;
        for( int i = 1 ; i < nums.size(); ++i){
            sum = sum>0 ? sum+nums[i]: nums[i];
            if(res < sum) res = sum;
        }
       
        return res;
    }
};
