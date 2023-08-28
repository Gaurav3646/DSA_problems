class MyStack {
public:
    queue<int> q1, q2;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
         if(q1.empty()) return   -1;
       while(q1.size()>1){
           // cout<<q1.front()<<endl;
         q2.push(q1.front());
           q1.pop();
       }
    
        int tp = q1.front();
        // cout<<tp<<endl;
        q1.pop();
        
     while(!q2.empty()){
         q1.push(q2.front());
           q2.pop();
       }
        return tp;
    }
    
    int top() {
         if(q1.empty()) return   -1;
       while(q1.size()>1){
         q2.push(q1.front());
             // cout<<q1.front()<<endl;
           q1.pop();
       }
          // cout<<q1.front()<<endl;
        int tp = q1.front();
        q2.push(q1.front());
        q1.pop();
     while(!q2.empty()){
         q1.push(q2.front());
           q2.pop();
       }
        return tp;
    }
    
    bool empty() {
       return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */