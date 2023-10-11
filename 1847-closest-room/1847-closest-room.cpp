class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(), rooms.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1]>b[1];
        });
        vector<vector<int>> Q = queries;
        sort(queries.begin(), queries.end(), [](const vector<int> &a, const vector<int> &b){
            return a[1]>b[1];
        });
        
        map<pair<int, int>, int> mp;
        map<int, int> mp2;
        int i =0;
        for(auto &q:queries){
            while(i<rooms.size() && q[1]<=rooms[i][1]){
                mp2[rooms[i++][0]];
                
            }
            auto it = mp2.upper_bound(q[0]);
            int id;
            int ans  = INT_MAX;
            if(it!=mp2.end()){
                if(ans>abs(it->first-q[0])){
                    ans = abs(it->first-q[0]);
                    id = it->first;
                }
            }
            if(it!=mp2.begin()){
                it--;
                 if(ans>=abs(it->first-q[0])){
                    ans = abs(it->first-q[0]);
                      id = it->first;
                }
            }
            mp[{q[0], q[1]}] = ans==INT_MAX?-1:id;
        }
        vector<int> aans;
        for(auto &q:Q){
            aans.push_back(mp[{q[0], q[1]}]);
        }
        
        return aans;
    }
};