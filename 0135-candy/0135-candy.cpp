class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<ratings.size(); i++){
            pq.push({-ratings[i], i});
            
        }
        
        int ans = 0;
        vector<int> count(ratings.size());
        while(!pq.empty()){
            int index = pq.top().second;
            int tp = -1*pq.top().first;
            int mx = 0;
            int mf = 0;
            if(index+1<ratings.size() && tp>ratings[index+1]){
                 mx = max(count[index+1], mx);
            }
            if(index-1<ratings.size() && tp>ratings[index-1]){
                 mx = max(count[index-1], mx);
            }
                ans += (1+mx);
               count[index] = 1+mx;
            
            pq.pop();
        }
        return ans;
    }
};