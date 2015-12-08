#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

class Solution {
private:
	void msort(vector<int> &vec){
		for(int i=vec.size()-1;i>=1;--i){
			for(int j=0;j<i;++j){
				if(vec[j+1]<vec[j]){
					int t 	 = vec[j+1];
					vec[j+1] = vec[j];
					vec[j] 	 = t;
				}
			}
		}
	}
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
		for( int i = 0 ; i < nums.size() ; ++i ){
            for( int j = i+1 ; j < nums.size() ; ++j ){
                for( int k = j+1 ; k < nums.size() ; ++k){
                    if( nums[i] + nums[j] + nums[k] == 0 ){
                        vector<int> vec;
                        vec.push_back(nums[i]);
						vec.push_back(nums[j]);
                        vec.push_back(nums[k]);
						msort(vec); 
                    	res.push_back(vec);
					}
                }
            }
        }
        return res;
    }
};

int main(){
	Solution s;
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(-1);
	nums.push_back(1);
	nums.push_back(-2);
	nums.push_back(2);	
	vector<vector<int> >res;
	res = s.threeSum(nums);
	for(int i = 0; i < res.size();++i){
		for(int j=0; j< res[i].size();++j){
			cout<< res[i][j]<<',';
		}
		cout<<endl; 
	}
	
} 
