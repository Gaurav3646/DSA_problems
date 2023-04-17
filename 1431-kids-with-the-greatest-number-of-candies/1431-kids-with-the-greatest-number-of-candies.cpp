class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       int maxi = INT_MIN;
        for(auto &it : candies){
            maxi = max(maxi, it);
        }
        vector<bool> ans;
        for(auto &it : candies){
            // maxi = max(maxi, it);
            if(it+extraCandies>=maxi) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};