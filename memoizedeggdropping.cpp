#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int static dp[1001][1001];
int solve(int e,int f)
{
    if(f==0 || f==1)
    return f;
    if(e==1)
    return f;
    if(dp[e][f]!=-1)
    return dp[e][f];
    int l,r;
    int mn = INT_MAX;
    for(int k=1;k<=f;++k)
    {
        if(dp[e-1][k-1]==-1)
        {
            l=solve(e-1,k-1);
            dp[e-1][k-1]=l;
        }
        else
        l=dp[e-1][k-1];
        if(dp[e][f-k]==-1)
        {
            r=solve(e,f-k);
            dp[e][f-k]=r;
        }
        else
        r=dp[e][f-k];
        int temp=1+max(l,r);
        mn = min(mn,temp);
    }
    return dp[e][f]=mn;
}
int main()
{
    int e,f;
    cin>>e>>f;
    memset(dp,-1,sizeof(dp));
    cout<<solve(e,f);
}