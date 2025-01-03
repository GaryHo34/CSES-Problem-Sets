#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, tmp;
    cin >> n;

    vector<long long> arr;
    arr.push_back(0);

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    long long cost = accumulate(arr.begin(), arr.end(), 0LL);
    long long ans = LLONG_MAX;

    for (int i = 1; i <= n; i++)
    {
        cost = cost - (arr[i] - arr[i - 1]) * (n - i + 1) + (arr[i] - arr[i - 1]) * (i - 1);
        ans = min(ans, cost);
    }
    cout << ans << endl;
    return 0;
}