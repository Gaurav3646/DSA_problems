class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=1;
        int e = arr.size()-2;
        int mid;
        
        while(s<=e){
            mid = (s+e)/2;
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){
                   return mid;
            }
            if(arr[mid]<arr[mid-1]&&arr[mid]>arr[mid+1]){
                   e = mid-1;
            }
            if(arr[mid]<arr[mid+1]){
               s = mid +1;
            }
        
        }
        return -1;
    }
};