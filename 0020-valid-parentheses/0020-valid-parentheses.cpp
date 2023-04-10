class Solution {
public:
   
    bool isValid(string s) {
            unordered_map<char, int> mp;
            mp['('] = 1;
            mp[')'] = -1;
            mp['{'] = 2;
            mp['}'] = -2;
            mp['['] = 3;
            mp[']'] = -3;
        stack<int> st;
        for(auto &i: s){
            if(mp[i]>0){
                st.push(mp[i]);
            }
            else{
                if(!st.empty()&&st.top()+mp[i]==0){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty())
          return true;
        
          return false;
    }
};