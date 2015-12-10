#include<iostream>
#include<cmath>

class Solution {
public:
    int mySqrt(int x) {
        if( 0 == x ) return 0;
        if( 1 == x ) return 1;
        int low = 0, high = x;
        while( high - low > 1){
        	int mid = (low + high) / 2; 
            if( mid > x / mid){
                high = mid;
            }else if( mid <= x / mid){
                low = mid;
            }
        }
        return low;
    }
};
int main(){
	Solution sol;
	//0.00001,2147483647
	//
	double res = sol.mySqrt(4);
	std::cout<< res << std::endl;
	return 0;	
}
