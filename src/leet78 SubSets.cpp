/*
 * https://leetcode.com/problems/subsets/
  Given a set of distinct integers, nums, return all possible subsets.
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:
[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
 *
 * */
class Solution {
	public:
		    vector< vector<int> > res;
		        vector<vector<int> > subsets(vector<int>& nums) {
				        sort(nums.begin(), nums.end());
					    res.clear();
					    vector<int> subset;
					    dfs(nums, subset, 0, nums.size() );
					    return res;
					        }
	private:
			    void dfs(vector<int>& nums,vector<int>& subset, int start, int size){
				        res.push_back(subset);
					    for( int i = start ; i < size ; ++i){
						        vector< int > t = subset;
							    t.push_back(nums[i]);
							        dfs(nums, t, i + 1, size);
								    }
					        }
};

