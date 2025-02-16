#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, t;
    cin >> n >> t;
    long long mx = 0;
    vector<long long> mac(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mac[i];
        mx = max(mx, mac[i]);
    }

    long long l = 0, r = mx * t;
    while (l < r)
    {
        long long mid = l + (r - l) / 2;
        long long cnt = 0;
        bool flag = false;
        for (auto x : mac)
        {
            flag = LLONG_MAX - cnt < mid / x;
            cnt += mid / x;
        }
        if (cnt >= t || flag)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}