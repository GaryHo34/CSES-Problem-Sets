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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ordered_set<int> Set;

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        Set.insert(i);

    int start = 0;
    while (!Set.empty())
    {
        int remove = (start + k) % Set.size();
        start = remove;
        auto t = Set.find_by_order(remove);
        cout << *t << " ";
        Set.erase(t);
    }

    return 0;
}