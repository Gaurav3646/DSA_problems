
    class Solution {
public:
    string reverseStr(string s, int k) {
         int count=0;
    for(int i=0;i<s.size(); i=i+k)
    {
        if(count%2==0){
            int j=i+ k-1;
            if(j>=s.size()){
             j = s.size()-1;   
            }
            for(int t=i;t<=j;){
                
            swap(s[t++],s[j--]);
          
            }
            
              count++;
        }
        else
        count++;
    }
    return s;
        
    }
 
};
