#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long MOD = 1e9 + 7;
    long long ret = 1;

    for (int i = 1; i <= n; i++)
    {
        ret <<= 1;
        ret %= MOD;
    }
    cout << ret << endl;
    return 0;
}