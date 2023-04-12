class Solution {
public:
    string simplifyPath(string path) {
        // return path;
        stack<string> st;
        string w = "";
        for(auto &s: path){
            
            if(s=='/'){
                if(w==".." && (!st.empty())){
                    st.pop();
                }
                else if(w.length()>0 && w!=".." && w!="."){
                    st.push(w);
                }
                // cout<<w<<endl;
                w = "";
            }
            else{
              w += s;  
            }
        }
        
        if(w==".." && (!st.empty())){
                    st.pop();
                }
                else if(w.length()>0 && w!=".." && w!="."){
                    st.push(w);
                }
        
      stack<string> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        string ans = "/";
        while(st2.size()>1){
           ans  += st2.top();
            ans += '/';
            st2.pop();
        }
        if(st2.size()==1)
        ans += st2.top();
        return ans;
    }
};