class Solution {
public:
int firstoccur(vector<int>& nums, int s, int e, int target){
    int ans = -1;
    int mid;
    while(s<=e){
        mid = (s+e)/2;
        if(nums[mid]==target){
            ans = mid;
            e = mid - 1;
        }
        if(nums[mid]>target){
            e = mid -1;
        }
        if(nums[mid]<target){
            s = mid + 1;
        }
    }
    return ans;
}
    int lastoccur(vector<int>& nums, int s, int e, int target){
    int ans = -1;
    int mid;
    while(s<=e){
        mid = (s+e)/2;
        if(nums[mid]==target){
            ans = mid;
            s = mid+1;
        }
        if(nums[mid]>target){
            e = mid -1;
        }
        if(nums[mid]<target){
            s = mid + 1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> vect;
        vect.push_back(firstoccur(nums, 0, n-1, target));
        vect.push_back(lastoccur(nums, 0, n-1, target));
        return vect;
    }
};