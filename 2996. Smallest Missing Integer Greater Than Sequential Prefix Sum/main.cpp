#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int x = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1] + 1) break;
            x += nums[i];
        }

        unordered_set<int> s(nums.begin(), nums.end());
        while (s.contains(x)) { 
            x++;
        }
        return x;
    }
};