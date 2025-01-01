#include <bits/stdc++.h>

using namespace std;

vector<string> ss;
void solve(string &s, int idx)
{
    int n = s.size();
    if (idx == n)
    {
        ss.push_back(s);
        return;
    }
    solve(s, idx + 1);

    vector<int> visited(26);
    for (int i = idx + 1; i < n; i++)
    {
        if (s[i] == s[idx] || visited[s[i] - 'a'])
        {
            continue;
        }
        visited[s[i] - 'a'] = 1;
        swap(s[i], s[idx]);
        solve(s, idx + 1);
        swap(s[i], s[idx]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    solve(s, 0);

    sort(ss.begin(), ss.end());
    cout << ss.size() << endl;
    for (auto x : ss)
    {
        cout << x << endl;
    }
    return 0;
}