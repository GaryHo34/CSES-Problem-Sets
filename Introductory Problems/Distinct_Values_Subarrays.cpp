#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int j=0;
    long long res = 0;
    set<int> s;
    for (int i=0; i<n; i++)
    {
        if (j < i) j = i;
        while (j < n && s.find(arr[j]) == s.end())
        {
            s.insert(arr[j]);
            j++;
        }
        res += j-i;
        s.erase(arr[i]);
    }
    cout << res << endl;
    return 0;
}