#include <bits/stdc++.h>

using namespace std;

long long MOD = 1e9 + 7;

long long quickPow(long long a, long long b)
{
    if (b == 0)
    {
        return 1;
    }
    long long res = quickPow(a, b / 2);
    if (b % 2 == 1)
    {
        return ((res * res) % MOD) * a % MOD;
    }
    return (res * res) % MOD;
}

long long inv(long long b)
{
    return quickPow(b, MOD-2);
}

long long mydiv(long long a, long long b)
{
    return (a * inv(b)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    unordered_map<int, long long> cnt;
    long long total = 1, res = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (cnt[num] == 0)
        {
            cnt[num] = 1;
        }
        long long diff = mydiv(total, cnt[num]);
        res = (res + diff) % MOD;
        total = (total + diff) % MOD;
        cnt[num]++;
    }
    cout << res << endl;
    return 0;
}