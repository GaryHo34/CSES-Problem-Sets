#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, num, prev = 0;
    cin >> n;
    long long ret = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num < prev)
        {
            ret += abs(num - prev);
        }
        else
        {
            prev = num;
        }
    }
    cout << ret << endl;
    return 0;
}