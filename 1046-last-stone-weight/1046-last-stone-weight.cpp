class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> queue(stones.begin(), stones.end());
        // for(int i=0; i<stones.size(); i++){
        //     queue.push(stones[i]);
        // }
        
        while(queue.size()>1){
            int x = queue.top();
            queue.pop();
            int y = queue.top();
            queue.pop();
            if(x!=y){
                queue.push(x-y);
            }
        }
        if(queue.size()==0) return 0;
        return queue.top();
    }
};