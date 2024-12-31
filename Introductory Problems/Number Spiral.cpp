#include <bits/stdc++.h>

using namespace std;

void solve(int x, int y)
{
    long long rank = max(x, y);
    if (rank % 2 == 1)
    {
        if (x >= y)
        {
            long long start = (rank - 1) * (rank - 1) + 1;
            cout << start + y - 1 << endl;
        }
        else
        {
            long long start = rank * rank;
            cout << start - x + 1 << endl;
        }
    }
    else
    {
        if (x >= y)
        {
            long long start = rank * rank;
            cout << start - y + 1 << endl;
        }
        else
        {
            long long start = (rank - 1) * (rank - 1) + 1;
            cout << start + x - 1 << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}