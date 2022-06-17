#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
unordered_map<string,int> mp;
int solve(string s,int i, int j, bool istrue)
{
    if(i>j)
    return false;
    if(i==j)
    {
        if(istrue=='T')
        return s[i]=='T';
        else
        return s[i]=='F';
    }
    string t=to_string(i)+'_'+to_string(j)+'_'+to_string(istrue);
    if(mp.find(t)!=mp.end())
    return mp[t];
    int ans=0;
    for(int k=i+1;k<j;k=k+2)
    {
      int rt=solve(s,i,k,true);
      int rf=solve(s,i,k,false);
      int lt=solve(s,k+1,j,true);
      int lf=solve(s,k+1,j,false);
      if(s[k]=='&')
      {
        if(istrue==true)
        ans+=lt*rt;
        else
        ans+=lt*rf+rt*lf+lf*rf;
      }
      else if(s[k]=='|')
      {
        if(istrue==true)
        ans+=lt*rt+lt*rf+rt*lf;
        else
        ans+=lf*rf;
      }
      else if(s[k]=='^')
      {
        if(istrue==true)
        ans+=lt*rf+rt*lf;
        else
        ans+=lf*rf+lt*rt;
      }

    }
    return mp[t]=ans;
}
int main()
{
    string s;
    cin>>s;
    cout<<solve(s,0,s.length()-1,true);
}