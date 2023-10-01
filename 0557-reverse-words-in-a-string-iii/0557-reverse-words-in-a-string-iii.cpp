class Solution {
public:
    string reverseWords(string s) {
        stringstream iss(s);
        string word;
        string ans ="";
        while(iss>>word){
            ans += " ";
            reverse(word.begin(), word.end());
            ans += word;
            
            
        }
        return ans.substr(1);
    }
};