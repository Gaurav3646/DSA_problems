class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        // boyer moore voting algo
        int n= nums.size();
        int num1 = -1;
        int num2 = -1;
        int count1 = 0;
        int count2 = 0;
        for(int &el : nums){
            if(el==num1){
                count1++;
            }
            else if(el==num2){
                count2++;
            }
           else if(count1==0){
                count1++;
                num1 = el;
            }
            else if(count2==0){
                count2++;
                num2 = el;
            }
            
            else{
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1=0;
        count2=0;
        for(int &el: nums){
            if(el==num1){
                count1++;
            }
         else if(el==num2){
                count2++;
            }
        }
        if(count1>n/3){
            ans.push_back(num1);
        }
        if(count2>n/3){
            ans.push_back(num2);
        }
        return ans;
    }
        
//         vector<int> ans;
//               int count = 1;
//         int x = nums[0];
//         int n = nums.size()/3;
    
        
//         sort(nums.begin(), nums.end());
//         for(int i=1; i<nums.size(); i++){
//             if(nums[i]==nums[i-1]){
//                 x = nums[i-1];
//                 count++;
//             }
//             else{
                
//                 if(count>n){
//                      ans.push_back(x);
//                 }
//                 count = 1;
//                 x= nums[i];
//             }
//         }
//         if(count>n){
//            ans.push_back(x); 
//         }
//         return ans;
//     }
};