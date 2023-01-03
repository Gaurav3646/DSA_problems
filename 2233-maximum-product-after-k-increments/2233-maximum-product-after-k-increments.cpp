class Solution {
public:
    int M = 1e9 + 7;
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int> q;
       for(int i=0; i<nums.size(); i++){
           q.push(-nums[i]);
       }
        while(k--){
              int top = q.top();
            q.pop();
            q.push(--top);
        }
        long long mod = 1;
        while(!q.empty()){
            int top = -q.top();
            q.pop();
            mod = (mod*top)%M;
        }
        return mod;
        
    }
};