#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_set<int> row[n];
    unordered_set<int> col[n];

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            int t = 0;
            while (row[i].count(t) || col[j].count(t))
                t++;
            cout << t;
            row[i].insert(t);
            col[j].insert(t);
            if (j == n-1) cout << endl;
            else cout << " ";
        }
    }

    return 0;
}