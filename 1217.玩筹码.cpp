/*
 * @lc app=leetcode.cn id=1217 lang=cpp
 *
 * [1217] 玩筹码
 */

// @lc code=start
class Solution {
public:
  int minCostToMoveChips(vector<int> &position) {
    int odd = 0, n = position.size();
    for (int i = 0; i < n; i++) {
      odd += (position[i] - 1) % 2;
    }
    return (odd > n - odd) ? n - odd : odd;
  }
};
// @lc code=end
