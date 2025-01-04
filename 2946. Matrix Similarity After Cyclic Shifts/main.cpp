#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        bool res = true;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if( i % 2 == 0) {  // odd indexed lines
                    if(mat[i][j] != mat[i][(j+k)%n]){
                        return false;
                    }
                } else{  // even indexed lines
                    if(mat[i][j] != mat[i][(j-k%n+n)%n]){
                        return false;
                    }
                }
            }
            
        }
        return true;
    }
};