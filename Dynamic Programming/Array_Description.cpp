#include <bits/stdc++.h>

using namespace std;
long long dp[105][100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (arr[0] == 0)
    {
        for (int i = 1; i <= m; i++)
            dp[i][0] = 1;
    }
    else
    {
        dp[arr[0]][0] = 1;
    }
    long long MOD = 1e9 + 7;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            dp[arr[i]][i] = (dp[arr[i] - 1][i - 1] + dp[arr[i]][i - 1] + dp[arr[i] + 1][i - 1]) % MOD;
        }
        else
            for (int j = 1; j <= m; j++)
            {
                dp[j][i] = (dp[j - 1][i - 1] + dp[j][i - 1] + dp[j + 1][i - 1]) % MOD;
            }
    }
    long long total = 0;
    for (int i = 1; i <= m; i++)
    {
        total = (total + dp[i][n - 1]) % MOD;
    }
    cout << total << endl;
    return 0;
}