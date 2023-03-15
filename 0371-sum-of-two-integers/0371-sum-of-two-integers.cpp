class Solution {
public:
    int getSum(int a, int b) {
        int n1 = a;
        int n2 = b;
        int ans = 0;
        int c = 0;
        int i = 0;
        while(i<32){
             int x1 = (n1>>i)&1;
             int x2 = (n2>>i)&1;
            if(x1&&x2){
                if(c==1)
                ans = ans|(1<<i);
                else
                    c=1;
   
            }
            else{
               if(x1==0 && x2==0){
                   if(c==1){
                       ans = ans|(1<<i);
                       c=0;
                   }
               }
                else{
                    if(c==0){
                        ans = ans|(1<<i);
                    }
                }
            }
            i++;
        }
        return ans;
    }
};