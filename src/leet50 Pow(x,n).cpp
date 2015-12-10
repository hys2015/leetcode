/*
    https://leetcode.com/problems/powx-n/
    pow(x,n)函数的实现
    本来用的最直接的方法，结果果然直接TLE
    然后用以下这种方法
    ·任何一个数的0次方都是1
    ·任何一个数的-n次幂都是这个数的n次幂的倒数
    ·任何一个数的1次方都是自己
    ·任何一个数的2次方都是自己乘自己
    ·任何一个数的奇数次幂都是比这个奇数小一的偶数次幂的结果乘一个自己得到
    ·任何一个数的偶数次幂可以利用位操作来快速实现
*/
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

