class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& cord) {
        // a = y1-y2
        int a = cord[0][1]-cord[1][1];
        // b = x2-x1
        int b = cord[1][0]-cord[0][0];
         // c = b*y1 - a*x1;
        int c =  cord[0][1]*b+cord[0][0]*a;
        // equ. ax + by = c
        for(auto &p: cord){
            int x = p[0];
            int y = p[1];
            if((b*y+a*x)!=c) return false;
        }
        
        return true;
    }
};