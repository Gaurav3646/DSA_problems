class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
//        int j=0;
//         int k = 0;
//         int x = nums[0];
//         for(int i=0; i<nums.size(); i++){
//            if(k<2 && x==nums[i]){
//                nums[j++] = nums[i];
//                k++;
//            }
//             else if(x!=nums[i]){
//                 nums[j++] = nums[i];
//                 x = nums[i];
//                 k =1;
//             }
            
//         }
//         return j;
        int j =0;
        for(int &n :nums){
            if(j<2 || n>nums[j-2]){
                nums[j++] = n;
            }
            
        }
        return j;
    }
};