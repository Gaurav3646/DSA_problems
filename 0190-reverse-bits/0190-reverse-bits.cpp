class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i =0;
        int x = 0;
        while(i<32){
           int d = (n>>i)&1;
            cout<<d<<endl;
            x<<=1;
           x= x|d;
            i++;
        }
        return x;
    }
};