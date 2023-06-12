class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
       vector<string>  ans;
        for(int i=0; i<nums.size(); i++){
            int j = i+1;
            while(j<nums.size()){
                if(nums[j]!=1+nums[j-1]){
                 break;
                }
                j++;
            }
            if(j-1==i){
               ans.push_back(to_string(nums[i])); 
            }
            else{
               ans.push_back(to_string(nums[i])+"->"+to_string(nums[j-1])); 
            }
            i = j-1;
        }
        return ans;
    }
};