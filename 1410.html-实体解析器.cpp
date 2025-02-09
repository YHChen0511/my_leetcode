/*
 * @lc app=leetcode.cn id=1410 lang=cpp
 *
 * [1410] HTML 实体解析器
 */

// @lc code=start
class Solution {
public:
  string entityParser(string text) {
    int n = text.size();
    unordered_map<string, string> hash = {{"&quot;", "\""}, {"&apos;", "'"},
                                          {"&amp;", "&"},   {"&gt;", ">"},
                                          {"&lt;", "<"},    {"&frasl;", "/"}};
    string res = "";
    for (int i = 0; i < n; i++) {
      if (text[i] == '&') {
        int j = i + 1;
        while (j < n && text[j] != ';') {
          j++;
        }
        if (j != n) {
          string sub = text.substr(i, j - i + 1);
          if (hash.find(sub) != hash.end()) {
            res += hash[sub];
            i = j;
            continue;
          }
        }
      }
      res += text[i];
    }
    return res;
  }
};
// @lc code=end
