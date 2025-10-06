#include <bits/stdc++.h>

using namespace std;

int val[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        coins.push_back(a);
    }
    for (int i=1; i<=x; i++)
        val[i] = INT_MAX/2;
    for (int i=1; i<=x; i++)
    {
        for (auto c: coins)
        {
            if (i-c >=0)
                val[i] = min(val[i], val[i-c] + 1);
        }
    }
    if (val[x] >= INT_MAX/2)
        cout << -1 << endl;
    else
        cout << val[x] << endl;    
    return 0;
}