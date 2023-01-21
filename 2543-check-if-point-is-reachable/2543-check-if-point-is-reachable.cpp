class Solution {
public:

    bool isReachable(int targetx, int targety) {
         int g = gcd(targetx, targety);
        while (g % 2 == 0) {
            g /= 2;
        }
       if(g==1) return true;
        return false;
    }
    
};