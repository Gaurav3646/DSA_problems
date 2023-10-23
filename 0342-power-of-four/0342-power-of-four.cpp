class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==1) return true;
        if(n<=0) return false;
        int x = log2(n);
        if(pow(2, x)!=n) return false;
        if(x%2!=0) return false;
        return true;
        // int y = log2(x);
        // if(pow(y, 2)!=x) return false;
        // return true;
        
    }
};