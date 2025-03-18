/*
 * @lc app=leetcode.cn id=128 lang=java
 *
 * [128] 最长连续序列
 *
 * https://leetcode.cn/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (50.49%)
 * Likes:    2434
 * Dislikes: 0
 * Total Accepted:    950.8K
 * Total Submissions: 1.9M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,0,1,2]
 * 输出：3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 
 * 
 */
import java.util.HashSet;
import java.util.Set;
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

