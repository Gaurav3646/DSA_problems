class Solution {
public:
    void solve(string &s, int &i, int &k, float &x, int &n){
        if(k==1) return ;
        x /= n-i;
        int v = ceil(k/x)-1;
         k = k - v*x;
        // cout<<k<<"*"<<x<<endl;
        int j = i+v;
        char ch = s[j];
        // cout<<ch<<j<<endl;
        while(i<j){
            s[j] = s[j-1];
            j--;
        }
       s[i] = ch;
        i++;
        solve(s, i, k, x, n);
    }
    string getPermutation(int n, int k) {
         float x = 1;
         string s = "";
       for(int i=1; i<=n; i++){
           s += ('0'+i);
           // cout<<s<<endl;
          x *= i; 
       }
        int i = 0;
        solve(s, i, k, x, n);
        return s;
    }
};