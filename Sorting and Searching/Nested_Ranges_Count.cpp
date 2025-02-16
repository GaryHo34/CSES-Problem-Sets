#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

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
    
    ordered_set<pair<int,int>> mns, mxs;
    mns.insert({arr[n-1][1], arr[n-1][2]});
    for (int i=n-2; i>=0; i--)
    {
        // for (auto [a, b]: mns) cout << a << " "; cout << endl;
        // cout << i << " " <<arr[i][1] << " " << mns.order_of_key({arr[i][1], INT_MAX}) << endl;
        v1[arr[i][2]] =  mns.order_of_key({arr[i][1], INT_MAX});
        mns.insert({arr[i][1], arr[i][2]});
    }

    mxs.insert({arr[0][1], arr[0][2]});
    for (int i = 1; i < n; i++)
    {
        v2[arr[i][2]] = mxs.size() - mxs.order_of_key({arr[i][1], INT_MIN});
        mxs.insert({arr[i][1], arr[i][2]});
    }

    print(v1);
    print(v2);

    return 0;
}