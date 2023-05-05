class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'|| ch=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int v = 0;
        int j = 0;
        int maxi = 0;
        for(int i=0,j=0; i<s.length(); i++){
            if(i<k){
                if(isVowel(s[i])) v++;
            }
            else{
              if(isVowel(s[j++])) v--;
              if(isVowel(s[i])) v++;
              
            }
             maxi = max(maxi, v); 
        }
        return maxi;
    }
};