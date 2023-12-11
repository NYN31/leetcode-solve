
#include <bits/stdc++.h>
using namespace std;
#define ll long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;

void solve()
{

    pbds_set st;
    st.insert(10);
    st.insert(20);
    st.insert(30);
    st.insert(40);
    st.insert(40);

    for (int x : st)
    {
        cout << x << endl;
    }

    cout << " " << st.order_of_key(30) << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}