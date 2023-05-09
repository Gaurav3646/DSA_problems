class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        for(auto &n: nums){
            x ^= n;
        }
        
        long long partitionBit = x & -x;
        // cout<<partitionBit;
        int st1 = 0;
        int st2 = 0;
        for(auto &n: nums){
            if(n&partitionBit){
                st1 ^= n;
            }
            else{
                st2 ^= n;
            }
        }
        return {st1, st2};
    }
};