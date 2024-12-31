#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin >> n;
    int ret = n;
    for (int i = 1; i < n; i++)
    {
        cin >> c;
        ret ^= (i ^ c);
    }
    cout << ret << endl;
    return 0;
}