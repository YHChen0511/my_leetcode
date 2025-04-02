/*
 * @lc app=leetcode.cn id=128 lang=java
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int max = 0;
        for (int num : nums){
            set.add(num);
        }
        for (int num : set){
            if(set.contains(num - 1)){
                continue;
            }
            int count = 0;
            while(set.contains(num)){
                count++;
                num++;
            }
            max = Math.max(max, count);
        }
        return max;
    }
}
// @lc code=end

