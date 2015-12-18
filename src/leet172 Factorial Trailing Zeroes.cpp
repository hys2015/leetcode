/**
    https://leetcode.com/problems/factorial-trailing-zeroes/
    ��n��ĩβ����0�ĸ���
	
	˼·��
	n! = n(n-1)(n-2)...1   
	��n��ĩβ��0�ĸ��������n!ĩβ��k��0����ô n!һ���� 10^k�ı����� �� 
	n! = a*(10^k) ���� a >= 1 
	����ʽдΪ
	a*(2*5)^k
	a*(2^k)*(5^k)
	�� n!������дΪ 
	n! = b*(2^m)*(5^n)   ���� b >= 1 �� mһ������n 
	��ôֻҪ���n����
	Ҳ���ǿ�n�����������ж��ٸ�5 
	�������˼·��ֱ�۵ķ�������Solution1��
	����ÿ��5�ı������ܱ�5�����Σ�����ֳ�������5������� 
	������Ϊʱ�临�Ӷ�Ϊ O(NlogN)���ԻᱨTLE
	 
	 ��ʵ������������
	 ���� 5^(m+1) > n! > 5^m
	 n! = a* 10^k
	 ��ô�� 
	 k = N/(5^1) + N/(5^2) + ... + N/(5^m) 
	 ���Ǿ���solution2 ��Solution3��������ΪSolution2���õ��˳�������TLE 
 */
 
//Solution1 TLE
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for( int i = 5 ; i > n ; i += 5 ){   //  n/5�� O(N)
            for( int k = i; k > 0 ; k /= 5){ // ������log5(N)
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


