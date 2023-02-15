class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        for(int i=num.size()-1; i>=0; i--){
            k += num[i];
            ans.push_back(k%10);
            k /=10;
        }
        while(k){
            ans.push_back(k%10);
            k /=10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};