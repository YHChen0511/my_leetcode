#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> getDifference(string word){
        int n = word.size();
        vector<int> difference(n-1);
        for(int i = 0; i < n - 1; i++){
            difference[i] = word[i+1] - word[i];
        }
        return difference;
    }

    string oddString(vector<string>& words) {
        string word0 = words[0], word1 = words[1];
        vector<int> difference = getDifference(word0);
        if (difference != getDifference(word1)){
            return (difference == getDifference(words[2]))? word1 : word0;
        }
        for(int i = 2; i < words.size(); i++){
            if(difference != getDifference(words[i])){
                return words[i];
            }
        }
        return "";
    }
};