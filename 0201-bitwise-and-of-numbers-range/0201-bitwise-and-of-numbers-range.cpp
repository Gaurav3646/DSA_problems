class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        int p = pow(2, 30);
        for(int i=30; i>=0; i--){
            int l = left&p;
            int r = right&p;
            // cout<<l<<" "<<r<<endl;
           if(l&r)
              ans += p;
           else if(l==0 && r==p) return ans; 
            
            // cout<<p<<endl;
            p /=2;
            
            
        }
        return ans;
    }

};