#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, n, tmp;
    cin >> x >> n;

    map<int, int> Map;
    multiset<int> Set;
    Map[0] = x;
    Set.insert(x);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        auto it = Map.upper_bound(tmp);
        it = prev(it);

        int a = it->first, b = it->second;
        Set.erase(Set.find(b - a));
        Map[a] = tmp;
        Map[tmp] = b;
        Set.insert(tmp - a);
        Set.insert(b - tmp);
        cout << *Set.rbegin() << " ";
    }
    cout << endl;
    return 0;
}