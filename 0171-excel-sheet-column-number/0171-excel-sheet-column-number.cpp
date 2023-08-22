class Solution {
public:
    int titleToNumber(string s) {
        reverse(s.begin(), s.end());
        int b = 1;
        int sum =0;
       int i=0;
        for(auto &ch:s){
            int k = (ch-'A')+1;
             sum += k*b;
        if(i!=s.size()-1)
            b *= 26;
            i++;
        }
        return sum;
    }
};