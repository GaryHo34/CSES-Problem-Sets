#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        s.push_back({a, 1});
        s.push_back({b, -1});
    }
    sort(s.begin(), s.end());
    int c = 0, ans = 0;
    for (auto &[t, v] : s)
    {
        c += v;
        ans = max(c, ans);
    }
    cout << ans << endl;
    return 0;
}