class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()==1) return 0;
        sort(nums.begin(), nums.end());
        // for(int i=0; i<nums.size(); i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        int ans = nums.size();
        int count = 1;
        int j=0;
     unordered_set<int> st;
        st.insert(nums[j]);
        for(int i=1; i<nums.size();){
          // cout<<nums[i]<<" ";
            if(st.count(nums[i])){
                i++;
            } 
          else if(nums[i]-nums[j]<nums.size()){
               count++;
               st.insert(nums[i]);
               i++;
           }
           else{
               j++;
              if(nums[j]!=nums[j-1])
                count--;
            }
            // cout<<count<<endl;
            int x = nums.size();
            // cout<<count<<endl;
           ans = min(ans, x-count); 
        }
        return ans;
    }
};