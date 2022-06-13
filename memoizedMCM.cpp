#include<bits/stdc++.h>
using namespace std;
int static dp[10][10];
int solve(int arr[], int i, int j)
{
    if(i>=j)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int mn=INT_MAX;
    for(int k=i;k<j;++k)
    {
        int t=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(t<mn)
        mn=t;
    }
    return dp[i][j]=mn;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int arr[n];
for (int i = 0; i < n; i++)
{
    /* code */
    cin>>arr[i];
}
    cout<<solve(arr,1,n-1);
    
}