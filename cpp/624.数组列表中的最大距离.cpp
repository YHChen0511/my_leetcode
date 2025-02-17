/*
 * @lc app=leetcode.cn id=624 lang=cpp
 *
 * [624] 数组列表中的最大距离
 *
 * https://leetcode.cn/problems/maximum-distance-in-arrays/description/
 *
 * algorithms
 * Medium (40.38%)
 * Likes:    117
 * Dislikes: 0
 * Total Accepted:    14.3K
 * Total Submissions: 35.2K
 * Testcase Example:  '[[1,2,3],[4,5],[1,2,3]]'
 *
 * 给定 m 个数组，每个数组都已经按照升序排好序了。
 * 
 * 现在你需要从两个不同的数组中选择两个整数（每个数组选一个）并且计算它们的距离。两个整数 a 和 b 之间的距离定义为它们差的绝对值 |a-b| 。
 * 
 * 返回最大距离。
 * 
 * 示例 1：
 * 
 * 
 * 输入：[[1,2,3],[4,5],[1,2,3]]
 * 输出：4
 * 解释：
 * 一种得到答案 4 的方法是从第一个数组或者第三个数组中选择 1，同时从第二个数组中选择 5 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：arrays = [[1],[1]]
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == arrays.length
 * 2 <= m <= 10^5
 * 1 <= arrays[i].length <= 500
 * -10^4 <= arrays[i][j] <= 10^4
 * arrays[i] 以 升序 排序。
 * 所有数组中最多有 10^5 个整数。
 * 
 * 
 * 
 * 
 */

#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int l_min = arrays[0][0], l_max = arrays[0].back(), res= INT_MIN;
        for(int i = 1; i < arrays.size(); i++){
            res = max({res, arrays[i].back() - l_min, l_max - arrays[i][0]});
            l_min = min(l_min, arrays[i][0]);
            l_max = max(l_max, arrays[i].back());
        }
        return res;
    }
};
// @lc code=end

