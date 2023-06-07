class Solution {
public:
    int minFlips(int a, int b, int c) {
        int x = a|b;
        int f = x^c;
        int d = a&b;
        int ans = 0;
        for(int i=0; i<=31; i++){
            if((f>>i)&1){
                if((d>>i)&1) ans+=2;
                else ans++;
            }
            
        }
        return ans;
    }
};