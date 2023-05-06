class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int s = 0;
        int e = nums.size()-1;
        int c = 0;
        while(s<e){
            int x = nums[s]+nums[e];
            if(x==k){
                c++;
                s++;
                e--;
            }
            else if(x>k){
                e--;
            }
            else s++;
           // cout<<s<<" "<<e<<endl;     
            
        }
        return c;
    }
};