/*
 * @lc app=leetcode.cn id=11 lang=java
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
    public int maxArea(int[] height) {
        int n = height.length, left = 0, right = n - 1, max_v = 0;
        while(left < n && right >= 0){
            int shorter = (height[left] < height[right])? left : right;
            int curr_v = (right - left) * height[shorter];
            if(curr_v > max_v){
                max_v = curr_v;
            }
            if(shorter == left){
                left++;
            }else {
                right --;
            }

        }
        return max_v;
    }
}
// @lc code=end

