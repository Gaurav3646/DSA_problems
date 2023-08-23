class Solution {
public:
    string reorganizeString(string s) {
        int a[26]={0};
        for(auto &ch:s){
            a[ch-'a']++;
        }
       int mx =0;
        int l=0;
        for(int i=0; i<26; i++){
             if (a[i] > mx) {
                mx = a[i];
                l = i;
            }
        }
        int n = ceil(s.size()/2.0);
        if(mx>n) return "";
        string ans = s;
        int i = 0;
        
        while (a[l] != 0) {
            ans[i] = char(l + 'a');
            i += 2;
            a[l]--;
        }
        for (int j = 0; j < 26; j++) {
            while (a[j] > 0) {
                if (i >= s.length()) {
                    i = 1;
                }
                ans[i] = char(j + 'a');
                i += 2;
                a[j]--;
            }
        }
        return ans;
        
    }
};