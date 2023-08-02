class Solution {
public:
    void solve(vector<int>& nums, int i, vector<vector<int>> &vect, int n){
        if(i==n){
            vect.push_back(nums);
            return ;
        }
     for(int j=i; j<nums.size(); j++){
         swap(nums[i], nums[j]);
         solve(nums, i+1, vect, n);
         swap(nums[i], nums[j]);
     }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vect;
       
        solve(nums, 0, vect, nums.size());
        return vect;
    }
};