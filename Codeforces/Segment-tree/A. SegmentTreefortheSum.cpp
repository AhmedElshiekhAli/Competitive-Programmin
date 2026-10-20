#include <bits/stdc++.h>
#define el endl
#define int long long
using namespace std;
void inout() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
void Ahmed() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
struct Node {
    int64_t v;
    Node() : v(0) {}
    Node(int64_t x) : v(x) {}
    operator int64_t() const { return v; }
};
template<typename T, typename U, auto merge>
struct SegmentTree {
    int n;
    vector<T> tree;
    SegmentTree() {}
    SegmentTree(const vector<U> &v) { init(v); }
    void update(int idx, U val) {
        update(1, 0, n - 1, idx, val);
    }
    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
    void init(const vector<U> &v) {
        n = v.size();
        tree.assign(n << 2, T());
        build(1, 0, n - 1, v);
    }
    void build(int node, int l, int r, const
  vector<U> &v) {
        if (l == r) {
            tree[node] = T(v[l]);
            return;
        }
        int m = l + r >> 1;
        build(node << 1, l, m, v);
        build(node << 1 | 1, m + 1, r, v);
        tree[node] = merge(tree[node << 1],
        tree[node << 1 | 1]);
    }
    void update(int node, int l, int r, int idx, U
  val) {
        if (l == r) {
            tree[node] = T(val);
            return;
        }
        int m = l + r >> 1;
        if (idx <= m) {
            update(node << 1, l, m, idx, val);
        } else {
            update(node << 1 | 1, m + 1, r, idx, val);
        }
        tree[node] = merge(tree[node << 1],
    tree[node<< 1 | 1]);
    }
    T query(int node, int l, int r, int lx, int rx)
    {
        if (l > rx || r < lx) {
            return T();
        }
        if (l >= lx && r <= rx) {
            return tree[node];
        }
        int m = l + r >> 1;
        T l_ans = query(node << 1, l, m, lx, rx);
        T r_ans = query(node << 1 | 1, m + 1, r, lx,
    rx);
        return merge(l_ans, r_ans);
    }
};
inline Node mergeNode(const Node &a, const Node &b) {
    return Node(a.v + b.v);
}
void solve() {
    int n,q;
    cin>>n>>q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    SegmentTree<Node,int,mergeNode>st(v);
    while (q--) {
        int t;cin>>t;
        if (t == 1) {
            int i,u; cin>>i>>u;
            st.update(i,u);
        }
        else {
            int l,r;cin>>l>>r;
           cout<<st.query(l,r-1)<<el;
        }
    }
}
signed main() {
    Ahmed();
    int t=1;
   // cin>>t;
    while(t--) {
        solve();
    }
}
