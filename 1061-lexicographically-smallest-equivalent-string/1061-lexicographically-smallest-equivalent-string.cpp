class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
       char mn[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
        int n = s1.size();
        
        // for(auto &m : mp){
        //     cout<<m.first<<" "<<m.second<<endl;
        // }
        for(int i=0; i<n; i++){
          if(s1[i]==s2[i]) continue;
            char ch = min(mn[s1[i]-'a'], mn[s2[i]-'a']);
         char chm = max(mn[s1[i]-'a'], mn[s2[i]-'a']);
            for(int i=0; i<26; i++){
                if(mn[i]==chm) mn[i]=ch;
            }
        }
        string s = "";
        for(int i=0; i<baseStr.size(); i++){
            s+= mn[baseStr[i]-'a'];
        
        }
        return s;
    }
};