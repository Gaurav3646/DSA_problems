class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> prefix(nums.size());
        prefix[0]= nums[0];
        for(int i=1; i<nums.size(); i++){
            prefix[i] = nums[i] + prefix[i-1];
            
        }
        long long sum = prefix.back();
        long long min = INT_MAX;
        int minIndex=-1;
        for(int i=0; i<nums.size(); i++){
            long long leftAvg = prefix[i]/(i+1);
            long long rightAvg = i!=nums.size()-1? (sum-prefix[i])/(nums.size()-i-1) : 0;
            if(min>abs(leftAvg-rightAvg)){
                min = abs(leftAvg-rightAvg);
                minIndex = i;
            }
        }
        return minIndex;
    }
};