class Solution {
public:
    
    int solve(string &s, int i, char &ch , unordered_map<char, int> &mp){
        if(i>=s.length()) return 0;
        if(ch!='#' && mp[s[i]]>mp[ch]){
            char x = ch;
            ch = s[i];
            // cout<<mp[s[i]] - 2*mp[x]<<" "<<s[i]<<endl;
          return solve(s, i+1, ch, mp)+ mp[s[i]] - 2*mp[x];  
        }
        else{
            ch = s[i];
            // cout<<mp[s[i]]<<s[i]<<endl;
           return solve(s, i+1, ch, mp)+ mp[s[i]]; 
        }
    }
    int romanToInt(string s) {
     unordered_map<char, int> mp;
    
    mp['I'] = 1;
    mp['X'] = 10;
    mp['V'] = 5;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
        char ch ='#';
      return solve(s, 0, ch, mp);
    }
};