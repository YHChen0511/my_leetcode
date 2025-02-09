/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */

// @lc code=start
class Solution {
public:
  string path(char curr, char ch) {
    string res = "";
    if (curr == 'z' && ch != 'z') {
      res += 'U';
      curr = 'z' - 5;
    }
    int r = (int)(ch - 'a') / 5 - (int)(curr - 'a') / 5;
    int col = (int)(ch - 'a') % 5 - (int)(curr - 'a') % 5;
    for (int i = 0; i < abs(col); i++) {
      if (col > 0) {
        res += 'R';
      } else {
        res += 'L';
      }
    }
    for (int i = 0; i < abs(r); i++) {
      if (r > 0) {
        res += 'D';
      } else {
        res += 'U';
      }
    }

    return res;
  }

  string alphabetBoardPath(string target) {
    string res = "";
    char curr = 'a';
    for (char ch : target) {
      res += path(curr, ch);
      res += '!';
      curr = ch;
    }
    return res;
  }
};
// @lc code=end
