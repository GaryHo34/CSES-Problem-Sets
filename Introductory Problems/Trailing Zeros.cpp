#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ret = 0;
    for (int i = 5; i <= n; i *= 5)
    {
        ret += n / i;
    }
    cout << ret << endl;
    
    return 0;
}