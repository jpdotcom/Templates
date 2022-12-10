#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define FOR(b) for(int i=0;i<(int)b;i++)
#define mp(a,b) make_pair(a,b)
typedef std::vector<long  long> vi;
typedef std::pair<int,int> pi;
typedef long long ll;
#define F first 
#define S second 
#define PI 3.14159265358979323846
#define print(x) cout<<x<<'\n'
#define endl '\n'
#define bit(x,s) ((x>>(s))&1)
#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define INF ((ll)1e18)
#define MOD ((ll)998244353)
using namespace std;
using u64 = uint64_t;
using u128 = __uint128_t;
using namespace std;

const int MAXN = 500005;  // Maximum number of nodes in the tree
const int MAXLOG = 30;    // Maximum depth of the tree

vector<int> adj[MAXN];    // Adjacency list representing the tree
int parent[MAXN][MAXLOG]; // parent[i][j] = the 2^jth parent of node i
int depth[MAXN];          // depth[i] = the depth of node i in the tree

void dfs(int u, int p) {
  // Set the depth and parent of the current node
  depth[u] = depth[p] + 1;
  parent[u][0] = p;
  for (int i = 1; i < MAXLOG; i++) {
    parent[u][i] = parent[parent[u][i - 1]][i - 1];
  }
  // Traverse the subtree rooted at u
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }

}

int lift(int u, int d) {
  // Lift the node u up d levels in the tree
  for (int i = MAXLOG - 1; i >= 0; i--) {
    if (d & (1 << i)) {
      u = parent[u][i];
    }
  }
  return u;
}

int lca(int u, int v) {
  // If u is deeper than v, swap them
  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  // Lift u up so that it is at the same depth as v
  u = lift(u, depth[u] - depth[v]);

  // If u and v are the same node, we're done
  if (u == v) {
    return u;
  }

  // Lift both nodes up until they have the same parent
  for (int i = MAXLOG - 1; i >= 0; i--) {
    if (parent[u][i] != parent[v][i]) {
      u = parent[u][i];
      v = parent[v][i];
    }
  }
  // The parent of u and v is their lowest common ancestor
  return parent[u][0];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  // read input and construct the tree
  int n,q; cin>>n>>q;
  FOR(n-1){
      int v; cin>>v;v++;
      adj[v].pb(i+2);
  }
  dfs(1, 0);  // compute the parents of each node using binary lifting
  FOR(q){
      int a,b; cin>>a>>b; a++,b++;
      cout<<(lca(a,b)-1)<<endl;
  }
  // use the computed parents to answer queries
}
