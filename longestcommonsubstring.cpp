#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pb emplace_back
const unsigned int M = 1000000007;
#define tc int tc; cin>>tc;while(tc--)
int dp[22][22];
int coun= 0;
int res=0;
int lcsu(string x, string y, int m ,int  n)
{
    if(m==0 || n==0)
    return res;
  
    else{
        if(x[m-1]==y[n-1])
        {   lcsu(x,y,m-1,n-1);
           return res+1;
    }
        else
        { res=0;
        res=max(lcsu(x,y,m-1,n),lcsu(x,y,m,n-1));
        return res;
    }
    return res;
}
}
int main()
{
    memset(dp,-1,sizeof(dp));
    string x,y;
    cin>>x>>y;
    cout<<lcsu(x,y,x.length(),y.length());
    for (int i = 0; i < 10; i++)
    { cout<<endl;
        /* code */
        for (int j = 0; j < 10; j++)
        {
            /* code */
            cout<<dp[i][j]<<' ';
        }
       
    }
     cout<<endl<<res<<' ';
    
   
}
