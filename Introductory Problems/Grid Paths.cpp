#include <bits/stdc++.h>

using namespace std;

string path;
int ans = 0;
bool vis[9][9];
int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void solve(int x, int y, int idx)
{
    if (x == 7 && y == 1)
    {
        ans += (idx == 48);
        return;
    }

    if (vis[x - 1][y] && vis[x + 1][y] && !vis[x][y - 1] && !vis[x][y + 1])
    {
        return;
    }

    if (!vis[x - 1][y] && !vis[x + 1][y] && vis[x][y - 1] && vis[x][y + 1])
    {
        return;
    }

    if (path[idx] == '?')
    {
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dirs[i][0], dy = y + dirs[i][1];
            if (dx >= 1 && dy >= 1 && dx < 8 && dy < 8 && !vis[dx][dy])
            {
                vis[dx][dy] = true;
                solve(dx, dy, idx + 1);
                vis[dx][dy] = false;
            }
        }
    }
    else
    {
        int dx = x, dy = y;
        if (path[idx] == 'D')
            dx++;
        else if (path[idx] == 'U')
            dx--;
        else if (path[idx] == 'R')
            dy++;
        else if (path[idx] == 'L')
            dy--;
        if (dx >= 1 && dy >= 1 && dx < 8 && dy < 8 && !vis[dx][dy])
        {
            vis[dx][dy] = true;
            solve(dx, dy, idx + 1);
            vis[dx][dy] = false;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 9; i++)
    {
        vis[0][i] = true;
        vis[i][0] = true;
        vis[8][i] = true;
        vis[i][8] = true;
    }
    cin >> path;

    vis[1][1] = true;
    solve(1, 1, 0);

    cout << ans << endl;

    return 0;
}