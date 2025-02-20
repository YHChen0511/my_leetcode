#
# @lc app=leetcode.cn id=852 lang=python3
#
# [852] 山脉数组的峰顶索引
#
# https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/
#
# algorithms
# Medium (68.25%)
# Likes:    428
# Dislikes: 0
# Total Accepted:    178.4K
# Total Submissions: 261.3K
# Testcase Example:  '[0,1,0]'
#
# 给定一个长度为 n 的整数 山脉 数组 arr ，其中的值递增到一个 峰值元素 然后递减。
# 
# 返回峰值元素的下标。
# 
# 你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：arr = [0,1,0]
# 输出：1
# 
# 
# 示例 2：
# 
# 
# 输入：arr = [0,2,1,0]
# 输出：1
# 
# 
# 示例 3：
# 
# 
# 输入：arr = [0,10,5,2]
# 输出：1
# 
# 
# 
# 
# 提示：
# 
# 
# 3 <= arr.length <= 10^5
# 0 <= arr[i] <= 10^6
# 题目数据 保证 arr 是一个山脉数组
# 
# 
#
from typing import List
# @lc code=start
class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        if(len(arr) == 1):
            return 0
        if(len(arr) == 2):
            return 0 if arr[0] > arr[1] else 1
        if (arr[len(arr)//2] > arr[len(arr)//2+1]):
            return self.peakIndexInMountainArray(arr[:len(arr)//2+1])
        else:
            return len(arr)//2 + self.peakIndexInMountainArray(arr[len(arr)//2:])
# @lc code=end

