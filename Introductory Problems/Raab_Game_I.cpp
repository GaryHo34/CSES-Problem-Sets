#include <bits/stdc++.h>
#define PRINT(_x) for(auto _y : _x) cout << _y << " "; cout << endl

using namespace std;

void solve(int n, int a, int b)
{
    if ((a + b) > n || (a == 0 && b > 0) || (a > 0 && b == 0))
    {
        cout << "NO" << endl;
        return;
    }

    vector<int> x, y;

    while (n > a + b)
    {
        x.push_back(n);
        y.push_back(n);
        n--;
    }
    int k = n;
    while (n)
    {
        x.push_back(n);
        y.push_back((n - b < 1) ? (n - b + k) : n - b);
        n--;
    }
    cout << "YES" << endl;
    PRINT(x);
    PRINT(y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, a, b;
        cin >> n >> a >> b;
        solve(n, a, b);
    }
    return 0;
}
