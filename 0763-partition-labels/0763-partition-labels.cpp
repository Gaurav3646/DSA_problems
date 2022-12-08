class Solution {
public:
    // static bool cmp(pair<int,int> p1, pair<int, int> p2){
    //       return p1.second<p2.second;
    // }
    vector<int> partitionLabels(string s) {
        vector<int> p(26, INT_MIN);
        for(int i=0; i<s.length(); i++){
             p[s[i]-'a'] = max(i,  p[s[i]-'a']);
        }
//         sort(p.begin(), p.end(), cmp);
//         int i= 
        vector<int> ans;
//         int last =
//         for(int i=0; i<26;  i++){
//             if(p[i].first==INT_MAX)continue;
            
//         }
        // int l=-1;
        // int r=-1;
         int l=0;
         int r=0;
        for(int i=0; i<s.length(); i++){
              if(r<i){
                // if(l!=-1 && r!=-1)
                 ans.push_back(r-l+1);
                  r = i;
                  l = i;
              }
              r = max(r,p[s[i]-'a']);
            
             
            
            
        }
    // if(l!=-1 && r!=-1)
        ans.push_back(r-l+1);
        return ans;
    }
};