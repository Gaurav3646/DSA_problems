class Solution {
public:
    int trailingZeroes(int n) {
        int i =5;
        int ans =0;
        while(i<=n){
            ans += n/i;
            i *= 5;
        }
        return ans;
    }
};