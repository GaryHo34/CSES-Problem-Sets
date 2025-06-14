#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    size_t k;
    cin >> n >> k;
 
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
 
    int j = 0;
    long long ret = 0;
    map<int, int> M;
    for (int i = 0; i < n; i++)
    {
        while (j < n && (M.find(arr[j]) != M.end() || (M.size() + 1) <= k))
        {
            M[arr[j]]++;
            j++;
        }
        ret += j - i;
        M[arr[i]]--;
        if (M[arr[i]] == 0)
        {
            M.erase(arr[i]);
        }
    }
    cout << ret << endl;
 
    return 0;
}