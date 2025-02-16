#include <bits/stdc++.h>

using namespace std;

inline void print(vector<int> &v)
{
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

    int n;
    cin >> n;

    vector<int> v1(n), v2(n);
    vector<array<int, 3>> arr;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b, i});
    }

    sort(arr.begin(), arr.end(), [](array<int, 3> &a, array<int, 3> &b) {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0]; 
    });
    
    int mn = arr[n-1][1];
    for (int i=n-2; i>=0; i--)
    {
        if (arr[i][1] >= mn)
        {
            v1[arr[i][2]] = 1;
        }
        mn = min(mn, arr[i][1]);
    }

    int mx = arr[0][1];
    for (int i = 1; i < n; i++)
    {
        if (arr[i][1] <= mx)
        {
            v2[arr[i][2]] = 1;
        }
        mx = max(mx, arr[i][1]);
    }

    print(v1);
    print(v2);

    return 0;
}