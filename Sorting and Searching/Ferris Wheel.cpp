#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, tmp;
    cin >> n >> x;

    vector<int> children;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        children.push_back(tmp);
    }

    sort(children.begin(), children.end());

    int l = 0, r = children.size() - 1, ans = 0;
    while (l <= r)
    {
        if (children[r] + children[l] <= x && l != r)
        {
            l++;
        }
        ans++;
        r--;
    }
    cout << ans << endl;
    return 0;
}