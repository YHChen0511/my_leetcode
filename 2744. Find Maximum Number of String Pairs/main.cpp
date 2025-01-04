#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size(), res = 0;
        unordered_set<string> set;
        for(int i = 0; i < n; i++){
            if(set.contains(words[i])){
                res++;
            } else{
                string tmp = "";
                for(int j = words[i].size() - 1; j >= 0; j--){
                    tmp += words[i][j];
                }
                set.insert(tmp);
            }
        }
        return res;
    }
};