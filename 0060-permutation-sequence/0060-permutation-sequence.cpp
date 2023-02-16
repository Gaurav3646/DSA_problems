class Solution {
public:
    // void solve(string &s, int &i, int &k, float &x, int &n){
    //     if(k==1) return ;
    //     x /= n-i;
    //     int v = ceil(k/x)-1;
    //      k = k - v*x;
    //     int j = i+v;
    //     char ch = s[j];
    //     while(i<j){
    //         s[j] = s[j-1];
    //         j--;
    //     }
    //    s[i] = ch;
    //     i++;
    //     solve(s, i, k, x, n);
    // }
    string getPermutation(int n, int k) {
         float x = 1;
         string s = "";
       for(int i=1; i<=n; i++){
           s += ('0'+i);
          x *= i; 
       }
        int i = 0;
        // solve(s, i, k, x, n);
        while(k>1){
        x /= n-i;
        int v = ceil(k/x)-1;
         k -= v*x;
        int j = i+v;
        char ch = s[j];
        while(i<j){
            s[j] = s[j-1];
            j--;
        }
       s[i] = ch;
        i++;
        }
        return s;
    }
};