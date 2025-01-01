#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> v({""});
    for (int i = 1; i <= n; i++)
    {
        for (int j = v.size() - 1; j >= 0; j--)
        {
            v.push_back(v[j]);
        }
        for (int j = 0; j < v.size(); j++)
        {
            if (j < v.size() / 2)
            {
                v[j] = "0" + v[j];
            }
            else
            {
                v[j] = "1" + v[j];
            }
        }
    }
    for (auto s : v)
    {
        cout << s << endl;
    }
    return 0;
}