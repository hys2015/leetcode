/**
	https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
    ��Ŀ˵��ͦ��������ʵ�����������е���Сֵ
    ��ת����ת���ظ����ظ���ʵûʲô���� 
	�ö��ַ�ֱ���Ҽ��� 
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
        int mid = low + (high - low)/2;  //��Ҫ��㽫����ת��Ϊλ���� 
        int n1 = findm(nums, low, mid);
        int n2 = findm(nums, mid+1,high);
        return n1 > n2 ? n2: n1;
    }
};
