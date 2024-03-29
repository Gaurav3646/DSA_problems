class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos  =0;
        for(auto &n: nums){
            ones = (ones^n)& ~twos;
            twos = (twos^n)& ~ones;
        }
        return ones;
    }
};