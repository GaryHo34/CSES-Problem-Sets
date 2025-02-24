#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    cin >> n;

    multiset<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        auto it = s.upper_bound(tmp);
        if (it == s.end())
        {
            ans++;
        }
        else
        {
            s.erase(it);
        }
        s.insert(tmp);
    }
    cout << ans << endl;
    return 0;
}