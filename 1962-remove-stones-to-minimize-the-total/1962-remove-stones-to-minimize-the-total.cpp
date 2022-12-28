class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // sort(piles.begin(), piles.end(), greater<int>());
        priority_queue<int> q;
        for(int i=0; i<piles.size(); i++){
            q.push(piles[i]);
        }
        while(k--){
            int x = q.top();
            x -= x/2;
            q.pop();
            q.push(x);
        }
        int ans = 0;
        while(!q.empty()){
            // cout<<q.top()<<" ";
           ans += q.top();
            q.pop();
        }
        
        return ans;
    }
};