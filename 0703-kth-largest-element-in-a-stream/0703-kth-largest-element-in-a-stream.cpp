class KthLargest {
public:
    priority_queue<int , vector<int> , greater<int>> pq;
    int x;
    KthLargest(int k, vector<int>& nums) {
         priority_queue<int , vector<int> , greater<int>> npq;
        pq= npq;
        int i = 0;
        x = k;
        while(i<nums.size()){
             pq.push(nums[i]);
            if(pq.size()>k){
                // cout<<pq.top()<<endl;
                pq.pop();
                
            }
           i++; 
        }
    }
    
    int add(int val) {
         
           pq.push(val);
        // cout<<pq.top()<<endl;
        if(pq.size()>x)
           pq.pop();
        return pq.top();  
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */