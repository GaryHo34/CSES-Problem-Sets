#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> arr;
    for (int i=0; i<n; i++)
    {
        long long c;
        cin >> c;
        arr.push_back(c);
    }

    vector<long long> presum(n+1);
    for (int i=0; i<n; i++)
    {
        presum[i+1] = presum[i] + arr[i];
    }

    long long mx = LLONG_MIN;
    multiset<long long> s;
    for (int i=a; i<=n; i++)
    {
        s.insert(presum[i-a]);
        mx = max(mx, presum[i] - *s.begin());
        if (i-b >= 0)
        {
            s.erase(s.find(presum[i-b]));
        }
    }
    cout << mx << endl;
    return 0;
}