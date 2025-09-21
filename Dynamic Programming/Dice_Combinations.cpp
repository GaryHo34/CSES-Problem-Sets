#include <bits/stdc++.h>

using namespace std;

long long dp[7];
long long MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long tmp = 0;
        for (int j=6; j>=1; j--)
        {
            tmp = (tmp + dp[j] + 1 * (j == i)) % MOD;
            dp[j] = dp[j-1];
        }
        if (i == n)
            cout << tmp << endl;
        else
            dp[1] = tmp;
    }
    return 0;
}