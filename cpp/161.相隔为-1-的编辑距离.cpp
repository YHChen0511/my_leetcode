/*
 * @lc app=leetcode.cn id=161 lang=cpp
 *
 * [161] 相隔为 1 的编辑距离
 *
 * https://leetcode.cn/problems/one-edit-distance/description/
 *
 * algorithms
 * Medium (34.53%)
 * Likes:    153
 * Dislikes: 0
 * Total Accepted:    21K
 * Total Submissions: 60.9K
 * Testcase Example:  '"ab"\n"acb"'
 *
 * 给定两个字符串 s 和 t ，如果它们的编辑距离为 1 ，则返回 true ，否则返回 false 。
 * 
 * 字符串 s 和字符串 t 之间满足编辑距离等于 1 有三种可能的情形：
 * 
 * 
 * 往 s 中插入 恰好一个 字符得到 t
 * 从 s 中删除 恰好一个 字符得到 t
 * 在 s 中用 一个不同的字符 替换 恰好一个 字符得到 t
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入: s = "ab", t = "acb"
 * 输出: true
 * 解释: 可以将 'c' 插入字符串 s 来得到 t。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "cab", t = "ad"
 * 输出: false
 * 解释: 无法通过 1 步操作使 s 变为 t。
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 0 <= s.length, t.length <= 10^4
 * s 和 t 由小写字母，大写字母和数字组成
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        // if (m == 0 && n == 1) return true;
        // if (m == 1 && n == 0) return true;
        if (n - m > 1 || n - m < -1) return false;
        if (n - m == 1 || n - m == -1){
            int i = 0, j = 0, diff = 0;
            while(i < m && j < n){
                if(s[i] != t[j]){
                    diff++;
                    if(diff > 1) return false;
                    if(m > n) i++;
                    else j++;
                } else {
                    i++;
                    j++;
                }
            }
            return true;
        }else {
            int diff = 0;
            for(int i = 0; i < m; i++){
                if(s[i] != t[i]){
                    diff++;
                    if(diff > 1) return false;
                }
            }
            return diff == 1;
        }
    }
};
// @lc code=end

