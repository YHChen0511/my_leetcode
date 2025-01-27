class Solution {
public:
    int clumsy(int n) {
        if(n == 1) return 1; 
        if(n == 2) return 2;
        if(n == 3) return 6;
        if(n == 4) return 7;
        if(n % 4 == 3){
            return n - 1;
        }else if(n % 4 == 0){
            return n + 1;
        }else{
            return n + 2;
        }
    }
};