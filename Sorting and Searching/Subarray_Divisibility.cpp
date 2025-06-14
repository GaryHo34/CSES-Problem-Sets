#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> presum(n + 1);
    for (int i = 1; i <= n; i++)
    {
        presum[i] = presum[i - 1] + arr[i - 1];
    }

    map<ll, ll> M;
    M[0] = 1;
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        ll target = ((presum[i] % n) + n) % n;
        cnt += M[target]++;
    }
    cout << cnt << endl;

    return 0;
}