/*
 * @lc app=leetcode.cn id=1561 lang=cpp
 *
 * [1561] 你可以获得的最大硬币数目
 */

// @lc code=start
class Solution {
public:
  int maxCoins(vector<int> &piles) {
    int res = 0, n = piles.size();
    sort(piles.begin(), piles.end());
    for (int i = n / 3; i < n; i += 2) {
      res += piles[i];
    }
    return res;
  }
};
// @lc code=end
