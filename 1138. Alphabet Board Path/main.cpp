#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string path(char curr, char ch){
        string res = "";
        if(curr == 'z' && ch != 'z'){
            res += 'U';
            curr = 'z' - 5;   
        }
        int r = (int)(ch - 'a') / 5 - (int)(curr - 'a') / 5 ;
        int col = (int)(ch - 'a') % 5 - (int)(curr - 'a') % 5;
        for(int i = 0; i < abs(col); i++){
            if( col > 0 ){
                res += 'R';
            }else {
                res += 'L';
            }
        }
        for(int i = 0; i < abs(r); i++){
            if( r > 0 ){
                res += 'D';
            }else {
                res += 'U';
            }
        }
        
        return res;
    }

    string alphabetBoardPath(string target) {
        string res = "";
        char curr = 'a';
        for(char ch: target){
            res += path(curr , ch);
            res += '!';
            curr = ch;
        }
        return res;
    }
};


// class Solution {
// public:
//     string alphabetBoardPath(string target) {
//         string ans;
//         int x = 0, y = 0;
//         for (char c : target) {
//             int nx = (c - 'a') / 5, ny = (c - 'a') % 5; // 目标位置
//             string v(abs(nx - x), "UD"[nx > x]); // 竖直
//             string h(abs(ny - y), "LR"[ny > y]); // 水平
//             ans += (c != 'z' ? v + h : h + v) + "!";
//             x = nx, y = ny;
//         }
//         return ans;
//     }
// };