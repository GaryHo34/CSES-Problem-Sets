#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, tmp;
    cin >> n >> m;

    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        auto it = s.upper_bound(tmp);
        int ans = -1;
        if (it != s.begin())
        {
            it = prev(it);
            ans = *it;
            s.erase(it);
        }
        cout << ans << endl;
    }
    return 0;
}