// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string answer;
 int dp[1001][1001];
class Solution{ 
    public:
 
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        if(n==0||m==0)
        return 0;
        if (dp[n][m]!=-1)
        return dp[n][m];
        else if(S1[n-1]==S2[m-1])
        {   answer.push_back(S1[n-1]);
        cout<<answer<<endl;
            return dp[n][m]=1+longestCommonSubstr(S1,S2,n-1,m-1);}
        else {
           
            return dp[n][m]=max(longestCommonSubstr(S1,S2,n-1,m),longestCommonSubstr(S1,S2,n,m-1));}
         return dp[n][m];   
    }
  
};

// { Driver Code Starts.

int main()
{
   
    {
         memset(dp,-1,sizeof(dp));
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, s1.length(), s2.length()) << endl;
    
        cout<<answer<<' ';
    }
}