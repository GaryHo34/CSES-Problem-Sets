#include <bits/stdc++.h>

using namespace std;
long long dp[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<int> a(m + 1), b(n + 1);
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    unordered_map<int, unordered_map<int, pair<int, int>>> parent;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j - 1] >= dp[i - 1][j])
            {
                dp[i][j] = dp[i][j - 1];
                parent[i][j] = {i, j - 1};
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                parent[i][j] = {i - 1, j};
            }
            if (a[i] == b[j] && dp[i - 1][j - 1] + 1 > dp[i][j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                parent[i][j] = {i - 1, j - 1};
            }
        }
    }
    cout << dp[m][n] << endl;
    int x = m, y =n;
    vector<int> path;
    while (parent.find(x) != parent.end() && parent[x].find(y) != parent[x].end())
    {
        auto [px, py] = parent[x][y];
        if (px == x-1 && py == y-1)
        {
            path.push_back(a[x]);
        }
        x = px, y = py;
    }
    reverse(path.begin(), path.end());
    for (auto x: path)
        cout << x << " ";
    cout << endl;
    return 0;
}