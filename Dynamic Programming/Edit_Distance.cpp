#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    int m = a.size(), n = b.size();
    a = "_" + a;
    b = "_" + b;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX / 2));
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            // add char
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            // remove char
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            // replace char
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    cout << dp[m][n] << endl;
    return 0;
}