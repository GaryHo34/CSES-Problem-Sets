#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int arr[200005];

bool check(ll mid, int n, int k)
{
    ll cnt = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        if (sum + arr[i] > mid)
        {
            cnt++;
            sum = 0;
        }
        sum += arr[i];
    }
    return cnt <= k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    ll l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        l = max((ll)arr[i], l);
        r += arr[i];
    }

    while (l < r)
    {
        ll mid = l + (r - l) / 2;
        if (!check(mid, n, k))
            l = mid + 1;
        else
            r = mid;
    }

    cout << l << endl;

    return 0;
}