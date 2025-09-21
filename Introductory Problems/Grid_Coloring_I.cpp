#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> res[i];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            bool flag = false;
            for (char ch = 'A'; ch <= 'D'; ch++)
            {
                if (ch != res[i][j] && (i - 1 < 0 || ch != res[i - 1][j]) && (j - 1 < 0 || ch != res[i][j - 1]))
                {
                    res[i][j] = ch;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                cout <<"IMPOSSIBLE" << endl;
                return 0;
            }
        }
    for (auto s: res) cout << s << endl;
    return 0;
}