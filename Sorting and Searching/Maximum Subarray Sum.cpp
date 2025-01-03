#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, tmp;
    cin >> n;

    cin >> tmp;
    long long sum = tmp, ans = tmp;

    for (int i = 1; i < n; i++)
    {
        cin >> tmp;
        sum = max(sum + tmp, tmp);
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}