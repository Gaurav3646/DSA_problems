class Solution {
public:
    long long int Mod = 1000000007;
    int numTilings(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<long long int> fully(n+1);
        vector<long long int> partially(n+1);
        fully[1] = 1;
        fully[2] = 2;
        partially[1] = 0;
        partially[2] = 1;
        for(int i=3; i<=n; i++){
            
            fully[i] = (fully[i-1] + fully[i-2] + (2*partially[i-1])%Mod)%Mod;
           partially[i] =( partially[i-1]+ fully[i-2])%Mod;
        }
        
        return fully[n];
    }
};