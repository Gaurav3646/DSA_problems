class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int g) {
        int j=0;
        int ans = 0;
        int k = 1;
        for(int i=0; i<nums.size(); i++){
            g -= nums[i];
            if(g<0){
            if(nums[j])
                j++;
            else j = i+1;
                g = 0;
                k=1;
            }
            while(j<i && !nums[j] ){
                j++;
                k++;
            }
             
            // cout<<j<<" "<<i<<" "<<k<<endl;
            
            if(!g && j<=i){
                ans += k;
            }
           
        }
       
        return ans;
    }
};