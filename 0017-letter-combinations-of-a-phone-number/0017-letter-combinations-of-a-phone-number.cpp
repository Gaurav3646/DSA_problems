class Solution {
public:
    string s[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"};
    void helper(vector<string> &vect1, vector<string> &vect2){
    for (int i = 0; i < vect2.size(); i++){
        vect1.push_back(vect2[i]);
    }
    return;
}
 vector<string> solve(string p,string digits){
     if(digits.length()==0){
         vector<string> v;
         v.push_back(p);
         return v;
     }
     vector<string> vect1;
     for(int i=0; i<s[(digits[0]-'0')].length(); i++){
      vector<string> vect2 = solve(p+s[(digits[0]-'0')][i], digits.substr(1));
         helper(vect1, vect2);
     }
     return vect1;
 }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
       return solve("", digits);
       
    }
};