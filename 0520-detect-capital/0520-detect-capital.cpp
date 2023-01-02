class Solution {
public:
    bool detectCapitalUse(string word) {
        // if(word[0]>='A' && word[0]<='Z'){
        //     for(int i=1; i<word.length(); i++){
        //         if(word[i]<'A' || word[i]>'Z'){
        //             return false;
        //         }
        //     }
        //     return true;
        // }
        int x = 0;
         for(int i=1; i<word.length(); i++){
                if(word[i]>='A' && word[i]<='Z'){
                    x++;
                    // return false;
                }

            }
        if(x==0){
            return true;
        }
        else if(x==word.length()-1 && word[0]>='A' && word[0]<='Z'){
            return true;
        }
        else{
            return false;
        }

        
    }
};