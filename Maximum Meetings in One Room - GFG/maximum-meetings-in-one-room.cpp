//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
 static bool cmp(vector<int> &v1, vector<int> &v2){
        return v1[1]<v2[1];
    }
    vector<int> maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), cmp);
        int cnt =0;
        int k =-1;
        vector<int> ans;
        for(auto &e:events){
          if(k<e[0]){
            //   cnt++;
              ans.push_back(e[2]+1);
              k = e[1];
          }  
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<vector<int>> events;
        for(int i=0; i<N; i++){
            events.push_back({S[i], F[i], i});
        }
        return maxEvents(events);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends