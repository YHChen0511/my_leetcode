#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size(), sum = 0;
        vector<int> prefixSums(n + 1);
        for (int i = 0; i < n; i++) {
            prefixSums[i + 1] = prefixSums[i] + arr[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if((j - i) % 2 == 0){
                    sum += prefixSums[j + 1] - prefixSums[i];
                }
            }
        }
        return sum;
    }
};