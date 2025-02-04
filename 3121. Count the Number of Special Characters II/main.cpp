#include <string>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int res = 0;
        int status[26];  // 0: not traversed; 1: lower first; 2: special letter; 3: Not special
        for(auto ch : word){
            bool cap = ch >= 'A' && ch <= 'Z';
            int i = (cap) ? ch - 'A' : ch - 'a';
            if(status[i] == 3){
                continue;
            } else if(!cap && status[i] == 0){
                status[i] = 1;
            } else if (!cap && status[i] == 2){
                status[i] = 3;
                res--;
            } else if (cap && status[i] == 1){
                status[i] = 2;
                res++;
            } else if (cap && status[i] == 0){
                status[i] = 3;
            }
        }
        return res;
    }
};