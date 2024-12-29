#include <string>
#include <vector>
#include <algorithm>

// C++20

using namespace std;

class Solution
{
public:
    string rankTeams(vector<string> &votes)
    {
        int m = votes[0].length(); // m is the number of candidates
        vector<vector<int>> cnts(26, vector<int>(m));
        for (auto vote : votes)
        {
            for (int i = 0; i < m; i++)
            {
                cnts[vote[i] - 'A'][i]--;
            }
        }

        string ans = votes[0];
        namespace ranges = std::ranges;
        ranges::sort(ans, {},
                     [&](char a)
                     { return make_pair(cnts[a - 'A'], a); });

        return ans;
    }
};