/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 K 小的数对距离
 */

// @lc code=start
class Solution {
public:
  bool check(const vector<int> &nums, int k, int mid, int n) {
    int i = 0, j = 1, count = 0;
    while (j < n && i < n) {
      if (nums[j] - nums[i] <= mid) {
        count += (j - i);
        j++;
      } else {
        i++;
      }
    }
    return count < k;
  }

  int smallestDistancePair(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), left = 0, right = nums[n - 1] - nums[0];
    while (left < right) {
      int mid = (left + right) >> 1;
      if (check(nums, k, mid, n)) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};
// @lc code=end
