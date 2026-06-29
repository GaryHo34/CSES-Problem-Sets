#include <bits/stdc++.h>

using namespace std;

int mn = 20;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    vector<pair<int, int>> dp((1 << n));
    dp[0] = {1, 0};
    for (int state = 1; state < (1 << n); state++)
    {
        dp[state] = {INT_MAX / 2, INT_MAX / 2};
        for (int i = 0; i < n; i++)
        {
            if (((state >> i) & 1) == 0)
                continue;
            pair<int, int> cand;
            if (dp[state - (1 << i)].second + vec[i] > x)
            {
                cand = {dp[state - (1 << i)].first + 1, vec[i]};
            }
            else
            {
                cand = {dp[state - (1 << i)].first, dp[state - (1 << i)].second + vec[i]};
            }
            dp[state] = min(dp[state], cand);
        }
    }

    cout << dp[(1 << n) - 1].first << endl;

    return 0;
}