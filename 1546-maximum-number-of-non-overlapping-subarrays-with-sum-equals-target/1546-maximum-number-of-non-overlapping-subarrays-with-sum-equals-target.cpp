class Solution {
public:
    int maxNonOverlapping(vector<int>& arr, int target) {
         unordered_map<int, int> mp;
        vector<int> prefix(arr.size());
        prefix[0] = arr[0];
        for(int i=1; i<arr.size(); i++){
            prefix[i] = arr[i] + prefix[i-1];
        }
        mp[0] = -1;
        int k=-1;
        int count = 0;
        for(int i=0; i<arr.size(); i++){
            if(mp.find(prefix[i]-target)!=mp.end() && mp[prefix[i]-target]>=k){
                count++;
                mp[prefix[i]] = i;
                k = i;
            }
            else{
                mp[prefix[i]]=i;
            }
        }
        return count;
    }
};