class Solution {
public:
    int getSum(int a, int b) {
        // 2 , 3
       unsigned int c = 0;
        while(b){
            c = a&b; // 2&3 --> 10
            a = a^b; // 01
            b = c<<1;  // 100 
        }
        return a;
    }
};