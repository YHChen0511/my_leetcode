/*
 * @Description: 
 */
/*
 * @lc app=leetcode.cn id=56 lang=java
 *
 * [56] 合并区间
 *
 * https://leetcode.cn/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (51.20%)
 * Likes:    2555
 * Dislikes: 0
 * Total Accepted:    1.1M
 * Total Submissions: 2.2M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi]
 * 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
 * 输出：[[1,6],[8,10],[15,18]]
 * 解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：intervals = [[1,4],[4,5]]
 * 输出：[[1,5]]
 * 解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
        int i = 0, j = 0, k = 0, n = intervals.length;
        List<int[]> ans = new ArrayList<>();
        for(int[] interval : intervals){
            if(ans.isEmpty() || ans.get(ans.size()-1)[1] < interval[0]){
                ans.add(interval);
            } else{
                ans.get(ans.size()-1)[1] = Math.max(ans.get(ans.size()-1)[1], interval[1]);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}
// @lc code=end

