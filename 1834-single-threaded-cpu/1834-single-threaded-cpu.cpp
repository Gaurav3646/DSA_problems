class Solution {
public:
    static bool cmp(vector<int> &p1, vector<int> &p2){
       return  p1[0]<p2[0];
      // if(p1[1]!=p2[1]) return p1[1]<p2[1];
        // else return p1[0]<p2[0];
}
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i=0; i<tasks.size(); i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end(), cmp);
         vector<int> ans;
        // for(int i=0; i<tasks.size(); i++){
        //     ans.push_back(tasks[i][2]);
        // }
        // return ans;
        priority_queue<vector<int>> q;
        // q.push(task[0]);
        int i = 0;
        int time = 0;
        while(i<tasks.size()){
            
           while(i<tasks.size() && tasks[i][0]<=time){
               q.push({-tasks[i][1], -tasks[i][2]});
                i++;
            } 
          if(q.empty()){
                time = tasks[i][0];
            }
            else{
           vector<int> top = q.top();
            q.pop();
             time -= top[0];
            // cout<<top[1]<<endl;
            ans.push_back(-top[1]);
            }

        }
        while(!q.empty()){
            // cout<<"*";
            vector<int> top = q.top();
            q.pop();
            ans.push_back(-top[1]);
        }
        return ans;
    }
};