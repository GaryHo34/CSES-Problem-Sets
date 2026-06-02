#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    
    bitset<100001> possible;
    possible[0] = 1;

    for (int i = 0; i < n; i++)
    {
        possible |= (possible << coins[i]);
    }

    vector<int> ret;
    for (int i=1; i<100001; i++)
    {
        if (possible[i])
            ret.push_back(i);
    }
    cout << ret.size() << endl;
    for (auto x: ret)
        cout << x << " ";
        cout << endl;
    return 0;
}