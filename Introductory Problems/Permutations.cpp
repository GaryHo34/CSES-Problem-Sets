#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION" << endl;
    }
    else
    {
        int cur = 2;
        while (cur <= n)
        {
            cout << cur << " ";
            cur += 2;
        }
        cur = 1;
        while (cur <= n)
        {
            cout << cur << " ";
            cur += 2;
        }
        cout << endl;
    }
    return 0;
}