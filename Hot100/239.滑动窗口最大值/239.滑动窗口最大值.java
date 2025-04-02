/*
 * @lc app=leetcode.cn id=239 lang=java
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> deque = new ArrayDeque<>();
        int n = nums.length;
        int[] res = new int[n - k + 1];
        for(int i = 0; i < n; i++){
            while(!deque.isEmpty() && nums[deque.getLast()] <= nums[i]){
                deque.removeLast();
            }
            deque.addLast(i);
            
            if(i - k + 1 > deque.getFirst()){
                deque.removeFirst();
            }
            if(i >= k - 1){
                res[i - k + 1] = nums[deque.getFirst()];
            }
        }
        // res[n-k] = nums[deque.getFirst()];
        return res;

    }
}
// @lc code=end

