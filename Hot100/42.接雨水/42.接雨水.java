/*
 * @lc app=leetcode.cn id=42 lang=java
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int res = 0;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i = 1; i < n; i++){
            left[i] = Math.max(left[i-1], height[i]);
        }
        for(int i = n - 2; i >= 0; i--){
            right[i] = Math.max(right[i+1], height[i]);
            if(height[i] < left[i] && height[i] < right[i]){
                res += Math.min(left[i],  right[i]) - height[i];
            }
        }
        return res;
    }
}
// @lc code=end

