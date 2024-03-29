class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // nums.push_back(INT_MIN);
        int l =0;
        int r=nums.size()-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(nums[mid]<nums[mid+1]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
};