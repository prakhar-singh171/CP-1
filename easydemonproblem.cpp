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
 




void solve() {
    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;

    vector<int> v(n), v1(m);
    for (auto &i : v) cin >> i;
    for (auto &i : v1) cin >> i;

    int t1 = accumulate(v.begin(), v.end(), 0LL);
    int t2 = accumulate(v1.begin(), v1.end(), 0LL);

    set<int> s, s1;
    for (auto i : v) s.insert(t1 - i);
    for (auto i : v1) s1.insert(t2 - i);
        debug(s); debug(s1);
    while(q--){
        int xx; cin>>xx;
        bool ok=0;
        debug(xx);

        for(int j=1;j*j<=abs(xx);j++){
            if(xx % j) continue;
            int d1=j; int d2=xx/j;
            int d3=-j; int d4=-xx/j;
            debug(d1); debug(d2);
            bool x1=s.find(d1)!=s.end() && s1.find(d2)!=s1.end();
            bool x2=s.find(d3)!=s.end() && s1.find(d4)!=s1.end();
            bool x3=s1.find(d1)!=s1.end() && s.find(d2)!=s.end();
            bool x4=s1.find(d3)!=s1.end() && s.find(d4)!=s.end();          
            if(x1 || x2 || x3 || x4) {yes; ok=1; break;}
        }
        if(!ok) {no; }
    }
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