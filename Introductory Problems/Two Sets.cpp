#include <bits/stdc++.h>

using namespace std;

void print(vector<long long> &v)
{
    cout << v.size() << endl;
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    if ((n * (n + 1) / 2) & 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        vector<long long> v1, v2;
        if (n & 1)
        {
            v2.push_back(n);
            n--;
        }
        for (int i = 1; i <= n / 2; i += 2)
        {
            v1.push_back(i);
            v1.push_back(n - i + 1);
            if (i + 1 <= n / 2)
            {
                v2.push_back(i + 1);
                v2.push_back(n - i);
            }
        }
        print(v1);
        print(v2);
    }
    return 0;
}