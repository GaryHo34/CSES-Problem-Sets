#include <bits/stdc++.h>

using namespace std;

long long dp[200000];
long long MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    long long sz = ((n + 1) * n) / 2;
    if (sz % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    dp[0] = 1;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = sz; j >= 0; j--)
        {
            dp[j + i] = (dp[j] + dp[j + i]) % MOD;
        }
    }
    // 500000004 is inv element of divide 2
    cout << (dp[sz / 2] * 500000004) % MOD << endl;
    return 0;
}