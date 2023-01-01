class Solution {
public:
    bool wordPattern(string pattern, string s) {
       unordered_map<char, string> pt;
       unordered_map<string, char> st;
       int i=0;
       string word;
        stringstream iss(s);
        while(iss>>word){
            if(i==pattern.size()) return false;
            if(pt.count(pattern[i]) && st.count(word)){
               if(pt[pattern[i]] != word || st[word] != pattern[i]) return false; 
            }
            else if(!pt.count(pattern[i]) && !st.count(word)){
                pt[pattern[i]] = word;
                st[word]  = pattern[i];
            }
            else{
                return false;
            }
            i++;
        }
        if(i==pattern.size())
        return true;
        
        return false;
    
    }
};