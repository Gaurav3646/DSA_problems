class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
    int n=nums.size();

    int totSum=0;
    
    int minSum=INT_MAX,mincurr=0;
    int maxSum=INT_MIN,maxcurr=0;
    for(int i=0;i<n;i++){
        totSum+=nums[i];

        mincurr+=nums[i];
        minSum=min(mincurr,minSum);
        if(mincurr>0){
            mincurr=0;
        }

        maxcurr+=nums[i];
        maxSum=max(maxcurr,maxSum);
        if(maxcurr<0){
            maxcurr=0;
        }
    }
    
    return totSum==minSum?maxSum:max(maxSum,totSum-minSum);
        
    }
};