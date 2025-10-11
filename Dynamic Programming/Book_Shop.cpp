#include <bits/stdc++.h>

using namespace std;
int dp[1001][100001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);

    for (int i = 0; i < n; i++)
        cin >> prices[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    prices.insert(prices.begin(), 0);
    pages.insert(pages.begin(), 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (j >= prices[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i]] + pages[i]);
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}