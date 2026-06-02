#include <bits/stdc++.h>

using namespace std;

int dp[510][510];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;


    for (int i=0; i<=max(a,b); i++)
    {
        for (int j=0; j<=max(a,b); j++)
        {
            if (i == j) dp[i][j] = 0;
            else dp[i][j] = INT_MAX/2;
        }
    }

    for (int i=1; i<=a; i++)
    {
        for (int j=1; j<=b; j++)
        {
            for (int x=1; x<i; x++)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[x][j] + dp[i-x][j]);
            }
            for (int y=1; y<j; y++)
            {
                dp[i][j] = min(dp[i][j], 1 + dp[i][y] + dp[i][j-y]);
            }
        }
    }
    cout << dp[a][b] << endl;

    return 0;
}