class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0;
        int ti = 0;
        while(ti<t.size()&&si<s.size()){
            if(t[ti++]==s[si]) si++;
        }
       return si==s.size()?true:false; 
    }
};