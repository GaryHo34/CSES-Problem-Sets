#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, tmp;
    cin >> n >> m;

    vector<int> v(n + 2);
    vector<int> arr(n + 2);
    v[0] = 0, v[n + 1] = n + 1;
    unordered_set<long long> s;

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        ans += s.find(tmp - 1) == s.end();
        s.insert(tmp);
        v[tmp] = i;
        arr[i] = tmp;
    }

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        int a = min(arr[x], arr[y]), b = max(arr[x], arr[y]);

        int flag_a1 = 0, flag_a2 = 0;
        int flag_b1 = 0, flag_b2 = 0;
        flag_a1 = (v[a] < v[a - 1]) ? 1 : -1;
        flag_b2 = (v[b] < v[b + 1]) ? 1 : -1;
        if (b != a + 1)
        {
            flag_a2 = (v[a] < v[a + 1]) ? 1 : -1;
            flag_b1 = (v[b] < v[b - 1]) ? 1 : -1;
        }
        else
        {
            if (v[a] < v[b])
                ans++;
            else
                ans--;
        }

        swap(v[a], v[b]);
        swap(arr[x], arr[y]);

        if (flag_a1 == 1 && v[a] > v[a - 1])
            ans--;
        if (flag_a1 == -1 && v[a] < v[a - 1])
            ans++;
        if (flag_a2 == 1 && v[a] > v[a + 1])
            ans++;
        if (flag_a2 == -1 && v[a] < v[a + 1])
            ans--;
        if (flag_b1 == 1 && v[b] > v[b - 1])
            ans--;
        if (flag_b1 == -1 && v[b] < v[b - 1])
            ans++;
        if (flag_b2 == 1 && v[b] > v[b + 1])
            ans++;
        if (flag_b2 == -1 && v[b] < v[b + 1])
            ans--;
        cout << ans << endl;
    }
    return 0;
}