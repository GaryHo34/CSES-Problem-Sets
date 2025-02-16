#include <bits/stdc++.h>

using ll = long long;
using namespace std;

struct CustomIntHash
{
    size_t operator()(const ll &key) const
    {
        return hash<ll>()(key * 2654435761ull);
    }
};
unordered_map<ll, ll, CustomIntHash> cnt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    cin >> n >> target;
    vector<ll> presum(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        presum[i] = presum[i - 1] + a;
    }
    ll ret = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        ll t = presum[i] - target;
        ret += cnt[t];
        cnt[presum[i]]++;
    }
    cout << ret << endl;
    return 0;
}