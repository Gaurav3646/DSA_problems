class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int i =1;
        int ans = -1;
        while(i<=(x/i)){
            ans = i;
            i++;
        }
        return ans;
    }
};