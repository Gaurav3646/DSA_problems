class Solution {
public:
   string solve(string &s, int &i){
        if(i==s.size()) return "";
        string str = "";
        while(i<s.size()){
            if(s[i]==']') return str;
           else if(s[i]>='0' && s[i]<='9'){
                int k  = 0;
               while(s[i]>='0' && s[i]<='9'){
                  k  = k*10 + s[i]-'0';
                   i++;
               }
               i++;
                // cout<<k<<endl;
             string t = solve(s, i);
             for(int j=0; j<k; j++){
                  str += t;
                 // cout<<str<<endl;
             }
            }
           else{
               str += s[i];
           }
           i++; 
        }
        return str;
    }
    string decodeString(string s) {
        int i =0;
        return solve(s, i);
    }
};