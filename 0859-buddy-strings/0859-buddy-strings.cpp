class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        vector<int> vect;
        unordered_set<char> st;
        for(int i=0; i<s.size(); i++){
           if(s[i]!=goal[i]){
               if(vect.size()==2) return false;
               vect.push_back(i);   
           }
            st.insert(s[i]);
        }
        if(vect.size()==2 && s[vect[0]]==goal[vect[1]] && s[vect[1]]==goal[vect[0]]) return true;
        if(vect.size()==0 && st.size()!=s.size()) return true;
        
        return false;
    }
};