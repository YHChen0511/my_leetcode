#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size(), i = 0, j = 0;
        long long res = 0;
        while(i < n){
            while(j < n){
                if(j < n - 1 && prices[j] - prices[j+1] == 1){
                    j++;
                }else{
                    res += (long long)(j - i + 2)*(j-i+1) /2;
                    j++;
                    i = j;
                }
            }
        }
        return res;
    }
};