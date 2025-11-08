#include <bits/stdc++.h>

using namespace std;
int dp[501][501];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;
    if (m == n)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
        {
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INT_MAX / 2;
        }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            for (int x = 1; x < i; x++)
            {
                dp[i][j] = min(dp[i][j], dp[i - x][j] + dp[x][j] + 1);
            }
            for (int x = 1; x < j; x++)
            {
                dp[i][j] = min(dp[i][j], dp[i][j - x] + dp[i][x] + 1);
            }
        }

    cout << dp[m][n] << endl;
    return 0;
}