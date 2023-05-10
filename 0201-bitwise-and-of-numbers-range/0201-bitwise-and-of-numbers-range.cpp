class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i=30; i>=0; i--){
            int l = (left>>i)&1;
            int r = (right>>i)&1;
            // cout<<l<<" "<<r<<endl;
           if(l&r)
              ans += 1<<i;
           else if(l==0 && r==1) return ans; 
            
        }
        return ans;
    }
};