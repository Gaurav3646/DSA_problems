class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp;
        vector<int> ans(temperatures.size());
        for(int i=0; i<temperatures.size(); i++){
            if(temp.empty()){
                temp.push(i);
            }
            else{
                while(!temp.empty() && temperatures[temp.top()]<temperatures[i]){
                    ans[temp.top()] = i-temp.top();
                    temp.pop();
                }
                temp.push(i);
                
                
            }
        }
        return ans;
    }
};