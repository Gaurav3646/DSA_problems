class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        double maxi = INT_MIN;
        for(int i=0, j=0; i<nums.size(); i++){
            if(i<k){
                avg += nums[i];
            }
            else{
                maxi = max(maxi, avg);
               avg -=nums[j++];
                avg += nums[i];
            } 
        }
         maxi = max(maxi, avg);
       
       return maxi/k; 
    }
};