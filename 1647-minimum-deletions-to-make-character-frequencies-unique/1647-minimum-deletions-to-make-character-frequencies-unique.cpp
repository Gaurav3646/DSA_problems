class Solution {
public:
    int minDeletions(string s) {
       int a[26]={0};
        for(int i=0; i<s.size(); i++){
            a[s[i]-'a']++;
        }
        sort(a, a+26);
        int max = a[25];
        int n=0;
        for(int i=25; i>=0; i--){
  
           if(a[i]!=0){
              if(a[i]>=max){
               n += a[i]-max;   
              }
               else{
                  max = a[i]; 
               }
           }
            else{
                break;
            }
            if(max!=0)
            max--;
        }
        return n;
    }
};