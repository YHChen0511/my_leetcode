/*
 * @lc app=leetcode.cn id=3121 lang=cpp
 *
 * [3121] 统计特殊字母的数量 II
 *
 * https://leetcode.cn/problems/count-the-number-of-special-characters-ii/description/
 *
 * algorithms
 * Medium (45.69%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 14.6K
 * Testcase Example:  '"aaAbcBC"'
 *
 * 给你一个字符串 word。如果 word 中同时出现某个字母 c
 * 的小写形式和大写形式，并且 每个 小写形式的 c 都出现在第一个大写形式的 c
 * 之前，则称字母 c 是一个 特殊字母 。
 *
 * 返回 word 中 特殊字母 的数量。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入：word = "aaAbcBC"
 *
 * 输出：3
 *
 * 解释：
 *
 * 特殊字母是 'a'、'b' 和 'c'。
 *
 *
 * 示例 2:
 *
 *
 * 输入：word = "abc"
 *
 * 输出：0
 *
 * 解释：
 *
 * word 中不存在特殊字母。
 *
 *
 * 示例 3:
 *
 *
 * 输入：word = "AbBCab"
 *
 * 输出：0
 *
 * 解释：
 *
 * word 中不存在特殊字母。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= word.length <= 2 * 10^5
 * word 仅由小写和大写英文字母组成。
 *
 *
 */

// @lc code=start
class Solution {
public:
  int numberOfSpecialChars(string word) {
    int res = 0;
    int status[26]; // 0: not traversed; 1: lower first; 2: special letter; 3:
                    // Not special
    for (auto ch : word) {
      bool cap = ch >= 'A' && ch <= 'Z';
      int i = (cap) ? ch - 'A' : ch - 'a';
      if (status[i] == 3) {
        continue;
      } else if (!cap && status[i] == 0) {
        status[i] = 1;
      } else if (!cap && status[i] == 2) {
        status[i] = 3;
        res--;
      } else if (cap && status[i] == 1) {
        status[i] = 2;
        res++;
      } else if (cap && status[i] == 0) {
        status[i] = 3;
      }
    }
    return res;
  }
};
// @lc code=end
