class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // vector<int> count(s.size());
       int  ttz = 0;
        int tto = 0;
        
       for(int i=0; i<s.size(); i++){
         if(s[i]=='0') ttz++;
           else tto++;
       }
        int mn = INT_MAX;
        int z=0;
        int o = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0') z++;
            else o++;
            mn = min(mn, o+ttz-z);
            
        }
        mn = min(ttz, mn);
        mn = min(tto, mn);
        return mn;
    }
};