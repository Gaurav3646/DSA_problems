//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int catchThieves(char arr[], int n, int k) 
    {
        // Code here 
        int i =0;
        int j =0;
        vector<int> police;
        vector<int> theif;
        for(int i=0; i<n; i++){
            if(arr[i]=='P')
            police.push_back(i);
            else
            theif.push_back(i);
        }
        int ans =0;
        while(i<police.size()&&j<theif.size()){
            if(abs(police[i]-theif[j])<=k){
                ans++;
                j++;
                i++;
            }
            else if(police[i]<theif[j]) i++;
            else if(police[i]>theif[j]) j++;
         
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n >> k;
		char arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		Solution obj;
		cout<<obj.catchThieves(arr, n, k) << endl;
	}
	return 0; 
} 


// } Driver Code Ends