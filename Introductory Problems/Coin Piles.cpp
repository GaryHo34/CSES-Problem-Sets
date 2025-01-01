#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    long long a, b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        if (abs(a - b) > min(a, b) || (min(a, b) - abs(a - b)) % 3 != 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}