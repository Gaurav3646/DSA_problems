class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freq1(26);
        vector<int> freq2(26);
        for(auto &ch:s){
            freq1[ch-'a']++;
        }
        for(auto &ch:t){
            freq2[ch-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq1[i]!=freq2[i]) return 'a'+i;
        }
        return '#';
    }
};