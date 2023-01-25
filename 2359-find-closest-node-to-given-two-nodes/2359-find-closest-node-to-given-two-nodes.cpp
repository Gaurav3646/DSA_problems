class Solution {
public:
    int closestMeetingNode(vector<int>& ed, int n1, int n2) {
        //dfs on node1
        unordered_map<int,int> m1;
        unordered_set<int> vis1;
        vis1.insert(n1);
        int count=0;
        while(true){
            m1[n1]= count;
            count++;
            if(ed[n1]==-1 || vis1.count(ed[n1]))break;
            n1= ed[n1];
            vis1.insert(n1);
        }
        
        //dfs on node2
        count=0;
        unordered_set<int> vis;
        vis.insert(n2);
        int ans= INT_MAX, dis= INT_MAX;
        while(true){
            if(m1.find(n2)!= m1.end()){
                if(max(count,m1[n2]) < dis){
                    dis= max(count,m1[n2]);
                    ans= n2;
                }
                else if(max(count,m1[n2]) == dis) ans= min(ans,n2);
            }
            count++;
            if(ed[n2]==-1 || vis.count(ed[n2])) break;
            n2= ed[n2];
            vis.insert(n2);
        }
        
        return ans==INT_MAX?-1:ans;
    }
};