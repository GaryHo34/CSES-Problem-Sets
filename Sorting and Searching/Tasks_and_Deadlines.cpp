#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    
    sort(arr.begin(), arr.end());

    long long ret = 0, cur = 0;
    for (auto [a, b]: arr)
    {
        cur += a;
        ret += b - cur;
    }
    cout << ret << endl;
    return 0;
}

// b1 - (t + a1) + b2 - (t + a1 + a2) > b2 - (t + a2) + b1 - (t + a2 + a1)
