#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, num;
    cin >> n;

    vector<long long> p;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        p.push_back(num);
    }

    long long diff = LLONG_MAX;
    for (int i = 0; i < (1 << n); i++)
    {
        long long a = 0, b = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
            {
                a += p[j];
            }
            else
            {
                b += p[j];
            }
        }
        diff = min(diff, abs(a - b));
    }
    cout << diff << endl;
    return 0;
}