#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	if(obstacleGrid.size() > 0 && obstacleGrid[0].size() > 0 && obstacleGrid[0][0] == 1){
           return 0;
        }
        for( int i = 0 ; i < obstacleGrid[0].size() ; ++i){
            if( obstacleGrid[0][i] == 1 ){
                obstacleGrid[0][i] = 0;
                break;                
            }
            obstacleGrid[0][i] = 1;
        }
        for( int i = 1; i < obstacleGrid.size(); ++i){
            if(obstacleGrid[i][0] == 1){
                obstacleGrid[i][0] = 0;
            }else{
                obstacleGrid[i][0] = 1;
            }
            for( int j = 1; j < obstacleGrid[0].size(); ++j){
                if( obstacleGrid[i][j] == 1 ){
                    obstacleGrid[i][j] == 0;
                }else{
                    int left = obstacleGrid[i][j-1];
                    int up = obstacleGrid[i-1][j];
                    obstacleGrid[i][j] = left + up;
                }
            }
        }
        return obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
int main(){
	Solution sol;
	vector<vector<int> > nums;
	vector<int> s;
	s.push_back(0);
	s.push_back(0);
	nums.push_back(s);
	cout<< nums[0].size() << endl;
	int res = sol.uniquePathsWithObstacles(nums);
	cout << res << endl;
	return 0;	
}
