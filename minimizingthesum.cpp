
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
 

int powerMod(int base, int exp, int mod) {
    int result = 1;
    base = base % mod; 

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}
void solve(int xx){
    int n; cin>>n;
    int k; cin>>k;
    vector<int> v(n);
    for(auto &i:v) cin>>i;
    vector<vector<int>> dp(n+2,vector<int>(k+2,1000000000000000));
    for(int i=0;i<=k+1;i++) dp[n][i]=0;
    for(int i=n-1;i>=0;i--){
        for(int j=k;j>=0;j--){
            int mn=v[i];
            for(int l=0;l<=j && i+l+1<=n;l++){
                mn=min(mn,v[i+l]);
                int tt=mn*(l+1)+(dp[i+l+1][j-l]);
                debug(tt); debug(i); debug(j); debug(l);
                dp[i][j]=min(dp[i][j],tt);
            }
        }
    }

    cout<<dp[0][k]<<endl;

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
