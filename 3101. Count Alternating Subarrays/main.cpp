#include <vector>

using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 1, cnt = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1]){
                cnt += 1;
            } else{
                cnt = 1;
            }
            ans += cnt;
        }


        return ans;
    }
};