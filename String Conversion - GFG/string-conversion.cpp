//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:	
	
	int solve(string s1, string s2){
	   int n = s1.length();
	int m = s2.length();

	vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

	
	dp[0][0] = true;

	
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j <= s2.length(); j++) {
			if (dp[i][j]) {

				if (j < s2.length() && 
					(toupper(s1[i]) == s2[j]))
					dp[i + 1][j + 1] = true;
				
				if (islower(s1[i]))
					dp[i + 1][j] = true;
			}
		}
	}

	return int(dp[n][m]);
	}	
		
	int stringConversion(string X, string Y)
	
	{
	   
	   return solve(X, Y);
	    
	}
};






//{ Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s1, s2;
   		cin >> s1 >> s2;

   		Solution ob;

   		cout << ob.stringConversion(s1, s2) << "\n";
   	}

    return 0;
}
// } Driver Code Ends