/*
 * @lc app=leetcode.cn id=283 lang=java
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int left_z = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                int tmp = nums[i];
                nums[i] = 0;
                nums[left_z] = tmp;
                left_z++;
            }
        }
    }
}
// @lc code=end

