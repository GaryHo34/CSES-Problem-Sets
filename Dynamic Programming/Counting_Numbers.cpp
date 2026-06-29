#include <bits/stdc++.h>

using namespace std;

long long solve(string &num, int len, int prev, bool isSame, long long memo[20][10][2])
{
    long long ret = 0;
    int n = num.size();

    // cout << "num: " << num << " len: " << len << " prev: " << prev << " isSame: " << isSame << endl;

    if (len == 0)
    {
        return 1;
    }

    if (memo[len][prev][isSame] != -1)
        return memo[len][prev][isSame];

    if (!isSame)
    {
        for (int d = 0; d < 10; d++)
        {
            if (d == prev)
                continue;
            ret += solve(num, len - 1, d, false, memo);
        }
    }
    else
    {
        int D = num[n - len] - '0';
        for (int d = 0; d < D; d++)
        {
            if (d == prev)
                continue;
            ret += solve(num, len - 1, d, false, memo);
        }
        if (D != prev)
            ret += solve(num, len - 1, D, true, memo);
    }

    memo[len][prev][isSame] = ret;

    return ret;
}

long long helper(long long num)
{
    if (num < 0)
        return 0;

    if (num == 0)
        return 1;

    // memo
    long long memo[20][10][2];
    memset(memo, -1, sizeof(memo));

    string NUM = to_string(num);
    int length = NUM.size();
    long long ret = 0;
    int D = NUM[0] - '0';

    for (int len = 1; len < length; len++)
    {
        if (len == 1)
            ret += solve(NUM, len - 1, 0, false, memo);

        for (int d = 1; d < 10; d++)
        {
            ret += solve(NUM, len - 1, d, false, memo);
        }
    }

    if (length == 1)
        ret += solve(NUM, length - 1, 0, false, memo);

    for (int d = 1; d < D; d++)
    {
        ret += solve(NUM, length - 1, d, false, memo);
    }

    ret += solve(NUM, length - 1, D, true, memo);

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long a, b;
    cin >> a >> b;

    cout << helper(b) - helper(a - 1) << endl;
    return 0;
}