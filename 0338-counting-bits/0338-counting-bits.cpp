class Solution {
public:
    
    vector<int> countBits(int n) {
         vector<int> ans(n+1);
          ans[0] = 0;
          int cnt = 1;
          int j = 0;
        for(int i=1; i<=n; i++, j++){
             if(cnt==i){
                 j = 0;
                 ans[i] = 1;
                 cnt *= 2;
             }
            else{
                ans[i] = 1+ans[j];
            }
            
        }
        return ans;
    }
};