#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<array<int, 3>> vec(n);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vec[i] = {a, b, c};
    }

    sort(vec.begin(), vec.end(), [](array<int, 3> &a, array<int, 3> &b) {
        if (a[1] == b[1]) 
            return a[0] < b[0];
        return a[1] < b[1]; 
    });

    long long mx = 0;
    map<int, long long> dp;
    dp[0] = 0;
    for (auto [start, end, cost] : vec)
    {
        auto it = dp.lower_bound(start);
        if (it != dp.begin())
        {
            it = prev(it);
            auto tail = prev(dp.end());
            dp[end] = max({dp[end], it->second + cost, tail->second});
            mx = max(mx, dp[end]);
        }
    }
    cout << mx << endl;
    return 0;
}