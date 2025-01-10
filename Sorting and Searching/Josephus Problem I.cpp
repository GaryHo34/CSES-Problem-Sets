#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ordered_set Set;
    int n, k = 1;
    cin >> n;

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