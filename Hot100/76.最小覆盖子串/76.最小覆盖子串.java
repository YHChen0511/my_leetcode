/*
 * @lc app=leetcode.cn id=76 lang=java
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode.cn/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (47.18%)
 * Likes:    3207
 * Dislikes: 0
 * Total Accepted:    759.6K
 * Total Submissions: 1.6M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""
 * 。
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
 * 如果 s 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "ADOBECODEBANC", t = "ABC"
 * 输出："BANC"
 * 解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "a", t = "a"
 * 输出："a"
 * 解释：整个字符串 s 是最小覆盖子串。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "a", t = "aa"
 * 输出: ""
 * 解释: t 中两个字符 'a' 均应包含在 s 的子串中，
 * 因此没有符合条件的子字符串，返回空字符串。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * ^m == s.length
 * ^n == t.length
 * 1 <= m, n <= 10^5
 * s 和 t 由英文字母组成
 * 
 * 
 * 
 * 进阶：你能设计一个在 o(m+n) 时间内解决此问题的算法吗？
 */

// @lc code=start
class Solution {
    boolean isMatch(int[] s_times, int[] t_times) {
        for (int i = 0; i < 52; i++) {
            if (s_times[i] < t_times[i]) {
                return false;
            }
        }
        return true;
    }

    public String minWindow(String s, String t) {
        char[] s_chars = s.toCharArray();
        char[] t_chars = t.toCharArray();

        int[] s_times = new int[52];
        int[] t_times = new int[52];
        for (int i = 0; i < t.length(); i++) {
            if (t_chars[i] >= 'a') {
                t_times[t_chars[i] - 'a' + 26]++;
            } else {
                t_times[t_chars[i] - 'A']++;
            }
        }
        int left = 0;
        int ansLeft = -1;
        int min = s.length() + 1;
        for (int i = 0; i < s.length(); i++) {
            if (s_chars[i] >= 'a') {
                s_times[s_chars[i] - 'a' + 26]++;
            } else {
                s_times[s_chars[i] - 'A']++;
            }
            while (isMatch(s_times, t_times)) {
                // System.out.println(left + " " + i);
                if (i - left + 1 < min) {
                    min = i - left + 1;
                    ansLeft = left;
                }
                if (s_chars[left] >= 'a') {
                    s_times[s_chars[left] - 'a' + 26]--;
                } else {
                    s_times[s_chars[left] - 'A']--;
                }
                left++;
            }
        }
        return ansLeft >= 0 ? s.substring(ansLeft, ansLeft + min) : "";
    }
}
// @lc code=end
