#include <bits/stdc++.h>

using namespace std;

int ans;
vector<string> b;
unordered_set<int> rec;

bool check(int i, int j)
{
    for (auto r : rec)
    {
        int x = r / 8, y = r % 8;
        if (abs(i - x) == abs(j - y) || x == i || y == j)
        {
            return false;
        }
    }
    return true;
}

void solve(int idx, int x)
{
    if (idx == 8)
    {
        ans++;
        return;
    }
    for (int k = x; k < 64; k++)
    {
        int i = k / 8, j = k % 8;
        if (check(i, j) && b[i][j] != '*')
        {
            rec.insert(i * 8 + j);
            solve(idx + 1, k + 1);
            rec.erase(i * 8 + j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string l;
    for (int i = 0; i < 8; i++)
    {
        cin >> l;
        b.push_back(l);
    }

    solve(0, 0);
    cout << ans << endl;

    return 0;
}