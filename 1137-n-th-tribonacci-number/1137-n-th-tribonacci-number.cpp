class Solution {
public:
    int tribonacci(int n) {
       int t0 = 0;
       int t1 = 1;
        int t2 = 1;
        int ti;
        for(int i=3; i<=n; i++){
           ti = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = ti;
            
        }
        return n==0? 0 : t2;
    }
};