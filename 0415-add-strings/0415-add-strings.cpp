class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.length()==1 && num1[0]=='0'){
            return num2;
        }
        if(num2.length()==1 && num2[0]=='0'){
            return num1;
        }
        string s="";
         int i1 = num1.length()-1;
         int i2 = num2.length()-1;
         int carry = 0;
         while(i1>=0 && i2>=0){
             int  n1 = num1[i1]-'0';
             int  n2  = num2[i2]-'0';
             int sum = n1 + n2 + carry;
              carry = sum/10;
               sum = sum%10;
             char ch = '0' + sum;
             s += ch;
             i1--;
             i2--;
         }
        while(i1>=0){
             int  n1 = num1[i1]-'0';
             // int  n2  = num2[i2]-'0';
             int sum = n1 + carry;
              carry = sum/10;
               sum = sum%10;
             char ch = '0' + sum;
             s += ch;
            i1--;
         }
         while(i2>=0){
             // int  n1 = num1[i1]-'0';
             int  n2  = num2[i2]-'0';
             int sum = n2 + carry;
              carry = sum/10;
               sum = sum%10;
             char ch = '0' + sum;
             s += ch;
             i2--;
         }
        while(carry){
            int n = carry%10;
        char ch = '0' + n;
            s += ch;
            carry /=10;
        }
       reverse(s.begin(), s.end());
        return s;
    }
};