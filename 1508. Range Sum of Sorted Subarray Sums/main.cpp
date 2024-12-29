#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    pair<long, long> check(const vector<long> &psum, const vector<long> &ppsum, long mid, long n)
    {
        long i = 0, j = 0, cnt = 0, s = 0;
        while (i < n)
        {
            if (j < n && psum[j + 1] - psum[i] < mid)
            {
                j++;
            }
            else
            {
                cnt += (j - i);
                s += ppsum[j] - ppsum[i] - (j - i) * psum[i];
                i++;
            }
        }
        pair<long, long> res = {cnt, s};
        return res;
    }

    long getKSum(const vector<long> &psum, const vector<long> &ppsum, int k, int n)
    {
        int left = 0, right = psum[n];
        long cnt = 0, s = 0;
        while (left < right)
        {
            int mid = (left + right + 1) >> 1;
            auto p = check(psum, ppsum, mid, n);
            cnt = p.first, s = p.second;
            if (cnt < k)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return s + (k - cnt) * left;
    }

    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<long> psum(n + 1, 0), ppsum(n + 1, 0);
        for (int i = 1; i < n + 1; i++)
        {
            psum[i] = psum[i - 1] + nums[i - 1];
            ppsum[i] = ppsum[i - 1] + psum[i];
        }
        return (int)((getKSum(psum, ppsum, right, n) - getKSum(psum, ppsum, left - 1, n)) % 1000000007);
    }
};