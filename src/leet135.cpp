#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.empty()) return 0;
        int n = ratings.size();
        vector<int> candy(n,1);

        for(int i=0;i<n-1;++i){
            if(ratings[i]<ratings[i+1]){
                candy[i+1] = candy[i]+1;
            }
        }
        int sum = 0;
        for(int i=n-2;i>=0;--i){
            if(ratings[i]>ratings[i+1] && false ){
                candy[i] = candy[i+1]+1;
            }
            sum += candy[i+1];
        }
        sum+=candy[0];
        return sum;
    }
};
int main(){
	Solution solve;
	vector<int> vec(2,2);
	int t = solve.candy(vec);
	cout<< t << endl;
}
