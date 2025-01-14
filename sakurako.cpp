#include <bits/stdc++.h>
using namespace std;

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
#define lb lower_bound
#define up upper_bound
#define lld long double
#define int long long
#define ull unsigned int
#define ll int
const int mod = 998244353;
const ll inf = LLONG_MAX;
const ll ninf = LLONG_MIN;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) {
    cerr << "{"; _print(p.ff); cerr << ","; _print(p.second); cerr << "}";
}
template <class T> void _print(vector<T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(set<T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T> void _print(multiset<T> v) {
    cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";
}
template <class T, class V> void _print(map<T, V> v) {
    cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";
}
void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

long long fpow(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}
#define double long double
#define ss second

int ans;

vi pre;

#define MOD 1000000007

int nC2(int n) {
    if (n < 2) return 0; 
    return (long long)(n) * (n - 1) / 2 % MOD;
}

void solve(int xx){
    int n; cin>>n;
    vi v(n);
    for(auto &i:v) cin>>i;
        reverse(all(v));
    v.push_back(0);
    reverse(all(v));
    n++;
        vi pre=v;
    rep(i,1,n) pre[i]+=pre[i-1];
    map<int,vector<int>> mp;
   // mp[0].pb(-1);
    rep(i,0,n){
        mp[pre[i]].pb(i);
    }
    vector<int> dp(n+2,0);
    debug(pre);
    rev(i,n-1,0){
        auto it=upper_bound(all(mp[pre[i]]),i)-mp[pre[i]].begin();
        int x1=0;
        if(it!=mp[pre[i]].size()){
            x1=1+dp[mp[pre[i]][it]];
        }
        dp[i]=max(x1,dp[i+1]);
        debug(dp[i]);
    }
    cout<<dp[0]<<endl;
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
   cin >> test;
    rep(i, 1, test + 1) solve(i);

    return 0;
}
