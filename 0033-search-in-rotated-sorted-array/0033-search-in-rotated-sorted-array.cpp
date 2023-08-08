class Solution {
public:
    
     int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (right + left) / 2;
            if (nums[left] < nums[right]) {
                return left; 
            }
            if (nums[right] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
    
    int search(vector<int>& nums, int target) {
        int  x= findMin(nums);
        int lo=0;
        int hi = nums.size()-1;
        while(lo<=hi){
            int m = (lo+hi)/2;
            int mid = (m+x)%nums.size();
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                lo = m+1;
            }
            else{
                hi = m-1;
            }
        }
        return -1;
    }
};