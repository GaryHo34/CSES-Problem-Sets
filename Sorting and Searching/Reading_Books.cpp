#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    long long sum = 0, mx = 0;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        sum += a;
        mx = max(a, mx);
    }

    cout << max(mx << 1, sum) << endl;

    return 0;
}