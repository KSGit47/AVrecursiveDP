#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
int static dp[1001][1001];
bool ispal(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int solve(string s, int i, int j)
{
    if (i >= j)
        return 0;
    if (ispal(s, i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mn = INT_MAX, l, r;
    for (int k = i; k < j; ++k)
    {
        if (dp[i][k] != -1)
            l = dp[i][k];
        else
           { dp[i][k] = solve(s, i, k); l = dp[i][k];}
        if (dp[k+1][j] != -1)
            r = dp[k+1][j];
        else
            {dp[k+1][j] = solve(s, k+1, j); r = dp[k+1][j] ;}

        int temp = 1 + l + r;
        mn = min(temp, mn);
    }
    return dp[i][j] = mn;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    string s;
    cin >> s;
    cout << solve(s, 0, s.length() - 1);
}