#include<iostream>
#include<cmath>

class Solution {
public:
    double myPow(double x, int n) {
    	if( n == 0) return 1.0;
    	if( n < 0){
    		n = ~n + 1;
    		x = 1/x;
    	} 
    	if( n == 1) return x;
    	if( n == 2) return x * x;
    	if( n & 1 ) return ( x * myPow(x * x, n >> 1));
    	return myPow(x * x, n >> 1);
    }
};
int main(){
	Solution sol;
	//0.00001,2147483647
	//
	double res = sol.myPow(2,-3);
	std::cout<< res << std::endl;
	return 0;	
}
