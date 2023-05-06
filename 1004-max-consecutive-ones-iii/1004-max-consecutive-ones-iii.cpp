class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       vector<int> ones(nums.size()+1);
        for(int i=0; i<nums.size(); i++){
            if(nums[i]){
                ones[i+1] = nums[i] + ones[i];
            }  
            // cout<<ones[i]<<endl;
        }
        queue<int> q;
        int count = 0;
        int maxi = 0;
        for(int i=0; i<nums.size(); i++){
            count += nums[i];
           
            if(!nums[i]){
                
                q.push(i);
                count++;
                if(q.size()>k){
                    int f = q.front();
                    count -= (ones[f]+1);
                    q.pop();  
                }
            }
            
            maxi = max(maxi, count);
        }
        return maxi;
    }
};