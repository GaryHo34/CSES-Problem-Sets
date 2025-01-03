#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k, tmp;
    cin >> n >> m >> k;

    vector<int> sz, app;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        sz.push_back(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        app.push_back(tmp);
    }

    sort(sz.begin(), sz.end());
    sort(app.begin(), app.end());

    int j = 0, ans = 0;
    for (auto a : app)
    {
        while (j < n && sz[j] < a - k)
            j++;
        if (j < n && sz[j] >= a - k && sz[j] <= a + k)
        {
            ans++;
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}