#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <typename T,typename R> using ordered_map = tree<T, R , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T,typename R> using ordered_multimap = tree<T, R , less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// *** note: in ordered_multiset lower_bound() works as upper_bound() and vice verca

int main() {
    int i, j, k, n, m;
    ordered_set<int> st;
    st.insert(1);
    st.insert(2);
    cout << *st.find_by_order(0) << endl; ///k th element
    cout << st.order_of_key(2) << endl; ///number of elements less than k
    ordered_map<int, int> mp;
    mp.insert({1, 10});
    mp.insert({2, 20});
    cout << mp.find_by_order(0)->second << endl; ///k th element
    cout << mp.order_of_key(2) << endl; ///number of first elements less than k
    return 0;
}