class Solution {
public:
    void sortColors(vector<int>& nums) {
       //bubble sort
        int n = nums.size();
        // for(int i=0; i<n; i++){
        //     int flag = 0;
        //     for(int j=0; j<n-i-1; j++){
        //         if(nums[j]>nums[j+1]){
        //             flag = 1;
        //             swap(nums[j], nums[j+1]);
        //         }
        //     }
        //     if(flag==0){
        //         break;
        //     }
        // }
       // vector<int> arr(3, 0);
       //  for(int i=0; i<n; i++){
       //      arr[nums[i]]++;
       //  }
       //  int k = 0;
       //  for(int i=0; i<3; i++){
       //      for(int j=0; j<arr[i]; j++){
       //          nums[k++] = i;
       //      }
       //  }
        int i=0;
        int k=0;
        int j=n-1;
        for(i; i<=j; i++){
            while(nums[i]==2 && i<j) swap(nums[i], nums[j--]);
            while(nums[i]==0 && i>k) swap(nums[i], nums[k++]);
        }
       
        
    }
};