#
# @lc app=leetcode.cn id=159 lang=python3
#
# [159] 至多包含两个不同字符的最长子串
#
# https://leetcode.cn/problems/longest-substring-with-at-most-two-distinct-characters/description/
#
# algorithms
# Medium (57.00%)
# Likes:    247
# Dislikes: 0
# Total Accepted:    42.2K
# Total Submissions: 74.1K
# Testcase Example:  '"eceba"'
#
# 给你一个字符串 s ，请你找出 至多 包含 两个不同字符 的最长子串，并返回该子串的长度。
# 
# 
# 示例 1：
# 
# 
# 输入：s = "eceba"
# 输出：3
# 解释：满足题目要求的子串是 "ece" ，长度为 3 。
# 
# 
# 示例 2：
# 
# 
# 输入：s = "ccaabbb"
# 输出：5
# 解释：满足题目要求的子串是 "aabbb" ，长度为 5 。
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= s.length <= 10^5
# s 由英文字母组成
# 
# 
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        i = 0
        j = 0
        max_len = 0
        while(i < len(s) and j < len(s)):
            if len(set(s[i:j+1])) <= 2:
                j += 1
                max_len = max(max_len, j - i)
            else:
                i += 1
        return max_len

# @lc code=end
