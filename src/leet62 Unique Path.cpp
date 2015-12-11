/**
   https://leetcode.com/problems/unique-paths/
 * 典型的动态规划问题
 * 
 * 解释如下 
 * 
 * 1 1 1 1 1 1 1
 * 1 x . . . . .
 * . . . . . . .
 *
 * 上图是一个3*6的“迷宫”，求的是到达右下角(m-1,n-1)处的路径有多少条 
 * 可以看到从出发点到最上面一行的任意一点都只有条路即 f(0,j) = 0 | 其中j = {0,1,2...n-1} 
 * 假如要求x点(i,j)的路径数，那么可以看到x前驱点只有两个，x前面的点(i,j-1)和x上面的点(i-1,j) 
 * 那么f(i,j) = f(i,j-1) + f(i-1,j)而前面有 f(0,j) = 0 | 其中j = {0,1,2...n-1} 
 * 且每一行的第一个位置的 f(i,0) = 1
 * 根据这些条件 就能够很容易地算出f(m-1, n-1)的值 
 * 
 * 时间复杂度O(n^2) 
 * 
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
    	if( m == 0 || n == 0){
    		return 0;
    	}
    	int map[m][n];
    	for( int i = 0 ; i < n ; ++i){
    		map[0][i] = 1;
    	}
    	for( int i = 1 ; i < m ; ++i){
    		map[i][0] = 1;
    		for( int j = 1 ; j < n; ++j ){
    			map[i][j] = map[i - 1][j] + map[i][j - 1];
    		}
    	}
    	return map[m-1][n-1];
    }
};
