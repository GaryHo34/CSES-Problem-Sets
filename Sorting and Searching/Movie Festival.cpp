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
        s.push_back({a, b});
    }
    sort(s.begin(), s.end());
    int end = s[0].second, ans = 1;
    for (auto &[a, b] : s)
    {
        if (a >= end)
        {
            ans++;
            end = b;
        }
        else
        {
            end = min(end, b);
        }
    }
    cout << ans << endl;
    return 0;
}