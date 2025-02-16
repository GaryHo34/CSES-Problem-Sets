#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    map<int, int> ss;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        int target = x - a;
        if (ss.find(target) != ss.end())
        {
            cout << ss[target] << " " << i << endl;
            return 0;
        }
        ss[a] = i;
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}