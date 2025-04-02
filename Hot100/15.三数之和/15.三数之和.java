/*
 * @lc app=leetcode.cn id=15 lang=java
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;
        for(int i = 0; i < n - 2; i++){
            if(i>0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) break; // 优化一
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) continue; // 优化二
            int j = i + 1;
            int k = n - 1;
            while (j < k){
                int s = nums[i] + nums[j] + nums[k];
                if(s > 0){
                    k--;
                }else if(s < 0){
                    j++;
                }else{
                    res.add(List.of(nums[i],  nums[j], nums[k]));
                    for (j++; j < k && nums[j] == nums[j - 1]; j++); 
                    for (k--; k > j && nums[k] == nums[k + 1]; k--);
                }
            }
        }
        return res;
    }
}
// @lc code=end

