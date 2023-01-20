class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       vector<vector<int>> vect;
         vect.push_back({});
          for(int i=0; i<nums.size(); i++){
         
             
                vector<vector<int>> seq = vect;
              for(int j=0;j<seq.size(); j++){
                  if(seq[j].size()==0|| seq[j].back()<nums[i]){
                      
                      seq[j].push_back(nums[i]);
                      vect.push_back(seq[j]);
                  }
                  else if(seq[j].back()==nums[i]){
                      vect[j].push_back(nums[i]);
                  }
              }
              
            }
        vector<vector<int>> ans;
        for(int i=0;i<vect.size();i++){
            if(vect[i].size()>=2) ans.push_back(vect[i]);
        }
        return ans;
    }
};