class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int u,  vector<bool> &visited){
             visited[u] = true;
        for(auto &v : rooms[u]){
            if(!visited[v]){
                dfs(rooms, v, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
          vector<bool> visited(rooms.size());
           dfs(rooms, 0, visited);
        for(auto  it : visited){
            if(it==false) return false;
        }
        return true;
    }
};