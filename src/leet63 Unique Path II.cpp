/*
  https://leetcode.com/problems/unique-paths-ii/
  这个题是62的升级版，多了一个条件——障碍物
  但是原理和62相同，都是算出来(i,j)块的路径数，最后输出(m-1,n-1)处的值 
  只是遇到障碍物（1）就把这个地方的值设为0即可
  (i,j)的值是由(i-1,j)和(i,j-1)相加得到的 
*/



class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	if(obstacleGrid.size() > 0 && obstacleGrid[0].size() > 0 ){
    	    if(obstacleGrid[0][0] == 1){
                return 0;
    	    }
    	    if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1] == 1){
    	        return 0;
    	    }
        }
        for( int i = 0 ; i < obstacleGrid[0].size() ; ++i){
            if( obstacleGrid[0][i] == 1 ){
                obstacleGrid[0][i] = 0;
            }else{
                if(i > 0){
                    obstacleGrid[0][i] = obstacleGrid[0][i-1];
                }else{
                    obstacleGrid[0][i] = 1;
                }
            }
        }
        for( int i = 1; i < obstacleGrid.size(); ++i){
            if(obstacleGrid[i][0] == 1){
                obstacleGrid[i][0] = 0;
            }else{
                obstacleGrid[i][0] = obstacleGrid[i-1][0];
            }
            for( int j = 1; j < obstacleGrid[0].size(); ++j){
                if( obstacleGrid[i][j] == 1 ){
                    obstacleGrid[i][j] = 0;
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
