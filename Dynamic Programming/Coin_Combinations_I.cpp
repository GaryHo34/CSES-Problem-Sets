#include <bits/stdc++.h>

using namespace std;

long long val[1000005];

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
    val[0] = 1;
    long long MOD = 1e9 + 7;
    
    for (int i=1; i<=x; i++)
    {
        for (auto c: coins)
        {
            if (i-c >=0)
                val[i] = (val[i]+ val[i-c]) % MOD;
        }
    }
    cout << val[x] << endl;    
    return 0;
}