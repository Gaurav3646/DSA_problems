class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int l1 = a.length();
        int l2 = b.length();
        int x = l2/l1;
        if(l2%l1!=0){
            x++;
        }
        int k = x;
        string str ="";
        while(x--){
           str += a; 
        }
        
        if(str.find(b)!=string::npos){
            return k;
        }
        else if((str+a).find(b)!=string::npos){
            return ++k;
        }
        else{
            return -1;
        }
    }
};