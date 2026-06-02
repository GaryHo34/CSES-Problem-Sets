#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        grid[i] = input;
    }
    string res = "";
    res += grid[0][0];
    vector<pair<int, int>> next = {{0, 0}};
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<pair<int, int>> diff = {{0, 1}, {1, 0}};
    while (next.size() > 0)
    {
        map<char, vector<pair<int,int>>> candToNext;
        // cout << res << endl;
        for (auto [x, y] : next)
        {

            if (x == n - 1 && y == n - 1)
            {
                cout << res;
                return 0;
            }
            for (auto [a, b] : diff)
            {
                int dx = x + a, dy = y + b;
                if (dx == n || dy == n || visited[dx][dy])
                    continue;
                // pass, record the next
                visited[dx][dy] = true;
                candToNext[grid[dx][dy]].push_back({dx, dy});
            }
        }
        // first should be our candidate
        auto [nxtChar, nxtPath] = *candToNext.begin();
        res += nxtChar;
        swap(next, nxtPath);
    }
    return 0;
}