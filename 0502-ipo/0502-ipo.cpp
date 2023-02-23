class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> ipo;
        for(int i=0; i<profits.size(); i++){
            ipo.push_back({capital[i], profits[i]});
        }
        sort(ipo.begin(), ipo.end());
       auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
    return p1.second < p2.second;
    };

priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
       int i=0;
        while(i<profits.size()){
        if(ipo[i].first<=w){
            pq.push(ipo[i]);
            i++;
        }
        else if(k && !pq.empty()){
            
            pair<int, int> p = pq.top();
            pq.pop();
            // pq.push(ipo[i]);
            cout<<p.second<<endl;
           w += p.second;
            k--;
        }
        else{
            return w;
        }
      }
        while(k && !pq.empty()){
        pair<int, int> p = pq.top();
            pq.pop();
            // pq.push(ipo[i]);
            // cout<<p.second<<endl;
           w += p.second;
            k--;
        }
     return w; 
    
    }
};