class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       map<int, vector<int>> adj;
        for(int i=0; i<matches.size(); i++){
            int u = matches[i][1];
            int v = matches[i][0];
            adj[u].push_back(v);
            adj[v];
        }
        vector<vector<int>> answer(2);
        for(auto &u: adj){
           if(u.second.size()==0){
               answer[0].push_back(u.first);
           }
            else if(u.second.size()==1){
               answer[1].push_back(u.first);
            }
        }
    
        return answer;
    }
};