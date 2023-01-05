class Solution {
public:
    static int cmp(vector<int>& p1, vector<int>& p2){
        return p1[1]<p2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int count= 1;
        int end = points[0][1];
        for(int i=1; i<points.size(); i++){
            if(end<points[i][0]){
                count++;
                end = points[i][1];
            }
        }
        return count;
    }
};