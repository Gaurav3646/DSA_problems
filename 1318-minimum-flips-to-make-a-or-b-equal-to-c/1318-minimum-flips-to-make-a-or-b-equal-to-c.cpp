class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x = a|b;
        int f = x^c;
        int d = a&b;
        int ans = 0;
        while(f){
            if(f&1){
                if(d&1) ans+=2;
                else ans++;
            }
            
            f >>= 1;
            d >>= 1;
            
        }
        return ans;
    }
};