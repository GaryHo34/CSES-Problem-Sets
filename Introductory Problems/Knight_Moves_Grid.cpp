#include <bits/stdc++.h>
 
using namespace std;
int b[1001][1001];
int dirs[8][2] = {{2, 1}, {-2, -1}, {2, -1}, {-2, 1}, {1, 2}, {-1, -2}, {1, -2}, {-1, 2}};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin >> n;
    queue<pair<int, int>> q;
    b[0][0] = -1;
    q.push({0, 0});
    int step = 0;
    while (!q.empty())
    {
        int len = q.size();
        while (len--)
        {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int dx = x + dirs[i][0], dy = y + dirs[i][1];
                if (dx >= n || dy >= n || dx < 0 || dy < 0 || b[dx][dy] != 0)
                    continue;
                b[dx][dy] = step + 1;
                q.push({dx, dy});
            }
        }
        step++;
    }
    b[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}