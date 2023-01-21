class Solution {
public:
    vector<string> strs;
    void addPoints(string &s, int i, string p, int pt){
          if(pt==0 && i>=s.length()){
             //  int y = 0;
             //  if(i!=s.length()-1 && s[i]=='0') return;
             // while(i<s.length() && y<=255){
             //    y = y*10 + s[i]-'0';
             //     p += s[i];
             //     i++;
             // }
             //  if(y<=255){
              p.pop_back();
                  strs.push_back(p);
               p += '.';
              // }
          }
        if(pt==0) return;
        int x = 0;
        if(s[i]!='0'){
        for(int j=i; j<s.length() && (x*10+s[j]-'0')<=255; j++){
            x = x*10+s[j]-'0';
            p += s[j];
             addPoints(s, j+1, p+'.', pt-1);
        }
        }
        else{
           p += s[i];
             addPoints(s, i+1, p+'.', pt-1);  
        }
      }
    vector<string> restoreIpAddresses(string s) {
         addPoints(s, 0, "", 4);  
        return strs;
    }
};