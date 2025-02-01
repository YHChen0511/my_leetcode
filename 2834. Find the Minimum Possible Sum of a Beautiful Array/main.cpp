class Solution
{
public:
    int minimumPossibleSum(int n, int target)
    {
        int m = target / 2;
        if (n <= m)
            return ((long)(n + 1) * n / 2) % (1000000007);
        return (int)(((long)(n + 1) * n / 2 + (long)(target - 1 - m) * (n + 1 - m - 1)) % (1000000007));
    }
};