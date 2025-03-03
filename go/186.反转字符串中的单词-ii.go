/*
 * @lc app=leetcode.cn id=186 lang=golang
 *
 * [186] 反转字符串中的单词 II
 *
 * https://leetcode.cn/problems/reverse-words-in-a-string-ii/description/
 *
 * algorithms
 * Medium (77.45%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    22.7K
 * Total Submissions: 29.3K
 * Testcase Example:  '["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]'
 *
 * 给你一个字符数组 s ，反转其中 单词 的顺序。
 *
 * 单词 的定义为：单词是一个由非空格字符组成的序列。s 中的单词将会由单个空格分隔。
 *
 *
 *
 * 必须设计并实现 原地 解法来解决此问题，即不分配额外的空间。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
 * 输出：["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = ["a"]
 * 输出：["a"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= s.length <= 10^5
 * s[i] 可以是一个英文字母（大写或小写）、数字、或是空格 ' ' 。
 * s 中至少存在一个单词
 * s 不含前导或尾随空格
 * 题目数据保证：s 中的每个单词都由单个空格分隔
 *
 *
 *
 *
 */
package main

import "slices"

// @lc code=start
func reverseWords(s []byte) {
	slices.Reverse(s)
	i := 0
	j := 0
	for j < len(s) {
		if s[j] == ' ' {
			slices.Reverse(s[i:j])
			i = j + 1
		}
		j++
	}
	slices.Reverse(s[i:j])
}

// @lc code=end
