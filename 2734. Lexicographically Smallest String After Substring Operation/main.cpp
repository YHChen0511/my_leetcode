#include <string>

using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] != 'a'){
                for(; i < n && s[i] != 'a'; i++){
                    s[i]--;
                }
                return s;
            }
        }
        s[n - 1] = 'z';
        return s;
    }
};