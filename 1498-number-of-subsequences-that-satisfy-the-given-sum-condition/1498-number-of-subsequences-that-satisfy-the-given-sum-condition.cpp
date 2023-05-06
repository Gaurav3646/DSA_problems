class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int m = 1e9+7;
        sort(nums.begin(), nums.end());
        long long c = 0;
        vector<long long> power(nums.size()+1);
        power[0] = 1;
        for(int j=0; j<nums.size(); j++){
            int x = target - nums[j];
            int  i = upper_bound(nums.begin(), nums.begin()+j+1, x)-nums.begin()-1;
            // cout<<nums[j]<<" "<<i<<endl;
          if(i<0) continue;
            if(i!=j){
            long long x = power[i+1]-1;
            // int y = j-i-1;
            long long  y = power[j-i-1];
            c += (x*y)%m;
                
                // cout<<x*y<<endl;
                
            }  
            else{
               int x = power[i]; 
                c += x;
                 // cout<<x<<endl;
            }
            c %=m;
        power[j+1] = (power[j]*2)%m;
            
        }
        return c;
    }
};