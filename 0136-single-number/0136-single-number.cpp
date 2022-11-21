class Solution {
public:
    int singleNumber(vector<int>& nums) {
//         int n = nums.size(), c;

//         map<int, int> mp;
//         map<int, int>::iterator itr;
//         for(int i=0; i<n; i++){
//            mp[nums[i]]++;
//         }
        
//         for (itr = mp.begin(); itr != mp.end(); ++itr) {
//             int C = itr->second;
//             if(C==1){
//              c= itr->first;
                
//             }
           
//         }
//         return c;
      int x = 0;
        for(int i=0; i<nums.size(); i++){
            x ^= nums[i];
        }
        return x;
       
    }
};