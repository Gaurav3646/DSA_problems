class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        map<int, int> line;
        for(int i=0; i<intervals.size(); i++){
            line[intervals[i][0]]++;
            line[intervals[i][1]]--;
        }
        int x =0;
        int start = -1;
        int end = -1;
        vector<vector<int>> ans;
        for(auto it: line){
            x += it.second;
            if(x>0 && start==-1){
              start = it.first;  
            }
            if(x==0 && start==-1){
                start = it.first;
            }
             if(x==0 && start!=-1){
                 end = it.first;
             }
            if(start!=-1 && end!=-1){
                
               ans.push_back({start, end});
                start =-1;
                end = -1;
            }
        }
        return ans;
    }
};