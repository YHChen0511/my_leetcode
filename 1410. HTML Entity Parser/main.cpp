#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string entityParser(string text) {
        int n = text.size();
        unordered_map<string, string> hash = {
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };
        string res = "";
        for(int i = 0; i < n; i++){
            if(text[i] == '&'){
                int j = i + 1;
                while(j < n && text[j] != ';'){
                    j++;
                }
                if(j != n){
                    string sub = text.substr(i, j - i + 1);
                    if(hash.find(sub) != hash.end()){
                        res += hash[sub];
                        i = j;
                        continue;
                    }
                }
            }
            res += text[i];
        }
        return res;
    }
};