#include <bits/stdc++.h>
using namespace std;

#define ss second
#define vi vector<int>
#define vpi vector<pair<int, int>>
#define vii vector<vector<int>>
#define pi pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define maxf(v) *max_element(v.begin(), v.end())
#define minf(v) *min_element(v.begin(), v.end())
#define revr(v) reverse(v.begin(), v.end())
#define inp(v) for (auto &i : v) cin >> i;
#define print(v) for (auto &i : v) cout << i << " ";
#define tvs(v) for (auto &i : v)
#define rsort(v) sort(v.rbegin(), v.rend())
#define suv(s) set<int> s
#define mpg(s) map<int, int> s
#define pb push_back
#define pp pop_back
#define bb(v) v.back()
#define ff first
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define rr return
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define mx(x) *max_element(all(x))
#define mn(x) *min_element(all(x))
#define summ(x) accumulate(all(x), 0LL)
#define prt(x) cout << x << endl
#define bk break
#define lb lower_bound
#define up upper_bound
#define lld long double
#define int long long
#define ull unsigned int
#define ll int
const int mod = 1000000007;
const ll inf = LLONG_MAX;
const ll ninf = LLONG_MIN;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
 


const int MAXN = 200005;
vector<int> dp(MAXN, 0), dp1(MAXN, 0), price(MAXN, 0);
int mx = INT_MIN;

void dfs(int v, int parent, vector<vector<int>> &adj) {
    int t1 = 0;
    for (auto j : adj[v]) {
        if (j == parent) continue;
        dfs(j, v, adj);
        t1 += dp[j];
    }
    dp[v] = t1 + price[v];
}

int dfs1(int v, int parent, int depth, vector<vector<int>> &adj) {
    int t1 = 0;
    for (auto j : adj[v]) {
        if (j == parent) continue;
        t1 += dfs1(j, v, depth + 1, adj);
    }
    return dp1[v] = t1 + (depth * price[v]);
}

void dfs2(int v, int parent, int depth, int valp, int valp1, vector<vector<int>> &adj) {
    for (auto j : adj[v]) {
        if (j == parent) continue;
        int x1 = dp[v] - dp[j]-price[v];
        int x2 = dp1[v] - dp1[j]-(depth*dp1[v]);
        dfs2(j, v, depth + 1, x1, x2, adj);
    }
    int tt1 = dp1[v] - (depth * dp[v]);
    tt1 += (valp1 + valp);
    mx = max(mx, tt1);
}

void solve() {
    int n;
    cin >> n;

    // Input price of each node
    for (int i = 0; i < n; i++) cin >> price[i];

    // Input graph (undirected)
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int l, r;
        cin >> l >> r;
        --l; --r; // Convert to 0-based indexing
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    // Perform DFS traversals
    dfs(0, -1, adj);
    dfs1(0, -1, 0, adj);
    dfs2(0, -1, 0, 0, 0, adj);

     debug(dp1);

    // Output the maximum result
    cout << mx << endl;
}



 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
    freopen("input2.txt", "w", stdout);

    freopen("error1.txt", "w", stderr);
#endif
    int test = 1;
    //cin >> test; 
    rep(i, 1, test + 1) solve();

    return 0;
}