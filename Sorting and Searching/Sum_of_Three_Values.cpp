#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, target;
    cin >> n >> target;

    vector<array<int, 2>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0];
        arr[i][1] = i + 1;
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int t = target - arr[i][0];
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            if (arr[l][0] + arr[r][0] == t)
            {
                cout << arr[i][1] << " "
                     << arr[l][1] << " "
                     << arr[r][1] << endl;
                return 0;
            }
            else if (arr[l][0] + arr[r][0] < t)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}