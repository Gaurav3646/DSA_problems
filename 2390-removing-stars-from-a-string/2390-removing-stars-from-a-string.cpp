class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto &ch :s){
            if(ch=='*'){
                st.pop();
                continue;
            }
            st.push(ch);
        }
        string str = "";
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};