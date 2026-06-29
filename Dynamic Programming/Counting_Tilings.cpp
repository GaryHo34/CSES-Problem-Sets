#include <bits/stdc++.h>

using namespace std;

long long dp[1001][1025];
long long MOD = 1e9 + 7;

bool is_pos_occupied(int mask, int pos)
{
    int m = (mask & (1 << pos));
    return !(m == 0);
}



void genarate_next_mask(int mask, int pos, int new_mask, int n, vector<int> &next_mask)
{
    if (pos == n)
    {
        next_mask.push_back(new_mask);
        return;
    }

    // 1. already filled up, to the next pos
    if (is_pos_occupied(mask, pos))
    {
        genarate_next_mask(mask, pos + 1, new_mask, n, next_mask);
        return;
    }

    // try put 2 width tile
    if (pos + 1 < n && !is_pos_occupied(mask, pos + 1))
    {
        genarate_next_mask(mask, pos + 2, new_mask, n, next_mask);
    }

    // try put 1 width tile, but affect the new_mask
    genarate_next_mask(mask, pos + 1, new_mask + (1 << pos), n, next_mask);
}

long long solve(int cur_level, int m, int n, int mask, unordered_map<int, vector<int>> &mask_map)
{
    if (cur_level == m)
    {
        if (mask == 0)
            return 1;
        return 0;
    }

    long long ans = 0;
    for (auto next_mask : mask_map[mask])
    {
        if (dp[cur_level + 1][next_mask] != -1)
        {
            ans = (ans + dp[cur_level + 1][next_mask]) % MOD;
        }
        else
        {
            ans = (ans + solve(cur_level + 1, m, n, next_mask, mask_map)) % MOD;
        }
    }

    dp[cur_level][mask] = ans;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= (1 << n); j++)
            dp[i][j] = -1;

    unordered_map<int, vector<int>> mask_map;

    // pre-calculate all next_masks
    for (int i = 0; i < (1 << n); i++)
    {
        // what is the next mask if fill up this mask
        genarate_next_mask(i, 0, 0, n, mask_map[i]);
    }

    cout << solve(0, m, n, 0, mask_map) << endl;

    return 0;
}

/*

x
x x x

x x x
x x x

    x
x x x

*/