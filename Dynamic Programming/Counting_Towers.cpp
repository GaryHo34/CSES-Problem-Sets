#include <bits/stdc++.h>

using namespace std;
long long MOD = 1e9 + 7;
long long res[1000005];

void solve(int n)
{
    res[1] = 2;
    long long sperate = 1;
    long long combine = 1;
    for (int i = 2; i <= n; i++)
    {
        long long ts = (sperate * 4 + combine) % MOD;
        long long tc = (sperate + combine * 2) % MOD;
        sperate = ts;
        combine = tc;
        res[i] =  (sperate + combine) % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    
    int t;
    cin >> t;
    int mx = 0;
    vector<int> arr(t);
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        arr[i] = n;
        mx = max(mx, n);
    }

    solve(mx);

    for (auto x: arr)
        cout << res[x] << endl;
    
    return 0;
}