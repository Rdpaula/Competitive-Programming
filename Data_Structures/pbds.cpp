#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef
tree<
  ll,	//type of data pair<ll,ll> if multiset
  null_type, //null if set key ->data type if we want map (use ->first ->second) finds is on keys
  less<ll>, /// less<pair<int,int>> if multiset (elem,id), order_of_key = lower_bound, if want greater elements first use negative values
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
