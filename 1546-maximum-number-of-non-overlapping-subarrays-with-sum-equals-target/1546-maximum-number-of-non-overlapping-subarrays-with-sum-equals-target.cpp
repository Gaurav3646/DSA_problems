class Solution {
public:
    int maxNonOverlapping(vector<int>& arr, int target) {
         unordered_map<int, int> mp;
        // vector<int> prefix(arr.size());
        // prefix[0] = arr[0];
        // for(int i=1; i<arr.size(); i++){
        //     prefix[i] = arr[i] + prefix[i-1];
        // }
        mp[0] = -1;
        int k=-1;
        int count = 0;
        int prefix =0;
        for(int i=0; i<arr.size(); i++){
            prefix +=arr[i];
            if(mp.find(prefix-target)!=mp.end() && mp[prefix-target]>=k){
                count++;
                k = i;
            }
            mp[prefix] = i;
        }
        return count;
    }
};