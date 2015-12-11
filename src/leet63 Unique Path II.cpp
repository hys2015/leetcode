/*
  https://leetcode.com/problems/unique-paths-ii/
  �������62�������棬����һ�����������ϰ���
  ����ԭ���62��ͬ�����������(i,j)���·������������(m-1,n-1)����ֵ 
  ֻ�������ϰ��1���Ͱ�����ط���ֵ��Ϊ0����
  (i,j)��ֵ����(i-1,j)��(i,j-1)��ӵõ��� 
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
