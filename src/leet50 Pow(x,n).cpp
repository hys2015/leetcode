/*
    https://leetcode.com/problems/powx-n/
    pow(x,n)������ʵ��
    �����õ���ֱ�ӵķ����������Ȼֱ��TLE
    Ȼ�����������ַ���
    ���κ�һ������0�η�����1
    ���κ�һ������-n���ݶ����������n���ݵĵ���
    ���κ�һ������1�η������Լ�
    ���κ�һ������2�η������Լ����Լ�
    ���κ�һ�������������ݶ��Ǳ��������Сһ��ż�����ݵĽ����һ���Լ��õ�
    ���κ�һ������ż�����ݿ�������λ����������ʵ��
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

