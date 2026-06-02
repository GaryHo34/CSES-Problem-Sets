#include <bits/stdc++.h>

using namespace std;

long long dp[5001][5001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> scores(n);
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    for (int len = 1; len <= n; len++)
        for (int i = 0; i < n; i++)
        {
            int j = i + len - 1;
            if (j >= n)
                continue;
            if (i == j)
            {
                dp[i][j] = scores[i];
            }
            else if (j == i + 1)
            {
                dp[i][j] = max(scores[i], scores[j]);
            }
            else
            {
                dp[i][j] = max(scores[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                               scores[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
            }
        }
    cout << dp[0][n - 1];
    return 0;
}

// a_max = max(scores[i] - dp[i+1][j], scores[j] - dp[i][j-1])