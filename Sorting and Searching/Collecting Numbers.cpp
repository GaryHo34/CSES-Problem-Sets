#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, tmp;
    cin >> n;

    unordered_set<long long> s;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        ans += s.find(tmp - 1) == s.end();
        s.insert(tmp);
    }

    cout << ans << endl;
    return 0;
}