#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (long long i = 1; i <= n; i++)
    {
        cout << ((i * i) * (i * i - 1) >> 1) - ((i - 2) * (i - 1) << 2) << endl;
    }

    return 0;
}