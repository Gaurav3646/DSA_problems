class KthLargest {
public:
    priority_queue<int , vector<int> , greater<int>> pq;
    int x;
    KthLargest(int k, vector<int>& nums) {
        int i = 0;
        x = k;
        while(i<nums.size()){
             pq.push(nums[i]);
            if(pq.size()==k+1){
                // cout<<pq.top()<<endl;
                pq.pop();
                
            }
           i++; 
        }
    }
    
    int add(int val) {
         
           pq.push(val);
        // cout<<pq.top()<<endl;
        if(pq.size()==x+1)
           pq.pop();
        return pq.top();  
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */