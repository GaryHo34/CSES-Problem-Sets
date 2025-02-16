#include <bits/stdc++.h>

using namespace std;

vector<string> rets;

void solve(int n, int a, int b, int c)
{
    if (n > 0)
    {
        solve(n - 1, a, c, b);
        rets.push_back(to_string(a) + " " + to_string(b));
        solve(n - 1, c, b, a);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    solve(n, 1, 3, 2);
    cout << rets.size() << endl;
    
    for (auto step : rets)
    {
        cout << step << endl;
    }
    return 0;
}