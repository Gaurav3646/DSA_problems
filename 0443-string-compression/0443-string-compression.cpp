class Solution {
public:
    void solve(int &cnt , vector<char> &ns){
        if(cnt==0){
            return ;
        }
        int x = cnt%10;
        cnt /=10;
        solve(cnt, ns);
        
        ns.push_back(x+'0');
    }
    int compress(vector<char>& chars) {
        vector<char> ns;
        int cnt = 0;
        char m = chars[0];
        int ans = 0;
        for(auto & ch: chars){
            if(m==ch){
                cnt++;
            }
            else{
              ns.push_back(m);
                if(cnt>1)
                solve(cnt, ns);
                cnt = 1;
                m = ch;
            }
        }
        ns.push_back(m);
        if(cnt>1)
        solve(cnt, ns);
        chars = ns;
        return ns.size();
    }
};