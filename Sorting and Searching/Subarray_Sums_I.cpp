#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    cin >> n >> target;
    vector<int> presum(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        presum[i] = presum[i - 1] + a;
    }
    int ret = 0;
    int j = 0;
    for (int i = 0; i <= n; i++)
    {
        while (j <= n && presum[j] - presum[i] <= target)
        {
            if (presum[j] - presum[i] == target)
            {
                ret++;
            }
            j++;
        }
    }
    cout << ret << endl;
    return 0;
}