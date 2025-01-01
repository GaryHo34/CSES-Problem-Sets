#include <bits/stdc++.h>

using namespace std;

void solve(long long q)
{
    long long base = 1, p = 1;
    while (q > 9 * base * p)
    {
        q -= 9 * base * p;
        base *= 10;
        p++;
    }
    long long c = q / p, m = q % p;
    if (m != 0)
    {
        c++;
    }
    long long target = base + c - 1;
    cout << to_string(target)[(m + p - 1) % p] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long c;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> c;
        solve(c);
    }

    return 0;
}