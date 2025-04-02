/*
 * @lc app=leetcode.cn id=560 lang=java
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        int[] sums = new int[n+1];
        sums[0] = 0;
        for(int i = 0; i < n; i++){
            sums[i+1] = sums[i] + nums[i];
        }

        int ans = 0;
        Map<Integer, Integer> cnt = new HashMap<>();
        for(int sj : sums){
            ans += cnt.getOrDefault(sj - k, 0);
            cnt.merge(sj, 1, Integer::sum);
        }
        return ans;
    }
}
// @lc code=end

