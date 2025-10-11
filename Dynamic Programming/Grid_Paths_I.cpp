#include <bits/stdc++.h>

using namespace std;
long long dp[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0][0] = 1;
    if (arr[0][0] == '*') {
        cout << 0 << endl;
        return 0;
    }
    long long MOD = 1e9 + 7;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '*')
                continue;
            if (i - 1 >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            if (j - 1 >= 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}