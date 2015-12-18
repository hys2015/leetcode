/**
    https://leetcode.com/problems/factorial-trailing-zeroes/
    求n！末尾连续0的个数
	
	思路：
	n! = n(n-1)(n-2)...1   
	求n！末尾的0的个数，如果n!末尾有k个0，那么 n!一定是 10^k的倍数， 即 
	n! = a*(10^k) 其中 a >= 1 
	将上式写为
	a*(2*5)^k
	a*(2^k)*(5^k)
	而 n!还可以写为 
	n! = b*(2^m)*(5^n)   其中 b >= 1 且 m一定大于n 
	那么只要求出n即可
	也就是看n！的因子中有多少个5 
	按照这个思路最直观的方法就是Solution1，
	对于每个5的倍数看能被5除几次，即拆分出来几个5，再相加 
	但是因为时间复杂度为 O(NlogN)所以会报TLE
	 
	 其实，还可以这样
	 假设 5^(m+1) > n! > 5^m
	 n! = a* 10^k
	 那么有 
	 k = N/(5^1) + N/(5^2) + ... + N/(5^m) 
	 于是就有solution2 和Solution3，但是因为Solution2中用到乘除、所以TLE 
 */
 
//Solution1 TLE
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for( int i = 5 ; i > n ; i += 5 ){   //  n/5次 O(N)
            for( int k = i; k > 0 ; k /= 5){ // 最大次数log5(N)
				if( n % 5 == 0){
                	res ++;
            	}            	
            }
        }
        return res;
    }
};

//Solution2 TLE
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for( int i = 5; i <= n ; i *= 5){
            res += n/i;
        }
        return res;
    }
};

//AC
class Solution {
public:
    int trailingZeroes(int n) {
        int nn = n/5, res = 0;
        while(nn > 0){
            res += nn;
            nn /= 5;
        }
        return res;
    }
};


