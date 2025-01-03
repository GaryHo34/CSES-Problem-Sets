#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    cin >> n;

    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        s.insert(tmp);
    }
    cout << s.size() << endl;
    return 0;
}