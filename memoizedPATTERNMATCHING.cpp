#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb emplace_back
const unsigned int M = 1000000007;
#define tc int tc; cin>>tc;while(tc--)
// store maximum value in size of dp from constraints
int static dp[1001][1001];
int lcs(string x, string y, int m , int n)
{
    if(m==0 || n==0)
    return 0;
    if(dp[m][n]!=-1)
    return dp[m][n];
    if(x[m-1]==y[n-1])
    return dp[m][n] =1+lcs(x,y,m-1,n-1);
    else
    return dp[m][n]= max(lcs(x,y,m-1,n),lcs(x,y,m,n-1));

}
int main()
{ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
//tc
{
 memset(dp,-1,sizeof(dp));
 string x,y;
 cin >>x>>y;
 ll k=lcs(x,y,x.length(),y.length());
 cout<<(k==min(x.length(),y.length()));
}
}