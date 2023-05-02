class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int M = 1e9 + 7;
        // cout<<M<<endl;
        vector<long long> ans(arr.size(), 1);
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++){
            mp[arr[i]] = i;
        }
        long long total = arr.size();
        for(int i=1; i<arr.size(); i++){
            for(int j=0; j<i; j++){
                if(arr[i]%arr[j]==0){
                    if(mp.find(arr[i]/arr[j])!=mp.end()){
                       long long k = (ans[j]*ans[mp[arr[i]/arr[j]]])%M;
                        ans[i] = (ans[i]+k)%M;
                        total = (total+k)%M;
                        
                    }
                }
            }
        }
        return total;
    }
};