class Solution {
public:
    
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> vect;
        
      int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> mp;
        map<vector<int>, int> mp1;
        vector<int>:: iterator it;
       
        for(int i=0; i<n; i++){
           mp[nums[i]].push_back(i);
        }
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                if(i<=n-3){
                if(nums[i]==0&&nums[i+1]==0&&nums[i+2]==0){
                 vector<int> avect2;
                    avect2.push_back(0);
                    avect2.push_back(0);
                    avect2.push_back(0);
                    mp1[avect2];
                }
                }
                break;
            }
            
         for(int j=i+1; j<n; j++){
            
             if(mp.find(0-nums[i]-nums[j])!=mp.end()){
            it = lower_bound(mp[(0-nums[i]-nums[j])].begin(), mp[(0-nums[i]-nums[j])].end(), j+1);
             if(it!=mp[0-nums[i]-nums[j]].end()){
                 vector<int> avect;
                 avect.push_back(nums[i]);
                 avect.push_back(nums[j]);
                 avect.push_back(0-nums[i]-nums[j]);
                 
             mp1[avect];
             }
             }
}
        }
        for(auto it2: mp1){
     vect.push_back(it2.first);
        }
        return vect;
    }
};