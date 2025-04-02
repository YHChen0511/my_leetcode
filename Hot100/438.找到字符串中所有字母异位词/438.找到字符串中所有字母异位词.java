/*
 * @lc app=leetcode.cn id=438 lang=java
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int n = s.length(), m = p.length();
        char[] S = s.toCharArray();
        char[] P = p.toCharArray();
        List<Integer> res = new ArrayList<>();
        int[] s_times = new int[26];
        int[] p_times = new int[26];
        for(int i = 0; i < m; i++){
            p_times[P[i] - 'a']++;
        }
        for(int right = 0; right < n; right++){
            s_times[S[right] - 'a']++;
            int left = right - m + 1;
            if(left < 0) continue;
            if(Arrays.equals(p_times, s_times)){
                res.add(left);
            }
            s_times[S[left] - 'a']--;
        }
        return res;
    }
}
// @lc code=end

