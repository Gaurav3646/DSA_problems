class Solution {
public:
   static bool cmp(pair<int,int> &p1, pair<int, int> &p2){
        return p1.first!=p2.first?p1.first<p2.first: p1.second<p2.second;
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
       vector<pair<int,int>> diaSort;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                diaSort.push_back({i+j,j});
            }
        }
        sort(diaSort.begin(), diaSort.end(), cmp);
        vector<int> diagonal;
        for(int i=0; i<diaSort.size(); i++){
            int rc = diaSort[i].first;
            int c = diaSort[i].second;
            diagonal.push_back(nums[rc-c][c]);
        }
        return diagonal;
    }
};