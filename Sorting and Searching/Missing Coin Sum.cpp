#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, tmp;
    cin >> n;

    vector<long long> coins;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        coins.push_back(tmp);
    }

    sort(coins.begin(), coins.end());

    long long limit = 0;
    for (auto x : coins)
    {
        if (x > limit + 1)
            break;
        limit += x;
    }
    cout << limit + 1 << endl;
    return 0;
}